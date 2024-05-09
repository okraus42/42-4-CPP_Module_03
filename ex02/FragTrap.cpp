/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:30:55 by okraus            #+#    #+#             */
/*   Updated: 2024/05/09 12:38:11 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_name = "NoFrag";
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 30;
}

FragTrap::FragTrap(const FragTrap &st) : ClapTrap(st)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = st;
}

FragTrap&	FragTrap::operator=(const FragTrap &st)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->_name = st._name;
	this->_hp = st._hp;
	this->_ep = st._ep;
	this->_ad = st._ad;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "string FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = this->_hp_max;
	this->_ep = this->_ep_max;
	this->_ad = 30;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
	std::cout << "FragTrap "
	<< this->_name
	<< " took damage and now has "
	<< this->_hp << " hp"
	<< std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hp && this->_ep && amount)
	{
		--this->_ep;
		if (amount >= this->_hp_max - this->_hp)
			this->_hp = this->_hp_max;
		else
			this->_hp += amount;
		std::cout << "FragTrap "
		<< this->_name
		<< " heals itself and now has "
		<< this->_hp << " hp and "
		<< this->_ep << " ep"
		<< std::endl;
	}
	else
	{
		std::cout << "FragTrap "
		<< this->_name
		<< " does not have hit points or energy points to be repaired"
		<< std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap "
	<< this->_name
	<< " requests high five on the standard output."
	<< std::endl;
}

void	FragTrap::showStats(void)
{
	std::cout << "FragTrap ["
	<< this->_name << "] ["
	<< this->_hp << " HP] ["
	<< this->_ep << " EP] ["
	<< this->_ad << " AD]"
	<< std::endl;
}
