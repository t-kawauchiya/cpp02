/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:15:27 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/08 20:08:01 by takawauc         ###   ########.fr       */
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

    std::cout << "(addition)" << std::endl;
    std::cout << "Fixed(5.05f) + Fixed(2) = " << Fixed(5.05f) + Fixed(2) << std::endl;
    std::cout << separator;
    std::cout << "(substruction)" << std::endl;
    std::cout << "Fixed(5.05f) - Fixed(2) = " << Fixed(5.05f) - Fixed(2) << std::endl;
    std::cout << separator;
    std::cout << "(multiplcation)" << std::endl;
    std::cout << "Fixed(5.05f) * Fixed(2) = " << Fixed(5.05f) * Fixed(2) << std::endl;
    std::cout << separator;
    std::cout << "(division)" << std::endl;
    std::cout << "Fixed(5.05f) / Fixed(2) = " << Fixed(5.05f) / Fixed(2) << std::endl;
    // std::cout << "Fixed(5.05f) / Fixed(0) = " << Fixed(5.05) / Fixed(0) << std::endl;

    std::cout << separator;
    std::cout << "(compare)" << std::endl;

    std::cout << "  (>) \n";
    std::cout << "    Fixed(5.05f) > Fixed(2) : ";
    Fixed(5.05f) > Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) > Fixed(5.05f) : ";
    Fixed(2) > Fixed(5.05f) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) > Fixed(2) : ";
    Fixed(2) > Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << "  (<) \n";
    std::cout << "    Fixed(5.05f) < Fixed(2) : ";
    Fixed(5.05f) < Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) < Fixed(5.05f) : ";
    Fixed(2) < Fixed(5.05f) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) < Fixed(2) : ";
    Fixed(2) < Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << "  (>=) \n";
    std::cout << "    Fixed(5.05f) >= Fixed(2) : ";
    Fixed(5.05f) >= Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) >= Fixed(5.05f) : ";
    Fixed(2) >= Fixed(5.05f) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) > Fixed(2) : ";
    Fixed(2) >= Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << "  (<=) \n";
    std::cout << "    Fixed(5.05f) <= Fixed(2) : ";
    Fixed(5.05f) <= Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) <= Fixed(5.05f) : ";
    Fixed(2) <= Fixed(5.05f) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) <= Fixed(2) : ";
    Fixed(2) <= Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << "  (==) \n";
    std::cout << "    Fixed(5.05f) == Fixed(2) : ";
    Fixed(5.05f) == Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) == Fixed(2) : ";
    Fixed(2) == Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << "  (!=) \n";
    std::cout << "    Fixed(5.05f) != Fixed(2) : ";
    Fixed(5.05f) != Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";
    std::cout << "    Fixed(2) != Fixed(2) : ";
    Fixed(2) != Fixed(2) ? std::cout << "true" : std::cout << "false";
    std::cout << "\n";

    std::cout << separator;
    Fixed a(5);
    std::cout << "(increment)" << std::endl;
    std::cout << "  a  : " << a << std::endl;
    std::cout << "  ++a: " << ++a << std::endl;
    std::cout << "  a  : " << a << std::endl;
    std::cout << "  a++: " << a++ << std::endl;
    std::cout << "  a  : " << a << std::endl;

    std::cout << separator;
    std::cout << "(decrement)" << std::endl;
    a = 5;
    std::cout << "  a  : " << a << std::endl;
    std::cout << "  --a: " << --a << std::endl;
    std::cout << "  a  : " << a << std::endl;
    std::cout << "  a--: " << a-- << std::endl;
    std::cout << "  a  : " << a << std::endl;

    std::cout << separator;

    std::cout << "(max/min)" << std::endl;
    std::cout << "  max(Fixed(5.05f), Fixed(2)) : ";
    std::cout << Fixed::max(Fixed(5.05f), Fixed(2)) << std::endl;
    std::cout << "  min(Fixed(5.05f), Fixed(2)) : ";
    std::cout << Fixed::min(Fixed(5.05f), Fixed(2)) << std::endl;
    std::cout << "(max/min for const)" << std::endl;
    const Fixed b(2), c(3);
    std::cout << "  const Fixed b(2),c(3)" << std::endl;
    std::cout << "  max(b, c) : " << Fixed::max(b, c) << std::endl;
    std::cout << "  min(b, c) : " << Fixed::min(b, c) << std::endl;

    std::cout << separator;
    std::cout << "(toInt/toFloat)" << std::endl;
    std::cout << "  Fixed(5.05f).toInt() : " << Fixed(5.05f).toInt() << std::endl;
    std::cout << "  Fixed(-5.05f).toInt() : " << Fixed(-5.05f).toInt() << std::endl;
    std::cout << "  Fixed(5.05f).toFloat() : " << Fixed(5.05f).toFloat() << std::endl;
    std::cout << "  Fixed(-5.05f).toFloat() : " << Fixed(-5.05f).toFloat() << std::endl;
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
