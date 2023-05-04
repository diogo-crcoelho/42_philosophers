/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarvalh <dcarvalh@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:25:17 by dcarvalh          #+#    #+#             */
/*   Updated: 2023/05/04 17:09:16 by dcarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_phiilo
{
	pthread_t	philo;
	int			forks[2];
	int			min_eat;
}	t_philo;

typedef struct s_env
{
	t_philo			*philos;
	int				forks;
	pthread_mutex_t	*m_forks;
	int				ttd;
	int				tte;
	int				tts;
	int				min_eat;
}	t_env;

t_env			*env(void);
void			err_handle(char *err);
void			print_msg(int time, int phil, char *action);

#endif