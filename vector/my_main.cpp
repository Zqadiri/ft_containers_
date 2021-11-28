/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:56:06 by zqadiri           #+#    #+#             */
/*   Updated: 2021/11/28 18:14:34 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector/Vector.hpp"

int main() 
{
    
    // constructors used in the same order as described above:
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second(4,100);                       // four ints with value 100
    std::vector<int> third(second.begin(),second.end());  // iterating through second
    std::vector<int> fourth(third);                       // a copy of third
    
    std::cout << '\n';
    int a[] = {1,2,3,4,5};
    ft::Vector<int> v2(a+1, a+3);
    ft::Vector<int> default_vec;
    // ft::Vector<int> vec (4,100);                       
    // ft::Vector<int> vect(second);
    return(0);
}
