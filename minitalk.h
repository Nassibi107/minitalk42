/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:00:40 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/27 15:53:35 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

# define END "\033[0m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define RESET "\033[0m"

void	ft_putstr(char *str);
int		ft_atoi_base(char *str, int base);
void	ft_ursignals(int usr_1, int usr_2, void (*f)(int));
void	paket(pid_t pid, unsigned char c);
void	ft_putnub(int n);
void	confirm(int sch);
void	ft_write(char c);
void	show_me(int pid);
void	ft_sigactions_set(struct sigaction *obj);
void	ft_sigactions(int usr_1, int usr_2, struct sigaction *sig);
void	pid_handler( int *id_clt, int *id_cur, siginfo_t *info);
void	binding(int id, char *o, int *msg, int *i);
void	exchange(int sig, int *i, char *c);
#endif
