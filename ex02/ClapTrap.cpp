/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/08 13:27:43 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_name = "VoidTrap";
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ct;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &ct)
{
	std::cout << "Copy assignment ClapTrap operator called" << std::endl;
	this->_name = ct._name;
	this->_hp = ct._hp;
	this->_ep = ct._ep;
	this->_ad = ct._ad;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "string ClapTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hp && this->_ep)
	{
		--this->_ep;
		std::cout << "ClapTrap "
		<< this->_name << " attacks "
		<< target << " causing "
		<< this->_ad << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap "
		<< this->_name
		<< " does not have hit points or energy points to attack" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "ClapTrap "
	<< this->_name
	<< " took damage and now has "
	<< this->_hp << " hp"
	<< std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp && this->_ep && amount)
	{
		--this->_ep;
		if (amount >= this->_hp_max - this->_hp)
			this->_hp = this->_hp_max;
		else
			this->_hp += amount;
		std::cout << "ClapTrap "
		<< this->_name
		<< " heals itself and now has "
		<< this->_hp << " hp and "
		<< this->_ep << " ep"
		<< std::endl;
	}
	else
	{
		std::cout << "ClapTrap "
		<< this->_name
		<< " does not have hit points or energy points to be repaired"
		<< std::endl;
	}
}

void	ClapTrap::showStats(void)
{
	std::cout << "ClapTrap ["
	<< this->_name << "] ["
	<< this->_hp << " HP] ["
	<< this->_ep << " EP] ["
	<< this->_ad << " AD]" << std::endl;
}
