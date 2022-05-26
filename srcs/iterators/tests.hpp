/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:38:36 by ahernand          #+#    #+#             */
/*   Updated: 2022/05/26 20:20:49 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

# include <sys/time.h>
# include <stdio.h>
void	ft_every_test();
void	test_constructors();
void	test_assign();
long	time_now(struct timeval	*start);
void	test_swap_external();
void	test_lexicolographical_compare();
template < typename T>
void	print_vector(TYPE::vector<T> aux);
void	test_vector_iterators();
void	test_vector_reverse_iterators();
void	test_vector();
void	test_map();
void	test_stack();

#endif
