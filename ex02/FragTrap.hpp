/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 14:59:05 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		std::string					_name;
		unsigned int				_hp;
		static const unsigned int	_hp_max = 100;
		unsigned int				_ep;
		static const unsigned int	_ep_max = 100;
		unsigned int				_ad;

	public:
		FragTrap(void);
		FragTrap(const FragTrap& fix);
		FragTrap &operator=(const FragTrap& f);
		~FragTrap(void);

		FragTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	highFivesGuys(void);

		void	showStats(void);
};

#endif