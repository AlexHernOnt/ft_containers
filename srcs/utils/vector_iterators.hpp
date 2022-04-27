/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:48:17 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/27 20:09:43 by ahernand         ###   ########.fr       */
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
			typedef const value_type*						const_pointer_type;
			typedef const value_type&						const_reference_type;

		private:
			pointer_type									m_ptr;

		public:

			//
			//		_______________________________ Operators _______________________________
			//

			//		________		>< Operators

			template <typename K>
			bool					operator<(vector_iterator<K>& ref)
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<=(vector_iterator<K>& ref)
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>(vector_iterator<K>& ref)
			{
				if (&(*m_ptr) > &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>=(vector_iterator<K>& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}
			
			template <typename K>
			bool					operator==(vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) == &(*ref))
					return (true);
				return (false);
			}

			pointer_type	get_pointer() const	{ return (m_ptr); }
			
			template <typename K>
			bool					operator!=(vector_iterator<K> ref) const
			{
				if (m_ptr != ref.get_pointer())
					return (true);
				return (false);
			}



			//		________		+ Operators

			vector_iterator			operator+(const int n)
			{
				pointer_type aux;
				
				aux = m_ptr;
				for (int i = 0; i < n; ++i)
					++aux;
				return (aux);				
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
				pointer_type aux;
				
				aux = m_ptr;
				for (int i = 0; i < n; ++i)
					--aux;
				return (aux);
			}

			template <typename K>
			long			operator-(vector_iterator<K> n) const
			{
				return (m_ptr - n.get_pointer());
			}

			template <typename K>
			long			operator-(vector_iterator<K> n)
			{
				return (m_ptr - n.get_pointer());
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



			//		________		Copy Operator



			template <typename K>
			vector_iterator			&operator=(const vector_iterator<K>& ref)
			{
				this->m_ptr = ref.get_pointer();
				return (*this);
			}



			//		________		Access Operators

			reference_type			operator*()
			{
				return (*m_ptr);
			}

			const_reference_type	operator*() const
			{
				return (*m_ptr);
			}

			reference_type			operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}

			const_reference_type	operator[](const int &idx) const
			{
				return *(m_ptr + idx);
			}

			reference_type			operator->()
			{
				return (m_ptr);
			}

			const_reference_type	operator->() const
			{
				return (m_ptr);
			}			


			//
			//		______________________________ Cons & Dest ______________________________
			//

			template <typename K>
			vector_iterator(vector_iterator<K> a)
			{
				m_ptr = a.get_pointer();
			}
			
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

	template <typename T>
	class reverse_vector_iterator
	{
		public:
			typedef T										value_type;
			typedef value_type*								pointer_type;
			typedef value_type&								reference_type;
			typedef const value_type*						const_pointer_type;
			typedef const value_type&						const_reference_type;

		private:
			pointer_type									m_ptr;

		public:

			//
			//		_______________________________ Operators _______________________________
			//

			//		________		>< Operators

			template <typename K>
			bool					operator==(reverse_vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) == &(*ref))
					return (true);
				return (false);
			}
			
			pointer_type	get_pointer() const	{ return (m_ptr); }
			
			template <typename K>
			bool					operator!=(reverse_vector_iterator<K> ref) const
			{
				if (m_ptr != ref.get_pointer())
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<(reverse_vector_iterator<K>& ref)
			{
				if (&(*m_ptr) > &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<=(reverse_vector_iterator<K>& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>(reverse_vector_iterator<K>& ref)
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>=(reverse_vector_iterator<K>& ref)
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}
			

			//		________		+ Operators

			reverse_vector_iterator			operator+(const int n)
			{
				pointer_type aux;
				
				aux = m_ptr;
				for (int i = 0; i < n; ++i)
					--aux;
				return (aux);				
			}

			reverse_vector_iterator			operator+=(const int n)
			{
				for (int i = 0; i < n; ++i)
					--m_ptr;
				return (*this);				
			}



			//		________		- Operators

			reverse_vector_iterator			operator-(const int n)
			{
				pointer_type aux;
				
				aux = m_ptr;
				for (int i = 0; i < n; ++i)
					++aux;
				return (aux);
			}

			reverse_vector_iterator			operator-=(const int n)
			{
				for (int i = 0; i < n; ++i)
					++m_ptr;
				return (*this);
			}



			////		________		++-- Operators

			reverse_vector_iterator			&operator++()
			{
				m_ptr--;
				return (*this);
			}

			reverse_vector_iterator			operator++(int)
			{
				reverse_vector_iterator		it_aux = *this;
				m_ptr--;
				return (it_aux);
			}

			reverse_vector_iterator			&operator--()
			{
				m_ptr++;
				return (*this);
			}

			reverse_vector_iterator			operator--(int)
			{
				reverse_vector_iterator		it_aux = *this;
				m_ptr++;
				return (it_aux);
			}



			////		________		Copy Operator



			template <typename K>
			reverse_vector_iterator			&operator=(const reverse_vector_iterator<K>& ref)
			{
				this->m_ptr = ref.get_pointer();
				return (*this);
			}



			//		________		Access Operators

			reference_type			operator*()
			{
				return (*m_ptr);
			}

			const_reference_type	operator*() const
			{
				return (*m_ptr);
			}

			reference_type			operator[](const int &idx)
			{
				return *(m_ptr - idx);
			}

			const_reference_type	operator[](const int &idx) const
			{
				return *(m_ptr - idx);
			}

			//reference_type			operator->()
			//{
			//	return (m_ptr);
			//}

			//const_reference_type	operator->() const
			//{
			//	return (m_ptr);
			//}	

			//
			//		______________________________ Cons & Dest ______________________________
			//

			reverse_vector_iterator()
			{
				m_ptr = NULL;
			}
			
			reverse_vector_iterator(pointer_type ptr)
			{
				m_ptr = ptr;
			}

			~reverse_vector_iterator()
			{
			}
	};
}
