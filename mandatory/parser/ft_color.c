/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouizer <rbouizer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 22:51:31 by marvin            #+#    #+#             */
/*   Updated: 2025/05/10 22:58:51 by rbouizer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int get_color(const char *color, unsigned int *result)
{
    char    **values;
    int        vals[3];
    int        i;

    if (!color || !result)
        return (0);
    values = ft_split(color, ',');
    if (!values)
        return (0);
    
    // Count how many values we have
    i = 0;
    while (values[i])
        i++;
    
    // We must have exactly 3 values
    if (i != 3)
    {
        free_values(values);
        return (0);
    }
    
    // Now parse the values
    i = 0;
    while (i < 3)
    {
        vals[i] = ft_atoi(values[i]);
        if (vals[i] < 0 || vals[i] > 255)
        {
            free_values(values);
            return (0);
        }
        i++;
    }
    
    *result = create_trgb(0, vals[0], vals[1], vals[2]);
    free_values(values);
    return (1);
}

int	is_valid_type(char **tokens, const char *type, unsigned int *color)
{
	if (!ft_strcmp(type, "F") || !ft_strcmp(type, "C"))
		return (get_color(tokens[1], color));
	return (tokens[1][0] != '\0');
}

int	check_meta(const char *str, const char *type)
{
	char			**tokens;
	int				valid;
	unsigned int	color;

	if (!str || !type)
		return (0);
	tokens = ft_split(str, ' ');
	if (!tokens || !tokens[0] || !tokens[1])
		return (free_values(tokens));
	valid = 0;
	color = 0;
	if (!ft_strcmp(tokens[0], type))
		valid = is_valid_type(tokens, type, &color);
	return (free_values(tokens) + valid);
}

int	process_meta_line(char *trimmed, int *tab)
{
	if (check_meta(trimmed, "NO"))
		tab[0]++;
	else if (check_meta(trimmed, "SO"))
		tab[1]++;
	else if (check_meta(trimmed, "WE"))
		tab[2]++;
	else if (check_meta(trimmed, "EA"))
		tab[3]++;
	else if (check_meta(trimmed, "F"))
		tab[4]++;
	else if (check_meta(trimmed, "C"))
		tab[5]++;
	else
		return (0);
	return (1);
}
