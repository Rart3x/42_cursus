/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kramjatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:55:40 by kramjatt          #+#    #+#             */
/*   Updated: 2023/05/02 18:15:27 by kramjatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define BUFFER_SIZE 42

# include "libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

/*-------GNL--------*/
char	*get_next_line(int fd);

/*-------GNL_utils--------*/
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strrchr(const char *s, int c);

#endif
