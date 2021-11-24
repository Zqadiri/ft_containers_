/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:10:22 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/24 16:57:12 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_
#define ITERATOR_

#include <stddef.h>
#include "./iterator_traits.hpp"

namespace ft
{
	//!----------------Category tags--------------!//
	
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag {};
	struct bidirectional_iterator_tag {};
	struct random_access_iterator_tag {};
	
	/*
		This is a base class template that can be used to derive iterator classes from it. 
		It is not an iterator class and does not provide any
		of the functionality an iterator is expected to have.
	*/

	//!---------------- Iterator Base Class -----------------!//
	
	template <class Category, class T, class Distance = ptrdiff_t,
			class Pointer = T*, class Reference = T&>
	class iterator 
	{
		typedef T						value_type;
		typedef Distance				difference_type;
		typedef Pointer					pointer;
		typedef Reference				reference;
		typedef Category 				iterator_category;
	};

	//!--------------- Predefined iterators ----------------!//
	
			/*----------- REVERSE ITERATOR -----------*/
	
	template <class Iterator> 
	class reverse_iterator
	{
			
		public :
			/*Iterator's type*/
			typedef Iterator												iterator_type;
			/*Preserves Iterator's category*/
			typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
			/*Preserves Iterator's value type*/
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			/*Preserves Iterator's difference type*/
			typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
			/*Preserves Iterator's pointer type*/
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			/*Preserves Iterator's reference type*/
			typedef typename iterator_traits<Iterator>::reference			reference;
		
			/*------------- Constructors --------------*/
		
		//* Constructs a reverse iterator that points to no object.
		reverse_iterator() : _it(){
		}
		//* Constructs a reverse iterator from some original iterator it. 
		explicit reverse_iterator (iterator_type it) : _it(it){
		}
		//* copy / type-cast constructor
		template <class Iter>
  			reverse_iterator (const reverse_iterator<Iter>& rev_it){
		}
		
			/*----------- Public Member Function --------*/

		iterator_type base() const{
			return(_it);
		}


	
		private:
			Iterator		_it;
	};
	
}

#endif
