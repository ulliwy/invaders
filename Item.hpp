/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:13 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 10:50:47 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <ncurses.h>
#include <ctime>

#include "Cell.hpp"

class	Item {
private:

	static unsigned maxId;

	unsigned id;
	int		y;
	int		x;

protected:

	virtual Cell *getCells() = 0;

public:

	Item();
	virtual ~Item();
	Item(int yy, int xx);

	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	void draw(WINDOW *win) {
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

	void	move(int dy, int dx);

	int getX() const {
		return x;
	}

	int getY() const {
		return y;
	}

	unsigned getId() {
		return id;
	}

	virtual bool step(std::clock_t timeStamp) { return false; };

	virtual bool takeDamage() { return true; };
};

#endif
