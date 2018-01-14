/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 22:59:31 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/13 23:26:36 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Bullet.hpp"
#include "Item.hpp"

Bullet::~Bullet() {}

Bullet::Bullet(int yy, int xx) : Item::Item(yy, xx) {
	cells[0][0].value = '_';
	cells[0][0].attrib = COLOR_PAIR(1);
}