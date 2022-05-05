/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AVL.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:24:15 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/05 18:04:29 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AVL_HPP__
# define __AVL_HPP__
# include  <iostream>

template <class paired>
class node
{
	public:
		const paired		data;

		node*				left;
		node* 				right;
	
		node (paired ref) : data(ref)
		{
			left = NULL;
			right = NULL;
		}
};

template <class paired>
void	new_node(node<paired> **_root, paired val)
{
	if (val.first > (*_root)->data.first)
		(*_root)->right = new node<paired>(val);
	else if (val.first < (*_root)->data.first)
		(*_root)->left = new node<paired>(val);
}

#endif