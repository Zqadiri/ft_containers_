/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:28:22 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/17 19:18:41 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "../vector/Vector.hpp"
#include <iostream>

namespace ft
{
	template <class T, class Container = ft::Vector<T> >
	class Stack
	{
		//! --------- Member types --------------- !//
		public:
		typedef  T              value_type;
		typedef  Container      container_type;
		typedef  size_t         size_type;   
		
		//! -------- Member functions ------------ !//

		/* Constructs a stack container adaptor object.*/
		explicit Stack (const container_type& ctnr = container_type()):_vec(ctnr){
		}

		size_type size() const{
			return (_vec.size());
		}
		
		bool empty() const{
			if (this->size() == 0)
				return (true);
			return (false);
		}

		void push (const value_type& val){
			_vec.push_back(val);
		}

		value_type& top(){
			return (_vec.back());
		}

		const value_type& top() const{
			return (_vec.back());
		}
		
		void pop(){
			_vec.pop_back();
		}

		//! --------------- relational operators --------------- !//

		friend bool operator== (const Stack& lhs, const Stack& rhs){
			return(lhs._vec == rhs._vec);
		}

		friend bool operator!= (const Stack& lhs, const Stack& rhs){
			return(!(lhs._vec == rhs._vec));
		}

		friend bool operator< (const Stack& lhs, const Stack& rhs){
			return(lhs._vec < rhs._vec);
		}
		
		friend bool operator<= (const Stack& lhs, const Stack& rhs){
			return(!(rhs._vec < lhs._vec));
		}

		friend bool operator> (const Stack& lhs, const Stack& rhs){
			return(rhs._vec < lhs._vec);
		}
		
		friend bool operator>= (const Stack& lhs, const Stack& rhs){
			return(!(lhs._vec < rhs._vec));
		}
		
		private:
			container_type _vec;
	};
}

#endif