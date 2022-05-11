/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:55:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/11 18:17:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "utils/functions.hpp"
# include "utils/map_iterators.hpp"
# include "utils/BST.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T>					value_type;
			typedef	Compare									key_compare;
//			typedef											value_compare;
			typedef Alloc									allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef value_type*								pointer;
			typedef const value_type*						const_pointer;
			typedef ft::map_iterator<value_type>			iterator;
//			typedef 										const_iterator;
//			typedef 										reverse_iterator;
//			typedef 										const_reverse_iterator;
//			typedef 										difference_type;
			typedef size_t									size_type;

			node<value_type>								*_root;
		private:
			allocator_type									_allocator;
			key_compare										_compare;
			size_type										_size;
			
		public:
		
			/*
			**		_______________________________ Iterators  _______________________________
			*/

			iterator begin()
			{
				return (ft::map_iterator<value_type>(bst_get_first(_root)));
			}

			iterator end()
			{
				return (ft::map_iterator<value_type>(bst_get_last(_root)));
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




			/*
			**		____________________________ Element Access  ____________________________
			*/

			//mapped_type&		operator[] (const key_type& k)
			//{
			//	_size++;
			//}




			/*
			**		_______________________________ Modifiers _______________________________
			*/

			void	insert (const value_type val)
			{
				if (_size == 0)
				{
					_root = new node<value_type>(val, NULL, 0);
					node<value_type>	*sentinel = new node<value_type>(val, _root, 1);
					_root->right = sentinel;
				}
				else
					new_node(_root, _root, val);
				_size++;
			}

			void	erase(const key_type &val)
			{
				mapped_type		mapped_aux;
				_root = delete_node(_root, ft::pair<const key_type, mapped_type>(val, mapped_aux), _root);
				--_size;
			}

			void	print_in_order()
			{
				in_order(_root);
			}




			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_compare = comp;
				_size = 0;
			}

			~map()
			{
				clear_tree(_root);
			}
	};
}

#endif