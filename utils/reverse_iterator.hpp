/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:06:54 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/23 12:29:37 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP_
#define REVERSE_ITERATOR_HPP_

/*
	This class reverses the direction in which a bidirectional or 
	random-access iterator iterates through a range.
*/
namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
			typedef typename iterator_traits<Iterator>::value_type value_type;
			typedef typename iterator_traits<Iterator>::difference_type difference_type;
			typedef typename iterator_traits<Iterator>::pointer pointer;
			typedef typename iterator_traits<Iterator>::reference reference;
			
			
	};
	
}

#endif
