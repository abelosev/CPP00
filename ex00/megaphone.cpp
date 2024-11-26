#include <iostream>
#include <string>
#include <cctype>

void ft_megaphone(std::string &s)
{
	size_t i = 0;
	while(i < s.length())
	{
		if(std::isalpha(s[i]))
			s[i] = std::toupper(s[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int i = 1;
	if(ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		std::string s(av[i]);
		ft_megaphone(s);
		std::cout << s;
		if(i + 1 < ac)
			std::cout << ' ';
		else
			std::cout << std::endl;
		i++;
	}
	return (0);
}