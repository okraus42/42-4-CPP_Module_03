/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 14:38:47 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap c;
	ScavTrap b("Serena");
	ScavTrap a(b);
	ScavTrap d;

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
	d.guardGate();
	d.guardGate();
	for (int i = 0; i < 25;  ++i)
	{
		d.attack("enemy");
		d.takeDamage(25);
		d.beRepaired(20);
		d.beRepaired(20);
		d.showStats();
	}
	d.showStats();
	return (0);
}