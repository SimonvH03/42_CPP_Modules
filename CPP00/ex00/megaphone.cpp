#include <iostream>

class	megaphone
{
	public:
		megaphone();
		~megaphone();
		char *str_uppercase(char *str);
};

megaphone::megaphone()
{
}

megaphone::~megaphone()
{
}

char	*megaphone::str_uppercase(char *str)
{
	int		i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	megaphone	megaphone;

	if (argc > 1)
		for (int i = 1; i < argc; i++)
			std::cout << megaphone.str_uppercase(argv[i]);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << '\n';
	return (0);
}
