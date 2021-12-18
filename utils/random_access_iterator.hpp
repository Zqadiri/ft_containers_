/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:49 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/18 16:06:40 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator.hpp"

namespace ft
{
	template <typename Category, typename T, typename Distance = ptrdiff_t,
							typename Pointer = T*, typename Reference = T&>
	class random_access_iterator
	{
		private:
			typedef  typename ft::random_access_iterator<std::random_access_iterator_tag, const T>  const_iterator;
		public:

		//?------------Member types--------------?//

		/* Category of the iterator. */
		typedef  Category				iterator_category;
		
		/* Type of elements pointed. */
		typedef  T						value_type;
		
		/* Type to represent the difference between two iterators. */
		typedef  Distance				difference_type;
		
		/* Type to represent a pointer to an element pointed */
		typedef  Pointer				pointer;
		
		/* Type to represent a reference to an element pointed */
		typedef  Reference				reference;
		
		//?------------- Constructors --------------?//

		random_access_iterator()
		:_it(){
		}
		
		random_access_iterator(const random_access_iterator &it){
			this->_it = it._it;
		}

		random_access_iterator(pointer p){
			this->_it = p;
		}

		//////////////////////
		 operator const_iterator() const {
			return (const_iterator(this->_it));
		}
		/////////////////////////////

		random_access_iterator &operator=(const random_access_iterator& op) {
			if (this == &op)
				return (*this);
			this->_it = op._it;
			return (*this);
		}
		
		//?------------- Destructors --------------?//
		
		~random_access_iterator(){};
		
		//?----------- Public Member Function and operators --------?//
			
		reference operator*(void) const {
			return (*_it);}

		pointer operator->(void) { 
			return &(this->operator*());}

		random_access_iterator operator+ (difference_type n) const{
			return (random_access_iterator(_it + n));}
			
		random_access_iterator operator- (difference_type n) const {
			return (random_access_iterator(_it - n));}

		// pre-increment version
		random_access_iterator& operator++(){
			_it++;
			return (*this);}

		// post-increment version
		random_access_iterator operator++(int) {
  			random_access_iterator temp = *this;
  			operator++();
  			return temp;
		}

		random_access_iterator& operator+=(difference_type n) {
			_it += n;
			return (*this);
		}

		// pre-decrement version
		random_access_iterator& operator--(){
			_it--;
			return (*this);
		}

		// post-decrement version
		random_access_iterator operator--(int) {
  			random_access_iterator temp = *this;
  			operator--();
  			return temp;
		}
		
		random_access_iterator& operator-= (difference_type n) {
			_it -= n;
			return (*this);}
		
		reference operator[](difference_type n) { 
			return (*(operator+(n))); }
		
					//*-------relational operators-----------*//

		/*
		** One iterator object is equal to another if they address 
		** the same elements in a container. If two iterators 
		** point to different elements in a container, then they are not equal.
		*/

		friend bool operator==(const random_access_iterator &lhs,
		const random_access_iterator &rhs){
			return (lhs._it == rhs._it);
		}
		
		friend bool operator!=(const random_access_iterator &lhs,
				const random_access_iterator &rhs){
			return (!(lhs._it == rhs._it));
		}

		friend bool operator<(const random_access_iterator& lhs,
		const random_access_iterator &rhs){
			return (lhs._it < rhs._it);
		}

		friend bool operator<=(const random_access_iterator& lhs,
		const random_access_iterator& rhs){
			return (lhs._it <= rhs._it);
		}
	
		friend bool operator>(const random_access_iterator &lhs,
				const random_access_iterator &rhs){
			return (lhs._it > rhs._it);
		}
	
		friend bool operator>=(const random_access_iterator& lhs,
				const random_access_iterator &rhs){
			return (lhs._it >= rhs._it);
		}
		
		friend random_access_iterator operator+ (difference_type n,
			const random_access_iterator& it) { 
			return (it + n);
		}
		
		friend difference_type operator-(const random_access_iterator &lhs,
				const random_access_iterator &rhs){
			return (lhs._it - rhs._it);
		}
			
		private:
			pointer _it;
	};
}

#endif
				