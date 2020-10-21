#include <stdio.h>
#include "../libasm.h"

int		main(void)
{
	printf("The size of a int pointer is %ld bytes!\n", sizeof(int *));
	printf("The size of a char pointer is %ld bytes!\n", sizeof(char *));
	printf("The size of a void pointer is %ld bytes!\n", sizeof(void *));
	printf("The size of a t_list is %ld bytes!\n", sizeof(t_list));
	return (0);
}
