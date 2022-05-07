/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:33:50 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/07 20:09:22 by ahernand         ###   ########.fr       */
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



/*
**					Create Node
*/

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




/*
**					Delete Node
*/

template <class paired>
node<paired>	*delete_node(node<paired> *ptr, paired val)
{
	if (ptr == NULL)
		return (ptr);
	else if (val.first < ptr->data.first)
		ptr->left = delete_node(ptr->left, val);
	else if (val.first > ptr->data.first)
		ptr->right = delete_node(ptr->right, val);
	else
	{
		if (ptr->right == NULL && ptr->left == NULL)
		{
			delete ptr;
			return (NULL);
		}
		else if (ptr->left == NULL)
		{
			node<paired> *aux = new node<paired>(ptr->right->data);
			delete ptr;
			return (aux);
		}
		else if (ptr->right == NULL)
		{
			node<paired> *aux = new node<paired>(ptr->left->data);
			delete ptr;
			return (aux);
		}
		if (ptr->right->data->first < ptr->left->data->first)
			node<paired> *aux = ;
		else
			node<paired> *aux = ;
		
	}
	return (ptr);
}




/*
**					Print in order
*/

template <class paired>
void				in_order(node<paired> *ptr)
{
	if (ptr != NULL)
	{
		in_order(ptr->left);
		std::cout << ptr->data.first << std::endl;
		in_order(ptr->right);
	}
}




/*
**					Free
*/

template <class paired>
void				clear_tree(node<paired> *ptr)
{
	if (ptr != NULL)
	{
		clear_tree(ptr->left);
		delete ptr;
		clear_tree(ptr->right);
	}
	
}

#endif