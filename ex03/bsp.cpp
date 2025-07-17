/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:21:00 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/17 12:51:56 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float triangleArea(const Point &a, const Point &b, const Point &c)
{
	float result;

	result = (a.getX() * (b.getY() - c.getY()) +
			  b.getX() * (c.getY() - a.getY()) +
			  c.getX() * (a.getY() - b.getY()))
				 .toFloat() /
			 2.0f;
	if (result < 0)
		return -result;
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float fullArea = triangleArea(a, b, c);
	float area1 = triangleArea(point, b, c);
	float area2 = triangleArea(a, point, c);
	float area3 = triangleArea(a, b, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;

	if (fullArea == area1 + area2 + area3)
		return true;
	return false;
}