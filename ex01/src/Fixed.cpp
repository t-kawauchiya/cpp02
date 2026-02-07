/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/08 08:45:57 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>
#include <cmath>
#include <iostream>
#include <limits>

Fixed::Fixed(void) : _rawBits(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int& integer)
{
  std::cout << "Int constructor called\n";
  int64_t raw = (int64_t)integer * (1L << _frac_bits);

  if (raw > (int64_t)std::numeric_limits<int>::max())
    raw = std::numeric_limits<int>::max();
  else if (raw < (int64_t)std::numeric_limits<int>::min())
    raw = std::numeric_limits<int>::min();
  _rawBits = (int)raw;
}

Fixed::Fixed(const float& float_num)
{
  std::cout << "Float constructor called\n";
  if (!std::isfinite(float_num))
  {
    if (float_num < 0)
      _rawBits = std::numeric_limits<int>::min();
    else
      _rawBits = std::numeric_limits<int>::max();
    return;
  }
  double raw = (double)float_num * (1 << _frac_bits);
  if (raw > (double)std::numeric_limits<int>::max())
    _rawBits = std::numeric_limits<int>::min();
  else if (raw < (double)std::numeric_limits<int>::min())
    _rawBits = std::numeric_limits<int>::min();
  _rawBits = roundf(float_num * (1 << _frac_bits));
}

Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    _rawBits = other.getRawBits();
  return (*this);
}

int Fixed::getRawBits(void) const
{
  return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
  _rawBits = raw;
}

float Fixed::toFloat(void) const
{
  return (float)_rawBits / (float)(1 << _frac_bits);
}

int Fixed::toInt(void) const
{
  return (this->_rawBits / (1 << _frac_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
  os << f.toFloat();
  return os;
}
