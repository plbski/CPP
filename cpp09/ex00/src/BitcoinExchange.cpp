#include"../include/BitcoinExchange.hpp"

bool isValidDate(int y, int m, int d) {
	if (y < 109)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return false;
	return true;
}

time_t convert_date(std::string line)
{
	std::string date = line.substr(0, 10);
	std::tm test = {};
		test.tm_year = strtol(date.substr(0,4).c_str(), NULL, 10) - 1900;
		test.tm_mon = strtol(date.substr(5,2).c_str(), NULL, 10);
		test.tm_mday = strtol(date.substr(8,2).c_str(), NULL, 10);
	if ((date[4] != '-' && date[7] != '-' && !date [10]) ||
		!isValidDate(test.tm_year, test.tm_mon, test.tm_mday))
		throw(BitException("error date"));
	time_t time1 = std::mktime(&test);
	return (time1);
}

bool isfloat(std::string string)
{
	char *end = NULL;
	double val = strtof(string.c_str(), &end);
	(void)val;

	if (*end != '\0' || string.size() - string.rfind('.') < 2)
		return(false);
	return(true);
}

bool isInt(std::string string)
{
	char *end = NULL;
	long val = strtol(string.c_str(), &end, 10);

	if (val < 0 || val > 1000 || *end != '\0')
		return(false);
	return(true);
}


float DateValue(std::map<time_t, float>data, std::string line)
{
	time_t t = convert_date(line);
	time_t c;
	if (!t)
		return 0;
	std::map<time_t, float>::iterator it = data.lower_bound(t);
	if (it->first == t || it == data.begin())
		return(it->second);
	c = it->first;
	it --;
	if (c - t >= t - it->first)
		return(it->second);
	it ++;
	return(it->second);
}

void reader(std::map<time_t, float>data, char *av)
{
	std::string	line;
	float		value;
	float		nb;
	std::ifstream search_data(av);

	if (!search_data.is_open())
	{
		std::cout << "error open file"<< std::endl;
		return ;
	}
	while(std::getline(search_data, line))
	{
		if (line[11] != '|' || line.size() < 13)
			std::cout << "invalid format" << std::endl;
		else
		{
			try
			{
				value = DateValue(data, line);
				nb = strtod(line.substr(12).c_str(), NULL);
				if (nb < 0 && nb >= 1000)
					std::cout << "negative or to hight value" << std::endl;
				else
				{
					std::cout << line << " => " << nb * value << std::endl;
				}		
			}
			catch(const std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	search_data.close();
}
