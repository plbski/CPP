/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:04:42 by pbuet             #+#    #+#             */
/*   Updated: 2025/09/30 14:08:46 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type){this->type = type;}

Weapon::~Weapon(){}

std::string Weapon::getType(){return(this->type);}

void Weapon::setType(std::string type){this->type = type;}