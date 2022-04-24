/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:13:42 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/24 21:48:49 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP_
# define VECTOR_HPP_

# include <limits>
# include <iterator>
# include <string>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <memory>

# include "../utilities/iterator.hpp"
# include "../utilities/utility.hpp"
# include "../utilities/iterator_traits.hpp"
# include "../utilities/random_access_iterator.hpp"

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

			//! -------------------- Member types ------------------------ !//
			// The first template parameter Type representing the type of data stored in a vector
			typedef T																value_type; 
			// The second template parameter
			typedef Allocator														allocator_type;
			// Type that provides a reference to an element stored in a vector
			typedef	typename allocator_type::reference								reference;
			typedef typename allocator_type::const_reference 						const_reference; 
			// Type that provides a pointer to an element of a vector
			typedef typename allocator_type::pointer 								pointer;
			typedef typename allocator_type::const_pointer 							const_pointer;
			// Type that provides a random access iterator capable of reading an constelement in a vector
			typedef random_access_iterator<T>										iterator;
			typedef random_access_iterator<const T>									const_iterator;
			// Type that provides a random access iterator that can read or modify an element of an inverted vector
			typedef	reverse_iterator<iterator> 										reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			// Type that provides the difference between the addresses of two elements in a vector [ptrdiff_t]
			typedef typename iterator_traits<iterator>::difference_type				difference_type;
			// Type that counts the number of elements in a vector
			typedef typename allocator_type::size_type								size_type;

			//! ------------------- Constructors ------------------------ !//

			inline explicit Vector (const allocator_type& alloc = allocator_type()) 
			: _start(nullptr), _size(0), _capacity(0), _end(nullptr),  _alloc(alloc){
			} // Default

			inline explicit Vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			:_start(nullptr), _size(0), _capacity(0), _end(nullptr),  _alloc(alloc)
			{
				if (n > this->max_size())
					throw std::length_error("vector");
				_start = _alloc.allocate(n);
				_end = _start;
				for(size_t i = 0; i < n; i++)
				{
					_alloc.construct(_end, val);
					_end++;
				}
				_capacity = _size = n;
			} // Fill
			
			template <class InputIterator>
			inline explicit Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
				:_start(nullptr), _size(0), _capacity(0), _end(nullptr),  _alloc(alloc)
			{
				difference_type diff = std::distance(first, last);
				// diff = last - first;
				_start = _alloc.allocate(diff);
				_capacity = _size = diff;
				_end = _start;
				while (diff)
				{
					_alloc.construct(_end, *(first++));
					diff--;
					_end++;
				}
			} // Range

			Vector (const Vector& x):_start(nullptr), _size(0), _capacity(0), _end(nullptr){
				*this = x;
			} // Copy

			Vector &operator=(const Vector& x){
				for (size_t i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_alloc.deallocate(_start, _capacity);
				_size = x._size;
				_start = _alloc.allocate(x._capacity);
				_end = _start + _size;
				for (size_t i = 0; i < _size; i++)
					_alloc.construct((_start + i), *(x._start + i));
				_alloc = x._alloc;
				_capacity = x._capacity;
				return (*this);
			}

			//! ------------------------- Destructor ------------------------ !//

			/*
			TODO: Destructor
			** Destroy all elements in the container and deallocate
			** the container capacity.
			*/

			~Vector(){
				this->clear();
				_alloc.deallocate(_start, _capacity);
			}
			
			//!------------------------- Member functions -------------------- !//

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

			/*
			TODO: Return reverse iterator
			** - rbegin points to the element right before the one that would be pointed to by member end
			** - rend Returns a reverse iterator pointing to the theoretical element 
			** preceding the first element in the vector
			*/

			reverse_iterator rbegin() {
				return (reverse_iterator(this->end()));
			}
			
			const_reverse_iterator rbegin() const{
				return (const_reverse_iterator(this->end()));		
			}

			reverse_iterator rend(){
				return (reverse_iterator(this->begin()));		
			}
			
			const_reverse_iterator rend() const{
				return (const_reverse_iterator(this->begin()));		
			}
			
			/*
			TODO: Size and capacity Methods
			*/

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
			
			/*
			TODO: Access element
			** Returns a reference to the element at position n in the vector.
			*/

			reference at (size_type n){
				if (n < 0 || n >= this->size())
					throw (std::out_of_range("vector"));
				return ((*this)[n]);
			} 
			
			const_reference at (size_type n) const{
				if (n < 0 || n >= this->size())
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
			
			/*
			TODO: Request a change in capacity
			** Change the vector capacity be at least enough to contain n elements.
			*/

			void reserve (size_type n)
			{
				if (n >= this->max_size() || n < 0)
					throw std::length_error("vector:");
				else if (n > _capacity)
				{
					pointer start = _alloc.allocate(n);
					pointer end = start;
					size_type capacity = n;
					for (size_type i = 0; i < _size; i++, end++)
						_alloc.construct(end, *(_start + i));
					_alloc.deallocate(_start, _capacity);
					_start = start;
					_end = end;
					_capacity = capacity;
				}
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type pos = position - iterator(_start);
				size_type pos_index = _end - &(*position);
				if (_size == 0)
				{
					reserve(1);
					_alloc.construct(_start, val);
					_size++;
					return (iterator(_start + pos));
				}
				if (_capacity < _size + 1)
					reserve(_capacity * 2);
				for (size_type i = 0; i < pos_index ; i++)
					_alloc.construct(_end - i , *(_end - (i + 1)));
				_alloc.construct(_end - pos_index, val);
				_size++;
				_end++;
				return (iterator(_start + pos));
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type pos_index = _end - &(*position);
				if (_size == 0)
				{
					reserve (n);
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_start + i , val);
					_size += n;
					_end += n;
					return;
				}
				if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size +n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_end += n;
				_size += n;
				for (size_type i = 0; i < pos_index; i++)
					_alloc.construct(_end - i - 1, *(_end - ( n + i + 1)));
				for (size_type j = 0; j < n; j++)
					_alloc.construct(_end - pos_index - j - 1, val);
			}

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				size_type pos_index = _end - &(*position);
				size_type n = std::distance(first, last);
				if (_size == 0)
				{
					reserve (n);
					for (size_type i = 0; i < n; i++, first++)
						_alloc.construct(_start + i , *(&(*first)));
					_size += n;
					return;
				}
				if (_capacity < _size + n)
				{
					if (_capacity * 2 < _size + n)
						reserve (_size + n);
					else
						reserve (_capacity * 2);
				}
				_end += n;
				_size += n;
				for (size_type i = 0; i < pos_index; i++)
					_alloc.construct(_end - i - 1, *(_end - ( n + i + 1)));
				for (size_type j = 0; j < n; j++, first++)
					_alloc.construct(_end - pos_index - j - 1, (*first));
			}

			/*
			TODO: Remove element from the vector at "position".
			** Reduce the size of 1;
			** Return value : an iterator point to the element position + 1
			*/

			iterator erase(iterator position)
			{
				std::copy(&(*position) + 1, _end, &(*position));
				_size--;
				_end--;
				return position;
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_type n = std::distance(first, last);
				size_t start_pos = _end - &(*last);
				pointer last_pointer = &(*last) ;
				pointer first_pointer = &(*first);
				for (size_t i = 0; i < start_pos; i++){
					_alloc.construct((first_pointer + i), *(last_pointer + i));
					_alloc.destroy((last_pointer + i));
				}
				_end -= n;
				_size -= n;
				return (iterator(first_pointer));	
			}

			/*
			TODO:Swap content
			** Exchanges the content of the container by the content of x, which is another 
			** vector object of the same type. Sizes may differ.
			** Done by exchanging references to their data, without actually performing any element copy or movement
			*/

			void swap (Vector& x){
				std::swap(this->_size, x._size);
				std::swap(this->_start, x._start);
				std::swap(this->_alloc, x._alloc);
				std::swap(this->_end, x._end);
				std::swap(this->_capacity, x._capacity);
			}
			
			/*
			TODO: Clear the vector 
			** Clear often doesn't actually reduce the storage used by a 
			** vector, it merely destroys all the objects contained there.
			*/
		
			void clear(){
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_start + i);
				_size = 0;
			}

			allocator_type get_allocator() const{
				allocator_type ret(_alloc);
				return (ret);
			}

			void push_back (const value_type& val)
			{ 
				if (!_size)
					reserve(1);
				else if (_size == _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_end, val);
				_size++;
				_end++;
			}

			/*
			TODO:Assign vector content
			** Assigns new contents to the vector, replacing its 
			** current contents, and modifying its size accordingly.
			*/

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last,
			  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{				
				size_type n = std::distance(first, last);
				if (n > _capacity){
					this->clear();
					_alloc.deallocate(_start, _capacity);
					_start = _alloc.allocate(n);
					_end = _start + n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_start + i, *(&(*first) + i));
					_size = _capacity = n;
				}
				else
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_start + i);
					_size = n;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_start + i, *(&(*first) + i));
				}
			}
			
			void assign (size_type n, const value_type& val)
			{
				if (_capacity < n)
				{
					this->clear();
					_alloc.deallocate(_start, _capacity);
					_start = _alloc.allocate(n);
					_end = _start + n;
					for (size_type i = 0; i < n; i++)
						_alloc.construct(_start + i, val);
					_size = _capacity = n;
				}
				else
				{
					for (size_type i = n; i < _size; i++)
						_alloc.destroy(_start + i);
					_size = n;
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_start + i, val);
				}
			}
			
			void pop_back(){
				if (_size != 0)
				{
					_alloc.destroy(_end);
					_end -= 1;
					_size -= 1;
				}
			}

			bool empty() const{
				return (this->size() == 0);
			}
			
			void	resize (size_type n, value_type val = value_type())
			{
				if (n >= this->max_size())
					throw (std::length_error("vector::resize"));
				if (n < _size)
				{
					for (pointer it = _start + n; it < _end; it++)
						_alloc.destroy(it);
					_end = _start + n;
					_size = n;
				}
				else
				{
					pointer start, end;
					if (n > _size && n < _capacity)
					{
						start = _alloc.allocate(_capacity);
						end = start + _size + n;
					}
					else
					{
						size_t cap = _capacity * 2;
						if (n > cap)
							cap = n;
						start = _alloc.allocate(cap);
						end = start + n;
						_capacity = cap;
					}
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(start + i, *(_start + i));
					for (size_type i = _size; i < n; i++)
						_alloc.construct(start + i, val);
					for (pointer it = _start; it < _end; it++)
						_alloc.destroy(it);
					_alloc.deallocate(_start, _capacity);
					_start = start;
					_end = end;
					_size = n;
				}
			}

		private:
			pointer				_start;
			size_t				_size;
			size_t				_capacity;
			pointer				_end;
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
