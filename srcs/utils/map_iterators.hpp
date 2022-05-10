/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:14 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/10 21:04:53 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_ITERATORS__
# define __MAP_ITERATORS__
# include "BST.hpp"
# include <iostream>

namespace ft
{
	template <class paired>
	class map_iterator
	{
		public:
			typedef node<paired>* 								pointer;
			typedef node<paired>&								reference;

		private:
			node<paired>										*_ptr;

		public:

			//
			//		_______________________________ Operators _______________________________
			//

			////////		________		++-- Operators

			map_iterator				&operator++()
			{
				_ptr = bst_increment(_ptr);
				return (*this);
			}

			//vector_iterator			operator++(int)
			//{
			//	vector_iterator it_aux = *this;
			//	++(*this);
			//	return (it_aux);
			//}




			//		________		Copy Operators


			//template <typename K>
			//map_iterator			&operator=(const map_iterator<K>  g_ptr)
			//{
			//	_ptr = g_ptr;
			//	std::cout << "yes: " << *_ptr << std::endl;
			//	return (*this);
			//}

			paired*		operator->()
			{
				return (&_ptr->data);
			}

			//
			//		______________________________ Cons & Dest ______________________________
			//
			
			map_iterator()
			{
				_ptr = NULL;
			}

			map_iterator(pointer g_ptr)
			{
				_ptr = g_ptr;
			}

			~map_iterator()
			{
			}
	};
	
}

#endif