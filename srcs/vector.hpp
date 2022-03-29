/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/03/29 20:04:26 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <iostream>
# include <cmath>

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;







		typedef unsigned int					size_type;

		private:
			size_type				_size;
			size_type				_capacity;
			allocator_type			_allocator;
			value_type				*_ptr;

		public:
			
			/*
			**		_______________________________ Capacity  _______________________________
			*/
			
			size_type size() const
			{
				return (_size);				
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




			/*
			**		_______________________________ Modifiers _______________________________
			*/

			void push_back (const value_type& val)
			{
				if (_size != 0)
				{
					value_type				*aux;

					//_capacity = log2();
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
					_ptr = _allocator.allocate(1);
					_ptr[_size] = val;
					_size++;
				}
			}




			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			vector(const T &ref)
			{

			}

			vector() 
			{
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