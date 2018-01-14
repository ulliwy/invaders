/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:04:18 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 13:37:05 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"
#include "Player.hpp"
#include "Item.hpp"

Player::Player() {
}

Player::Player(int yy, int xx) : Item::Item(yy, xx) {
	for (int ii = 0; ii < 2; ii++)
	{
		for (int jj = 0; jj < 4; jj++)
		{
			cells[ii][jj].value = '|';
			cells[ii][jj].attrib = COLOR_PAIR(1);
		}
	}
}

Player::Player(Player const &rfs) {
	*this = rfs;
}

Player &Player::operator=(Player const &rfs) {
	(void)rfs;
	return *this;
}

Player::~Player() {
}

Cell *Player::getCells() {
	return &cells[0][0];
}

int Player::getWidth() const {
	return 4;
}

int Player::getHeight() const {
	return 2;
}
