#include <iostream>

int main(int ac, char **argv)
{
	for (int i = 1; i < ac; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			argv[i][j] = toupper(argv[i][j]);
		std::cout << argv[i];
	}
	std::cout << std::endl;
}