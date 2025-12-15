/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:15:27 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/15 13:47:52 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

int main(void)
{
  Fixed a;
  // L Default constructor called
  Fixed b(a);
  // L Copy constructor called
  // L Copy assignment operator called
  // // <-- This line may be missing depending on your implementation
  // getRawBits member function called
  Fixed c;
  // L Default constructor called

  c = b;
  // L Copy assignment operator called
  // getRawBits member function called

  std::cout << a.getRawBits() << std::endl;
  // L getRawBits member function called
  // L 0
  std::cout << b.getRawBits() << std::endl;
  // L getRawBits member function called
  // L 0
  std::cout << c.getRawBits() << std::endl;
  // L getRawBits member function called
  // L 0

  // L Destructor called
  // L Destructor called
  // L Destructor called
  return 0;
}
