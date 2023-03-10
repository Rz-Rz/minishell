/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yboudoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:52:03 by yboudoui          #+#    #+#             */
/*   Updated: 2023/01/11 15:56:13 by yboudoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# include "memory.h"
# include "string.h"
# include "list.h"

typedef enum e_token_kind {
	TOKEN_VALUE		= (1UL << 8),
	TOKEN_OPERATOR	= (1UL << 9),
}	t_token_kind;

typedef enum e_token_type {
	TOKEN_SPACES				=	0	| TOKEN_VALUE,
	TOKEN_WORD					=	1	| TOKEN_VALUE,
	TOKEN_DOUBLE_QUOTES			=	2	| TOKEN_VALUE,
	TOKEN_SIMPLE_QUOTES			=	3	| TOKEN_VALUE,
	TOKEN_WILDCARD				=	4	| TOKEN_VALUE,
	TOKEN_COMMANDE				=	5	| TOKEN_VALUE,
	TOKEN_REDIRECT_IN			=	6	| TOKEN_OPERATOR,
	TOKEN_HERE_DOCUMENT			=	7	| TOKEN_OPERATOR,
	TOKEN_PIPE					=	8	| TOKEN_OPERATOR,
	TOKEN_REDIRECT_OUT			=	9	| TOKEN_OPERATOR,
	TOKEN_REDIRECT_OUT_APPEND	=	10	| TOKEN_OPERATOR,
	TOKEN_AND					=	11	| TOKEN_OPERATOR,
	TOKEN_OR					=	12	| TOKEN_OPERATOR,
	TOKEN_SUBSHELL				=	13	| TOKEN_OPERATOR,
	MAX_TOKEN					=	14	| TOKEN_OPERATOR,
}	t_token_type;

typedef struct s_token	*t_token;

struct s_token {
	t_token_type	type;
	char			*input;
};

t_token	token_create(t_token_type type, char *substr);
t_token	token_dup(t_token src);
void	token_destroy(void *input);
bool	token_match(char *str, t_list *output);
bool	token_list_sanitizer(t_list *lst);

char	*tokenizer(char *input, t_list *out);
#endif
