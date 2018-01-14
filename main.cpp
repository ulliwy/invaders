/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:40:43 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 13:40:43 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Board.hpp"

#include <iostream>

void	init_display()
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	cbreak();
	noecho();
	refresh();
}

int		main()
{
	init_display();

	Board	board = Board(16, 16, 2, 5);

	while (1)
	{
		board.display();
		getch();
		board.getPlayer().move(1, 1);
	}
	endwin();
}
