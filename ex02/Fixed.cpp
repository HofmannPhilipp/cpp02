/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:02:43 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/16 17:50:24 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream &operator<<(std::ostream &os, const Fixed &number)
{
	os << number.toFloat();
	return os;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed::Fixed() : rawBits(0) {}
Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}
Fixed::Fixed(const int rawBits)
{
	this->rawBits = (rawBits * (1 << this->bits));
}

Fixed::Fixed(const float rawBits)
{
	this->rawBits = (roundf(rawBits * (1 << this->bits)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->rawBits = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
	if (this->rawBits > other.rawBits)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->rawBits < other.rawBits)
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->rawBits <= other.rawBits)
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->rawBits >= other.rawBits)
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->rawBits == other.rawBits)
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->rawBits != other.rawBits)
		return true;
	return false;
}

Fixed Fixed::operator*(const Fixed &other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other)
{
	return (Fixed(this->toInt() + other.toInt()));
}

Fixed Fixed::operator-(const Fixed &other)
{
	return (Fixed(this->toInt() - other.toInt()));
}

Fixed Fixed::operator/(const Fixed &other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	this->rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{

	Fixed temp = *this;
	this->rawBits += 1;
	return temp;
}
Fixed &Fixed::operator--()
{
	this->rawBits -= 1;
	return *this;
}
Fixed Fixed::operator--(int)
{

	Fixed temp = *this;
	this->rawBits -= 1;
	return temp;
}

int Fixed::getRawBits(void) const
{
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

int Fixed::toInt(void) const
{
	int num = this->getRawBits();
	return num / (1 << this->bits);
}

float Fixed::toFloat(void) const
{
	int num = this->getRawBits();
	return ((float)(num) / (1 << this->bits));
}