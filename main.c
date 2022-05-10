#include "monty.h"

int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		write(stderr, "USAGE: monty file", 17);
		exit(EXIT_FAILURE);
	}
	else
	{
		file = fopen(av[1], "r");
		if (!file)
		{
			write(stderr, "Error: Can't open file <file>", 29);
			exit(EXIT_FAILURE);
		}
	}
}
