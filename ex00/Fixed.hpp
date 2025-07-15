/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:47:33 by phhofman          #+#    #+#             */
/*   Updated: 2025/07/15 13:07:40 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
private:
	int rawBits;
	static const int bits = 8;

public:
	Fixed();
	Fixed(Fixed &other);
	Fixed &operator=(Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};