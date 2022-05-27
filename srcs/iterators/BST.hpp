/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:33:50 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/27 13:48:18 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BST_HPP__
# define __BST_HPP__
# include <iostream>

template <class paired>
class node
{
	public:
		paired				data;
		
		int					_ite;
		node*				left;
		node* 				right;
		node* 				parent;
		
		node (paired ref, node<paired> *g_parent, int g_ite) : data(ref)
		{
			left = NULL;
			parent = g_parent;
			right = NULL;
			_ite = g_ite;
		}
};






	/*
	**									Create Node
	*/
	
	
	
	
	template <class paired, class _alloc>
	node<paired>						*ft_move_sentinel(node<paired> *prev, node<paired> *sentinel, paired val, _alloc alloc)
	{
		node<paired>					*aux;
		node<paired>					c_aux(val, prev, 0);

		aux = alloc.allocate(1);
		alloc.construct(aux, c_aux);
	
		aux->right = sentinel;
		sentinel->parent = aux;
		return (aux);
	}
	
	
	
	
	template <class paired, class _comp, class _alloc>
	node<paired>						*create_node(node<paired> *ptr, node<paired> *prev, paired val, _comp comp, _alloc alloc)
	{
		if (ptr == NULL)
		{
			node<paired>					*aux;
			node<paired>					c_aux(val, prev, 0);
			
			aux = alloc.allocate(1);
			alloc.construct(aux, c_aux);
			return (aux);
		}
		if (ptr->_ite == 1)
		{
			ptr = ft_move_sentinel(prev, ptr, val, alloc);
			return (ptr);
		}		
		if (!comp(val.first, ptr->data.first) && val.first != ptr->data.first)
		{
			if (ptr->right != NULL && ptr->right->_ite == 1)
			{
				ptr->right = ft_move_sentinel(ptr, ptr->right, val, alloc);
			}
			else
				ptr->right = create_node(ptr->right, ptr, val, comp, alloc);
		}
		else if (comp(val.first, ptr->data.first) && val.first != ptr->data.first)
		{
			ptr->left = create_node(ptr->left, ptr, val, comp, alloc);
		}
		return (ptr);
	}
	
	
	
	
	
	
	
	
	/*
	**									Eliminate Node
	*/
	
	
	
	
	template <class paired>
	node<paired>						*min_value_node(node<paired> *ptr)
	{
		node<paired>		*current = ptr;
	
		while (current && current->left != NULL)
			current = current->left;
		return (current);	
	}
	
	
	
	
	template <class paired>
	node<paired>						*max_value_node(node<paired> *ptr)
	{
		node<paired>		*current = ptr;
	
		while (current && current->right != NULL && current->right->_ite != 1)
			current = current->right;
		return (current);	
	}
	
	
	
	
	template <class paired>
	void								parent_point_to_second_not_first(node<paired> *ptr, node<paired> *aux, node<paired> *root)
	{
		if (root != NULL)
		{
			parent_point_to_second_not_first(ptr, aux, root->left);
			
			if (root->left == ptr)
				root->left = aux;
			else if (root->right == ptr)
				root->right = aux;
			parent_point_to_second_not_first(ptr, aux, root->right);
		}
	}
	
	
	
	
	template <class paired, class _comp, class _alloc>
	node<paired>						*destroy_node(node<paired> *ptr, paired val, node<paired> *root, _comp comp, _alloc alloc)
	{
		if (ptr == NULL)
			return (ptr);
		else if (comp(val.first, ptr->data.first) && val.first != ptr->data.first)
			ptr->left = destroy_node(ptr->left, val, root, comp, alloc);
		else if (!comp(val.first, ptr->data.first) && val.first != ptr->data.first)
			ptr->right = destroy_node(ptr->right, val, root, comp, alloc);
		else if (ptr->_ite == 0)
		{
			if (ptr->right == NULL && ptr->left == NULL)
			{
				alloc.deallocate(ptr, 1);
				return (NULL);
			}
			else if (ptr->left == NULL)
			{
				node<paired> *aux = ptr->right;
				aux->parent = ptr->parent;
				alloc.deallocate(ptr, 1);
				return (aux);
			}
			else if (ptr->right == NULL)
			{
				node<paired> *aux = ptr->left;
				aux->parent = ptr->parent;
				alloc.deallocate(ptr, 1);
				return (aux);
			}
			/*
				1º Obtener el mínimo en la rama derecha (tmp)
				2º Hacer copia del valor de tmp. Y los links de aquel nodo que queremos eliminar 
				3º Borramos el nodo tmp
			*/
		
			node<paired>			*tmp = min_value_node(ptr->right);
			
			node<paired>			c_aux(tmp->data, ptr->parent, tmp->_ite);
			node<paired>			*aux = alloc.allocate(1);
			
			alloc.construct(aux, c_aux);
	
			aux->parent = ptr->parent;
			ptr->left->parent = aux;
			aux->left = ptr->left;
			aux->right = destroy_node(ptr->right, tmp->data, root, comp, alloc);
			if (aux->right != NULL)
				aux->right->parent = aux;
			if (root == ptr)
			{
				alloc.deallocate(ptr, 1);
				return (aux);
			}
			parent_point_to_second_not_first(ptr, aux, root);
			alloc.deallocate(ptr, 1);
			ptr = aux;
		}
		return (ptr);
	}
	
	
	
	
	
	
	
	
	/*
	**									Print in order
	*/
	
	
	
	
	template <class paired>
	void								in_order(node<paired> *ptr)
	{
		if (ptr != NULL)
		{
			in_order(ptr->left);
			std::cout << ptr->data.first << std::endl;
			in_order(ptr->right);
		}
	}
	
	
	
	
	
	
	
	
	/*
	**									Free
	*/
	
	
	
	
	template <class paired, class _alloc>
	void								clear_tree(node<paired> *ptr, _alloc alloc)
	{
		if (ptr != NULL)
		{
			clear_tree(ptr->left, alloc);
			alloc.deallocate(ptr, 1);
			clear_tree(ptr->right, alloc);
		}
	}
	
	
	
	
	
	
	
	
	/*
	**									Iterator stuff
	*/
	
	
	
	
	template <class paired>
	node<paired>						*bst_get_first(node<paired> *ptr)
	{
		while (ptr != NULL && ptr->left != NULL)
			ptr = ptr->left;
		return (ptr);
	}
	
	
	
	
	template <class paired>
	node<paired>						*bst_get_last(node<paired> *ptr)
	{
		while (ptr != NULL && ptr->right != NULL)
			ptr = ptr->right;
		return (ptr);
	}
	
	
	
	
	template <class paired, class _comp>
	node<paired>						*bst_increment(node<paired> *ptr, _comp comp)
	{
		if (ptr->right != NULL)
			return (min_value_node(ptr->right));
		else
		{
			
			if (ptr->parent != NULL && !comp(ptr->parent->data.first, ptr->data.first) && ptr->parent->data.first != ptr->data.first)
				return (ptr->parent);
			else
			{
				node<paired>		*aux;
				
				aux = ptr;
				
				while (aux->parent != NULL && comp(aux->parent->data.first, aux->data.first) && aux->parent->data.first != aux->data.first)
					aux = aux->parent;
				if (aux->parent == NULL)
				{
					return (ptr->right);
				}
				return (aux->parent);
			}
		}
	}
	
	
	
	
	template <class paired, class _comp>
	node<paired>						*bst_decrement(node<paired> *ptr, _comp comp)
	{
		if (ptr->_ite == 1)
		{
			return (ptr->parent);
		}
		if (ptr->left != NULL)
			return (max_value_node(ptr->left));
		else
		{
			
			if (ptr->parent != NULL && comp(ptr->parent->data.first, ptr->data.first) && ptr->parent->data.first != ptr->data.first)
				return (ptr->parent);
			else
			{
				node<paired>		*aux;
	
				aux = ptr;
				while (aux->parent != NULL && !comp(aux->parent->data.first , ptr->data.first) && aux->parent->data.first != ptr->data.first)
					aux = aux->parent;
				if (aux->parent != NULL)
					return (aux->parent);
				return (ptr);
			}
		}
	}




	template <class paired, class K, class _comp>
	node<paired>						*bst_search(node<paired> *ptr, K key, _comp comp)
	{
		if (ptr == NULL || ptr->data.first == key)
			return (ptr);

		if (comp(ptr->data.first, key))
			return (bst_search(ptr->right, key, comp));
		return (bst_search(ptr->left, key, comp));
}
#endif