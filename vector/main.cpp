/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/23 18:20:02 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"

int main()
{

    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    // std::vector<int> third (second.begin(),second.end());  // iterating through second
    // std::vector<int> fourth (third);                       // a copy of third
    
    std::cout << '\n';

    ft::Vector<int> default_vec;
    ft::Vector<int> vec (4,100);                       
    
    return(0);
}
 