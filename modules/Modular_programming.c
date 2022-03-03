/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Modular_programming.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablaamim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:29:51 by ablaamim          #+#    #+#             */
/*   Updated: 2022/03/03 12:55:54 by ablaamim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
# define ENDL write(1, "\n", 1)

typedef struct s_intarray
{
	int	*data;
	int	len;
}	t_intarray;

void	ft_putchar(char c){write(1, &c, 1);}
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}
void	ft_putnbr(int nb)
{
	long	nbr = nb;
	if (nbr < 0x0)
	{
		nbr *= -1;
		ft_putchar('-');
	}
	if (nbr > 9){ft_putnbr(nbr / 10);}
	write(0x1, &"0123456789"[nbr % 10], 0x1);
}

void	ft_intarray_print_positive_values(t_intarray tab)
{
	int	i;

	i = 0x0;
	ft_putchar('[');
	while (i < tab.len - 1)
	{
		if (tab.data[i] >= 0x0)
		{
			ft_putnbr(tab.data[i]);
			ft_putstr(", ");
		}
		i++;
	}
	ft_putnbr(tab.data[tab.len - 0x1]);
	ft_putchar(']');
}

void	ft_intarray_debug(t_intarray tab)
{
	int	i = 0x0;

	ft_putchar('[');
	while (i < tab.len - 0x1)
	{
		ft_putnbr(tab.data[i]);
		ft_putstr(", ");
		i++;
	}
	ft_putnbr(tab.data[tab.len - 0x1]);
	ft_putchar(']');
}

int	ft_intarray_search(t_intarray tab, int n)
{
	int	j = 0x0;
	while (j < tab.len)
	{
		if (tab.data[j] == n)
			return (0x1);
		j++;
	}
	return (0x0);
}

int	ft_intarray_nb_occurences(t_intarray tab, int value)
{
	int	i = 0x0;
	int	occurences = 0x0;
	while (i < tab.len)
	{
		if (tab.data[i] == value)
			occurences++;
		i++;
	}
	return (occurences);
}

t_intarray	ft_intarray_create(int len)
{
	int	i = 0x0;
	t_intarray create;
	create.len = len;
	create.data = malloc (sizeof(int) * len);
	while (i < len)
	{
		create.data[i] = 0x0;
		i++;
	}
	return (create);
}

int	ft_intarray_get(t_intarray tab, int index)
{
	if (index < 0x0 || index >= tab.len)
	{
		ft_putstr("Please set a valid index : ");
		return (-1);
	}
	return (tab.data[index]);
}

void	ft_intarray_set(t_intarray tab, int index, int value)
{
	if (index < 0x0 || index >= tab.len)
	{
		ft_putstr("Please set a valid index");
		return ;
	}
	tab.data[index] = value;
}

void	ft_intarray_destroy(t_intarray tab)
{
	free(tab.data);
}

int	ft_intarray_len(t_intarray tab)
{
	return (tab.len);
}

int	main(int argc, char **argv)
{
	(void)	argc;
	(void)	argv;
	t_intarray tab = ft_intarray_create(10);
	ft_putstr("Debugging an intarray : ");
	ft_intarray_debug(tab);
	ENDL;
	ft_putstr("Retrieving positive values : ");
	ft_intarray_print_positive_values(tab);
	ENDL;
	ft_putstr("Searching for an element inside an intarray : ");
	ft_putnbr(ft_intarray_search(tab, 0));
	ENDL;
	ft_putstr("Searching for an element inside an intarray : ");
	ft_putnbr(ft_intarray_search(tab, 555));
	ENDL;
	ft_putstr("Counting number of occurences in an intarray : ");
	ft_putnbr(ft_intarray_nb_occurences(tab, 0));
	ENDL;
	ft_putstr("Retrieve the value at the specified index : ");
	ft_putnbr(ft_intarray_get(tab, 1));
	ENDL;
	ft_intarray_set(tab, 0, 1);
	ft_intarray_set(tab, 1, -42);
	ft_intarray_set(tab, 2, 1337);
	ft_putstr("Debugging the intarray to verify set function : ");
	ft_intarray_debug(tab);
	ENDL;
	ft_putstr("Retrieve index 2 : ");
	ft_putnbr(ft_intarray_get(tab, 10));
	ENDL;
	ft_putstr("Invalid index : ");
	ft_putnbr(ft_intarray_get(tab, -1));
	ENDL;
	ft_putstr("Length of my intarray : ");
	ft_putnbr(ft_intarray_len(tab));
	ENDL;
	ft_intarray_destroy(tab);
	return (EXIT_SUCCESS);
}