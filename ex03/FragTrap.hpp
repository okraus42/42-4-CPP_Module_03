/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 12:48:06 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const unsigned int	_hp_max = 100;
		static const unsigned int	_ep_max = 100;

	public:
		FragTrap(void);
		FragTrap(const FragTrap& fix);
		FragTrap &operator=(const FragTrap& f);
		~FragTrap(void);

		FragTrap(std::string name);

		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);

		void	showStats(void);
};

#endif