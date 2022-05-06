/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:33:50 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/06 16:34:02 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BST_HPP__
# define __BST_HPP__
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
node<paired>		*new_node(node<paired> *ptr, paired val)
{
	if (ptr == NULL)
	{
		return (new node<paired>(val));
	}
	if (val.first > ptr->data.first)
	{
		ptr->right = new_node(ptr->right, val);
	}
	else if (val.first < ptr->data.first)
	{
		ptr->left = new_node(ptr->left, val);
	}
	return (ptr);
}

#endif