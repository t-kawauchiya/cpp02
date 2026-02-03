/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:15:27 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/03 22:20:57 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main(void)
{
  std::string separator = "----------------------------------------\n";
  {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
  }

  std::cout << separator;

  try
  {
    Fixed a(5);
    Fixed const b(Fixed(5.05f) + Fixed(2));
    Fixed const c(Fixed(5.05f) - Fixed(2));
    Fixed const d(Fixed(5.05f) * Fixed(2));
    Fixed e(Fixed(5.05f) / Fixed(2));

    std::cout << "(addition)" << std::endl;
    std::cout << "a(5) = " << a << std::endl;
    std::cout << "Fixed(5.05f) + Fixed(2) = " << b << std::endl;
    std::cout << separator;
    std::cout << "(substruction)" << std::endl;
    std::cout << "Fixed(5.05f) - Fixed(2) = " << c << std::endl;
    std::cout << separator;
    std::cout << "(multiplcation)" << std::endl;
    std::cout << "Fixed(5.05f) * Fixed(2) = " << d << std::endl;
    std::cout << separator;
    std::cout << "(division)" << std::endl;
    std::cout << "Fixed(5.05f) / Fixed(2) = " << e << std::endl;
    // std::cout << "Fixed(5.05f) / Fixed(0) = " << Fixed(5.05) / Fixed(0) << std::endl;

    std::cout << separator;
    std::cout << "(compare)" << std::endl;
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

    std::cout << separator;
    std::cout << "(increment)" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << separator;
    std::cout << "(decrement)" << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;

    std::cout << separator;
    std::cout << "(max/min)" << std::endl;
    std::cout << "max(a, e) : " << Fixed::max(a, e) << std::endl;
    std::cout << "min(a, e) : " << Fixed::min(a, e) << std::endl;
    std::cout << "(max/min for const)" << std::endl;
    std::cout << "max(a, d) : " << Fixed::max(a, d) << std::endl;
    std::cout << "min(a, d) : " << Fixed::min(a, d) << std::endl;

    std::cout << separator;
    std::cout << "(toInt/toFloat)" << std::endl;
    std::cout << "Fixed(5.05f).toInt() : " << Fixed(5.05f).toInt() << std::endl;
    std::cout << "Fixed(-5.05f).toInt() : " << Fixed(-5.05f).toInt() << std::endl;
    std::cout << "Fixed(5.05f).toFloat() : " << Fixed(5.05f).toFloat() << std::endl;
    std::cout << "Fixed(-5.05f).toFloat() : " << Fixed(-5.05f).toFloat() << std::endl;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << "std::runtime_error: " << e.what() << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "std::exception: " << e.what() << "\n";
  }
  return 0;
}
