#include "push_swap.h"
static	int	my_isspace(int c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	j;
	long	count;

	i = 0;
	j = 1;
	count = 0;
	while (my_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		j *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else if (str[i] <= '0' && str[i] >= '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		count = (str[i] - 48) + (count * 10);
		i++;
	}
	return (count * j);
}

void    st_connect(t_stack *stack, t_stack *head, int argc)
{
    int i;
    t_stack *temp;
    stack->previous = head;
    head->next = stack;

    printf("tt %d %d \n", stack->num, head->num);
    i = argc - 1;
    temp = head;
    stack = head;
    while(i >= 1)
    {
        stack = stack->previous;
        stack->next = temp;
        temp = temp->previous;
        i--;
    }
}
t_stack *fill_stack(int argc, char   **argv)
{
    t_stack *stack;
    t_stack *temp;
    int i;

    stack = malloc(sizeof(t_stack));
    temp = stack;
    i = argc - 1;
    while (i >= 1)
    {
        stack->num = ft_atoi(argv[i]);
        printf("stack num ; %d\n",stack->num);
    
        printf("t %d\n",i);
        i--;
        if(i == 0)
            break ;
        stack->previous  = malloc(sizeof(t_stack));
        stack = stack->previous;
    }
    st_connect(stack , temp, argc);
    return  (temp);

}
t_head *stack_intialize(int argc, char   **argv)
{
    t_head  *heads;

    heads = malloc(sizeof(t_head));
 //   if (!heads || !a_head || !b_head)
   //     panic(heads);
    heads->a_head = fill_stack(argc, argv);
    return (heads);
}
int main(int argc, char **argv)
{
    t_head *heads;
    int t;
    if (argc > 2)
    {
        heads = stack_intialize(argc, argv);
        while (1)
        {
        
        heads->a_head = heads->a_head->previous;
        t = heads->a_head->num;
        printf("num; %d\n",t);
        }
    }
}