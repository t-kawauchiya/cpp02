/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/08 09:00:38 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>
#include <limits>

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(const int& integer)
{
  int64_t raw = (int64_t)integer * (1L << _frac_bits);

  if (raw > (int64_t)std::numeric_limits<int>::max())
    raw = std::numeric_limits<int>::max();
  else if (raw < (int64_t)std::numeric_limits<int>::min())
    raw = std::numeric_limits<int>::min();
  _rawBits = (int)raw;
}

Fixed::Fixed(const float& float_num)
{
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
  *this = other;
}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator=(const Fixed& other)
{
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

int Fixed::toInt(void) const
{
  return (this->_rawBits / (1 << this->_frac_bits));
}

float Fixed::toFloat(void) const
{
  return (float)_rawBits / (float)(1 << _frac_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
  os << f.toFloat();
  return os;
}

bool Fixed::operator>(const Fixed& f) const
{
  return (*this).getRawBits() > f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) const
{
  return f > *this;
}

bool Fixed::operator>=(const Fixed& f) const
{
  return !(*this < f);
}

bool Fixed::operator<=(const Fixed& f) const
{
  return !(*this > f);
}

bool Fixed::operator==(const Fixed& f) const
{
  return (*this).getRawBits() == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) const
{
  return !(*this == f);
}

Fixed Fixed::operator+(const Fixed& f) const
{
  Fixed ret;

  ret.setRawBits(this->getRawBits() + f.getRawBits());
  return ret;
}

Fixed Fixed::operator-(const Fixed& f) const
{
  Fixed ret;

  ret.setRawBits(this->getRawBits() - f.getRawBits());
  return ret;
}

Fixed Fixed::operator*(const Fixed& f) const
{
  Fixed ret;
  long a = this->getRawBits();
  long b = f.getRawBits();
  long result;

  result = a * b >> _frac_bits;
  ret.setRawBits((int)result);
  return ret;
}

Fixed Fixed::operator/(const Fixed& f) const
{
  Fixed ret;
  long a = this->getRawBits() << _frac_bits;
  long b = f.getRawBits();
  long result;

  if (b == 0)
    throw std::runtime_error("division by zero");
  result = a / b;

  ret.setRawBits((int)result);
  return ret;
}

Fixed& Fixed::operator++()
{
  ++this->_rawBits;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed old(*this);
  ++this->_rawBits;
  return old;
}

Fixed& Fixed::operator--()
{
  --this->_rawBits;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed old(*this);
  --this->_rawBits;
  return old;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
  if (f1 < f2)
    return f1;
  return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
  if (f1 < f2)
    return f1;
  return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
  if (f1 > f2)
    return f1;
  return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
  if (f1 > f2)
    return f1;
  return f2;
}
