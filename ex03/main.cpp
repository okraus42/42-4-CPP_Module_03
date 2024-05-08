/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 17:58:15 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

//https://www.makeuseof.com/what-is-diamond-problem-in-cpp/
//https://www.geeksforgeeks.org/multiple-inheritance-in-c/

int main(void)
{
	DiamondTrap c;
	DiamondTrap b("WeirdD");
	DiamondTrap a(b);
	DiamondTrap d;

	c.showStats();
	b.showStats();
	a.showStats();
	a.takeDamage(7);
	a.showStats();
	d = a;
	d.showStats();
	d.beRepaired(2);
	d.showStats();
	d.beRepaired(20);
	d.showStats();
	d.showStats();
	d.attack("enemy");
	d.showStats();
	for (int i = 0; i < 38;  ++i)
	{
		d.attack("enemy");
		d.takeDamage(25);
		d.beRepaired(20);
		d.beRepaired(20);
		d.showStats();
	}
	d.showStats();
	d.whoAmI();
	return (0);
}