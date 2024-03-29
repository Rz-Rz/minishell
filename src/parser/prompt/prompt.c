/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:14:15 by yboudoui          #+#    #+#             */
/*   Updated: 2023/03/21 17:24:58 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_list	slice_commande(t_token_list *lst)
{
	t_list	output;

	output = NULL;
	while (*lst)
	{
		if ((*lst)->token->type == TOKEN_PIPE)
			break ;
		else
			list_create_back((t_list *)&output, token_dup((*lst)->token));
		(*lst) = (*lst)->next;
	}
	return (output);
}

static bool	syntaxer(t_token_list *root)
{
	t_token_list	lst;
	t_token_list	output;

	output = NULL;
	lst = (*root);
	while (lst)
	{
		if (lst->token->type == TOKEN_PIPE)
			lst = lst->next;
		else
			list_create_back((t_list *)&output,
				commande_create(slice_commande(&lst)));
	}
	list_clear(root, token_destroy);
	(*root) = output;
	return (true);
}

t_prompt	prompt_create(char *input)
{
	t_token_list	lexer_output;

	if (input == NULL)
		return (NULL);
	lexer_output = lexer(input);
	if (lexer_output == NULL)
		return (NULL);
	syntaxer(&lexer_output);
	return ((t_prompt)lexer_output);
}

void	prompt_destroy(void *data)
{
	t_prompt	*input;

	input = data;
	if (input == NULL)
		return ;
	list_clear(input, commande_destroy);
	free(*input);
	(*input) = NULL;
}
