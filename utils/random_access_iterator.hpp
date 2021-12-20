/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:49 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/19 17:01:43 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator.hpp"

namespace ft
{
	template <typename Category, typename T, typename Distance = ptrdiff_t,
							typename Pointer = T*, typename Reference = T&>
	class Iterator
	{
		private:
			typedef  typename ft::Iterator<std::random_access_iterator_tag, const T>  const_iterator;
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

		Iterator()
		:_it(){
		}
		
		Iterator(const Iterator &it){
			this->_it = it._it;
		}

		Iterator(pointer p){
			this->_it = p;
		}

		//////////////////////
		operator const_iterator() const {
			return (const_iterator());
		}
		/////////////////////////////

		Iterator &operator=(const Iterator& op) {
			if (this == &op)
				return (*this);
			this->_it = op._it;
			return (*this);
		}
		
		//?------------- Destructors --------------?//
		
		~Iterator(){};
		
		//?----------- Public Member Function and operators --------?//
			
		reference operator*(void) const {
			return (*_it);}

		pointer operator->(void) { 
			return &(this->operator*());}

		Iterator operator+ (difference_type n) const{
			return (Iterator(_it + n));}
			
		Iterator operator- (difference_type n) const {
			return (Iterator(_it - n));}

		// pre-increment version
		Iterator& operator++(){
			_it++;
			return (*this);}

		// post-increment version
		Iterator operator++(int) {
  			Iterator temp = *this;
  			operator++();
  			return temp;
		}

		Iterator& operator+=(difference_type n) {
			_it += n;
			return (*this);
		}

		// pre-decrement version
		Iterator& operator--(){
			_it--;
			return (*this);
		}

		// post-decrement version
		Iterator operator--(int) {
  			Iterator temp = *this;
  			operator--();
  			return temp;
		}
		
		Iterator& operator-= (difference_type n) {
			_it -= n;
			return (*this);}
		
		reference operator[](difference_type n) { 
			return (*(operator+(n))); }
		
					//*-------relational operators-----------*//

		/*
		** One Iterator object is equal to another if they address 
		** the same elements in a container. If two Iterators 
		** point to different elements in a container, then they are not equal.
		*/

		friend bool operator==(const Iterator &lhs, const Iterator &rhs){
			return (lhs._it == rhs._it);
		}
		
		friend bool operator!=(const Iterator &lhs, const Iterator &rhs){
			return (!(lhs._it == rhs._it));
		}

		friend bool operator<(const Iterator& lhs, const Iterator &rhs){
			return (lhs._it < rhs._it);
		}

		friend bool operator<=(const Iterator& lhs, const Iterator& rhs){
			return (lhs._it <= rhs._it);
		}
	
		friend bool operator>(const Iterator &lhs, const Iterator &rhs){
			return (lhs._it > rhs._it);
		}
	
		friend bool operator>=(const Iterator& lhs, const Iterator &rhs){
			return (lhs._it >= rhs._it);
		}
		
		friend Iterator operator+ (difference_type n, const Iterator& it) { 
			return (it + n);
		}
		
		friend difference_type operator-(const Iterator &lhs, const Iterator &rhs){
			return (lhs._it - rhs._it);
		}
			
		private:
			pointer _it;
	};
}

#endif
				


