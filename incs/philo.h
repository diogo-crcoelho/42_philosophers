/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:25:17 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/16 02:54:31 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef struct s_philo
{
	pthread_t		philo;
	int				forks[2];	
	int				min_eat;
	pthread_mutex_t	m_eaten;
	long			last_ate;
	pthread_mutex_t	m_ate;
	int				tod;
	int				pair;
}	t_philo;

typedef struct s_env
{
	t_philo			*philos;
	int				forks;
	int				*l_forks;
	pthread_mutex_t	*m_forks;
	pthread_mutex_t	m_message;
	int				dead;
	pthread_mutex_t	m_dead;
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
long			cut_time(t_timeval tv);
void			check_dead(void);
void			quit(void);
void			change_fork(int i, int flag);
int				dead_inside(void);
int				av_forks(t_philo *p);
int				check_full(void);

void			p_sleep(int i);
void			p_eat(int i);
void			p_think(int i);

#endif