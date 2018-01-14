/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:13 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 13:36:17 by iprokofy         ###   ########.fr       */
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
	Item(int yy, int xx);
	Item(Item const &rfs);
	void operator=(Item const &rfs);
	virtual ~Item();
	
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;

	void draw(WINDOW *win);
	void move(int dy, int dx);

	int getX() const;
	int getY() const;
	unsigned getId();

	virtual bool step(std::clock_t timeStamp);
	virtual bool takeDamage();
};

#endif
