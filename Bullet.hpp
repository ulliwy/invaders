/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iprokofy <iprokofy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 22:59:29 by Ulliwy            #+#    #+#             */
/*   Updated: 2018/01/14 12:10:08 by iprokofy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include "Item.hpp"

class	Bullet : public Item {
private:
	Cell cells[1][1];

public:
	Bullet();
	Bullet(int yy, int xx);
	Bullet(Bullet const &frs);
	virtual ~Bullet();
	

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