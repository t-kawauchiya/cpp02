/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 16:40:45 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _rawBits(0) {
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(int integer) : _rawBits(integer << 8) {
  std::cout << "Int constructor called\n";
}

Fixed::Fixed(double float_num)
    : _rawBits(std::round(float_num * (1 << _frac_bits))) {
  std::cout << "Float constructor called\n";
}

Fixed::~Fixed(void) { std::cout << "Destructor called\n"; }

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called\n";
  *this = other;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called\n";
  return _rawBits;
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called\n";
  _rawBits = raw;
}
float Fixed::toFloat(void) const { return (float)_rawBits / (1 << _frac_bits); }

int Fixed::toInt(void) const { return _rawBits >> _frac_bits; }

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    _rawBits = other.getRawBits();

  return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &f) {

  os << f.toFloat();
  return os;
}
