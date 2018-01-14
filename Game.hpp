/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:41 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 12:42:30 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <ctime>
#include "Player.hpp"
#include "Cell.hpp"
#include "ItemList.hpp"
#include <sys/time.h>

class Game {
	Game();
	Game(Game &rfs);
	void operator=(Game const &frs) {}
	void drawBox() const;
	void drawBox(int y1, int y2, int x, int width) const;
	void reset();
	
	enum GameState {
		PLAY,
		GAMEOVER,
	};

	GameState 	gameState;
	unsigned 	score;
	bool 	needReset;

	int		height;
	int		width;
	WINDOW	*win;
	Cell	**cells;
	
	Player	player;
	ItemList	enemies;
	ItemList	bullets;

	unsigned enemyTimeStamp;
	unsigned bulletTimeStamp;
	unsigned bulletFireTimeStamp;

public:
	~Game();
	Game(int height, int width);

	WINDOW			*getWin();
	void			setWin(WINDOW *win);
	void			draw();
	Player&			getPlayer();
	bool			getNeedReset() const {return this->needReset;}

	bool	step();
};

#endif
