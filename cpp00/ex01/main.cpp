/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:53:41 by pbuet             #+#    #+#             */
/*   Updated: 2025/09/20 16:29:56 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"


int main()
{
	PhoneBook Book;
	std::string command;
	while (true)
	{
		std::cin.clear();
		std::cout << "enter command (ADD, SEARCH or EXIT)" <<std::endl;
		std::getline(std::cin, command);
		if(command == "ADD")
			Book.AddContact();
		else if(command == "SEARCH")
		{
			Book.Search();
			Book.DisplayC();
		}
		else if(command == "EXIT")
			break;
		else
			std::cout<< BOLDRED <<"wrong command"<< RESET <<std::endl;
	}
	return(0);
}