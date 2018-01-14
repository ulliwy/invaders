/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:31 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 00:28:02 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Item.hpp"

unsigned Item::maxId = 0;

Item::~Item() {}
Item::Item(int y, int x) : id(maxId++), y(y), x(x) {}

void	Item::move(int dy, int dx)
{
	y += dy;
	x += dx;
}
