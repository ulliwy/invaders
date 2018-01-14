/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 12:13:41 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 02:14:24 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_HPP
#define BOARD_HPP

#include <ncurses.h>
#include <ctime>

#include "Player.hpp"
#include "Cell.hpp"
#include <sys/time.h>

struct list_node_t {
	Item *item;
	list_node_t *next;
	list_node_t *prev;

	list_node_t(Item *item) : item(item), next(NULL), prev(NULL) {}
};

class list_t {
	list_node_t *head;
	list_node_t *tail;

public:
	class iterator {
		list_node_t *&head;
		list_node_t *&tail;
		list_node_t *ptr;
	public:
		iterator(list_node_t *&head,
				 list_node_t *&tail,
				 list_node_t *ptr) : head(head), tail(tail), ptr(ptr) {}
		
		iterator(list_node_t *&head,
				 list_node_t *&tail) : head(head), tail(tail), ptr(NULL) {}

		iterator(const iterator &arg) : head(arg.head), tail(arg.tail), ptr(arg.ptr) {}

		bool operator==(const iterator &it) {
			return ptr == it.ptr;
		}

		bool operator!=(const iterator &it) {
			return !(*this == it);
		}

		iterator operator++(int) { // a++
			iterator it(*this);
			ptr = ptr->next;
			return it;
		}

		iterator &operator++() {
			ptr = ptr->next;
			return *this;
		}

		list_node_t &operator*() {
			return *ptr;
		}

		list_node_t *operator->() {
			return ptr;
		}
	};

	list_t() : head(NULL), tail(NULL) {}

	~list_t() {
		while(head) {
			list_node_t *tmp = head->next;
			delete head;
			head = tmp;
		}
	}

	void push_back(Item *item) {
		list_node_t **ptr = tail ? &tail->next : &head;
		*ptr = new list_node_t(item);
		(*ptr)->prev = tail;
		tail = *ptr;
	}

	Item *erase(iterator &it) {
		// Update head
		if (head == &*it) {
			head = it->next;
		}

		// Update tail
		if (tail == &*it) {
			tail = it->prev;
		}

		// Update next link
		if (it->prev) {
			// If not the first element;
			it->prev->next = it->next;
		}

		// Update prev link
		if (it->next) {
			// If not the last element;
			it->next->prev = it->prev;
		}

		Item *tmp = it->item;

		delete &*it;

		return tmp;
	}

	Item *eraseInc(iterator &it) {
		Item *erasedItem = it->item;
		iterator ii = it++;
		erase(ii);
		return erasedItem;
	}

	Item *erase(Item *item) {
		for (iterator it = begin(), e = end(); it != e; ++it) {
			if (it->item == item) {
				erase(it);
			}
		}

		return item;
	}

	iterator begin() {
		return iterator(head, tail, head);
	}

	iterator end() {
		return iterator(head, tail);
	}
};

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

public:

	Board();
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
