/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:27 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/13 23:18:20 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Item.hpp"

class	Enemy : public Item
{
public:
	static const int WIDTH = 4; 
	static const int HEIGHT = 2;

private:
	Cell cells[HEIGHT][WIDTH];

public:
	Enemy();
	virtual ~Enemy();
	Enemy(int yy, int xx);

	virtual Cell *getCells() {
		return &cells[0][0];
	}

	virtual int getWidth() const {
		return WIDTH;
	}

	virtual int getHeight() const {
		return HEIGHT;
	}
};

#endif