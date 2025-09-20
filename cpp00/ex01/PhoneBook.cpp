#include"PhoneBook.hpp"

PhoneBook::PhoneBook(){index = 0;};

PhoneBook::~PhoneBook(){};

void	PhoneBook::AddContact()
{
	int	pos = this->index % 8;
	Contact new_contact;

	new_contact.iniContact();
	book[pos] = new_contact;
	if (this->index > 7)
		std::cout <<"contact: "<< pos << " have been replace with sucess" << std::endl;
	else
		std::cout<<"contact: " << pos << " initialisation finished" << std::endl;
	this->index ++;
}

std::string troc(std::string name)
{
	std::string replace;
	replace = name.substr(0,10);
	if (name.size() > 11)
		replace[9] = '.';
	return(replace);
}
void	PhoneBook::DisplayC()
{
	int	index = -1;

	if (this->index == 0)
	{
		std::cout << " no contact found" << std::endl;
		return;
	}
	while (index < 0 || index > std::min(7, this->index - 1))
	{	
		std::cout << "enter an Index between 0 - " << std::min(7, this->index - 1) << " :";
		std::cin >> index;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			index = -1;
		}
	}
	std::cout << "first name : "<< book[index].getfname() << std::endl
			<< "last name : "<< book[index].getlname() << std::endl
			<< "Nickname : "<< book[index].getnickname() << std::endl
			<< "phone number : "<< book[index].getphonenumber() << std::endl
			<< "secret : "<< book[index].getsecret() << std::endl;
	std::cin.clear();
	std::cin.ignore(1000, '\n');
}
void	PhoneBook::Search()
{
	std::cout << "|"
			<< std::right << std::setw(10) << "Index" << '|'
			<< std::right << std::setw(10) << "First name" << '|'
			<< std::right << std::setw(10) << "Last name" << '|'
			<< std::right << std::setw(10) << "Nickname" << '|'
			<<std::endl;
	for(int pos = 0; pos < 8 && pos < this->index; pos ++)
	{
		std::cout << "|"
			<< std::right << std::setw(10) << pos << '|'
			<< std::right << std::setw(10) << troc(book[pos].getfname()) << '|'
			<< std::right << std::setw(10) << troc(book[pos].getlname()) << '|'
			<< std::right << std::setw(10) << troc(book[pos].getnickname()) << '|'
			<<std::endl;
	}
	std::cout << std::endl;
}
