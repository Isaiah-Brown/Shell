#include <stdio.h>
#include "command.h"

void *make_command(struct command_t *self, char type)
{
    self->type = type;
}
char *get_type(struct command_t *self)
{
    return self->type;
}