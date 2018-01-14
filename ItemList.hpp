/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:18:39 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 10:27:54 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Item.hpp"

struct list_node_t {
	Item *item;
	list_node_t *next;
	list_node_t *prev;

	list_node_t(Item *item);
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
				 list_node_t *ptr);
		
		iterator(list_node_t *&head,
				 list_node_t *&tail);

		iterator(const iterator &arg);

		bool operator==(const iterator &it);

		bool operator!=(const iterator &it);

		iterator operator++(int);

		iterator &operator++();

		list_node_t &operator*();

		list_node_t *operator->();
	};

	list_t();
	~list_t();

	void push_back(Item *item);

	Item *erase(iterator &it);

	Item *eraseInc(iterator &it);

	Item *erase(Item *item);

	iterator begin();

	iterator end();
};