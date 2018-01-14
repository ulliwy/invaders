/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:25 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/13 22:45:43 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Enemy.hpp"
#include "Item.hpp"

Enemy::~Enemy() {}
Enemy::Enemy(int yy, int xx) : Item::Item(yy, xx) {
	for (int ii = 0; ii < 2; ii++)
	{
		for (int jj = 0; jj < 4; jj++)
		{
			cells[ii][jj].value = '<';
			cells[ii][jj].attrib = COLOR_PAIR(2);
		}
	}
}