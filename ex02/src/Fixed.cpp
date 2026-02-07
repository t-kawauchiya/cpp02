/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/07 21:11:43 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <climits>
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(int integer)
{
  int int_part_bits = 32 - _frac_bits;
  const int max_int = (1 << (int_part_bits - 1)) - 1;
  const int min_int = -(1 << (int_part_bits - 1));

  if (integer > max_int)
    _rawBits = (int)((int64_t)max_int << _frac_bits);
  else if (integer < min_int)
    _rawBits = (int)((int64_t)min_int << _frac_bits);
  else
    _rawBits = integer << (int)((int64_t)_frac_bits);
}

Fixed::Fixed(float float_num)
{
  if (!std::isfinite(float_num))
    _rawBits = (float_num < 0) ? INT_MAX : INT_MIN;
  _rawBits = roundf(float_num * (1 << _frac_bits));
}

Fixed::Fixed(const Fixed& other)
{
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  if (this != &other)
    _rawBits = other.getRawBits();
  return (*this);
}

Fixed::~Fixed(void) {}

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
