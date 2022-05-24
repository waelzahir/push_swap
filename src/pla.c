#include "../inc/push_swap.h"
void    ftprints(t_stacks *stacks)
{
    int i = 0;

    while (i != stacks->b_size + 1 && stacks->b_size > -1)
    {
        if (stacks->b_tail)
        {
            stacks->b_tail = stacks->b_tail->previous;
            ft_printf("__ \n\n IN B %d\n", stacks->b_tail->num);

        }
        else
            ft_printf(" b empty\n");
        i++;
    }
    ft_printf("\n");
    ft_printf("\n");
    i = 0;

    while (i != stacks->a_size + 1 && stacks->a_size > -1)
    {
        if (stacks->a_tail)
        {
             stacks->a_tail = stacks->a_tail->previous;
            ft_printf("__ \n\n IN %d A %d\n",stacks->a_tail->index, stacks->a_tail->num);
        }
        else
        ft_printf("a empty\n");
        i++;
    }
}
