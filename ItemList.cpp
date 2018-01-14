/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:18:35 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 12:51:12 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ItemList.hpp"

ListNode::ListNode(Item *item) : item(item), next(NULL), prev(NULL) {
}

ItemList::iterator::iterator(ListNode *&head, ListNode *&tail,
	ListNode *ptr) : head(head), tail(tail), ptr(ptr) {
}
		
ItemList::iterator::iterator(ListNode *&head,
	ListNode *&tail) : head(head), tail(tail), ptr(NULL) {
}

ItemList::iterator::iterator(const iterator &arg) : head(arg.head), tail(arg.tail),
	ptr(arg.ptr) {
}

bool ItemList::iterator::operator==(const iterator &it) {
	return ptr == it.ptr;
}

bool ItemList::iterator::operator!=(const iterator &it) {
	return !(*this == it);
}

ItemList::iterator ItemList::iterator::operator++(int) { // a++
	iterator it(*this);
	ptr = ptr->next;
	return it;
}

ItemList::iterator &ItemList::iterator::operator++() {
	ptr = ptr->next;
	return *this;
}

ListNode &ItemList::iterator::operator*() {
	return *ptr;
}

ListNode *ItemList::iterator::operator->() {
	return ptr;
}

ItemList::ItemList() : head(NULL), tail(NULL) {
}

ItemList::ItemList(ItemList const &rfs) {
	*this = rfs;
}

ItemList::~ItemList() {
	while(head) {
		ListNode *tmp = head->next;
		delete head;
		head = tmp;
	}
}

void ItemList::operator=(ItemList const &rfs) {
}

void ItemList::push_back(Item *item) {
	ListNode **ptr = tail ? &tail->next : &head;
	*ptr = new ListNode(item);
	(*ptr)->prev = tail;
	tail = *ptr;
}

Item *ItemList::erase(iterator &it) {
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

Item *ItemList::eraseInc(iterator &it) {
	Item *erasedItem = it->item;
	iterator ii = it++;
	erase(ii);
	return erasedItem;
}

Item *ItemList::erase(Item *item) {
	for (iterator it = begin(), e = end(); it != e; ++it) {
		if (it->item == item) {
			erase(it);
		}
	}

	return item;
}

ItemList::iterator ItemList::begin() {
	return iterator(head, tail, head);
}

ItemList::iterator ItemList::end() {
	return iterator(head, tail);
}
