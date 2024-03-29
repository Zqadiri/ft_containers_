/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 12:27:44 by zqadiri           #+#    #+#             */
/*   Updated: 2022/04/14 23:16:02 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

namespace ft
{
    //!------------------ Iterator Traits -----------------!//
	
	template <typename Iter>
	struct iterator_traits
	{
		public:
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};
	
	template<typename T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t 						difference_type;
		typedef T									value_type;
		typedef T* 									pointer;
		typedef T& 									reference;
		typedef	std::random_access_iterator_tag 	iterator_category;
	};

	template<typename T >
	struct iterator_traits<const T*>
	{
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
}

#endif