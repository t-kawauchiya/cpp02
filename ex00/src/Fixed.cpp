/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:46:39 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/15 13:50:58 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed(void) : _rawBits(0)
{
  std::cout << "Default constructor called\n";
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
  std::cout << "getRawBits member function called\n";
  return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called\n";
  this->_rawBits = raw;
}

Fixed& Fixed::operator=(const Fixed& other)
{
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    this->_rawBits = other.getRawBits();

  return (*this);
}
