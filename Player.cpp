/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:04:18 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 21:54:17 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"

#include "Player.hpp"
#include "Item.hpp"

Player::~Player() {}
Player::Player(int yy, int xx) : Item::Item(yy, xx) {
	for (int ii = 0; ii < 2; ii++)
	{
		for (int jj = 0; jj < 4; jj++)
		{
			cells[ii][jj].value = '|';
			cells[ii][jj].attrib = COLOR_PAIR(1);
		}
	}
}

// void	Player::display()
// {
// 	werase(win);
// 	for (int yy = 0; yy < 2; yy++)
// 	{
// 		for (int xx = 0; xx < 4; xx++)
// 		{
// 			wattron(win, cells[yy][xx].attrib);
// 			wprintw(win, "%c", cells[yy][xx].value);
// 			wattroff(win, cells[yy][xx].attrib);
// 		}
// 	}
// 	wrefresh(win);
// }
