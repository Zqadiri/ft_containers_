/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:13:42 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/22 00:01:18 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

# include <vector>
# include <limits>
# include <iterator>
# include <string>
# include <cstring>
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
			typedef typename ft::random_access_iterator<const T>						const_iterator;
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

			Vector (const Vector& x):_start(nullptr), _size(0), _capacity(0), _end(nullptr){
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
				{
					reserve(n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_start + i, val);
					_size += n;
					return;
				}
				else if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size +n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_end += n;
				_size += n;
				iterator save = position;
				for (size_type i = 0; i <= pos_index ; i++)
				{
					_alloc.construct(_end - i, *(_end - (n + i)));
				}
				for (size_type j = 0; j < n; j++, position++)
				{
					_alloc.destroy(_end - pos_index + j);			
				}
				for (size_type j = 0; j < n; j++, save++)
					_alloc.construct(_end - pos_index - j -1, val);			
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				
				size_type pos_index = _end - &(*position);
				size_type n = &(*last) - &(*first);
				// std::cout << n << std::endl;
				if (_size == 0)
				{
					reserve (n);
					for (size_type i = 0; i < n; i++, first++)
						_alloc.construct(_start + i , *(&(*first)));
					_size += n;
					return;
				}
				else if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size +n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_end += n;
				_size += n;
				iterator save = position;
				for (size_type i = 0; i <= pos_index; i++)
					_alloc.construct(_end - i, *(_end - (n + i)));
				for (size_type i = 0; i < n; i++)
					_alloc.destroy(_end - pos_index + i);
				for (size_type j = 0; j < n; j++, save++, first++)
					_alloc.construct(_end - pos_index - j -1, *(&(*first)));				
			}
			
			iterator erase (iterator position)
			{
				pointer pos = &(*position);
				if (&(*position) == _end)
					_alloc.destroy(&(*position));
				else
				{
					_alloc.destroy(&(*position));
					for (int i = 0; i < _end - &(*position) - 1; i++)
					{
						_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
						_alloc.destroy(&(*position) + i + 1);
					}
					_end -= 1;
					_size -= 1;
				}
				return (iterator(pos));
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_type n = &(*last) - &(*first);
				size_t start_pos = _end - &(*last);
				pointer last_pointer = &(*last) ;
				pointer first_pointer = &(*first);
				for (size_t i = 0; i < start_pos; i++)
				{
					_alloc.construct((first_pointer + i), *(last_pointer + i));
					_alloc.destroy((last_pointer + i));
				}
				_end -= n;
				_size -= n;
				return (iterator(first_pointer));	
			}

			void swap (Vector& x){
				if (x == *this)
					return;
				pointer start_tmp = x._start;
				pointer end_tmp  = x._end;
				allocator_type	tmp_alloc = x._alloc;
				size_t	size_tmp = x._size;
				size_t cap_tmp = x._capacity;
				
				x._start = this->_start;
				x._end = this->_end;
				x._alloc = this->_alloc;
				x._capacity = this->_capacity;
				x._size = this->_size;
				
				this->_start = start_tmp;
				this->_end = end_tmp;
				this->_alloc = tmp_alloc;
				this->_size = size_tmp;
				this->_capacity = cap_tmp;
			}

			void clear(){
				if (this->size() == 0)
					return;
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_end);
					_end--;
				}
				_size = 0;
			}

			allocator_type get_allocator() const
			{
				allocator_type ret(_alloc);
				return (ret);
			}

			// Vector &operator=(const Vector& x)
			// {
			// 	if (x == *this)
			// 		return (*this);
			// 	this->clear();
			// 	this->insert(this->begin(), x.begin(), x.end());
			// 	return (*this);
			// }

			void push_back (const value_type& val)
			{ 
				if (_size == _capacity)
				{
					int next_capacity = (this->size() > 0) ? (int)(this->size() * 2) : 1;
					this->reserve(next_capacity);
				}
				_alloc.construct(_end, val);
				_size++;
				_end++;
			}
			
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last,
			  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				
				size_type n = std::distance(first, last);
				std::cout << n << std::endl;
				this->clear();
				if (_capacity < n)
					reserve(n);
				for (size_type i = 0; i < n; i++, first++)
					_alloc.construct(_start + i , *(&(*first)));
				_size += n;				
			}
			
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				if (_capacity < n)
					reserve(n);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_start + i , val);
				_size += n;				
			}
			
		
		private:
			pointer		_start;
			size_t		_size;
			size_t		_capacity;
			pointer		_end;
			allocator_type		_alloc;
			
	};

	template <class T, class Alloc>
	bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (!(lhs == rhs));
	}
	
	template <class T, class Alloc>
	bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (!(rhs < lhs));
	}
	
	template <class T, class Alloc>
	bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (!(lhs < rhs));	
	}

	/*
	TODO:Exchange contents of vectors
	** It behaves as if x.swap(y) was called.
	*/

	template <class T, class Alloc>
	void swap (Vector<T,Alloc>& x, Vector<T,Alloc>& y){
		
		x.swap(y);
	}
	
}

#endif