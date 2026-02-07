/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/07 21:22:39 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Fixed
{
public:
  Fixed(void);
  Fixed(const int& integer);
  Fixed(const float& float_num);
  Fixed(const Fixed& other);

  ~Fixed(void);

  Fixed& operator=(const Fixed& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int _rawBits;
  static const int _frac_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);
