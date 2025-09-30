/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:34:26 by pbuet             #+#    #+#             */
/*   Updated: 2025/09/30 15:31:08 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& w): _weapon(w)
{
	this->name = name;
}

HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
}

