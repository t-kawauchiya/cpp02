/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:43:33 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 22:47:17 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(float x, float y)
{
  this->setX(Fixed(x));
  this->setY(Fixed(y));
}

Point::Point(const Point& other)
{
  *this = other;
}

Point& Point::operator=(const Point& other)
{
  if (this != &other)
  {
    this->_x = other.getX();
    this->_y = other.getY();
  }
  return *this;
}

Point::~Point(void) {}

Fixed Point::getX(void) const
{
  return this->_x;
}

Fixed Point::getY(void) const
{
  return this->_y;
}

void Point::setX(const Fixed x)
{
  this->_x = x;
}

void Point::setX(const float x)
{
  this->_x = Fixed(x);
}

void Point::setY(const Fixed y)
{
  this->_y = y;
}

void Point::setY(const float y)
{
  this->_y = Fixed(y);
}

Point Point::operator+(const Point p) const
{
  Point ret;

  ret.setX(this->getX() + p.getX());
  ret.setY(this->getY() + p.getY());
  return ret;
}

Point Point::operator-(const Point p) const
{
  Point ret;

  ret.setX(this->getX() - p.getX());
  ret.setY(this->getY() - p.getY());
  return ret;
}

Fixed Point::cross(const Point p)
{
  return this->getX() * p.getY() - this->getY() * p.getX();
}

std::ostream& operator<<(std::ostream& os, const Point& c)
{
  os << "{x,y} : " << "{" << c.getX() << "," << c.getY() << "}" << std::endl;
  return os;
}
