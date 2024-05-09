/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 12:29:38 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_name = "NoDiamond";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp_max;
	this->_ep = ScavTrap::_ep_max;
	this->_ad = ScavTrap::_ad;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ClapTrap(dt), ScavTrap(dt), FragTrap(dt)
{
	std::cout << "Copy DiamondTrap constructor called" << std::endl;
	*this = dt;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &dt)
{
	std::cout << "Diamondtrap Copy assignment operator called" << std::endl;
	this->_name = dt._name;
	ClapTrap::_name = dt.ClapTrap::_name;
	this->_hp = dt._hp;
	this->_ep = dt._ep;
	this->_ad = dt._ad;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
	std::cout << "string DiamondTrap constructor called" << std::endl;
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_hp_max;
	this->_ep = ScavTrap::_ep_max;
	this->_ad = ScavTrap::_ad;
}

// void	DiamondTrap::attack(const std::string& target)
// {
// 	if (this->_hp && this->_ep)
// 	{
// 		--this->_ep;
// 		std::cout << "DiamondTrap "
// 		<< this->_name << " attacks "
// 		<< target << " causing "
// 		<< this->_ad << " points of damage!" << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << "DiamondTrap "
// 		<< this->_name
// 		<< " does not have hit points or energy points to attack" << std::endl;
// 	}
// }

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "DiamondTrap "
	<< this->_name
	<< " took damage and now has "
	<< this->_hp << " hp"
	<< std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hp && this->_ep && amount)
	{
		--this->_ep;
		if (amount >= this->_hp_max - this->_hp)
			this->_hp = this->_hp_max;
		else
			this->_hp += amount;
		std::cout << "DiamondTrap "
		<< this->_name
		<< " heals itself and now has "
		<< this->_hp << " hp and "
		<< this->_ep << " ep"
		<< std::endl;
	}
	else
	{
		std::cout << "DiamondTrap "
		<< this->_name
		<< " does not have hit points or energy points to be repaired"
		<< std::endl;
	}
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap "
	<< this->_name
	<< " or "
	<< this->ClapTrap::_name
	<< std::endl;
}

void	DiamondTrap::showStats(void)
{
	std::cout << "DiamondTrap ["
	<< this->_name << "] ["
	<< this->ClapTrap::_name << "] ["
	<< this->_hp << " HP] ["
	<< this->_ep << " EP] ["
	<< this->_ad << " AD]"
	<< std::endl;
}
