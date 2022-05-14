/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:55:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/14 20:50:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "iterators/functions.hpp"
# include "iterators/map_iterators.hpp"
# include "iterators/BST.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef	Compare											key_compare;
//			typedef													value_compare;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;

			
			typedef node<value_type>								node_type;
			
			typedef ft::map_iterator<value_type, node_type>			iterator;
			typedef ft::map_iterator<const value_type, node_type>	const_iterator;


//			typedef 												reverse_iterator;
//			typedef 												const_reverse_iterator;
//			typedef 												difference_type;
			typedef size_t											size_type;

			node<value_type>										*_root;
		private:
			allocator_type											_allocator;
			key_compare												_compare;
			size_type												_size;

		public:
		
			/*
			**		_______________________________ Iterators  _______________________________
			*/

			iterator begin()
			{
				return (ft::map_iterator<value_type, node_type>(bst_get_first(_root)));
			}

			const_iterator begin() const
			{
				return (ft::map_iterator<value_type, node_type>(bst_get_first(_root)));

			}

			iterator end()
			{
				return (bst_get_last(_root));
			}

			const_iterator end() const
			{
				return (bst_get_last(_root));
			}




			/*
			**		_______________________________ Capacity  _______________________________
			*/

			bool				empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			size_type			size() const
			{
				return (_size);				
			}

			size_type			max_size() const
			{
				return (_allocator.max_size());
			}




			/*
			**		____________________________ Element Access  ____________________________
			*/

			mapped_type&		operator[] (const key_type& k)
			{
				node_type		*aux;

				aux = bst_search(_root, k);
				if (aux == NULL)
				{
					T		b;
					
					insert(ft::pair<const Key, T>(k, b));
					return (bst_search(_root, k)->data.second);
				}
				return(aux->data.second);
			}




			/*
			**		_______________________________ Modifiers _______________________________
			*/
			//		_________________                 Insert                 _________________

			void	insert (const value_type val)
			{
				if (_size == 0)
				{
					if (_root != NULL)
						delete _root;
					_root = new node<value_type>(val, NULL, 0);
					_root->left = NULL;
					_root->right = new node<value_type>(val, _root, 1);
					_root->parent = NULL;
				}
				else
					new_node(_root, _root, val);
				_size++;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(ft::pair<const Key, T>(first->first, first->second));
			}




			//		_________________                 Erease                 _________________

			void	erase(const key_type &val)
			{
				mapped_type		mapped_aux;
				_root = delete_node(_root, ft::pair<const key_type, mapped_type>(val, mapped_aux), _root);
				--_size;
			}




			/*
			**		______________________________ Operator =  ______________________________
			*/

			map&		operator= (const map& x)
			{
				clear_tree(_root);
				_root = NULL;
				_size = 0;
				insert(x.begin(), x.end());
				return (*this);
			}




			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				Key		a;
				T		b;

				_root = new node<value_type>(ft::pair<const Key, T>(a, b), NULL, 1);
				_allocator = alloc;
				_compare = comp;
				_size = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			{
				insert(first, last);
			}

			map (const map& x)
			{
				insert(x.begin(), x.end());
			}

			~map()
			{
				clear_tree(_root);
			}
	};
}

#endif