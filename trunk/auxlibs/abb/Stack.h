#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include "Alpha.h"

typedef struct sStack *Stack;

Stack stk_empty(void);

void stk_push(alpha e, Stack s);

alpha stk_top(Stack s);

Stack stk_pop(Stack s);

bool stk_isEmpty(Stack s);

Stack stk_destroy(Stack s);

void stk_bpush (alpha e, Stack s);

#endif
