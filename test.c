#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(void)
{
    stack_m *my_stack = init_stack(888);
    push_stack(&my_stack, 638);
    push_stack(&my_stack, 798);
    push_stack(&my_stack, 173);
    push_stack(&my_stack, 944);
    push_stack(&my_stack, 557);
    push_stack(&my_stack, 464);
    push_stack(&my_stack, 527);
    push_stack(&my_stack, 324);
    
    return 0;
}