/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:08:43 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/03 19:56:06 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__
# include <cmath>
# include <iostream>
# include <type_traits>
# include "utils/functions.hpp"
# include "utils/vector_iterators.hpp"

namespace ft
{
	template <typename T, typename Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef value_type&											reference;
			typedef const value_type&									const_reference;
			typedef value_type*											pointer;
			typedef const value_type*									const_pointer;
			typedef	ft::vector_iterator<T>								iterator;
			typedef	ft::vector_iterator<const T>						const_iterator;
			typedef ft::reverse_vector_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_vector_iterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t               							difference_type;
			typedef size_t												size_type;

		private:
			size_type													_size;
			size_type													_capacity;
			allocator_type												_allocator;
			value_type													*_ptr;

		public:

			/*
			**		_______________________________ Iterators _______________________________
			*/

			iterator begin()
			{
				return (vector_iterator<T>(_ptr));
			}

			const_iterator begin() const
			{
				return (vector_iterator<const T>(_ptr));
			}

			iterator end()
			{
				return (vector_iterator<T>(_ptr + _size));
			}

			const_iterator end() const
			{
				return (vector_iterator<const T>(_ptr + _size));
			}



			reverse_iterator rbegin()
			{
				return (reverse_iterator(_ptr + (_size)));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_ptr + (_size)));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(_ptr));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_ptr));
			}




			/*
			**		_______________________________ Capacity ________________________________
			*/

			size_type	size() const
			{
				return (_size);
			}

			size_type	max_size() const
			{
				return (_allocator.max_size());
			}

			//When in resize: n < (_capacity *2), ej(80 < 128) the reisize goes to that 128 instead of the 80
			void		resize (size_type n, value_type val = value_type())
			{
				if (n <= _size)
					_size = n;
				else
				{
					if (n > _capacity)
						reserve(n);

					while (_size < n)
					{
						_ptr[_size] = val;
						_size++;
					}
				}
			}

			size_type	capacity() const
			{
				return (_capacity);
			}

			bool empty() const
			{
				if (_size == 0)
					return (true);
				return (false);
			}

			void reserve (size_type n)
			{
				if (n > max_size())
					std::length_error("Error: reserve: trying to reserve more memory than possible by system.");
				if (n > _capacity)
				{
					value_type				*aux;

					_capacity = n;

					aux = _allocator.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
					{
						aux[i] = _ptr[i];
					}
					if (_ptr != NULL)
					{
						_allocator.deallocate(_ptr, _capacity);
					}
					_ptr = aux;
				}
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


			reference front()
			{
				return (_ptr[0]);
			}
			
			const_reference front() const
			{
				return (_ptr[0]);
			}


			reference back()
			{
				return (_ptr[_size - 1]);
			}
			
			const_reference back() const
			{
				return (_ptr[_size - 1]);
			}




			/*
			**		_______________________________ Modifiers _______________________________
			*/

			//		_________________                 Assign                _________________


			void assign (size_type n, const value_type& val)
			{
				reserve(n);
				_size = n;
				for (size_type i = 0; i < n; ++i)
					_ptr[i] = val;
			}


			template <class InputIterator>
			void assign (typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
			{
				size_type			i;
				InputIterator		it;
						
				i = 0;
				it = first;
				while (it != last)
				{
					it++;
					i++;
				}
				if (i != 0)
				{
					reserve(i);
					_size = i;
					for (size_type j = 0; j < i; ++j)
					{
						_ptr[j] = *first;
						first++;
					}
				}
			}


			//		_________________               Push Back               _________________
			
			void	push_back (const value_type& val)
			{
				if (_capacity == 0)
				{
					_ptr = _allocator.allocate(1);
					_ptr[_size] = val;
					_capacity++;
				}
				else if (_size == _capacity)
				{
					reserve(_capacity * 2);
					_ptr[_size] = val;
				}
				else
					_ptr[_size] = val;
				_size++;
			}

			//		_________________               Push Back               _________________

			void pop_back()
			{
				if (_size >= 1)
					_size--;
			}




			//		_________________                 Insert                 _________________
			
			iterator insert (iterator position, const value_type& val)
			{
				iterator	it;
				iterator	ite;
				size_t		i;

				it = begin();
				ite = end();
				ite++;
				i = 0;

				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					reserve(_size + 1);			// Too slow 1 to 1, expands only 1 time each, have to expand to x2 duuuhhh
					_size++;
					size_t a = _size - 1;
					size_t b = _size - 2;

					while (a != i)
					{
						_ptr[a] = _ptr[b];
						a--;
						b--;
					}
					_ptr[i] = val;
					
					it = begin();
					for (size_t j = 0; j < i; ++j)
					{
						it++;
					}
					return (it);
				}
				return (position);
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				iterator	it;
				iterator	ite;
				size_type	i;

				it = begin();
				ite = end();
				ite++;
				i = 0;

				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					reserve(_size + n);
					_size = _size + n;
					size_type a = i + n;
					size_type b = i;

					while (a != _size)
					{
						_ptr[a] = _ptr[b];
						a++;
						b++;
					}
					a = i;
					while (a < i + n)
					{
						_ptr[a] = val;
						a++;
					}
				}
			}


			template <class InputIterator>
			void	insert(iterator position, InputIterator first, typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last) 
			{
				size_type		size_iterators;
				iterator		it = begin();
				iterator		ite = end();
				size_t			i;

				i = 0;
				ite++;
				size_iterators = 0;
				while (it != position && it != ite)
				{
					it++;
					i++;
				}
				if (it != ite)
				{
					InputIterator first_aux = first;
					while (first_aux != last)
					{
						first_aux++;
						size_iterators++;
					}
					reserve(_size + size_iterators);
					_size = _size + size_iterators;
					value_type		store[_size - i - size_iterators];
					size_t a = 0;
					size_t b = i;
					while (b != _size)
					{
						store[a] = _ptr[b];
						a++;
						b++;
					}
					a = i + size_iterators;
					b = 0;
					while (a != _size)
					{
						_ptr[a] = store[b];
						++a;
						++b;
					}
					a = i;
					while (a < i + size_iterators && first != last)
					{
						_ptr[a] = *first;
						first++;
						a++;
					}
				}
			}




			//		_________________                 Erease                 _________________

			iterator erase (iterator position)
			{
				iterator	it = begin();
				iterator	ite = end();
				size_t		delete_pos = 0;
				size_t		a;

				while (it != position && it != ite)
				{
					delete_pos++;
					it++;
				}
				if (it != ite)
				{
					a = delete_pos;
					while (a + 1 != _size)
					{
						_ptr[a] = _ptr[a + 1];
						a++;
					}
					_size -= 1;
					return (it);
				}
				return (it);				
			}

			iterator erase (iterator first, iterator last)
			{
				iterator	it = begin();
				iterator	ite = end();
				size_type	n_first = 0;
				size_type	n_last = 0;
				size_type	a;
				size_type	b;

				ite++;
				while (it != first && it != ite)
				{
					n_first++;
					it++;
				}
				it = begin();
				while (it != last && it != ite)
				{
					n_last++;
					it++;
				}
				if (it != ite)
				{
					a = n_first;
					b = n_last;
					while (b != _size)
					{
						_ptr[a] = _ptr[b];
						b++;
						a++;
					}
					_size -= n_last - n_first;
					return (begin() + n_first);
				}
				return (it);				
			}




			//		_________________                 Clear                  _________________


			void clear()
			{
				_size = 0;
			}




			//		_________________                 Swap                   _________________

			void	swap(vector& x)
			{
				vector<T, allocator_type>			aux;

				aux.complete_memory_copy(*this);
				this->complete_memory_copy(x);
				x.complete_memory_copy(aux);
				aux._capacity = 0;
			}




			/*
			**		_______________________________ Allocator _______________________________
			*/

			allocator_type get_allocator() const
			{
				return (_allocator);
			}




			/*
			**		_______________________________ Operator= _______________________________
			*/

			vector&		operator=(const vector& x)
			{
				if (_capacity != 0)
				{
					_allocator.deallocate(_ptr, _capacity);
					_ptr = NULL;
				}
				_size = 0;
				_capacity = 0;
				reserve(x.capacity());
				for (size_t i = 0; i < x.size(); i++)
					_ptr[i] = x[i];
				_size = x.size();
				_capacity = x.capacity();
				return (*this);
			}




			/*
			**		______________________________ Cons & Dest ______________________________
			*/

			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_ptr = NULL;
				_size = 0;
				_capacity = 0;
				_allocator = alloc;
			}


			explicit vector (size_type n, const value_type& val = value_type(),
								const allocator_type& alloc = allocator_type())
			{
				_size = n;
				_capacity = n;
				_allocator = alloc;
				_ptr = _allocator.allocate(_capacity);
				for (size_type i = 0; i < n; ++i)
					_allocator.construct(&_ptr[i], val);
			}


			template <class InputIterator>
			vector (typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type())
			{

				size_type		i = 0;
				InputIterator	it = first;

				_ptr = NULL;
				_size = 0;
				_capacity = 0;
				_allocator = alloc;
				while (it != last) 
				{
					it++;
					i++;
				}
				if (i != 0)
				{
					reserve(i);
					for (size_type j = 0; j < i; ++j)
					{
						_ptr[j] = *first;
						first++;
					}
				}
				_size = i;
			}


			vector (const vector& x)
			{
				_size = 0;
				_capacity = 0;
				_ptr = NULL;
				reserve(x.capacity());
				for (size_t i = 0; i < x.size(); i++)
					_ptr[i] = x[i];
				_size = x.size();
				_capacity = x.capacity();
			}


			~vector()
			{
				if (_capacity != 0)
					_allocator.deallocate(_ptr, _capacity);
			}

			private:
				void	complete_memory_copy(vector	&x)
				{
					_size = x.size();
					_capacity = x.capacity();
					_allocator = x.get_allocator();
					_ptr = x._ptr;
				}
	};


	/*
	**		______________________________ Operators ______________________________
	*/

	template <class T, class Allocator>
	bool operator==(const vector<T, Allocator> &lhs, const vector<T, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())	
			return (false);
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return (false);
		}
		return (true);
	}


	template <class T, class Allocator>
	bool operator!= (const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (!(lhs == rhs));
	}


	template <class T, class Allocator>
	bool operator<(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return (true);
			if (lhs[i] > rhs[i])
				return (false);
		}
		if (lhs.size() < rhs.size())	
			return (true);
		return (false);
	}


	template <class T, class Allocator>
	bool operator>(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return (true);
			if (lhs[i] < rhs[i])
				return (false);
		}
		if (lhs.size() > rhs.size())	
			return (true);
		return (false);
	}


	template <class T, class Allocator>
	bool operator<=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}

	template <class T, class Allocator>
	bool operator>=(const vector<T, Allocator>& lhs, const vector<T, Allocator>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}

	template <class T, class Allocator>
	void swap (vector<T, Allocator>& x, vector<T, Allocator>& y)
	{
		x.swap(y);
	}
}
#endif