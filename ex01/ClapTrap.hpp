/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 11:06:08 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		std::string					_name;
		unsigned int				_hp;
		static const unsigned int	_hp_max = 10;
		unsigned int				_ep;
		static const unsigned int	_ep_max = 10;
		unsigned int				_ad;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& fix);
		ClapTrap &operator=(const ClapTrap& f);
		~ClapTrap(void);

		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	showStats(void);
};

#endif