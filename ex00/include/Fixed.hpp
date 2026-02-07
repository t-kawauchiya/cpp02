/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/07 21:24:26 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
public:
  Fixed(void);
  Fixed(const Fixed& other);
  ~Fixed(void);

  Fixed& operator=(const Fixed& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _rawBits;
  static const int _frac_bits = 8;
};
