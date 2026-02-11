
#include"../include/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::ifstream file("data.csv");
	if (ac != 2)
	{
		std::cout << "enter a file " << std::endl;
		return(1);
	}
	if (!file.is_open())
	{
		std::cout << "error open file"<< std::endl;
		return(1);
	}
	std::string line;
	std::map<time_t, float> data;
	std::getline(file, line);
	time_t t;
	while( std::getline(file, line))
	{
		try
		{
			t = convert_date(line);
		}
		catch(const std::exception & e){};
		
		data[t] = std::strtof(line.substr(11).c_str(), NULL);
	}
	file.close();
	reader(data, av[1]);
	return(0);
}
