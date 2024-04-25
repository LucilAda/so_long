
#ifndef MAP_CHECK_H
#define MAP_CHECK_H

typedef enum e_mode {
    MODE_1,
    MODE_2,
    MODE_3
} t_mode;

typedef struct s_test {
    int data;
}   t_test;

typedef struct s_data {
    int i;
    t_test test;
    t_mode mode;
    struct s_data *next;
}   t_data;

t_data t;
t.mode = MODE_1;

if (t.mode == MODE_1)
    action();


typedef struct s_game {
    char **map;
    t_mode;
    int fd;

} t_game;

#endif