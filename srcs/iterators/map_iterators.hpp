/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:14 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/21 19:25:29 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_ITERATORS__
# define __MAP_ITERATORS__
# include "BST.hpp"
# include <iostream>

namespace ft
{
	template <class _paired, class node_type>
	class map_iterator
	{
		public:
			typedef node_type* 								pointer;
			typedef node_type&								reference;
			typedef _paired									paired;


			node_type										*_ptr;
		private:

		public:

			//
			//		_______________________________ Operators _______________________________
			//




			//		________		>< Operators




			template <typename K, typename N>
			bool					operator!=(const map_iterator<K, N> &ref) const
			{
				if (this->_ptr != ref._ptr)
				{
					return (true);
				}
				return (false);
			}




			//template <typename K>
			//bool					operator!=(const ft::reverse_map_iterator<k> &ref) const
			//{
			//	if (*this != ref.base())
			//	{
			//		return (true);
			//	}
			//	return (false);
			//}




			template <typename K, typename N>
			bool					operator==(const map_iterator<K, N> &ref) const
			{
				if (this->_ptr == ref._ptr)
				{
					return (true);
				}
				return (false);
			}








			/*
			**		___________________		inc / dec oepreators     ___________________
			*/




			map_iterator					&operator++()
			{
				_ptr = bst_increment(_ptr);
				return (*this);
			}

			map_iterator					operator++(int)
			{
				map_iterator it_aux = *this;
				++(*this);
				return (it_aux);
			}

			map_iterator					&operator--()
			{
				_ptr = bst_decrement(_ptr);
				return (*this);
			}

			map_iterator					operator--(int)
			{
				map_iterator it_aux = *this;
				--(*this);
				return (it_aux);
			}








			/*
			**		___________________		Operator=     ___________________
			*/




			template <typename K, typename N>
			map_iterator					&operator=(const map_iterator<K, N> &ref)
			{
				this->_ptr = ref._ptr;
				return (*this);
			}








			/*
			**		___________________		Access Opereator     ___________________
			*/




			paired&							operator*() const
			{
				return (_ptr->data);  
			}

			paired*							operator->() const
			{
				return (&_ptr->data);
			}








			//
			//		______________________________ Cons & Dest ______________________________
			//




			template <typename T, typename _node_type>
			map_iterator(_node_type *src)
			{
				this->_ptr = src;
			}

			template <typename T, typename _node_type>
			map_iterator(const map_iterator  &src)
			{
				*this = src;
			}













			map_iterator()
			{
				_ptr = NULL;
			}

			map_iterator(pointer	 ptr)
			{
				_ptr = ptr;
			}

			~map_iterator()
			{
			}
	};















































			//template <typename K, typename N>
			//map_iterator(N a)
			//{
			//	_ptr = a._ptr;
			//}

			//template <typename K, typename N>
			//map_iterator(map_iterator<_paired, N> a)
			//{
			//	_ptr = a._ptr;
			//}


















































	template <class iterator>
	class reverse_map_iterator
	{
		public:
			typedef typename iterator::pointer						pointer;
			typedef typename iterator::reference					reference;
			typedef typename iterator::paired						paired;

			iterator												_base;
		private:

		public:




			//
			//		_______________________________ Base      _______________________________
			//

			iterator				base() const
			{
				return (_base);
			}








			//
			//		_______________________________ Operators _______________________________
			//




			//		________		>< Operators





			template <typename K>
			bool					operator!=(const reverse_map_iterator<K> &ref) const
			{
				if (_base != ref.base())
					return (true);
				return (false);
			}


			template <typename K>
			bool					operator==(const reverse_map_iterator<K> &ref) const
			{
				if (_base == ref)
					return (true);
				return (false);
			}








			/*
			**		___________________		inc / dec oepreators     ___________________
			*/




			reverse_map_iterator					&operator++()
			{
				--_base;
				return (*this);
			}

			reverse_map_iterator					operator++(int)
			{
				reverse_map_iterator it_aux = *this;
				--_base;
				return (it_aux);
			}

			reverse_map_iterator					&operator--()
			{
				++_base;
				return (*this);
			}

			reverse_map_iterator					operator--(int)
			{
				reverse_map_iterator it_aux = *this;
				++(_base);
				return (it_aux);
			}








			/*
			**		___________________		Operator=     ___________________
			*/




			template <typename K>
			reverse_map_iterator					&operator=(const reverse_map_iterator<K> &ref)
			{
				_base = ref.base();
				return (*this);
			}








			/*
			**		___________________		Access Opereator     ___________________
			*/




			paired&							operator*() const
			{
				iterator					aux;

				aux = _base;
				aux--;
				return (*aux);
			}

			paired*							operator->() const
			{
				return  &operator*();
			}








			//
			//		______________________________ Cons & Dest ______________________________
			//




			template <typename K, typename N>
			reverse_map_iterator(map_iterator<K, N> a)
			{
				_base = a;
			}

			template <typename K>
			reverse_map_iterator(reverse_map_iterator<K> a)
			{
				_base = a.base();
			}

			reverse_map_iterator()
			{
				_base = NULL;
			}

			reverse_map_iterator(pointer	 ptr)
			{
				_base = ptr;
			}

			~reverse_map_iterator()
			{
			}
	};

}

#endif