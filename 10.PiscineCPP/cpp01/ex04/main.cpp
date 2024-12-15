#include <iostream>
#include <string>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac > 3 && av[1] && av[2] && av[3])
	{
		std::string		filein(av[1]);
		std::string		s1(av[2]);
		std::string		s2(av[3]);
		if (filein.empty() || s1.empty() || s2.empty())
		{
			std::cout << "Error: Empty string input" << std::endl;
			return (0);
		}
		std::ifstream	ifs(filein);
		if (!ifs)
		{
			std::cout << "Error: Input file stream doesn't exist" << std::endl;
			return (0);
		}
		std::string		fileout = filein + ".replace";
		std::ofstream	ofs(fileout);

		std::string		buff;
		size_t			pos = 0;

		while (getline(ifs, buff))
		{
			while ((pos = buff.find(s1)) != std::string::npos)
			{
				if (pos != std::string::npos)
				{
					buff = buff.erase(pos, s1.length());
					buff = buff.insert(pos, s2);
				}
			}
			ofs << buff << std::endl;
		}
	}
}
