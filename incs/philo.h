/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:25:17 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/05 22:44:51 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	 t_timeval;

typedef struct s_phiilo
{
	pthread_t	philo;
	int			forks[2];
	int			min_eat;
	long		last_ate;
}	t_philo;

typedef struct s_env
{
	t_philo			*philos;
	int				forks;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_message;
	t_timeval		start;	
	int				ttd;
	int				tte;
	int				tts;
	int				min_eat;
}	t_env;

t_env			*env(void);
void			err_handle(char *err);
void			print_msg(int time, int phil, char *action);
void			sleeper(int time);

void			p_sleep();
void			p_eat(t_philo *philo);

#endif