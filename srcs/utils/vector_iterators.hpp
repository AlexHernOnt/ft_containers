/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:48:17 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/18 17:59:41 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template <typename vector>
	class vector_iterator
	{
		public:
			typedef typename vector::value_type				value_type;
			typedef value_type*								pointer_type;
			typedef value_type&								reference_type;
			typedef const value_type&						const_reference_type;

		private:
			pointer_type									m_ptr;

		public:

			/*
			**		_______________________________ Operators _______________________________
			*/

			//		________	>< Operators

			bool			operator<(vector_iterator& ref)
			{
				if (&(*m_ptr) < &(*ref))
					return (true);
				return (false);
			}

			bool			operator<=(vector_iterator& ref)
			{
				if (&(*m_ptr) <= &(*ref))
					return (true);
				return (false);
			}

			bool			operator>(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}

			bool			operator>=(vector_iterator& ref)
			{
				if (&(*m_ptr) >= &(*ref))
					return (true);
				return (false);
			}
			



			//		________	+ Operators

			vector_iterator		operator+(const int n)
			{
				for (int i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}

			vector_iterator		operator+=(const int n)
			{
				for (int i = 0; i < n; ++i)
					++m_ptr;
				return (*this);				
			}



			//		________	- Operators

			vector_iterator		operator-(const int n)
			{
				for (int i = 0; i < n; ++i)
					--m_ptr;
				return (*this);				
			}

			vector_iterator		operator-=(const int n)
			{
				for (int i = 0; i < n; ++i)
					--m_ptr;
				return (*this);				
			}



			//		________	++-- Operators

			vector_iterator		&operator++()
			{
				m_ptr++;
				return (*this);
			}

			vector_iterator		operator++(int)
			{
				vector_iterator it_aux = *this;
				++(*this);
				return (it_aux);
			}

			vector_iterator		&operator--()
			{
				m_ptr--;
				return (*this);
			}

			vector_iterator		operator--(int)
			{
				vector_iterator it_aux = *this;
				--(*this);
				return (it_aux);
			}
			
			vector_iterator		operator=(const vector_iterator& ref)
			{
				this->m_ptr = ref.m_ptr;
				return (*this);				
			} 

			reference_type		operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}

			bool				operator==(vector_iterator& ref) const
			{
				if (&(*m_ptr) == &(*ref))
					return (true);
				return (false);
			} 

			bool				operator!=(vector_iterator& ref) const
			{
				if (m_ptr != ref.m_ptr)
					return (true);				
				return (false);				
			}

			reference_type		operator*()
			{
				return (*m_ptr);
			}

			reference_type		operator->()
			{
				return (m_ptr);
			}


			/*
			**		______________________________ Cons & Dest ______________________________
			*/

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



	//template <typename vector>
	//class vector_const_iterator : public vector_iterator<vector>
	//{
	//	public:
	//		typedef const typename vector::value_type		value_type;
	//		typedef value_type*								pointer_type;
	//		typedef value_type&								reference_type;
	//		typedef const value_type&						const_reference_type;

	//	private:
	//		pointer_type									m_ptr;

	//	public:
	//		vector_const_iterator		operator=(vector_const_iterator& ref)
	//		{
	//			this->m_ptr = ref.m_ptr;
	//			return (*this);				
	//		}

	//		vector_const_iterator		operator=(vector_iterator<vector>& ref)
	//		{
	//			this->m_ptr = ref.m_ptr;
	//			return (*this);				
	//		} 

	//		reference_type		operator[](const int &idx)
	//		{
	//			return *(m_ptr + idx);
	//		}

	//		reference_type		operator*()
	//		{
	//			return (*m_ptr);
	//		}

	//		reference_type		operator->()
	//		{
	//			return (m_ptr);
	//		}


	//		/*
	//		**		______________________________ Cons & Dest ______________________________
	//		*/

	//		vector_const_iterator()
	//		{
	//			m_ptr = NULL;
	//		}

	//		vector_const_iterator(pointer_type ptr)
	//		{
	//			m_ptr = ptr;
	//		}

	//		~vector_const_iterator()
	//		{
	//		}
	//};
}
