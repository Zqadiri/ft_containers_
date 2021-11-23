/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:10:22 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/23 19:20:04 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_
#define ITERATOR_

template <class Category,              // iterator::iterator_category
          class T,                     // iterator::value_type
          class Distance = ptrdiff_t,  // iterator::difference_type
          class Pointer = T*,          // iterator::pointer
          class Reference = T& > 
    class iterator
    {
        
    };
          
#endif
