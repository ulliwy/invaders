/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:31 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 14:54:31 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Item.hpp"

Item::Item() {}
Item::~Item() {}
Item::Item(int yy, int xx) : yy(yy), xx(xx), cells()
{
	win = newwin(2, 4, yy, xx);
}

void	Item::move(int dy, int dx)
{
	yy += dy;
	xx += dx;
	mvwin(win, yy, xx);
}
