/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 22:16:55 by takawauc          #+#    #+#             */
/*   Updated: 2025/12/16 22:37:28 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
  Point ab(a - b);
  Point bc(b - c);
  Point ca(c - a);
  Point ap(a - point);
  Point bp(b - point);
  Point cp(c - point);

  if (ab.cross(ap) > 0 && bc.cross(bp) > 0 && ca.cross(cp) > 0)
    return true;
  if (ab.cross(ap) < 0 && bc.cross(bp) < 0 && ca.cross(cp) < 0)
    return true;
  return false;
}
