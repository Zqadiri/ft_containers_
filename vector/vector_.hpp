/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:13:42 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/20 23:42:08 by zqadiri          ###   ########.fr       */
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

			explicit Vector (const allocator_type& alloc = allocator_type())
			: _start(NULL), _size(0), _capacity(0), _end(NULL),  _alloc(alloc){
			}

			explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			:_alloc(alloc)
			{
				if (n)
				{
					_start = _alloc.allocate(n);
					_end = _start;
					for(size_t i = 0; i < n; i++)
					{
						_alloc.construct(_end, val);
						_end++;
					}
					_capacity = _size = n;
				}
			}
			
			template <class InputIterator>
			explicit Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				 typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
				:_alloc(alloc)
			{
				difference_type diff;
				diff = last - first;
				_start = _alloc.allocate(diff);
				_capacity = _size = diff;
				_end = _start;
				while (diff)
				{
					_alloc.construct(_end, *(first++));
					diff--;
					_end++;
				}
			}

			Vector (const Vector& x):_start(NULL), _size(0), _capacity(0), _end(NULL){
				*this = x;
			}

			iterator begin(){
				return(this->_start);
			}
			const_iterator begin() const{
				return(this->_start);
			}

			iterator end(){
				return(_end);
			}
			const_iterator end() const{
				return (this->_end);
			}

			reverse_iterator rbegin() {
				return (reverse_iterator(this->end()));
			}
			
			const_reverse_iterator rbegin() const{
				return (reverse_iterator(this->end()));		
			}

			reverse_iterator rend(){
				return (reverse_iterator(this->begin()));		
			}
			
			const_reverse_iterator rend() const{
				return (reverse_iterator(this->begin()));		
			}

			size_type size() const{
				return (_size);
			}

			size_type capacity() const{
				return (_capacity);
			}

			size_type max_size() const{
				allocator_type alloc;
				return(alloc.max_size());
			}

			reference at (size_type n){
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return ((*this)[n]);
			} 
			
			const_reference at (size_type n) const{
				if (n >= this->size())
					throw (std::out_of_range("vector"));
				return ((*this)[n]);
			}

			reference operator[] (size_type n) const {
				return (*(_start + n));
			}

			reference back () { 
				return (*(_end - 1));
			}
			
			const_reference back () const {
				return (*(_end - 1));
			}

			reference front(){
				return(*_start);
			}
			const_reference front() const{
				return(*_start);
			}
			
			void push_back (const value_type& val)
			{ 
				if (_end == _capacity)
				{
					int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
					this->reserve(next_capacity);
				}
				_alloc.construct(_end, val);
				_end++;
			}
			
			void reserve (size_type n)
			{
				if (n >= this->max_size() || n < 0)
					throw std::length_error("vector:");
				if (n < _capacity)
					return;
				else
				{
					pointer start = _alloc.allocate(n);
					pointer end = start;
					size_type capacity = n;
					// size_type len = _end - _start;
					for (size_type i = 0; i < _size; i++)
					{
						_alloc.construct(end, *(_start + i));
						end++;
					}
					_alloc.deallocate(_start, _size);
					_start = start;
					_end = end;
					_capacity = capacity;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type pos = &(*position) - _start;
				size_type pos_index = _end - &(*position);					
				if (_size == 0)
				{
					reserve(1);
					_alloc.construct(_start, val);
					_size++;
					return (iterator(_start + pos));
				}
				else if (_capacity < _size + 1)
					reserve(_capacity * 2);
				for (size_type i = 0; i <= pos_index ; i++)
					_alloc.construct(_end - i, *(_end - (i + 1)));
				_alloc.construct(_end - pos_index, val);
				_size++;
				return (iterator(_start + pos));
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type pos_index = _end - &(*position);
				if (_size == 0)
					reserve(n);
				else if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size +n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_end += pos_index;
				std::cout << "[" << pos_index << "] " << "[" << n << "]\n";

				for (size_type i = 0; i < pos_index ; i++)
					_alloc.construct(_end - i - 1, *(_end - (pos_index + i + 1)));
				// _size += n;
				while (n)
				{
					_alloc.construct(&(*position) + (n - 1), val);	
					n--;
				}
			}
			
		
		private:
			pointer		_start;
			size_t		_size;
			size_t		_capacity;
			pointer		_end;
			allocator_type		_alloc;
			
	};
	
}

#endif