#include"Contact.hpp"

Contact::Contact() {};

Contact::~Contact() {};

void Contact::iniContact()
{
	while (this->fname.empty())
	{
		std::cout << "enter first name: ";
		std::getline(std::cin, this->fname);
	}
	while (this->lname.empty())
	{
		std::cout << "enter last name: ";
		std::getline(std::cin, this->lname);
	}
	while (this->nickname.empty())
	{
		std::cout << "enter nickname: ";
	
		std::getline(std::cin, this->nickname);
	}
	while(this->phonenumber.empty())
	{
		std::cout << "enter number: ";
		std::getline(std::cin, this->phonenumber);
	}
	while (this->secret.empty())
	{
		std::cout << "enter secret: ";
		std::getline(std::cin, this->secret);
	}
}


std::string Contact::getfname() {return(this->fname);}
std::string Contact::getlname() {return(this->lname);}
std::string Contact::getnickname() {return(this->nickname);}
std::string Contact::getphonenumber() {return(this->phonenumber);}
std::string Contact::getsecret() {return(this->secret);}
