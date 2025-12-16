/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:15:27 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 20:31:32 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main(void)
{
  Fixed a(5);
  Fixed const b(Fixed(5.05f) + Fixed(2));
  Fixed const c(Fixed(5.05f) - Fixed(2));
  Fixed const d(Fixed(5.05f) * Fixed(2));
  Fixed e(Fixed(5.05f) / Fixed(2));

  std::cout << "addition" << std::endl;
  std::cout << "a(5) = " << a << std::endl;
  std::cout << "b(Fixed(5.05f) + Fixed(2)) = " << b << std::endl;
  std::cout << "substruction" << std::endl;
  std::cout << "c(Fixed(5.05f) - Fixed(2)) = " << c << std::endl;
  std::cout << "multiplcation" << std::endl;
  std::cout << "d(Fixed(5.05f) * Fixed(2)) = " << d << std::endl;
  std::cout << "division" << std::endl;
  std::cout << "e(Fixed(5.05f) / Fixed(2)) = " << e << std::endl;

  std::cout << "[compare]" << std::endl;
  std::cout << "a > b : ";
  a > b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a > a : ";
  a > a ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a < b : ";
  a < b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a < a : ";
  a < a ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a >= b : ";
  a >= b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a >= a : ";
  a >= a ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a <= b : ";
  a <= b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a <= a : ";
  a <= a ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a == b ";
  a == b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "a != b ";
  a != b ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;

  std::cout << "increment" << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << "decrement" << std::endl;
  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;

  std::cout << "max/min" << std::endl;
  std::cout << "max(a, e) : " << Fixed::max(a, e) << std::endl;
  std::cout << "min(a, e) : " << Fixed::min(a, e) << std::endl;
  std::cout << "max/min for const" << std::endl;
  std::cout << "max(a, d) : " << Fixed::max(a, d) << std::endl;
  std::cout << "min(a, d) : " << Fixed::min(a, d) << std::endl;
  return 0;
}
