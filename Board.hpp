/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:41 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 10:31:57 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <ncurses.h>
#include <ctime>

#include "Player.hpp"
#include "Cell.hpp"
#include "ItemList.hpp"
#include <sys/time.h>

class Board {
	enum GameState {
		PLAY,
		GAMEOVER,
	};

	GameState gameState;
	unsigned score;
	bool needReset;

	int		height;
	int		width;
	WINDOW	*win;
	Cell	**cells;
	
	Player	player;
	list_t	enemies;
	list_t	bullets;

	unsigned enemyTimeStamp;
	unsigned bulletTimeStamp;
	unsigned bulletFireTimeStamp;

	void drawBox() const;
	void drawBox(int y1, int y2, int x, int width) const;
	void reset();
	Board() {}
	Board(Board &rfs) {};
	void operator=(Board const &frs) {}

public:
	~Board();
	Board(int height, int width);

	WINDOW			*getWin();
	void			setWin(WINDOW *win);
	void			draw();
	Player&			getPlayer();
	bool			getNeedReset() const {return this->needReset;}

	bool	step();
};

#endif
