/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:52:35 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 11:16:58 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c;
	ClapTrap b("Bob");
	ClapTrap a(b);
	ClapTrap d;

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
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.showStats();
	d.attack("enemy");
	d.takeDamage(7);
	d.showStats();
	d.beRepaired(2);
	d.showStats();
	d.takeDamage(7);
	d.showStats();
	d.attack("enemy");
	d.showStats();
	
	return (0);
}