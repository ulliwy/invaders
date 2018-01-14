/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:31 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 13:36:03 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"
#include "Item.hpp"

unsigned Item::maxId = 0;

Item::Item() {
}

Item::Item(int y, int x) : id(maxId++), y(y), x(x) {
}

Item::Item(Item const &rfs) {
	*this = rfs;
}

Item::~Item() {
}

void Item::operator=(Item const &rfs) {
	maxId = rfs.maxId;
	id = rfs.maxId;
	y = rfs.y;
	x = rfs.x;
}

void Item::move(int dy, int dx)
{
	y += dy;
	x += dx;
}

void Item::draw(WINDOW *win) {
	Cell *cells = getCells();
	int height = getHeight();
	int width = getWidth();

	for (int yy = 0; yy < height; yy++) {
		for (int xx = 0; xx < width; xx++) {
			Cell &cell = cells[yy + xx * height];

			wattron(win, cell.attrib);
			mvwprintw(win, y + yy, x + xx, "%c", cell.value);
			wattroff(win, cell.attrib);
		}
	}
}

int Item::getX() const {
	return x;
}

int Item::getY() const {
	return y;
}

unsigned Item::getId() {
	return id;
}

bool Item::step(std::clock_t timeStamp) {
	(void)timeStamp;
	return false;
};

bool Item::takeDamage() {
	return true;
}
