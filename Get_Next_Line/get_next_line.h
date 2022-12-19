/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:39:59 by mmesum            #+#    #+#             */
/*   Updated: 2022/12/19 12:47:08 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_gnl_strchr(const char *str, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*get_new_arr(char *arr);
#endif
