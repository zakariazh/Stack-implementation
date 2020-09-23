#include <stack.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


stack_m *init_stack(long init_value)
{
    stack_m *new_stack = (stack_m *)malloc(sizeof(stack_m));
    if(!new_stack)
    {
        perror("Error while creating stack\n");
        return NULL;
    }
    new_stack->prev_stk_m = NULL;
    new_stack->value = init_value;
    new_stack->actuel_nbr_elemnt = 1;
    return new_stack;
}

int push_stack(stack_m **stack, long value)
{
    if(!can_push_into(*stack))
    {
        perror("Cannot push new element in stack : Stack is full or not initialized\n");
        return -1;
    }
    stack_m *new_element = (stack_m *)malloc(sizeof(stack_m));
    if(!new_element)
    {
        perror("Error while creating new element\n");
        return -ENOMEM;
    }
    new_element->value = value;
    new_element->prev_stk_m = *stack;
    new_element->actuel_nbr_elemnt = (*stack)->actuel_nbr_elemnt + 1;
    *stack = new_element;
    return 0;
}

stack_m *pull_stack(stack_m *stack)
{
    if(is_empty(stack))
    {
        printf("Warning : Empty stack cannot pull entity\n");
        return stack;
    }
    stack_m *stk = stack->prev_stk_m;
    free(stack);
    return stk;
}

int is_empty(stack_m *stack)
{
    if(stack == NULL)
        return 1;
    return 0;
}

int can_push_into(stack_m *stack)
{
    if(is_empty(stack) || stack->actuel_nbr_elemnt >= MAX_SIZE)
        return 0;
    return 1;
}

void trace_stack(stack_m *stack)
{
    if(is_empty(stack)){
        printf("\n|_---_|\n\n");
        return;
    }
    int len = stack->actuel_nbr_elemnt;
    printf("\n _____\n");
    for(int i = 0; i < len; i++)
    {
        printf("|_%ld_|\n",stack->value);
        stack = stack->prev_stk_m;
    }
    printf("\n");
}

void destroy_stack(stack_m **stack)
{
    if(is_empty(*stack))
        return;
    int len = (*stack)->actuel_nbr_elemnt;
    for(int i=0; i<len; i++)
    {
        *stack = pull_stack(*stack);
    }
}

