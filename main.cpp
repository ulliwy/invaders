/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:40:43 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 10:57:18 by Ulliwy           ###   ########.fr       */
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
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
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

	while (1) {
		init_display(&height, &width);
		Board board(height, width);
		board.draw();

		while (!board.getNeedReset())
		{	
			if (board.step()) {
				board.draw();
			}
		}
	}
	endwin();
}
