/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:35:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/17 12:28:35 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(1), y(1) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point Point::operator+(const Point &other)
{
	Point result(this->x + other.x, this->y + other.y);
	return result;
}
Point Point::operator-(const Point &other)
{
	Point result(this->x - other.x, this->y - other.y);
	return result;
}

Fixed Point::getX() const
{
	return this->x;
}
Fixed Point::getY() const
{
	return this->y;
}