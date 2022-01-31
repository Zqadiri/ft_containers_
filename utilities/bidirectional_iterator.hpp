/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:36:17 by zqadiri           #+#    #+#             */
/*   Updated: 2022/01/31 19:48:33 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename Pair, typename Alloc, typename Compare>
	class map_iterator : public ft::iterator<std::bidirectional_iterator_tag, Pair>
	{
		public:
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, Pair>::value_type		value_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, Pair>::iterator_category	iterator_category;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Pair>::difference_type	difference_type;
			typedef	typename ft::iterator<std::bidirectional_iterator_tag, Pair>::reference			reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, Pair>::pointer			pointer;

		map_iterator(): _node(nullptr){};
		
		map_iterator(const	map_iterator &mi){
		}
		
			

		private:
			Alloc		_alloc;
			Pair		*_node;
	};
}

#endif