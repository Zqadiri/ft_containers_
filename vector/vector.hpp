/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:50 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/09 10:35:52 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERCTOR_HPP_
#define VERCTOR_HPP_

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

/*
	Namespace refers to various blocks that can be created in a 
	program to group all similar objects, and you can 
	refer to all variables, functions, or classes within a block.
*/

/*
	start with iterators +resize +insert +assign >> htagrourt
*/
namespace   ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			/*-------------------- Member types --------------------------*/
			
			/*The first template parameter
			Type representing the type of data stored in a vector.*/
			typedef T value_type; 
			/*The second template parameter*/
			typedef Allocator	allocator_type;
			/*Type that provides a reference to an element stored in a vector.*/
			typedef	typename allocator_type::reference reference;
			/*Type that provides a random access iterator that can read or
			modify an element of an inverted vector.*/
			typedef typename allocator_type::const_reference const_reference; 
			/*Type that provides a pointer to an element of a vector.*/
			typedef typename allocator_type::pointer pointer;
			/*Type that provides a pointer to an constelement of a vector.*/
			typedef typename allocator_type::const_pointer const_pointer;
			/*Type that provides a random access iterator capable
			of reading an constelement in a vector.*/
			typedef ft::random_access_iterator<value_type>	iterator;
			/*Type that provides a random access iterator capable of reading
			 an constelement in a vector.*/
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			/*Type that provides a random access iterator that can read or modify 
			an element of an inverted vector.*/
			typedef	ft::reverse_iterator<iterator>;
			/*Type that provides a random access iterator capable of reading an 
			constelement of the vector.*/
			typedef	ft::reverse_iterator<const iterator>;
			/*Type that provides the difference between the addresses of two elements in a vector.*/
			typedef ft::iterator_traits<iterator>::difference_type difference_type;
			/*Type that counts the number of elements in a vector.*/
			typedef typename allocator_type::size_type          size_type;

			
			
	};
}

#endif
