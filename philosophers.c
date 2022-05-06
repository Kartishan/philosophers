/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwildcat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:31:17 by pwildcat          #+#    #+#             */
/*   Updated: 2022/05/06 14:31:24 by pwildcat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int			c;
	unsigned long int	i;
	int					n;

	c = 0;
	n = 1;
	i = ft_space(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c *= 10;
		c += (str[i] - '0');
		if (c > 2147483647 && n == 1)
			return (-1);
		if (c > 2147483648 && n == -1)
			return (0);
		i++;
	}
	return ((int)c * n);
}

void*	helloWorld(void *args)
{
	// printf("Hello from thread!\n");
	// return (args);
	return (0);
}

void*	takeleft(void *args)
{
	pthread_mutex_init();
	
}

// void*	takeright(void *args)
// {

// }

// void*	eat(void *args)
// {

// }

// void*	forks(void *args)
// {


// }

void*	philo_init(pthread_t	*philo, char *str)
{
	int	i;
	int	n;

	i = 0;
	n = ft_atoi(str);
	if (n < 1)
	{
		write(1, "Philo numbers Error\n", 20);
		exit(1);
	}
	philo = malloc(sizeof(int) * (n + 1));
	if (philo == NULL)
		return (NULL);
	while (i < n)
	{
		pthread_create(&philo[i], NULL, helloWorld, NULL);
		i++;
	}
	return (philo);
}

int	main(int argc, char **argv)
{
	//if (argc != 5 && argc != 6)
		// return(write(1, "Args Error\n", 11));
	pthread_t	*philo;
	philo_init(philo, argv[1]);
}

//берём левую вилку/правую
//кушаем
//кладём вилку
//спим
//думаем
// повтор!
// умираем если кто-то не успел поесть.