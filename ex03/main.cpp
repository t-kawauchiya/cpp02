/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:15:27 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 22:46:19 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
  Point a(0, 0);
  Point b(3, 0);
  Point c(0, 4);
  Point p1(1, 1);
  Point p2(5, 5);
  Point p3(1, 0);
  Point p4(3, 0);

  std::cout << "a : " << a;
  std::cout << "b : " << b;
  std::cout << "c : " << c;
  std::cout << "p1 : " << p1;
  std::cout << "p2 : " << p2;
  std::cout << "p3 : " << p3;
  std::cout << "p4 : " << p4;

  std::cout << "bsp(a,b,c,p1) : ";
  bsp(a, b, c, p1) ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;

  std::cout << "bsp(a,b,c,p2) : ";
  bsp(a, b, c, p2) ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "bsp(a,b,c,p3) : ";
  bsp(a, b, c, p3) ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;
  std::cout << "bsp(a,b,c,p4) : ";
  bsp(a, b, c, p4) ? std::cout << "true" : std::cout << "false";
  std::cout << std::endl;

  return 0;
}
