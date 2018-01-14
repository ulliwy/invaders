/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:02:40 by olkovale          #+#    #+#             */
/*   Updated: 2018/01/13 15:02:40 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"

class	Player : public Item
{
public:
	Player();
	~Player();
	Player(int yy, int xx);

	void	display();
};

#endif
