/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:07:57 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/17 10:10:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void moreTests(void)
{
	Fixed a(2.5f);
	Fixed b(5.25f);

	std::cout << "\n--- Comparison Operators ---" << std::endl;
	std::cout << "a < b:  " << (a < b) << std::endl;
	std::cout << "a > b:  " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << "\n--- Arithmetic Operators ---" << std::endl;
	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "b / a: " << (b / a) << std::endl;

	std::cout << "\n--- Increment / Decrement ---" << std::endl;
	Fixed x(1.5f);
	std::cout << "x: " << x << std::endl;
	std::cout << "++x: " << ++x << std::endl; // prefix
	std::cout << "x++: " << x++ << std::endl; // postfix
	std::cout << "x: " << x << std::endl;
	std::cout << "--x: " << --x << std::endl;
	std::cout << "x--: " << x-- << std::endl;
	std::cout << "x: " << x << std::endl;

	std::cout << "\n--- min / max ---" << std::endl;
	Fixed &minRef = Fixed::min(a, b);
	Fixed &maxRef = Fixed::max(a, b);
	std::cout << "min(a, b): " << minRef << std::endl;
	std::cout << "max(a, b): " << maxRef << std::endl;

	const Fixed ca(10.5f);
	const Fixed cb(9.99f);
	std::cout << "min(const): " << Fixed::min(ca, cb) << std::endl;
	std::cout << "max(const): " << Fixed::max(ca, cb) << std::endl;
}

int main(void)
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	moreTests();
	return 0;
}