/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:40 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 00:23:44 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"

class	Player : public Item
{
	Cell cells[2][4];

public:
	Player();
	virtual ~Player();
	Player(int yy, int xx);

	virtual Cell *getCells() {
		return &cells[0][0];
	}

	virtual int getWidth() const {
		return 4;
	}

	virtual int getHeight() const {
		return 2;
	}
};

#endif
