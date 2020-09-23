#ifndef __STACK_IMP__
#define __STACK_IMP__

#define MAX_SIZE 25

struct stack_m
{
    long value;
    struct stack_m *prev_stk_m;
    int actuel_nbr_elemnt;
} typedef stack_m;

stack_m *init_stack(long init_value);
int push_stack(stack_m **stack, long value);
stack_m *pull_stack(stack_m *stack);
int is_empty(stack_m *stack);
int can_push_into(stack_m *stack);
void trace_stack(stack_m *stack);
void destroy_stack(stack_m **stack);


#endif