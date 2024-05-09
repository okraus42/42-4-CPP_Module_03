/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 12:28:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	//this->_name = "NoScav";
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 20;
	this->_gate = false;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = st;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &st)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	this->_name = st._name;
	this->_hp = st._hp;
	this->_ep = st._ep;
	this->_ad = st._ad;
	this->_gate = st._gate;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "string ScavTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 20;
	this->_gate = false;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hp && this->_ep)
	{
		--this->_ep;
		std::cout << "ScavTrap "
		<< this->_name << " attacks "
		<< target << " causing "
		<< this->_ad << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ScavTrap "
		<< this->_name
		<< " does not have hit points or energy points to attack" << std::endl;
	}
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "ScavTrap "
	<< this->_name
	<< " took damage and now has "
	<< this->_hp << " hp"
	<< std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hp && this->_ep && amount)
	{
		--this->_ep;
		if (amount >= this->_hp_max - this->_hp)
			this->_hp = this->_hp_max;
		else
			this->_hp += amount;
		std::cout << "ScavTrap "
		<< this->_name
		<< " heals itself and now has "
		<< this->_hp << " hp and "
		<< this->_ep << " ep"
		<< std::endl;
	}
	else
	{
		std::cout << "ScavTrap "
		<< this->_name
		<< " does not have hit points or energy points to be repaired"
		<< std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->_gate)
	{
		std::cout << "ScavTrap "
		<< this->_name
		<< " is already in Gate keeper mode."
		<< std::endl;
	}
	else
	{
		this->_gate = true;
		std::cout << "ScavTrap "
		<< this->_name
		<< " started guarding the gate."
		<< std::endl;
	}
}

void	ScavTrap::showStats(void)
{
	std::cout << "ScavTrap ["
	<< this->_name << "] ["
	<< this->_hp << " HP] ["
	<< this->_ep << " EP] ["
	<< this->_ad << " AD] ["
	<< this->_gate << " guard state]"  << std::endl;
}
