/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/03/31 19:17:59 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <iostream>
# include <cmath>

namespace ft
{
	template <typename vector>
	class vector_iterator
	{
		public:
			typedef typename vector::value_type				value_type;
			typedef value_type*								pointer_type;
			typedef value_type&								reference_type;

		private:
			pointer_type									m_ptr;

		public:

			/*
			**		_______________________________ Operators _______________________________
			*/

			vector_iterator operator=(const vector_iterator& ref)
			{
				this->m_ptr = ref.m_ptr;
				return (*this);				
			} 
			
			vector_iterator &operator++()
			{
				m_ptr++;
				return (*this);
			}

			vector_iterator operator++(int)
			{
				vector_iterator it_aux = *this;
				++(*this);
				return (it_aux);
			}

			vector_iterator &operator--()
			{
				m_ptr--;
				return (*this);
			}

			vector_iterator operator--(int)
			{
				vector_iterator it_aux = *this;
				--(*this);
				return (it_aux);
			}

			reference_type operator[](const int &idx)
			{
				return *(m_ptr + idx);
			}




			bool operator==(const vector_iterator& ref) const
			{
				if (m_ptr == ref)
					return (true);				
				return (false);				
			} 

			bool operator!=(const vector_iterator& ref) const
			{
				if (m_ptr != ref.m_ptr)
					return (true);				
				return (false);				
			}

			reference_type operator*()
			{
				return (*m_ptr);
			}
			
			reference_type operator->()
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
	};
	

	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T										value_type;
			typedef Allocator								allocator_type;
			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef	vector_iterator<vector<T> >				iterator;
		//	typedef	vector_const_iterator<vector<T> >		const_iterator;



			typedef size_t									size_type;

		private:
			size_type										_size;
			size_type										_capacity;
			allocator_type									_allocator;
			value_type										*_ptr;

		public:

			/*
			**		_______________________________ Iterators _______________________________
			*/

			iterator begin()
			{
				if (!empty())
					return (vector_iterator<vector<T> >(_ptr));
			}

			// const_iterator begin()
			// {
			// 	if (!empty())
			// 		return (vector_iterator<vector<T> >(_ptr));
			// }

			iterator end()
			{
				return (vector_iterator<vector<T> >(_ptr + _size));
			}




			/*
			**		_______________________________ Capacity ________________________________
			*/

			size_type size() const
			{
				return (_size);
			}
			
			size_type max_size	() const
			{
				return (_allocator.max_size());
			}

			size_type capacity() const
			{
				return (_capacity);
			}

			//		Implement resize bro, are you retarded ???

			bool empty() const
			{
				return (_size == 0);
			}




			/*
			**		_____________________________ Element access ____________________________
			*/

			reference operator[] (size_type n)
			{
				return (_ptr[n]);
			}

			const_reference operator[] (size_type n) const
			{
				return (_ptr[n]);
			}


			reference at(size_type n)
			{
				if (n < size())
					return (_ptr[n]);
				else
					throw (std::out_of_range("Error: at: trying to access out of bound element."));
			}	

			const_reference	at(size_type n) const
			{
				if (n < size())
					return (_ptr[n]);
				else
					throw (std::out_of_range("Error: at: trying to access out of bound element."));
			}

			/*
			**		_______________________________ Modifiers _______________________________
			*/

			void	push_back (const value_type& val)
			{
				if (_capacity == 0)
				{
					_ptr = _allocator.allocate(1);
					_ptr[_size] = val;
					_size++;
					_capacity++;
				}
				else if (_size == _capacity)
				{
					value_type				*aux;

					_capacity *= 2;
					aux = _allocator.allocate(_capacity);
					for (unsigned int i = 0; i < _size; i++)
						aux[i] = _ptr[i];

					_allocator.deallocate(_ptr, _capacity);
					_ptr = aux;
					_ptr[_size] = val;
					_size++;
				}
				else
				{
					_ptr[_size] = val;
					_size++;
				}
			}




			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			vector(const T &ref)
			{
				_size = ref.size();
			}

			vector() 
			{
				_ptr = NULL;
				_size = 0;
				_capacity = 0;
			}

			~vector()
			{
				if (_capacity != 0)
					_allocator.deallocate(_ptr, _capacity);
			}
	};
}


void	ft_leaks()
{
	system("leaks ft_containers");
}

#endif