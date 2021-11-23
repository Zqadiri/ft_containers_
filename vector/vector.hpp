/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:50 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/23 19:13:44 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

# include <vector>
# include <limits>
# include <iterator>
# include <string>
# include <iostream>
# include <algorithm>
# include <memory>
# include "../utils/iterator_traits.hpp"
# include "../utils/random_access_iterator.hpp"
# include "../utils/reverse_iterator.hpp"

/*
	Namespace refers to various blocks that can be created in a 
	program to group all similar objects, and you can 
	refer to all variables, functions, or classes within a block.
*/

/*
	start with iterators +resize +insert +assign >> htagrourt
*/

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector
	{
		private:
			T*			_array;
			size_t		_size;
			size_t		_capacity;
			Allocator	_alloc;
			
		public:
			//!-------------------- Member types ------------------------!//
			/*The first template parameter
			Type representing the type of data stored in a vector.*/
			typedef T																value_type; 
			/*The second template parameter*/
			typedef Allocator														allocator_type;
			/*Type that provides a reference to an element stored in a vector.*/
			typedef	typename allocator_type::reference								reference;
			/*Type that provides a random access iterator that can read or
			modify an element of an inverted vector.*/
			typedef typename allocator_type::const_reference 						const_reference; 
			/*Type that provides a pointer to an element of a vector.*/
			typedef typename allocator_type::pointer 								pointer;
			/*Type that provides a pointer to an constelement of a vector.*/
			typedef typename allocator_type::const_pointer 							const_pointer;
			/*Type that provides a random access iterator capable
			of reading an constelement in a vector.*/
			typedef typename std::__is_random_access_iterator<value_type>			iterator;
			/*Type that provides a random access iterator capable of reading
			 an constelement in a vector.*/
			typedef typename std::__is_random_access_iterator<const value_type>		const_iterator;
			/*Type that provides a random access iterator that can read or modify 
			an element of an inverted vector.*/
			typedef	typename std::reverse_iterator<iterator> 						reverse_iterator;
			/*Type that provides a random access iterator capable of reading an 
			constelement of the vector.*/
			typedef	typename std::reverse_iterator<const iterator>					const_reverse_iterator;
			/*Type that provides the difference between the addresses of two elements in a vector.*/
			// typedef typename std::iterator_traits<iterator>::difference_type	difference_type;
			/*Type that counts the number of elements in a vector.*/
			typedef typename allocator_type::size_type								size_type;

			//! ------------------------- Constructors ------------------------ !//

			//* Constructs an empty container, with no elements.
			explicit Vector (const allocator_type& alloc = allocator_type())
			: _array(NULL),_size(0),_capacity(0), _alloc(alloc){
				    std::cout << "Empty container" <<std::endl;
			}
			//* Constructs a container with n elements. Each element is a copy of val.
			explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			:_size(n), _capacity(n), _alloc(alloc) 
			{
				if (n)
				{
					this->_array = this->_alloc.allocate(n);
					for(int i = 0; i < n; i++)
						this->_alloc.construct(this->_array[i], val);
				}
			}
			//*Constructs a container with as many elements as the range [first,last), 
			//* with each element constructed from its corresponding element in that range, in the same order.
			template <class InputIterator>
			Vector ( first, InputIterator last,
				 const allocator_type& alloc = allocator_type()) :_alloc(alloc)
			{
				//?[first, last)
				(void)first;
				(void)last;
			}
			//* Constructs a container with a copy of each of the elements in x, in the same order.
			Vector (const Vector& x);

			//! ------------------------- Destructor ------------------------ !//
			~Vector(){
			}
			//! ------------------------- Assign.Operator ------------------------!//
			Vector& operator= (const Vector& x);
				
	};
}

#endif
