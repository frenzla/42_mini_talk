#include "mini_talk.h"

int	main(int argc, char **argv)
{
	(void)argc;
	ft_printf("Result from `kill 0`: %d\n", kill(ft_atoi(argv[1]), 0));
	return (0);
}
