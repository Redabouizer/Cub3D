#include "../includes/cub3d.h"

int check_ext(char *file) {
    int i = 0;
    while (file[i] != '\0') i++;
    if (i > 4 && file[i - 4] == '.' && file[i - 3] == 'c' && 
        file[i - 2] == 'u' && file[i - 1] == 'b') {
        return 0;
    }
    return 1;
}

void count_meta(const char *str, const char *type, int *count) {
    char **tokens;
    int i = 0;

    if (!str || !type || !count) return;

    tokens = ft_split(str, ' ');
    if (!tokens || !tokens[0]) {
        free(tokens);
        return;
    }

    if (ft_strcmp(tokens[0], type) == 0) {
        (*count)++;
    }

    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

int get_color(const char *color, int *r, int *g, int *b) {
    char **values;
    int vals[3];
    int i = 0;

    if (!color || !r || !g || !b) return 0;

    values = ft_split(color, ',');
    if (!values) return 0;

    while (i < 3 && values[i] != NULL) {
        vals[i] = ft_atoi(values[i]);
        if (vals[i] < 0 || vals[i] > 255) {
            while (values[i] != NULL) {
                free(values[i]);
                i++;
            }
            free(values);
            return 0;
        }
        i++;
    }

    if (i != 3) {
        while (values[i] != NULL) {
            free(values[i]);
            i++;
        }
        free(values);
        return 0;
    }

    *r = vals[0];
    *g = vals[1];
    *b = vals[2];

    while (values[i] != NULL) {
        free(values[i]);
        i++;
    }
    free(values);

    return 1;
}

int check_meta(const char *str, const char *type) {
    char **tokens;
    int valid = 0;
    int r, g, b;
    int i = 0;

    if (!str || !type) return 0;

    tokens = ft_split(str, ' ');
    if (!tokens || !tokens[0] || !tokens[1]) {
        while (tokens[i] != NULL) {
            free(tokens[i]);
            i++;
        }
        free(tokens);
        return 0;
    }

    if (ft_strcmp(tokens[0], type) == 0) {
        if (ft_strcmp(type, "F") == 0 || ft_strcmp(type, "C") == 0) {
            if (get_color(tokens[1], &r, &g, &b)) valid = 1;
        } else {
            if (tokens[1][0] != '\0') valid = 1;
        }
    }

    while (tokens[i] != NULL) {
        free(tokens[i]);
        i++;
    }
    free(tokens);
    return valid;
}

int check_map(const char *str) {
    int i = 0;

    if (!str || *str == '\0') return 0;

    while (str[i] != '\0') {
        if (str[i] != '0' && str[i] != '1' && str[i] != 'N' &&
            str[i] != 'S' && str[i] != 'E' && str[i] != 'W' && str[i] != ' ') {
            return 0;
        }
        i++;
    }
    return 1;
}

int validate_map_borders(const char *line) {
    int len = ft_strlen(line);

    if (len > 0 && (line[0] != '1' || line[len - 1] != '1')) {
        return 0;
    }
    return 1;
}

int validate_continuous_ones(const char *line) {
    int i = 0;

    while (line[i] != '\0') {
        if (line[i] != '1') {
            return 0;
        }
        i++;
    }
    return 1;
}

int process_file(const char *file) {
    int tab[6] = {0};
    int ply_count = 0;
    int map_on = 0;
    int map_ended = 0;
    char *first_map_line = NULL;
    char *last_map_line = NULL;
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("Error: Could not open file");
        return -1;
    }

    while ((line = read_fd(fd))) {
        char *trimmed = ft_strtrim(line, " \t\n\r");
        free(line);

        if (!trimmed || trimmed[0] == '\0') {
            if (map_on) {
                map_ended = 1;
            }
            free(trimmed);
            continue;
        }

        if (!map_on) {
            if (check_meta(trimmed, "NO")) tab[0]++;
            else if (check_meta(trimmed, "SO")) tab[1]++;
            else if (check_meta(trimmed, "WE")) tab[2]++;
            else if (check_meta(trimmed, "EA")) tab[3]++;
            else if (check_meta(trimmed, "F")) tab[4]++;
            else if (check_meta(trimmed, "C")) tab[5]++;
            else if (check_map(trimmed)) {
                map_on = 1;
                first_map_line = ft_strdup(trimmed);

                if (!validate_continuous_ones(first_map_line)) {
                    printf("Error: First map line must be continuous '1's.\n");
                    free(first_map_line);
                    free(trimmed);
                    close(fd);
                    return -1;
                }
            } else {
                printf("Error: Invalid line before map section.\n");
                free(trimmed);
                close(fd);
                return -1;
            }
        } else {
            if (!check_map(trimmed)) {
                printf("Error: Non-map line detected after map section started.\n");
                free(trimmed);
                close(fd);
                return -1;
            }

            if (map_ended) {
                printf("Error: Double map detected.\n");
                free(trimmed);
                close(fd);
                return -1;
            }

            if (!validate_map_borders(trimmed)) {
                printf("Error: Map line must start and end with '1'.\n");
                free(trimmed);
                close(fd);
                return -1;
            }

            if (last_map_line) {
                free(last_map_line);
            }
            last_map_line = ft_strdup(trimmed);

            int i = 0;
            while (trimmed[i] != '\0') {
                if (trimmed[i] == 'N' || trimmed[i] == 'S' || 
                    trimmed[i] == 'E' || trimmed[i] == 'W') {
                    ply_count++;
                }
                i++;
            }
        }

        free(trimmed);
    }

    close(fd);

    if (last_map_line && !validate_continuous_ones(last_map_line)) {
        printf("Error: Last map line must be continuous '1's.\n");
        free(first_map_line);
        free(last_map_line);
        return -1;
    }

    if (tab[0] == 1 && tab[1] == 1 && tab[2] == 1 && tab[3] == 1 &&
        tab[4] == 1 && tab[5] == 1 && ply_count == 1) {
        free(first_map_line);
        free(last_map_line);
        return 0;
    }

    printf("Validation failed: Metadata or player count incorrect.\n");
    free(first_map_line);
    free(last_map_line);
    return -1;
}

int validate_map(t_mem **mm, const char *file) {
    (void)mm;

    if (process_file(file) != 0)
        return -1;
    return 0;
}