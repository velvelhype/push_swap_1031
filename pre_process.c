#include "push_swap.h"

long    custom_atoi(const char *str)
{
	long	i;
	long	sum;
	long    j;

	sum = 0;
	i = 0;
	j = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
    if(j * sum > 2147483647 || j * sum < -2147483648)
        write_error();
	return ((long)j * sum);
}

void    write_error()
{
    write(1, "Error\n", 6);
    exit(1);
}

void    digit_check(char **argv, int c)
{
    if(ft_strlen(*(argv + c)) > 11)
        write_error();
}

void    value_type_check(char **argv, int c)
{
    int i = 0;
    if(*(*(argv + c) + i) == '-')
        i++;
    while(*(*(argv + c) + i))
    {
        if(ft_isdigit(*(*(argv + c) + i)) == FALSE)
        {
            write_error();
        }
        i++;
    }
}

void    pre_process(int argc, char **argv)
{
    int a = 10;
    printf("==============\n");
    if(argc < 2)
        write_error();
    int c = 1;
    while(*(argv + c))
    {
        digit_check(argv, c);
        value_type_check(argv, c);
        printf("%ld\n", custom_atoi(*(argv + c)));
        //read(1,NULL,1);
        c++;
    }
    printf("==============\n");
    
}