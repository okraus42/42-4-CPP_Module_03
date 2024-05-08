/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 14:04:53 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string					_name;
		unsigned int				_hp;
		static const unsigned int	_hp_max = 100;
		unsigned int				_ep;
		static const unsigned int	_ep_max = 50;
		unsigned int				_ad;
		bool						_gate;

	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& fix);
		ScavTrap &operator=(const ScavTrap& f);
		~ScavTrap(void);

		ScavTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate(void);

		void	showStats(void);
};

#endif