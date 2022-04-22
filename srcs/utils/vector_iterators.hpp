/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:48:17 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/22 17:44:02 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
	template <typename T>
	class vector_iterator
	{
		public:
			typedef T										value_type;
			typedef value_type*								pointer_type;
			typedef value_type&								reference_type;
			typedef const value_type&						const_reference_type;
			typedef const value_type*						const_pointer_type;

		private:
			pointer_type									m_ptr;

		public:

			//
			//		_______________________________ Operators _______________________________
			//

			//		________		>< Operators

			bool					operator<(vector_iterator& ref)
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			bool					operator<=(vector_iterator& ref)
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}

			bool					operator>(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}

			bool					operator>=(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}




			//		________		+ Operators

			vector_iterator			operator+(const int n)
			{
				for (int i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}

			vector_iterator			operator+=(const int n)
			{
				for (int i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}



			//		________		- Operators

			vector_iterator			operator-(const int n)
			{
				for (int i = 0; i < n; ++i)
					--m_ptr;
				return (*this);
			}

			vector_iterator			operator-=(const int n)
			{
				for (int i = 0; i < n; ++i)
					--m_ptr;
				return (*this);
			}



			//		________		++-- Operators

			vector_iterator			&operator++()
			{
				m_ptr++;
				return (*this);
			}

			vector_iterator			operator++(int)
			{
				vector_iterator it_aux = *this;
				++(*this);
				return (it_aux);
			}

			vector_iterator			&operator--()
			{
				m_ptr--;
				return (*this);
			}

			vector_iterator			operator--(int)
			{
				vector_iterator it_aux = *this;
				--(*this);
				return (it_aux);
			}

			vector_iterator			operator=(const vector_iterator& ref)
			{
				this->m_ptr = ref.m_ptr;
				return (*this);
			}

			ft::vector_iterator<const T>		operator=(ft::vector_iterator<int> ref)
			{
				this->m_ptr = ref.m_ptr;
				return (*this);
			}

			reference_type			operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}

			bool					operator==(vector_iterator& ref) const
			{
				if (&(*m_ptr) == &(*ref))
					return (true);
				return (false);
			} 

			bool					operator!=(vector_iterator ref) const
			{
				if (m_ptr != ref.m_ptr)
					return (true);				
				return (false);				
			}

			reference_type			operator*()
			{
				return (*m_ptr);
			}

			reference_type			operator->()
			{
				return (m_ptr);
			}


			//
			//		______________________________ Cons & Dest ______________________________
			//

			vector_iterator()
			{
				m_ptr = NULL;
			}

			vector_iterator(pointer_type ptr)
			{
				m_ptr = ptr;
			}

			~vector_iterator()
			{
			}
	};
}
