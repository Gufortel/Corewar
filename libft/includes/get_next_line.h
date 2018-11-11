/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:53:53 by abossard          #+#    #+#             */
/*   Updated: 2018/07/05 06:14:51 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 4096
# define RESTE reste[fd]
# define OPENMAX 4864

int		get_next_line(const int fd, char **line);

#endif
