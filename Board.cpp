/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:34 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 16:29:25 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Board.hpp"
#include "Player.hpp"
#include "Cell.hpp"

Board::Board(int height, int width, int yy, int xx) :
	height(height), width(width), yy(yy), xx(xx), player(yy, xx)
{
	win = newwin(height, width, yy, xx);
	Board::allocCells();
	Board::initCells('O', COLOR_PAIR(1));
}

Board::~Board()
{
	Board::delCells();
	delwin(win);
}

void	Board::delCells()
{
	for (int ii = 0; ii < height; ii++)
		delete[] cells[ii];
	delete[] cells;
}

void	Board::allocCells()
{
	cells = new Cell*[height];
	for (int ii = 0; ii < height; ii++)
		cells[ii] = new Cell[width];
}

void	Board::initCells(char value, int attrib)
{
	for (int yy = 0; yy < height; yy++)
	{
		for (int xx = 0; xx < width; xx++)
		{
			cells[yy][xx].value = value;
			cells[yy][xx].attrib = attrib;
		}
	}
}

void	Board::display()
{
	werase(win);
	for (int yy = 0; yy < height; yy++)
	{
		for (int xx = 0; xx < width; xx++)
		{
			wattron(win, cells[yy][xx].attrib);
			wprintw(win, "%c", cells[yy][xx].value);
			wattroff(win, cells[yy][xx].attrib);
		}
	}
	wrefresh(win);
	player.display();
}

void	Board::setWin(WINDOW *win)
{
	this->win = win;
}

WINDOW	*Board::getWin()
{
	return (win);
}

void	Board::setCells(Cell **cells)
{
	for (int ii = 0; ii < height; ii++)
		delete[] cells[ii];
	delete[] cells;
	this->cells = cells;
}

Cell	**Board::getCells()
{
	return (cells);
}

Player&	Board::getPlayer()
{
	return (player);
}

void	Board::setPlayer(Player const& player)
{
	this->player = player;
}
