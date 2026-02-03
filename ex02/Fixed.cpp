/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 20:33:12 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _rawBits(0) {}

Fixed::Fixed(int integer) : _rawBits(integer << 8) {}

Fixed::Fixed(double float_num) : _rawBits(std::roundf(float_num * (1 << _frac_bits))) {}

Fixed::~Fixed(void) {}

Fixed::Fixed(const Fixed& other)
{
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
  return (float)_rawBits / (1 << _frac_bits);
}

int Fixed::toInt(void) const
{
  return _rawBits >> _frac_bits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  if (this != &other)
    _rawBits = other.getRawBits();
  return (*this);
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
  long long a = this->getRawBits();
  long long b = f.getRawBits();
  long long result;

  result = a * b >> _frac_bits;
  ret.setRawBits((int)result);
  return ret;
}

Fixed Fixed::operator/(const Fixed& f) const
{
  Fixed ret;
  long long a = this->getRawBits() << _frac_bits;
  long long b = f.getRawBits();
  long long result;

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
