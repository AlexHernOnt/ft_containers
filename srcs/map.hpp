/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:55:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/05 18:07:05 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_HPP__
# define __MAP_HPP__
# include <iostream>
# include "utils/functions.hpp"
# include "utils/AVL.hpp"

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
//			typedef 										iterator;
//			typedef 										const_iterator;
//			typedef 										reverse_iterator;
//			typedef 										const_reverse_iterator;
//			typedef 										difference_type;
			typedef size_t									size_type;

		private:
			allocator_type									_allocator;
			node<value_type>								*_root;
			key_compare										_compare;
			size_type										_size;
			
		public:

			/*
			**		_______________________________ Capacity  _______________________________
			*/

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
					_root = new node<value_type>(val);
				else
					new_node(&_root, val);
				_size++;
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
	};
}

#endif