/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:38:36 by ahernand          #+#    #+#             */
/*   Updated: 2022/04/26 14:37:30 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTS_HPP__
# define __TESTS_HPP__

void	test_constructors();
void	test_assign();
long	time_now(struct timeval	*start);
void	test_swap_external();
void	test_lexicolographical_compare();
template < typename T>
void print_vector(TYPE::vector<T> aux);
void	test_vector_iterators();
#endif
