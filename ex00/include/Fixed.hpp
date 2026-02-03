/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/15 13:21:44 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H_
#define _FIXED_H_

class Fixed
{
public:
  Fixed(void);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed(void);
  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _rawBits;
  static const int _frac_bits = 8;
};

#endif
