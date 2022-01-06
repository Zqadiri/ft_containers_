/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/01/05 21:20:51 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template<typename T>
	class bidirectional_iterator: public ft::iterator<std::bidirectional_iterator_tag, T>
	{
		// public:

		// 	typedef T																				iterator_type;
		// 	/* Category of the iterator. */
		// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		// 	/* Type of elements pointed. */
		// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
		// 	/* Type to represent the difference between two iterators. */
		// 	typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
		// 	/* Type to represent a pointer to an element pointed */
		// 	typedef T*																				pointer;
		// 	/* Type to represent a reference to an element pointed */
		// 	typedef T&																				reference;

		// 		//?---- Constructors and Destructor -------?//
		
		// bidirectional_iterator():_it(nullptr){};

		// bidirectional_iterator(const bidirectional_iterator &b){
		// 	*this = b;}
		
		// bidirectional_iterator(pointer it){
		// 	_it = it;}

		// bidirectional_iterator& operator=(const bidirectional_iterator &b){
		// 	this->_it = b._it;
		// 	return (*this);}

		// ~bidirectional_iterator(){};

		// // operator bidirectional_iterator<const T>() const {
		// // 	return bidirectional_iterator<const T>(this->_it); }

		// 		//?----------- Public Member Function and operators --------?//
		
		// reference operator*(void) const {
		// 	return (*_it);}

		// pointer operator->(void) { 
		// 	return &(this->operator*());}
		
		// friend bool operator==(const bidirectional_iterator &lhs,const bidirectional_iterator &rhs){
		// 	return (lhs.base() == rhs.base());}
		
		// friend bool operator!=(const bidirectional_iterator &lhs,const bidirectional_iterator &rhs){
		// 	return (!(lhs.base() == rhs.base()));}

		// bidirectional_iterator& operator++(){
		// 	_it++;
		// 	return (*this);}

		// // post-increment version
		// bidirectional_iterator operator++(int) {
  		// 	bidirectional_iterator temp = *this;
  		// 	operator++();
  		// 	return temp;}

		// // pre-decrement version
		// bidirectional_iterator& operator--(){
		// 	_it--;
		// 	return (*this);}

		// // post-decrement version
		// bidirectional_iterator operator--(int) {
  		// 	bidirectional_iterator temp = *this;
  		// 	operator--();
  		// 	return temp;}

		

		
		
		// private:
		// 	pointer _it;
	};
}

#endif