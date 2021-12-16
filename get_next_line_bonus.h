/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:44:07 by yabtaour          #+#    #+#             */
/*   Updated: 2021/12/09 13:45:31 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen_bonus(char *str);
char	*ft_strchr_bonus(char *str, int c);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
