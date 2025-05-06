/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:28:33 by marvin            #+#    #+#             */
/*   Updated: 2025/05/05 22:28:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_player_count(char *trimmed, int *ply_count)
{
	int	i;

	i = 0;
	while (trimmed[i] != '\0')
	{
		if (ft_strchr("NSEW", trimmed[i]))
			(*ply_count)++;
		i++;
	}
	return (1);
}

int	check_ext(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (i > 4 && file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	return (1);
}

void	count_meta(const char *str, const char *type, int *count)
{
	char	**tokens;
	int		i;

	if (!str || !type || !count)
		return ;
	tokens = ft_split(str, ' ');
	if (!tokens || !tokens[0])
	{
		free(tokens);
		return ;
	}
	if (ft_strcmp(tokens[0], type) == 0)
		(*count)++;
	i = 0;
	while (tokens[i] != NULL)
		free(tokens[i++]);
	free(tokens);
}

int	check_map(const char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'E' && str[i] != 'W' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	validate_continuous_ones(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_trailing_newlines(int fd)
{
	char	*line;
	int		empty_lines;

	empty_lines = 0;
	line = read_fd(fd);
	while (line != NULL)
	{
		if (line[0] == '\0')
			empty_lines++;
		else
			empty_lines = 0;
		free(line);
		line = read_fd(fd);
	}
	return (empty_lines <= 1);
}
