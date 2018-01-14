/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:25 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 13:44:32 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"
#include "Enemy.hpp"
#include "Item.hpp"
#include <stdlib.h>

Enemy::Enemy() {
}

Enemy::Enemy(int yy, int xx) : Item::Item(yy, xx), lives(1 + rand() % 3) {
	for (int ii = 0; ii < 2; ii++)
	{
		for (int jj = 0; jj < 4; jj++)
		{
			cells[ii][jj].value = '<';
			cells[ii][jj].attrib = COLOR_PAIR(lives + 1);
		}
	}
}

Enemy::Enemy(Enemy const &rfs) {
	*this = rfs;
}

Enemy &Enemy::operator=(Enemy const &rfs) {
	(void)rfs;
	return *this;
}

Enemy::~Enemy() {
}

Cell *Enemy::getCells() {
	return &cells[0][0];
}

int Enemy::getWidth() const {
	return WIDTH;
}

int Enemy::getHeight() const {
	return HEIGHT;
}

bool Enemy::takeDamage() {
	--lives;
	int attr = 1 + lives;
	for (int ii = 0; ii < 2; ii++) {
		for (int jj = 0; jj < 4; jj++) {
			cells[ii][jj].attrib = COLOR_PAIR(attr);
		}
	}

	return lives == 0;
}
