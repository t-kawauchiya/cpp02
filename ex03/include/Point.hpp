/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:40:30 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 22:28:29 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _POINT_H_
#define _POINT_H_

#include "Fixed.hpp"

#include <iostream>

class Point
{
public:
  Point(void);
  Point(float x, float y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point(void);

  Fixed getX(void) const;
  Fixed getY(void) const;
  void setX(const Fixed x);
  void setX(const float x);
  void setY(const Fixed x);
  void setY(const float x);

  Fixed cross(const Point p);
  Point operator+(const Point) const;
  Point operator-(const Point) const;

private:
  Fixed _x;
  Fixed _y;
};

std::ostream& operator<<(std::ostream& os, const Point& c);

#endif
