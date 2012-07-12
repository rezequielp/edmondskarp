#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "Alpha.h"

#define FORWARD 1
#define BACKWARD -1

typedef struct sStack *Stack;

Stack stk_empty(void);

void stk_push(alpha vertex, alpha ancestor, unsigned int line, Stack s);

alpha stk_top_vertex(Stack s);

alpha stk_top_ancestor(Stack s);

alpha stk_top_line(Stack s);

Stack stk_pop(Stack s);

bool stk_isEmpty(Stack s);

Stack stk_destroy(Stack s);

void stk_bpush (alpha e, Stack s);

#endif