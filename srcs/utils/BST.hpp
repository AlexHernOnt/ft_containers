/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:33:50 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/10 21:03:08 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BST_HPP__
# define __BST_HPP__
# include  <iostream>

template <class paired>
class node
{
	public:
		paired				data;

		node*				left;
		node* 				right;
		node* 				parent;
	
		node (paired ref, node<paired> *g_parent) : data(ref)
		{
			left = NULL;
			parent = g_parent;
			right = NULL;
		}
};




/*
**					Create Node
*/

template <class paired>
node<paired>		*new_node(node<paired> *ptr, node<paired> *prev, paired val)
{
	if (ptr == NULL)
	{
		return (new node<paired>(val, prev));
	}
	if (val.first > ptr->data.first)
	{
		ptr->right = new_node(ptr->right, ptr, val);
	}
	else if (val.first < ptr->data.first)
	{
		ptr->left = new_node(ptr->left, ptr, val);
	}
	return (ptr);
}




/*
**					Delete Node
*/

template <class paired>
node<paired>		*min_value_node(node<paired> *ptr)
{
	node<paired>		*current = ptr;

	while (current && current->left != NULL)
		current = current->left;
	return (current);	
}

template <class paired>
void		parent_point_to_second_not_first(node<paired> *ptr, node<paired> *aux, node<paired> *root)
{
	if (root != NULL)
	{
		parent_point_to_second_not_first(ptr, aux, root->left);
		
		if (root->left == ptr)
			root->left = aux;
		else if (root->right == ptr)
		{
			root->right = aux;
		}
		parent_point_to_second_not_first(ptr, aux, root->right);
	}
}

template <class paired>
node<paired>	*delete_node(node<paired> *ptr, paired val, node<paired> *root)
{
	if (ptr == NULL)
		return (ptr);
	else if (val.first < ptr->data.first)
		ptr->left = delete_node(ptr->left, val, root);
	else if (val.first > ptr->data.first)
		ptr->right = delete_node(ptr->right, val, root);
	else
	{
		if (ptr->right == NULL && ptr->left == NULL)
		{
			delete ptr;
			return (NULL);
		}
		else if (ptr->left == NULL)
		{
			node<paired> *aux = ptr->right;
			delete ptr;
			return (aux);
		}
		else if (ptr->right == NULL)
		{
			node<paired> *aux = ptr->left;
			delete ptr;
			return (aux);
		}

		/*
			1º Obtener el mínimo en la rama derecha (tmp)
			2º Hacer copia del valor de tmp. Y los links de aquel nodo que queremos eliminar 
			3º Borramos el nodo tmp
		*/

		node<paired>		*tmp = min_value_node(ptr->right);
		node<paired>		*aux = new node<paired>(tmp->data);

		ptr->right = delete_node(ptr->right, tmp->data, root);
		aux->left = ptr->left;
		aux->right = ptr->right;
		if (root == ptr)
			root = aux;
		else
			parent_point_to_second_not_first(ptr, aux, root);
		delete ptr;
		ptr = aux;
	}
	return (ptr);
}




/*
**							Print in order
*/

template <class paired>
void						in_order(node<paired> *ptr)
{
	if (ptr != NULL)
	{
		in_order(ptr->left);
		std::cout << ptr->data.first << std::endl;
		in_order(ptr->right);
	}
}




/*
**							Free
*/

template <class paired>
void						clear_tree(node<paired> *ptr)
{
	if (ptr != NULL)
	{
		clear_tree(ptr->left);
		delete ptr;
		clear_tree(ptr->right);
	}
}




/*
**							Iterator stuff
*/

template <class paired>
node<paired>						*bst_get_first(node<paired> *ptr)
{
	while (ptr != NULL && ptr->left != NULL)
		ptr = ptr->left;
	return (ptr);
}

template <class paired>
node<paired>						*bst_increment(node<paired> *ptr)
{
	if (ptr->right != NULL)
		return (min_value_node(ptr->right));
	else
	{
		if (ptr->parent->data.first > ptr->data.first)
			return (ptr->parent);
		else
		{
			while (ptr->parent->data.first < ptr->data.first)
				ptr = ptr->parent;
			return (ptr);
		}
		
	}
}

#endif