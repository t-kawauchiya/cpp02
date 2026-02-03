/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/03 21:48:30 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _rawBits(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(int integer) : _rawBits(integer << _frac_bits)
{
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(float float_num) : _rawBits(roundf(float_num * (1 << _frac_bits)))
{
  std::cout << "Float constructor called\n";
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
  std::cout << "Copy constructor called\n";
  *this = other;
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
  return static_cast<int>(this->_rawBits / (1 << this->_frac_bits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    _rawBits = other.getRawBits();

  return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
  os << f.toFloat();
  return os;
}
