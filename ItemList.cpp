/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ItemList.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:18:35 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 10:30:02 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ItemList.hpp"

list_node_t::list_node_t(Item *item) : item(item), next(NULL), prev(NULL) {}

list_t::iterator::iterator(list_node_t *&head,
				 list_node_t *&tail,
				 list_node_t *ptr) : head(head), tail(tail), ptr(ptr) {}
		
list_t::iterator::iterator(list_node_t *&head,
		 list_node_t *&tail) : head(head), tail(tail), ptr(NULL) {}

list_t::iterator::iterator(const iterator &arg) : head(arg.head), tail(arg.tail), ptr(arg.ptr) {}

bool list_t::iterator::operator==(const iterator &it) {
	return ptr == it.ptr;
}

bool list_t::iterator::operator!=(const iterator &it) {
	return !(*this == it);
}

list_t::iterator list_t::iterator::operator++(int) { // a++
	iterator it(*this);
	ptr = ptr->next;
	return it;
}

list_t::iterator &list_t::iterator::operator++() {
	ptr = ptr->next;
	return *this;
}

list_node_t &list_t::iterator::operator*() {
	return *ptr;
}

list_node_t *list_t::iterator::operator->() {
	return ptr;
}

list_t::list_t() : head(NULL), tail(NULL) {}

list_t::~list_t() {
	while(head) {
		list_node_t *tmp = head->next;
		delete head;
		head = tmp;
	}
}

void list_t::push_back(Item *item) {
	list_node_t **ptr = tail ? &tail->next : &head;
	*ptr = new list_node_t(item);
	(*ptr)->prev = tail;
	tail = *ptr;
}

Item *list_t::erase(iterator &it) {
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

Item *list_t::eraseInc(iterator &it) {
	Item *erasedItem = it->item;
	iterator ii = it++;
	erase(ii);
	return erasedItem;
}

Item *list_t::erase(Item *item) {
	for (iterator it = begin(), e = end(); it != e; ++it) {
		if (it->item == item) {
			erase(it);
		}
	}

	return item;
}

list_t::iterator list_t::begin() {
	return iterator(head, tail, head);
}

list_t::iterator list_t::end() {
	return iterator(head, tail);
}
