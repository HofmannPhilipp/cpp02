/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:19 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/17 12:48:06 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"


class Point
{
private:
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(float x, float y);
	Point(const Fixed &x, const Fixed &y);
	Point(const Point &other);
	Point &operator=(const Point &other) = delete;
	~Point();
	Point operator+(const Point &other);
	Point operator-(const Point &other);
	Fixed getX() const;
	Fixed getY() const;
};