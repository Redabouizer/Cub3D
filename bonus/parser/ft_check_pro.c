/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:52:41 by rbouizer          #+#    #+#             */
/*   Updated: 2025/05/12 00:08:05 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_number(const char *str)
{
	const char	*ptr;

	if (!str || !*str)
		return (0);
	ptr = str;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
			return (0);
		ptr++;
	}
	return (1);
}

int	validate_color_components(char **values, int vals[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!is_valid_number(values[i]))
			return (0);
		vals[i] = ft_atoi(values[i]);
		if (vals[i] < 0 || vals[i] > 255)
			return (0);
		i++;
	}
	return (1);
}

int	has_trailing_comma(const char *trimmed)
{
	int	i;

	if (!trimmed)
		return (0);
	i = ft_strlen(trimmed) - 1;
	while (i >= 0 && (trimmed[i] == ' ' || trimmed[i] == '\t'
			|| trimmed[i] == '\n' || trimmed[i] == '\r'))
	{
		i--;
	}
	return (i >= 0 && trimmed[i] == ',');
}

int	check_texture(const char *path)
{
	int	fd;

	if (!path || !*path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	set_texture(char **texture, char *line)
{
	char	*path;

	path = ft_strtrim(line + 3, " \t\n\r\f\v");
	if (!path)
		return (printf("Error: Memory allocation failed\n"), 0);
	if (!check_texture(path))
		return (printf("Error: Texture not found ; %s\n", path), free(path),0);
	if (*texture)
		free(*texture);
	*texture = path;
	return (1);
}
