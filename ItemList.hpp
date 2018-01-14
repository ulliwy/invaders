/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemList.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:18:39 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 13:37:22 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Item.hpp"

struct ListNode {
	Item *item;
	ListNode *next;
	ListNode *prev;

	ListNode(Item *item);
};

class ItemList {
	ListNode *head;
	ListNode *tail;

public:
	struct iterator {
		ListNode *&head;
		ListNode *&tail;
		ListNode *ptr;
	public:
		iterator(ListNode *&head, ListNode *&tail, ListNode *ptr);
		iterator(ListNode *&head, ListNode *&tail);
		iterator(const iterator &arg);

		bool operator==(const iterator &it);
		bool operator!=(const iterator &it);

		iterator operator++(int);
		iterator &operator++();
		ListNode &operator*();
		ListNode *operator->();
	};

	ItemList();
	ItemList(ItemList const &rfs);
	~ItemList();

	void operator=(ItemList const &rfs);
	void push_back(Item *item);
	Item *erase(iterator &it);
	Item *eraseInc(iterator &it);
	Item *erase(Item *item);
	iterator begin();
	iterator end();
};