/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:49:53 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/26 18:01:07 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int		this_move(char	*move, t_stacks	*stacks)
{
	if (ft_strncmp(move, "sa", 2) == 0)
		return	(sa(stacks, 1), 1);
	if (ft_strncmp(move, "sb", 2) == 0)
		return	(sb(stacks, 1), 1);
	if (ft_strncmp(move, "ss", 2) == 0)
		return	(ss(stacks, 1), 1);
	if (ft_strncmp(move, "pa", 2) == 0)
		return	(pa(stacks, 1), 1);
	if (ft_strncmp(move, "pb", 2) == 0)
		return	(pb(stacks, 1), 1);
	if (ft_strncmp(move, "ra", 2) == 0)
		return	(ra(stacks, 1), 1);
	if (ft_strncmp(move, "rb", 2) == 0)
		return	(rb(stacks, 1), 1);
	if (ft_strncmp(move, "rr", 2) == 0)
		return	(rr(stacks, 1), 1);
	if (ft_strncmp(move, "rra", 3) == 0)
		return	(rra(stacks, 1), 1);
	if (ft_strncmp(move, "rrb", 3) == 0)
		return	(rrb(stacks, 1), 1);
	if (ft_strncmp(move, "rrr", 3) == 0)
		return	(rrr(stacks, 1), 1);
	return	(0);
}
int	st_is_sorted(t_stacks	*stacks)
{
	t_stack	*tail;
	int i;
	int size;

	tail = stacks ->a_tail;
	size = stacks->a_size;
    i  = 0;
    while (i < size)
    {
        if (tail->num < tail->next->num)
            return 0;
        tail = tail->next;
        i++;
    }
    return 1;
}

void	error_move(t_stacks *stacks, int	*array, int	mode)
{
	if (mode == 0)
		ft_putstr_fd("error\n", 2);
	if (array)
		free(array);
	while (stacks->b_size != -1)
	pa(stacks, 1);
	st_free(stacks);
	exit(0);
}
void	result_of_moves(t_stacks *stacks,int	*array)
{
	if (st_is_sorted(stacks) == 0 && stacks->b_size == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	error_move(stacks, array, 1);
}


void	checker(t_stacks *stacks, int *array)
{
	char	*move;
	int		state;

	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		state = this_move(move, stacks);
		free(move);
		if (state == 0)
			error_move(stacks, array, 0);
	}
	result_of_moves(stacks, array);
}
void	checker_func(char	**arg_list, int given_l)
{
	int *array;
	int	len;
	t_stack	*stack_a;
	t_stacks	*stacks;

	len = 0;
	stack_a = NULL;
	if (check_vals(arg_list) == 0)
		return	;
	if (given_l == 0)
		len = twd_len(arg_list);
	else
		len = given_l;
	array = get_vals(arg_list, len);
	if (!array)
		return ;
	stack_a = convert_array(arg_list, array);
	if	(stack_a == NULL)
		return ;
	indexing_func(stack_a, array, len);
	stacks = init_stacks(stack_a, len, array);
	if	(!stacks)
		return (free(array));
	checker(stacks, array);
}

int	main(int ac, char **av)
{
	char	**args;

	if(ac > 1)
	{
		if (ac == 2)
			{
				args = ft_split(av[1], ' ');
				checker_func(args, 0);
				d_free(args);
			}
		else
		checker_func(av + 1, ac - 1);
	}
}
