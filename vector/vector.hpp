/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:07:50 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/16 20:23:54 by zqadiri          ###   ########.fr       */
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
			typedef T																				value_type; 
			/*The second template parameter*/
			typedef Allocator																		allocator_type;
			/*Type that provides a reference to an element stored in a vector.*/
			typedef	typename allocator_type::reference												reference;
			/*Type that provides a random access iterator that can read or
			modify an element of an inverted vector.*/
			typedef typename allocator_type::const_reference 										const_reference; 
			/*Type that provides a pointer to an element of a vector.*/
			typedef typename allocator_type::pointer 												pointer;
			/*Type that provides a pointer to an constelement of a vector.*/
			typedef typename allocator_type::const_pointer 											const_pointer;
			/*Type that provides a random access iterator capable
			of reading an constelement in a vector.*/
			typedef typename ft::random_access_iterator<std::random_access_iterator_tag, T>			iterator;
			/*Type that provides a random access iterator capable of reading
			 an constelement in a vector.*/
			typedef typename ft::random_access_iterator<std::random_access_iterator_tag,const  T>	const_iterator;
			/*Type that provides a random access iterator that can read or modify 
			an element of an inverted vector.*/
			typedef	typename ft::reverse_iterator<iterator> 										reverse_iterator;
			/*Type that provides a random access iterator capable of reading an 
			constelement of the vector.*/
			typedef	typename ft::reverse_iterator<const iterator>									const_reverse_iterator;
			/*Type that provides the difference between the addresses of two elements in a vector.*/
			typedef typename ft::iterator_traits<iterator>::difference_type							difference_type;
			/*Type that counts the number of elements in a vector.*/
			typedef typename allocator_type::size_type												size_type;

			//! ------------------------- Constructors ------------------------ !//

			//* Constructs an empty container, with no elements.
			
			explicit Vector (const allocator_type& alloc = allocator_type())
			:  _alloc(alloc), _start(NULL), _end(NULL), _capacity(NULL){
					// std::cout << "Empty container" <<std::endl;
			}
			
			//* Constructs a container with n elements. Each element is a copy of val.
			
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
						// std::cout << "fill constructor " << val <<std::endl;
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
				
				// std::cout << "range constructor" <<std::endl;
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
			Vector (const Vector& x):_start(NULL), _end(NULL), _capacity(0){
				// std::cout << "copy constructor" <<std::endl;
				*this = x;
			}

			//! ------------------------- Destructor ------------------------ !//
			
			/*
			TODO: Destructor
			** Destroy the container object.
			** Destroy all elements in the container and deallocate
			** the container capacity.
			*/ 
			~Vector(){
				this->clear();
				_alloc.deallocate(_start, this->capacity());
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
				if (this->size() == 0)
					return (_start);
				return(_end);
			}
			const_iterator end() const{
				if (this->size() == 0)
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

			reference operator[] (size_type n) const {
				return (*(_start + n));
			}

			/*
			** Return size of allocated storage capacity
			*/
		
			size_type capacity() const{
				return (_capacity - _start);
			}

			/*
			** Returns a copy of the allocator object associated with the vector.
			*/
		
			allocator_type get_allocator() const
			{
				allocator_type ret(_alloc);
				return (ret);
			}

			/*
			** Return reverse iterator to reverse beginning
			** rbegin points to the element right before the one that would be pointed to by member end.	
			*/

			reverse_iterator rbegin() {
				return (reverse_iterator(this->end()));
			}
			
			const_reverse_iterator rbegin() const{
				return (reverse_iterator(this->end()));		
			}
			
			/*
			** Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
			*/

			reverse_iterator rend(){
				return (reverse_iterator(this->begin()));		
			}
			
			const_reverse_iterator rend() const{
				return (reverse_iterator(this->begin()));		
			}
			
			
			/*
			** The function returns an iterator which points to the newly inserted element.
			*/

			/*destroy() - "destroys" data on a memory location which makes the object 
			not usable,but the memory is still there for use(the object can be constructed again)*/

			/*deallocate() - "deallocates" the memory location where the object was, so that the 
			storage is not usable for constructing the object on this location again. enter code here*/
			
			iterator insert (iterator position, const value_type& val)
			{
				size_type save = _end - &(*position);
				size_type pos_index = _end - &(*position);					
				if (this->capacity() >= this->size() + 1)
				{
					for (size_type i = 0; i < pos_index; i++)
						_alloc.construct(_end - i, *(_end - i - 1));
					_end++;
					_alloc.construct(&(*position), val);
				}
				else
				{
					pointer start;
					pointer end;
					pointer capacity;

					int new_capacity ;
					if (this->size() == 0)
						new_capacity = 1; 
					else
						new_capacity = (this->capacity() * 2);
					start = _alloc.allocate(new_capacity);
					end = start + this->size() + 1;
					capacity = start + new_capacity;

					for (size_type i = 0; i < pos_index; i++)
						_alloc.construct(start + i, *(_start + i));
					_alloc.construct(start + pos_index, val);
					for (size_type i = 0; i < this->size() - pos_index; i++)
						_alloc.construct(end - i - 1, *(_end - i - 1));
					for (size_type i = 0; i < this->size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, this->capacity());
					_start = start;
					_end = end;
					_capacity = capacity;
				}
				return (iterator(_start + save));
			}
			
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type pos_index = &(*position) - _start;
				if (this->capacity() >= this->size() + n)
				{
					for (size_type i = 0; i < this->size() - pos_index; i++)
						_alloc.construct(_end - i + (n - 1), *(_end - i - 1));
					_end += n;
					while (n)
					{
						_alloc.construct(&(*position) + (n - 1), val);
						n--;
					}
				}
				else
				{
					int new_capacity = size_t(_capacity - _end);
					if (this->size() == 0)
						new_capacity = n; 
					else if (size_type(_capacity - _start) < this->size() + n)
					{
						new_capacity = this->size() * 2;
						if ((size_type)new_capacity < this->size() + n)
							new_capacity = this->size() + n;
					}
					pointer start = _alloc.allocate(new_capacity);
					pointer end = start + this->size() + n;
					pointer capacity = start + new_capacity;
					for (size_type i = 0; i < pos_index; i++)
						_alloc.construct(start + i, *(_start + i));
					for (size_type i = 0; i < n ; i++)
						_alloc.construct((start + pos_index + i), val);
					for (size_type i = 0; i < (this->size() - pos_index); i++)
						_alloc.construct(end - i - 1, *(_end - i - 1));
					for (size_type i = 0; i < this->size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, this->capacity());
					_start = start;
					_end = end;
					_capacity = capacity;
				}
			} //fill

			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type = InputIterator())
			{
				size_type n = &(*last) - &(*first);
				size_type pos_index = &(*position) - _start;
				if (this->capacity() >= this->size() + n + 1)
				{
					for(size_type i = 0; i < this->size() - (&(*position) - _start); i++)
						_alloc.construct(_end - i + (n - 1), *(_end - i - 1));
					_end += n;
					for (; &(*first) != &(*last); first++, position++)
						_alloc.construct(&(*position), *first);
				}
				else
				{
					int new_capacity = 0;
					if (this->size() == 0)
						new_capacity = n;
					else if (size_type(_capacity - _start) < this->size() + n)
					{
						new_capacity = this->size() * 2;
						if ((size_type)new_capacity < this->size() + n)
							new_capacity = this->size() + n;
					}
					pointer start = _alloc.allocate(new_capacity);
					pointer end = start + this->size() + n;
					pointer capacity = start + new_capacity;
					
					for (size_type i = 0; i < pos_index; i++)
						_alloc.construct(start + i, *(_start + i));
					for (size_type i = 0; i < n; i++)
						_alloc.construct((start + pos_index + i), *(first++));
					for (size_type i = 0; i < (this->size() - pos_index); i++)
						_alloc.construct(end - i - 1, *(_end - i - 1));
					for (size_type i = 0; i < this->size(); i++)
						_alloc.destroy(_start + i);
					_alloc.deallocate(_start, this->capacity());
					_start = start;
					_end = end;
					_capacity = capacity;
				}
			} //range

			/*
			TODO: Access element
			**Returns a reference to the element at position n in the vector.
			*/

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

			/*
			** std::vector<t>::clear often doesn't actually reduce the storage used by a 
			** vector, it merely destroys all the objects contained there.
			*/

			void clear(){
				if (this->size() == 0)
					return;
				size_type tmp = this->size();
				for (size_type i = 0; i < tmp; i++, _end--)
					_alloc.destroy(_end);
			}

			/*
			** Remove element from the vector at "position".
			** Reduce the size of 1;
			** Return value : an iterator point to the element position + 1
			*/

			iterator erase (iterator position)
			{
				pointer pos = &(*position);
				_alloc.destroy(&(*position));
				for (int i = 0; i < _end - &(*position) - 1; i++)
				{
					_alloc.construct(&(*position) + i, *(&(*position) + i + 1));
					_alloc.destroy(&(*position) + i + 1);
				}
				_end -= 1;
				return (iterator(pos));
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_t start_pos = _end - &(*last);
				pointer last_pointer = &(*last) ;
				pointer first_pointer = &(*first);
				for (size_t i = 0; i < start_pos; i++)
				{
					_alloc.construct((first_pointer + i), *(last_pointer + i));
					_alloc.destroy((last_pointer + i));
				}
				_end -= (&(*last) - first_pointer);
				return (iterator(first_pointer));	
			}
			
			/*
			** Removes the last element in the vector, effectively reducing the container size by one.
			*/
		
			void pop_back(){
				if (!this->empty())
					this->erase(_end);
			}

			/*
			** Adds a new element at the end of the vector, after its current last element.
			*/
			
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
			
			/*
			** Requests that the vector capacity be at least enough to contain n elements.
			*/

			void reserve (size_type n){
				
				if (n >= this->max_size() || n < 0)
					throw std::length_error("vector");
				if (this->size() + n < this->capacity())
					return;
				else
				{
					pointer start = _alloc.allocate(this->size() + n);
					pointer end = start;
					pointer capacity = start + n;
					size_type len = _end - _start;
					for (size_type i = 0; i < len; i++)
					{
						_alloc.construct(end, *(_start + i));
						end++;
					}
					_alloc.deallocate(_start, this->size());
					_start = start;
					_end = end;
					_capacity = capacity;
				}
			}

			/*
			TODO:Swap content
			** Exchanges the content of the container by the content of x, which is another 
			** vector object of the same type. Sizes may differ.
			** Done by exchanging references to their data, without actually performing any element copy or movement
			*/
		
			void swap (Vector& x){
				if (x == *this)
					return;
				pointer start_tmp = x._start;
				pointer end_tmp  = x._end;
				pointer tmp_capacity = x._capacity;
				allocator_type	tmp_alloc = x._alloc;
				
				x._start = _start;
				x._end = this->_end;
				x._capacity = this->_capacity;
				x._alloc = this->_alloc;
				
				this->_start = start_tmp;
				this->_end = end_tmp;
				this->_capacity = tmp_capacity;
				this->_alloc = tmp_alloc;
			}

			/*
			** 
			*/
		
			void	resize (size_type n, value_type val = value_type())
			{
				if (n > this->max_size())
					throw (std::length_error("vector::resize"));
				else if (n < this->size())
				{
					while (this->size() > n)
						this->erase(_end);
				}
				else if (this->capacity() >= n)
				{
					while (this->size() < n)
						this->insert(_end, val);
				}
				else{
					this->insert(_end, n - this->size(),val);
				}
			}

			/*
			TODO:Assign vector content
			** Assigns new contents to the vector, replacing its 
			** current contents, and modifying its size accordingly.
			*/

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
			{
				this->clear();
				this->insert(this->_start, first, last);
			} // range
			
			void assign (size_type n, const value_type& val)
			{
				this->clear();
				if (this->capacity() >= n)
				{
					for (size_type i = 0; i < n; i++)
					{
						_alloc.construct(_end, val);
						_end++;
					}
				}
				else
					this->insert(this->_end, n, val);
			} // fill

			//! ------------------------- Assign.Operator ------------------------!//

			Vector &operator=(const Vector& x)
			{
				if (x == *this)
					return (*this);
				this->clear();
				this->insert(this->end(), x.begin(), x.end());
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
