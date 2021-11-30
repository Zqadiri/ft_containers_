/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:25:09 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/30 22:54:13 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft
{

	/*
	** Trait class that identifies whether T is an integral type.
	*/

    template <bool is_integral, typename T>
    struct is_integral_res {
    };
		
	template<bool B, class T = void>
	struct enable_if {
	};
	
	template<class T>
	struct enable_if<true, T>{
		typedef T type;
		
	};
}

#endif
