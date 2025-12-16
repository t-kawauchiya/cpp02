/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 19:04:39 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

class Fixed
{
public:
  Fixed(void);
  Fixed(int integer);
  Fixed(double float_num);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;

  bool operator>(const Fixed& f) const;
  bool operator<(const Fixed& f) const;
  bool operator>=(const Fixed& f) const;
  bool operator<=(const Fixed& f) const;
  bool operator==(const Fixed& f) const;
  bool operator!=(const Fixed& f) const;

  Fixed operator+(const Fixed& f) const;
  Fixed operator-(const Fixed& f) const;
  Fixed operator*(const Fixed& f) const;
  Fixed operator/(const Fixed& f) const;

  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

  static Fixed& min(Fixed& f1, Fixed& f2);
  static const Fixed& min(const Fixed& f1, const Fixed& f2);
  static Fixed& max(Fixed& f1, Fixed& f2);
  static const Fixed& max(const Fixed& f1, const Fixed& f2);

private:
  int _rawBits;
  static const int _frac_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);

#endif
