/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:25 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 10:54:59 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Enemy.hpp"
#include "Item.hpp"

#include <stdlib.h>

Enemy::~Enemy() {}
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
