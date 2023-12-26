/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:00:40 by ynassibi          #+#    #+#             */
/*   Updated: 2023/12/26 12:28:30 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <signal.h>
# include <unistd.h>

# define END "\033[0m"
#define RED "\033[0;91m"      // Bright Red
#define GREEN "\033[0;92m"    // Bright Green
#define YELLOW "\033[0;93m"   // Bright Yellow
#define BLUE "\033[0;94m"     // Bright Blue
#define MAGENTA "\033[0;95m"  // Bright Magenta
#define CYAN "\033[0;96m"     // Bright Cyan
#define RESET "\033[0m"       // Reset to default color
#define _True 0;
#define _False 1;

void	ft_putstr(char *str);
int ft_atoi_base(char *str, int base);
void ft_ursignals (int usr_1,int usr_2,void (*f)(int));
void	paket(pid_t pid, unsigned char c);
void	ft_putnub(int n);
void	confirm(int sch);
void ft_write(char c);
#endif
