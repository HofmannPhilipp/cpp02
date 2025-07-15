/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:02:43 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/15 16:03:06 by phhofman         ###   ########.fr       */
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

Fixed::Fixed() : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int rawBits)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(rawBits * (1 << this->bits));
}
Fixed::Fixed(const float rawBits)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(rawBits * (1 << this->bits)));
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