#include <iostream>
#include <fstream>

static	int	error(std::string const &msg, int const &code)
{
	std::cout << msg << '\n';
	return (code);
}

size_t	replace(std::string &str, size_t pos, size_t len, std::string const &s2)
{
	if (pos > str.length())
		return (1);
	// std::cout << "- [pos]: "<< pos << '\n'
	// 	<< '\"' << str << "\"\n"
	// 	<< "+ [len]: " << len << '\n'
	// 	<< '\"' << s2 << "\"\n";
	for (size_t i = 0; pos + i < str.length() && i < len && i < s2.length(); i++)
	{
		str[pos + i] = s2[i];
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
		return error("Usage: \"./Sed is for losers\" filename s1 s2", EINVAL);
	std::string filenameIn = argv[1];
	std::string	filenameOut = filenameIn + ".replace";
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream fileIn(filenameIn.data());
	if (!fileIn.is_open())
		return error("Error: failed to open file", errno);
	std::ofstream fileOut(filenameOut.data());
	if (!fileOut.is_open())
		return error("Error: failed to create file", errno);
	std::string line;
	while (std::getline(fileIn, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			if (replace(line, pos, s2.length(), s2))
				return (error("replace() failed", errno));
			pos += s2.length();
		}
		fileOut << line << '\n';
	}
}
