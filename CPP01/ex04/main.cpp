#include <errno.h>
#include <iostream>
#include <fstream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " filename s1 s2\n";
		return (EINVAL);
	}

	std::string	filenameIn = argv[1];
	std::string	filenameOut = filenameIn + ".replace";
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream	fileIn(filenameIn.data());
	if (!fileIn.is_open())
	{
		std::cerr << "Error: failed to open file" << filenameIn << "\n";
		return (errno);
	}
	std::ofstream	fileOut(filenameOut.data());
	if (!fileOut.is_open())
	{
		std::cerr << "Error: failed to create file" << filenameOut << "\n";
		return (errno);
	}

	std::string	line;
	while (std::getline(fileIn, line))
	{
		std::size_t	pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		fileOut << line << "\n";
	}
}
