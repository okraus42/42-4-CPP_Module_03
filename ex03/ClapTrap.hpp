/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 16:04:06 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
	private:
		static const unsigned int	_hp_max = 10;
		static const unsigned int	_ep_max = 10;
	
	protected:
		std::string					_name;
		unsigned int				_hp;
		unsigned int				_ep;
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