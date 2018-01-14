/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ulliwy <Ulliwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 22:59:29 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/13 23:25:51 by Ulliwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include "Item.hpp"

class	Bullet : public Item
{
	Cell cells[1][1];

public:
	Bullet();
	virtual ~Bullet();
	Bullet(int yy, int xx);

	virtual Cell *getCells() {
		return &cells[0][0];
	}

	virtual int getWidth() const {
		return 1;
	}

	virtual int getHeight() const {
		return 1;
	}
};

#endif