/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:29:00 by pbuet             #+#    #+#             */
/*   Updated: 2025/08/20 14:29:14 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(int argc, char **argv)
{
	for (int i = 1 ; i < argc ; i ++)
	{
		for(int j = 0; argv[i][j] ; j ++)
			argv[i][j] = std::toupper(argv[i][j]);
		std::cout << argv[i];
	}

	return (0);
}