/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:50 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/07 21:43:44 by zqadiri          ###   ########.fr       */
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
# include "../utils/iterator.hpp"
# include "../utils/utility.hpp"
# include "../utils/iterator_traits.hpp"
# include "../utils/random_access_iterator.hpp"

/*
	Namespace refers to various blocks that can be created in a 
	program to group all similar objects, and you can 
	refer to all variables, functions, or classes within a block.
*/

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector
	{		
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
			typedef typename ft::random_access_iterator<T>							iterator;
			/*Type that provides a random access iterator capable of reading
			 an constelement in a vector.*/
			typedef typename ft::random_access_iterator<const T>					const_iterator;
			/*Type that provides a random access iterator that can read or modify 
			an element of an inverted vector.*/
			typedef	typename ft::reverse_iterator<iterator> 						reverse_iterator;
			/*Type that provides a random access iterator capable of reading an 
			constelement of the vector.*/
			typedef	typename ft::reverse_iterator<const iterator>					const_reverse_iterator;
			/*Type that provides the difference between the addresses of two elements in a vector.*/
			typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
			/*Type that counts the number of elements in a vector.*/
			typedef typename allocator_type::size_type								size_type;

			//! ------------------------- Constructors ------------------------ !//

			//* Constructs an empty container, with no elements.
			
			explicit Vector (const allocator_type& alloc = allocator_type())
			:  _alloc(alloc), _start(NULL), _end(NULL), _capacity(NULL){
					std::cout << "Empty container" <<std::endl;
			}
			
			//* Constructs a container with n elements. Each element is a copy of val.
			
			explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			:_alloc(alloc)
			{
				std::cout << "fill constructor " << n <<std::endl;
				if (n)
				{
					_start = _alloc.allocate(n);
					_end = _start;
					for(size_t i = 0; i < n; i++)
					{
						_alloc.construct(_end, val);
						_end++;
					}
					_capacity = _end;
				}
			}
			
			// //* Constructs a container with as many elements as the range [first,last), 
			// //* with each element constructed from its corresponding element in that range, in the same order.
			
			template <class InputIterator>
			explicit Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
				:_alloc(alloc)
			{
				
				std::cout << "range constructor" <<std::endl;
				difference_type diff;
				diff = last - first;
				_start = _alloc.allocate(diff);
				_end = _start;
				while (diff)
				{
					_alloc.construct(_end, *(first++));
					diff--;
					_end++;
				}
				_capacity = _end;
			}
			
			//* Constructs a container with a copy of each of the elements in x, in the same order.
			Vector (const Vector& x):_alloc(NULL), _start(NULL), _end(NULL), _capacity(0){
				std::cout << "copy constructor" <<std::endl;
				*this = x;
			}

			//! ------------------------- Destructor ------------------------ !//
			
			~Vector(){
			}
			
			//!------------------------- Member functions -----------------------!//
			
			/*
			** Return iterator to beginning
			*/
		
			iterator begin(){
				return(this->_start);
			}
			const_iterator begin() const{
				return(this->_start);
			}
			
			/*
			** Returns the number of elements in the vector.
			*/

			size_type size() const{
				return (_end - _start);
			}
			
			/*
			** Returns whether the vector is empty
			*/

			bool empty() const{
				if (this->size() == 0)
					return(1);
				return (0);
			}

			/*
			** Returns the maximum number of elements that the vector can hold.
			** USING: allocator::max_size Returns the maximum number of elements,
			** that could potentially be allocated by a call to member allocate.
			*/
	
			size_type max_size() const{
				allocator_type alloc;
				return(alloc.max_size());
			}

			/*
			** Returns an iterator referring to the past-the-end element in the vector container.
			** If the container is empty, this function returns the same as vector::begin
			*/

			iterator end(){
				if (this->size())
					return (_start);
				return(_end);
			}
			const_iterator end() const{
				if (this->size())
					return (_start);
				return (this->_end);
			}

			/*
			** Access first element
			** Returns a reference to the first element in the vector.
			*/

	  		reference front(){
				return(*_start);
			}
			const_reference front() const{
				return(*_start);
			}

			/*
			** Returns a const reference to the last element in the container.
			** If the container is empty, occur undefined behavior.
			*/
		
			reference back () { 
				return (*(_end - 1));
			}
			const_reference back () const {
				return (*(_end - 1));
			}
			
			/*
			** built-in function which inserts new elements before
			** the element at the specified position, effectively increasing
			** the container size by the number of elements inserted
			*/

			reference operator[] (size_type n) {
				return (*(_start + n));
			}
			
			reference at (size_type n){
				return ((*this)[n]);
			} 

			iterator insert (iterator position, const value_type& val)
			{
				
				size_type pos_len = &(*position) - _start;
				//* if the size of the vector is enough
				if (size_type(_capacity - _end) >= this->size() + 1)
				{
					for (size_type i = 0; i < pos_len; i++)
						_alloc.construct(_end - i, *(_end - i - 1));
					_end++;
					_alloc.construct(&(*position), val);
				}
				else
				{
					//* allocate new one
					pointer start;
					pointer end;
					pointer capacity;

					int new_capacity ;
					if (this->size() != 0)
						new_capacity = (this->size() * 2);
					else
						new_capacity = 1; 
					////std::cout << new_capacity << std::endl;
					start = _alloc.allocate(new_capacity);
					end = start + this->size() + 1;
					capacity = start + new_capacity;

					for (size_type i = 0; i < pos_len; i++)
						_alloc.construct(start + i, *(_start + i));
					_alloc.construct(start + pos_len, val);
					// for (size_type i = 0; i < this->size() - pos_len; i++)
					// 	_alloc.construct(end - i - 1, *(_end - i - 1));

					for (size_type i = 0; i < this->size(); i++)
						_alloc.destroy(_start + i);
					
					_start = start;
					_end = end;
					_capacity = capacity;
				}
				return (iterator(_start));
			}
			
			void insert (iterator position, size_type n, const value_type& val); //fill

			template <class InputIterator>
		    void insert (iterator position, InputIterator first, InputIterator last); //range

			//! ------------------------- Assign.Operator ------------------------!//
			
			Vector& operator= (const Vector& x){
				if (x == *this)
					return (*this);
				// insert x element in this 
				return (*this);
			}














			/*
			** _ALLOC:	Default allocator
			** _START: A pointer to the initial element in the block of storage(allocate return value).
			** _END: A pointer to the last element
			*/

			private:
				allocator_type	_alloc;
				pointer			_start;
				pointer			_end;
				pointer			_capacity;
	};
}

#endif
