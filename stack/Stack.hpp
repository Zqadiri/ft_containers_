/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:28:22 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/20 16:21:08 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "../vector/vector.hpp"
#include <iostream>
#include <stack>

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
			return (this->size() == 0); 
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

		template< class U, class con >
		friend bool operator==( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		template< class U, class con >
		friend bool operator!=( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		template< class U, class con >
		friend bool operator<( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		template< class U, class con >
		friend bool operator<=( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		template< class U, class con >
		friend bool operator>( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		template< class U, class con >
		friend bool operator>=( const Stack<U,con>& lhs, const Stack<U,con>& rhs );

		protected:
			container_type _vec;
	};
		//! --------------- relational operators --------------- !//

	template< class T, class Container >
	bool operator==( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(lhs._vec == rhs._vec);
	}

	template< class T, class Container >
	bool operator!=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(!(lhs._vec == rhs._vec));
	}

	template< class T, class Container >
	bool operator<( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(lhs._vec < rhs._vec);
	}
	template< class T, class Container >
	bool operator<=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(!(rhs._vec < lhs._vec));
		
	}
	template< class T, class Container >
	bool operator>( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(rhs._vec < lhs._vec);
	}

	template< class T, class Container >
	bool operator>=( const Stack<T,Container>& lhs, const Stack<T,Container>& rhs ){
		return(!(lhs._vec < rhs._vec));
	}
}

#endif