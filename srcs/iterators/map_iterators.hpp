/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:19:14 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/25 16:50:39 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAP_ITERATORS__
# define __MAP_ITERATORS__
# include "BST.hpp"

namespace ft
{
	template <class _paired, class node_type, class _comp>
	class map_iterator
	{
		
		public:
			typedef node_type* 								pointer;
			typedef node_type&								reference;
			typedef _paired									paired;

		protected:
			node_type										*_ptr;
			_comp											_compare;
		public:

			//
			//		_______________________________ Operators _______________________________
			//




			//		________		>< Operators




			bool					operator!=(const map_iterator &ref) const
			{
				if (this->_ptr != ref._ptr)
				{
					return (true);
				}
				return (false);
			}




			bool					operator==(const map_iterator &ref) const
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
				_ptr = bst_increment(_ptr, _compare);
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
				_ptr = bst_decrement(_ptr, _compare);
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




			map_iterator					&operator=(const map_iterator &ref)
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
				if (_ptr != NULL)
					return (&_ptr->data);
				return (NULL);
			}








			//
			//		______________________________ Cons & Dest ______________________________
			//

			operator		map_iterator<const _paired, node_type, _comp>(void) const
			{
				return (map_iterator<const _paired, node_type, _comp>(this->_ptr));
			}

			map_iterator()
			{
				_ptr = NULL;
			}

			map_iterator(node_type *src)
			{
				_ptr = src;
			}
			
			map_iterator(const map_iterator &src)
			{
				*this = src;
			}

			~map_iterator()
			{
			}
	};















































































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




			template <typename K, typename N, typename C>
			reverse_map_iterator(map_iterator<K, N, C> a)
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