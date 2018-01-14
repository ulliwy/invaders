/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:40:43 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 22:36:53 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Board.hpp"

#include <iostream>

void	init_display(int *height, int *width)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	curs_set(FALSE);
	//cbreak();
	noecho();
	timeout(1);
	refresh();
	getmaxyx(stdscr, *height, *width);
}

int		main()
{
	int 	height;
	int 	width;

	init_display(&height, &width);

	Board board = Board(height, width);
	board.draw();

	while (1)
	{	
		if (board.step()) {
			board.draw();
		}
		//mvprintw(0, 0, "%d", i);
		//board.getPlayer().move(1, 1);
	}
	endwin();
}
