#include<iostream>
#include<string>
#include <fstream>

std::string ft_replace(std::string s1, std::string s2, std::string text)
{
	int lenText = text.length();
	int lenS1 = s1.length();
	int i = 0;

	i = text.find(s1, i);
	while (i < lenText && i > 0)
	{
		text.erase(i, lenS1);
		text.insert(i, s2);
		i = text.find(s1, i);
	}
	return (text);
}
int main(int argc, char **argv)
{
	if (argc != 4 )
		return(0);
	std::string filename = argv[1];
	std::ofstream file_out(filename + ".replace");
	std::ifstream file_in(filename);
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string text;
	while (std::getline(file_in, text))
		file_out << ft_replace(s1, s2, text) << '\n';
	file_out.close();
	return(0);
}