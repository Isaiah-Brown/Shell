#ifndef COMMAND_H
#define COMMAND_H

struct command_t
{
    char *type;
    void (*make)(struct command_t *);
    char (*get)(struct command_t *);
};

void *make_command(struct command_t *, char *type);
char *get_type(struct command_t *);

#endif