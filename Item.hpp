/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Item.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:54:13 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 14:54:13 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_HPP
#define ITEM_HPP

#include "ncurses.h"

#include "Cell.hpp"

class	Item
{
	int		yy;
	int		xx;
protected:
	WINDOW	*win;
	Cell	cells[2][4];
public:
	Item();
	~Item();
	Item(int yy, int xx);

	void	display();
	void	move(int dy, int dx);
};

#endif
