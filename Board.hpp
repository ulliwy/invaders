/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:41 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 12:13:41 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "ncurses.h"

#include "Player.hpp"
#include "Cell.hpp"

class	Board
{
	int				height;
	int				width;
	int				yy;
	int				xx;
	WINDOW			*win;
	Cell			**cells;
	//Displayable		*items;
	Player			player;
public:
	Board();
	~Board();
	Board(int height, int width, int yy, int xx);

	WINDOW			*getWin();
	void			setWin(WINDOW *win);
	Cell			**getCells();
	void			setCells(Cell **cells);
	void			display();
	void			initCells(char value, int attrib);
	void			allocCells();
	void			delCells();
	Player&			getPlayer();
	void			setPlayer(Player const&);
	//void			update_player();
	//void			update_items();
};

#endif
