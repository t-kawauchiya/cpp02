/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/15 14:18:19 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H_
#define _FIXED_H_

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(int integer);
  Fixed(double float_num);
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int _rawBits;
  static const int _frac_bits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &c);

#endif
