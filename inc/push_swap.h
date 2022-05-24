/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:50:13 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/20 17:50:14 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
#include <stdbool.h>
#include "../PRINT/ft_printf.h"
#include "../LIB/libft.h"
#include "../GNL/get_next_line.h"

//data structs

typedef	struct	s_stack
{
	struct	s_stack	*previous;
    struct	s_stack	*next;
	int				num;
    int				index;
	bool			out;
	bool			in;
}	t_stack;

typedef	struct	s_stacks
{
	t_stack		*temp_head;
	t_stack		*temp_b_head;
	int			b_size;
	int			a_size;
	t_stack		*a_tail;
	t_stack		*b_tail;
}	t_stacks;

// moves func' s
void	sa(t_stacks *stacks, int sig);
void	sb(t_stacks *stacks, int sig);
void	ss(t_stacks *stacks, int sig);
void	pb(t_stacks *stacks, int sig);
void	pa(t_stacks *stacks, int sig);
void	ra(t_stacks *stacks, int mode);
void	rb(t_stacks *stacks, int mode);
void	rr(t_stacks *stacks, int sig);
void	rra(t_stacks *stacks, int mode);
void	rrb(t_stacks *stacks, int mode);
void	rrr(t_stacks *stacks, int sig);

// moves helpers
t_stack	*init_push(t_stack *node);
t_stack	*delete_node(t_stack *tail, int size);
void	add_node(t_stack *tail, int size, t_stack *node);
void	swap(int* a, int* b);

//  mandatory func's
void		d_free(char	**args);
t_stack		*panic(t_stack *mem, int *array);
int			twd_len(char **args);
int			*arr_panic(int *array, int len, int mode);
int			check_vals(char **av);
int			*get_vals(char **av, int len);
void		quicksort(int *arr, int low, int high);
void		special_func(char **arg_list, int given_l);
t_stack		*convert_array(char **av, int *array);
void		indexing_func(t_stack *stack_a, int *array, int len);
t_stacks	*init_stacks(t_stack *stack_a, int size);
void		push_swap(t_stacks *stacks, int *array);
t_stack  *forward_increment(t_stack   *node, int times);
void    ftprints(t_stacks *stacks);


// bonus func's

#endif
