#include "../includes/cub3d.h"

int check_texture(const char *path)
{
    int fd;

    if (!path || !*path)
        return (0);
    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (0);
    close(fd);
    return (1);
}

int set_texture(char **texture, char *line)
{
    char *path;

    path = ft_strtrim(line + 3, " \t\n\r\f\v");
    if (!path)
        return (printf("Error : Memory allocation failed\n"), 0);
    if (!check_texture(path))
    {
        free(path);
        return (printf("Error : Texture not found\n"), 0);
    }
    *texture = path;
    return (1);
}