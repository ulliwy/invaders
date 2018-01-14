/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:54:27 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 13:43:57 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Item.hpp"

class	Enemy : public Item {
public:
	static const int WIDTH = 4; 
	static const int HEIGHT = 2;

private:
	Cell cells[HEIGHT][WIDTH];
	int lives;

public:
	Enemy();
	Enemy(int yy, int xx);
	Enemy(Enemy const &rfs);
	virtual ~Enemy();
	
	Enemy &operator=(Enemy const &rfs);
	virtual Cell *getCells();
	virtual int getWidth() const;
	virtual int getHeight() const;
	virtual bool takeDamage();
};

#endif