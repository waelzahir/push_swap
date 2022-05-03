#include "inc/push_swap.h"
int this_move(char  *move, t_stacks *stacks)
{
    if (ft_strncmp(move, "sa", 2) == 0)
        return (sa(stacks, 1) , 1);
    if (ft_strncmp(move, "sb", 2) == 0)
        return  (sb(stacks,  1), 1);
    if (ft_strncmp(move, "pb",  2) == 0)
        return (pb(stacks, 1), 1 );
    if (ft_strncmp(move, "pa",  2) == 0)
        return (pa(stacks, 1), 1 );
    if (ft_strncmp(move, "ra",  2) == 0)
        return (ra(stacks, 1), 1);
    if (ft_strncmp(move, "rb",  2) == 0)
        return (rb(stacks, 1), 1);
    if (ft_strncmp(move, "rra",  3) == 0)
        return (rra(stacks, 1), 1 );
    if (ft_strncmp(move, "rrb",  3) == 0)
        return (rrb(stacks, 1), 1 );

        if (ft_strncmp(move, "ss",  2) == 0)
            return (ss(stacks, 1), 1);
        if (ft_strncmp(move, "rrr",  2) == 0)
            return (rrr(stacks, 1), 1 );
        return 0;
}

void    apply_moves(char    *line, t_stacks *stacks)
{
    char    **lines;
    int i;
    int d;

    i = 0;
    lines = ft_split(line , '\n');
    d = 0;
    free(line);
    while(lines[i])
    {
        d =  this_move(lines[i], stacks);
        i++;
    }
    ftprints(stacks);
}
int     sort_check(t_node *tail, int size)
{
    int i;
    i  = 0;
    while (i < size)
    {
        ft_printf("prev %d next %d \n",tail->num , tail->uni_next->num );
        if (tail->num < tail->uni_next->num)
            return 0;
        tail = tail->uni_next;
        i++;
    }
    return 1;
}
void    checker(t_node   *tail, int size)
{
     t_stacks *stacks;
    t_node *temp;
    char    *tmp;
    char    *line;
    line = NULL;
    temp = tail;

    stacks  = init_stacks(tail, size);
    link_to_big(temp,stacks->a_size);
    while (1)
    { 
        tmp = get_next_line(0);
        if (!tmp)
            break;
        line = ft_strjoin(line, tmp);
    }
    apply_moves(line, stacks);
    temp = forward_increment(stacks->a_tail, stacks->a_size);
    if (sort_check(stacks->a_tail, stacks->a_size) == 1 && stacks->b_size == -1)
        ft_printf("ok\n");
    else 
        ft_printf("ko\n");
    

}
void rvereseArray(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];  
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }  
}    

int main    (int ac, char **av)
{
    t_node *univ;
    int *array;

    univ = NULL;
    if (ac >=2)
    {
         if (check_values(av + 1) == 0)
            return (0);
        array = get_values(av + 1, ac - 1);
        if (array == NULL)
            return (0);
                    rvereseArray(array, 0, ac -2);
        univ = array_to_list(av + 1);
        st_index(univ, array, ac -1);
        checker(univ, ac -1);

    }
}