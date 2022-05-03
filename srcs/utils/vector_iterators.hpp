/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:48:17 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/03 17:44:00 by ahernand         ###   ########.fr       */
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
			typedef ptrdiff_t               				difference_type;
			typedef value_type*								pointer;
			typedef value_type&								reference;
			typedef const value_type*						const_pointer;
			typedef const value_type&						const_reference;
		private:
			pointer											m_ptr;

		public:

			//
			//		_______________________________ Operators _______________________________
			//

			//		________		>< Operators
			pointer					get_pointer()			const	{ return (m_ptr); }

			template <typename K>
			bool					operator<(const vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<=(const vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>(const vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) > &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>=(const vector_iterator<K>& ref) const
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator==(const vector_iterator<K> ref) const
			{
				if (m_ptr == &(*ref))
					return (true);
				return (false);
			}

			
			template <typename K>
			bool					operator!=(const vector_iterator<K> ref) const
			{
				if (m_ptr != ref.get_pointer())
					return (true);
				return (false);
			}



			//		________		+ Operators

			friend vector_iterator<value_type>			operator+(difference_type n, const vector_iterator &ref)
			{
				return (ref.operator+(n));
			}

			vector_iterator			operator+(const long n) const
			{
				pointer				aux;
				
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
				pointer				aux;
				
				aux = m_ptr;
				for (int i = 0; i < n; ++i)
					--aux;
				return (aux);
			}

			template <typename K>
			long					operator-(vector_iterator<K> n) const
			{
				return (m_ptr - n.get_pointer());
			}

			template <typename K>
			long					operator-(vector_iterator<K> n)
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




			//		________		Access Operators

			reference				operator*()
			{
				return (*m_ptr);
			}

			const_reference			operator*() const
			{
				return (*m_ptr);
			}

			reference				operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}

			const_reference			operator[](const int &idx) const
			{
				return *(m_ptr + idx);
			}

			pointer					operator->(void)
			{
				return (m_ptr);
			}

			const_pointer			operator->(void) const
			{
				return (m_ptr);
			}		




			//		________		Copy Operator

			template <typename K>
			vector_iterator			&operator=(const vector_iterator<K>& ref)
			{
				this->m_ptr = ref.get_pointer();
				return (*this);
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
			
			vector_iterator(pointer ptr)
			{
				m_ptr = ptr;
			}

			~vector_iterator()
			{
			}
	};

	template <typename iterator>
	class reverse_vector_iterator
	{
		public:
			typedef iterator									iterator_type;
			typedef typename iterator::value_type				value_type;
			typedef typename iterator::difference_type			difference_type;
			typedef typename iterator::pointer					pointer;
			typedef typename iterator::reference				reference;

		private:
			iterator											m_base;
		public:

			iterator				base() const
			{
				return (m_base);
			};
			
			//
			//		_______________________________ Operators _______________________________
			//

			//		________		>< Operators

			template <typename K>
			bool					operator==(reverse_vector_iterator<K> ref) const
			{
				if (m_base == ref.base())
					return (true);
				return (false);
			}
			
			template <typename K>
			bool					operator!=(reverse_vector_iterator<K> ref) const
			{
				if (m_base != ref.base())
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<(reverse_vector_iterator<K> ref) const
			{
				if (m_base > ref.base())
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator<=(reverse_vector_iterator<K> ref) const
			{
				if (m_base >= ref.base())
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>(reverse_vector_iterator<K> ref) const
			{
				if (m_base < ref.base())
					return (true);
				return (false);
			}

			template <typename K>
			bool					operator>=(reverse_vector_iterator<K> ref) const
			{
				if (m_base <= ref.base())
					return (true);
				return (false);
			}
			

			//		________				+ Operators
			
			friend reverse_vector_iterator	operator+(difference_type n, reverse_vector_iterator &ref)
			{
				return (ref + n);
			}

			reverse_vector_iterator			operator+(const int n)
			{
				reverse_vector_iterator		a(m_base - n);
				return (a);
			}

			reverse_vector_iterator			operator+=(const int n)
			{
				m_base -= n;
				return (*this);
			}



			////		________				- Operators

			reverse_vector_iterator			operator-(const int n) const
			{
				reverse_vector_iterator		a(m_base + n);
				return (a);
			}

			template <typename K>
			difference_type					operator-(const reverse_vector_iterator<K> &ref)
			{
				return ((m_base - ref.base()) * -1);
			}

			reverse_vector_iterator			operator-=(const int n)
			{
				m_base += n;
				return (*this);
			} 


			//////		________		++-- Operators

			reverse_vector_iterator			&operator++()
			{
				m_base.operator--();
				return (*this);
			}

			reverse_vector_iterator			operator++(int)
			{
				reverse_vector_iterator		it_aux = *this;
				m_base.operator--();
				return (it_aux);
			}

			reverse_vector_iterator			&operator--()
			{
				m_base.operator++();
				return (*this);
			}

			reverse_vector_iterator			operator--(int)
			{
				reverse_vector_iterator		it_aux = *this;
				m_base.operator++();
				return (it_aux);
			}




			//		________		Access Operators

			reference				operator*(void) const
			{
				return (--iterator(m_base)).operator*();
			}

			reference				operator[](const size_t &idx)
			{
				return *(this->operator+(idx));
			}

			pointer					operator->(void) const
			{
				return &operator*();
				//return (m_base);
			}




			//		________		Copy Operator

			template <typename K>
			reverse_vector_iterator			&operator=(const reverse_vector_iterator<K>& ref)
			{
				m_base = ref.base();
				return (*this);
			}



			
			//
			//		______________________________ Cons & Dest ______________________________
			//
  
			reverse_vector_iterator()
			{
				m_base = NULL;
			}

			reverse_vector_iterator(pointer ptr)
			{
				m_base = ptr;
			}

			template <typename K>
			reverse_vector_iterator(reverse_vector_iterator<K> ref)
			{
				m_base = ref.base();
			}

			template <typename K>
			reverse_vector_iterator(const vector_iterator<K> ref)
			{
				m_base = ref;
			}

			~reverse_vector_iterator()
			{
			}
	};
}
