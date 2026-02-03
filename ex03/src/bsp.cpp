/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:16:55 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/03 22:55:01 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Fixed abxap = Point(b - a).cross(Point(point - a));
  Fixed bcxbp = Point(c - b).cross(Point(point - b));
  Fixed caxcp = Point(a - c).cross(Point(point - c));

  if (abxap > 0 && bcxbp > 0 && caxcp > 0)
    return true;
  if (abxap < 0 && bcxbp < 0 && caxcp < 0)
    return true;
  return false;
}
