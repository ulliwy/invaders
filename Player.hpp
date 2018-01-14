/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:40 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/14 12:39:10 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"

class	Player : public Item {
private:
	Cell cells[2][4];

public:
	Player();
	Player(int yy, int xx);
	Player(Player const &rfs);
	virtual ~Player();

	Player &operator=(Player const &rfs);
	virtual Cell *getCells();
	virtual int getWidth() const;
	virtual int getHeight() const;
};

#endif
