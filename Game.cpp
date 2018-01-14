/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:34 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 13:35:32 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <stdlib.h>
#include "Game.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Cell.hpp"
#include "Bullet.hpp"

static unsigned getTimeStamp() {
	struct timespec time; 
    clock_gettime(CLOCK_REALTIME, &time);
    return (1000000000 * time.tv_sec + time.tv_nsec) / 1000000;
}

bool collide(const Item &m1, const Item &m2) {
	int x1a = m1.getX();
	int x1b = x1a + m1.getWidth();

	int y1a = m1.getY();
	int y1b = y1a + m1.getHeight();

	int x2a = m2.getX();
	int x2b = x2a + m2.getWidth();

	int y2a = m2.getY();
	int y2b = y2a + m2.getHeight();

	return ((x1a < x2b && x1b > x2a) || (x1a > x2b && x1b < x2a)) &&
		   ((y1a < y2b && y1b > y2a) || (y1a > y2b && y1b < y2a));
}

Game::Game() {
}

Game::Game(int height, int width)
	: gameState(PLAY), score(0), needReset(false),
	  height(height), width(width),
	  player(height/2, 1) {

	unsigned time = getTimeStamp();
	enemyTimeStamp = time;
	bulletTimeStamp = time;

	srand(time_t());

	win = newwin(height, width, 0, 0);
}

Game::Game(Game &rfs) {
	(void)rfs;
}

Game::~Game() {
	delwin(win);
	for (ItemList::iterator i = enemies.begin(); i != enemies.end(); ++i) {
		delete i->item;
	}

	for (ItemList::iterator i = bullets.begin(); i != bullets.end(); ++i) {
		delete i->item;
	}
}

void Game::drawBox() const {
	wborder(this->win, ' ', ' ', '-', '-', '+', '+', '+', '+');
}

void Game::drawBox(int y1, int y2, int x, int width) const {
	mvwhline(win, y1, x, '-', width);
	mvwhline(win, y2, x, '-', width);
}

void	Game::setWin(WINDOW *win)
{
	this->win = win;
}

WINDOW	*Game::getWin()
{
	return (win);
}

Player&	Game::getPlayer()
{
	return (player);
}

bool Game::step() {
	unsigned cur = getTimeStamp();

	getmaxyx(win, height, width);

	bool changed = false;

	int dx = 0;
	int dy = 0;
	bool createBullet = false;

	int ch = getch();
	if (ch == '\033') { // if the first value is esc
		getch(); // skip the [
		switch(getch()) { // the real value
		    case 'A':
		        // code for arrow up
		    	dy = -1;
		        break;
		    case 'B':
		        // code for arrow down
		    	dy = +1;
		        break;
		    case 'C':
		        // code for arrow right
		    	dx = +1;
		        break;
		    case 'D':
		        // code for arrow left
		    	dx = -1;
		        break;
		}
	} else if (ch == ' ') {
		createBullet = true;
	} else if (ch == 'r' && gameState == GAMEOVER) {
		needReset = true;
	}

	if (gameState == GAMEOVER) {
		return false;
	}

	int px = player.getX();
	int py = player.getY();
	if (px + dx < 0 || px + dx + player.getWidth() > width)
		dx = 0;
	if (py + dy - 1 < 0 || py + dy + player.getHeight() + 1 > height)
		dy = 0; 
	if (dx || dy) {
		player.move(dy, dx);
		changed = true;
	}

	if (createBullet) {
		if (cur - bulletFireTimeStamp > 100) {
			bulletFireTimeStamp = cur;
			bullets.push_back(new Bullet(py, px + player.getWidth()));
		}
	}

	if (cur - bulletTimeStamp >= 10) {
		bulletTimeStamp = cur;

		for (ItemList::iterator i = bullets.begin(); i != bullets.end();) {
			Item &m = *i->item;
			changed = true;
			m.move(0, 1);	

			// Destroy disappeared bullets
			if (m.getX() > width) {
				delete bullets.eraseInc(i);
				continue;
			}

			++i;
		}
	}

	if (cur - enemyTimeStamp >= 100) {
		enemyTimeStamp = cur;

		for (ItemList::iterator i = enemies.begin(); i != enemies.end();) {
			Item &m = *i->item;

			changed = true;

			unsigned r = rand() % 100;
			int dy = (r % 2) ? -1 : 1;
			int newY = m.getY() + dy;

			if (r >= 50 && newY > 1 && newY < height - Enemy::HEIGHT - 1) {
				// Change lane
				m.move(dy, 0);
				
				//Check if there is a collision
				for (ItemList::iterator ie = enemies.begin(); ie != enemies.end(); ++ie) {
					if(ie != i && collide(m, *ie->item)) {
						// Move back and forward
						m.move(-dy, -1);
						break;
					}
				}
			}

			// Move forward
			m.move(0, -1);	

			// Destroy disappeared enemies
			if (m.getX() <= -Enemy::WIDTH) {
				delete enemies.eraseInc(i);
				continue;
			}

			++i;
		}
	}

	if (changed) {
		for (ItemList::iterator ie = enemies.begin(); ie != enemies.end();) {
			Item &enemy = *ie->item;

			if (collide(player, enemy)) {
				gameState = GAMEOVER;
				break;
			}

			bool foundCollision = false;
			for (ItemList::iterator ib = bullets.begin(); ib != bullets.end();) {
				if (collide(*ib->item, enemy)) {
					if (enemy.takeDamage()) {
						delete enemies.eraseInc(ie);
						foundCollision = true;
						score++;
					}

					delete bullets.erase(ib);
					
					beep();
					break;
				}
				++ib;
			}

			if (!foundCollision) {
				++ie;
			}
		}
	}

	if ((rand() % 1000) <= 10) {
		enemies.push_back(new Enemy(1 + rand() % (height - Enemy::HEIGHT - 1), width));
	}

	return changed;
}

void Game::draw() {
	int start = 1;
	werase(win);
	drawBox();

	player.draw(win);
	for (ItemList::iterator i = enemies.begin(); i != enemies.end(); ++i) {
		i->item->draw(win);
	}
	for (ItemList::iterator i = bullets.begin(); i != bullets.end(); ++i) {
		i->item->draw(win);
	}

	unsigned idx = start;
	mvwprintw(win, idx++, 1, "Score: %u", score);

	// logs for lists
	// for (ItemList::iterator i = enemies.begin(); i != enemies.end(); ++i, ++idx) {
	// 	mvwprintw(win, idx, 1, "enemyId: %u", i->item->getId());
	// }
	// for (ItemList::iterator i = bullets.begin(); i != bullets.end(); ++i, ++idx) {
	// 	mvwprintw(win, idx, 1, "bulletId: %u", i->item->getId());
	// }

	if (gameState == GAMEOVER) {
		mvwprintw(win, height / 2, width / 2 - 4, "GAME OVER");
		drawBox(height / 2 - 1, height / 2 + 1, width / 2 - 5, 11);
	}
	
	wrefresh(win);
}
