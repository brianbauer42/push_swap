/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:03:12 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/09 17:08:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_operation		*use_rr(t_swap *selected, t_operation *op)
{
	int			i;
	int			rx;

	i = 0;
	op = (t_operation *)malloc(sizeof(t_operation) * (selected->moves_req + 1));
	rx = MAX(selected->mov_req_for, selected->sb_req_for) -
				MIN(selected->mov_req_for, selected->sb_req_for);
	while (i < rx)
		op[i++] = RR;
	rx = MAX(selected->mov_req_for, selected->sb_req_for);
	if (selected->mov_req_for > selected->sb_req_for)
		while (i < rx)
			op[i++] = RA;
	else if (selected->mov_req_for < selected->sb_req_for)
		while (i < rx)
			op[i++] = RB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}

t_operation		*use_rrr(t_swap *selected, t_operation *op)
{
	int			i;
	int			rx;

	i = 0;
	op = (t_operation *)malloc(sizeof(t_operation) * (selected->moves_req + 1));
	rx = MAX(selected->mov_req_bak, selected->sb_req_bak) -
				MIN(selected->mov_req_bak, selected->sb_req_bak);
	while (i < rx)
		op[i++] = RRR;
	rx = MAX(selected->mov_req_bak, selected->sb_req_bak);
	if (selected->mov_req_bak > selected->sb_req_bak)
		while (i < rx)
			op[i++] = RRA;
	else if (selected->mov_req_bak < selected->sb_req_bak)
		while (i < rx)
			op[i++] = RRB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}

t_operation		*sa_for_sb_bak(t_swap *selected, t_operation *op)
{
	int			i;
	int			rx;

	i = 0;
	op = (t_operation *)malloc(sizeof(t_operation) * (selected->moves_req + 1));
	rx = selected->mov_req_for;
	while (i < rx)
		op[i++] = RA;
	rx += selected->sb_req_bak;
	while (i < rx)
		op[i++] = RRB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}

t_operation		*sa_bak_sb_for(t_swap *selected, t_operation *op)
{
	int			i;
	int			rx;

	i = 0;
	op = (t_operation *)malloc(sizeof(t_operation) * (selected->moves_req + 1));
	rx = selected->mov_req_bak;
	while (i < rx)
		op[i++] = RRA;
	rx += selected->sb_req_for;
	while (i < rx)
		op[i++] = RB;
	op[i++] = PB;
	op[i] = 0;
	return (op);
}

t_operation		*build_instructions(t_swap *selected, t_operation *ops)
{
	if (selected->best_path_code == 0)
		return (use_rr(selected, ops));
	else if (selected->best_path_code == 1)
		return (use_rrr(selected, ops));
	else if (selected->best_path_code == 2)
		return (sa_for_sb_bak(selected, ops));
	else if (selected->best_path_code == 3)
		return (sa_bak_sb_for(selected, ops));
	else
		return (NULL);
}
