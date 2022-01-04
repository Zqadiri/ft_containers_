/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:05:49 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/23 18:02:36 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP_
#define RANDOM_ACCESS_ITERATOR_HPP_

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public:

		//?------------Member types--------------?//

		/* Category of the iterator. */
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category		iterator_category;
		
		/* Type of elements pointed. */
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
		
		/* Type to represent the difference between two iterators. */
		typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
		
		/* Type to represent a pointer to an element pointed */
		typedef T*																				pointer;
		
		/* Type to represent a reference to an element pointed */
		typedef T&																				reference;
		//?------------- Constructors --------------?//

		random_access_iterator()
		:_it(NULL){
			
		}
		
		random_access_iterator(const random_access_iterator &it){
			this->_it = it._it;
		}

		random_access_iterator(pointer p){
			this->_it = p;
		}

		//////////////////////
		operator random_access_iterator<const T>() const {
			return random_access_iterator<const T>(this->_it);
		}
		/////////////////////////////

		random_access_iterator& operator=(const random_access_iterator& op) {
			
			_it = op._it;
			return (*this);
		}
		
		//?------------- Destructors --------------?//
		
		~random_access_iterator(){};
		
		//?----------- Public Member Function and operators --------?//

		pointer base() const{
			return(this->_it);}
			
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
		
		private:
			pointer _it;
	};

		//?----------Non-member function overloads-------?//
	
			//*-------relational operators-----------*//

	/*
	** One iterator object is equal to another if they address 
	** the same elements in a container. If two iterators 
	** point to different elements in a container, then they are not equal.
	*/
	
	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator==(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() == rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator!=(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() != rhs.base());
	}
	
	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator<(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() < rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator<=(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() <= rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator>(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() > rhs.base());
	}

	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator>=(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() >= rhs.base());
	}
	
	template <class Iterator>
	random_access_iterator<Iterator> operator+ (
	typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator>& it) { 
		return (it + n);
	}
	
	template <typename T>
	typename ft::random_access_iterator<T>::difference_type
	operator-(const ft::random_access_iterator<T> lhs,
			const ft::random_access_iterator<T> rhs){
		return (lhs.base() - rhs.base());
	}		
}

#endif