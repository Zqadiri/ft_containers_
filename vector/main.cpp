/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zqadiri <zqadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:49:41 by zqadiri           #+#    #+#             */
/*   Updated: 2021/12/23 18:09:30 by zqadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include "vector_.hpp"

int main()
{
    ft::Vector<int> v(4, 5);
    ft::Vector<int>::reverse_iterator my_rit2(v.begin());
    ft::Vector<int>::const_reverse_iterator c_it(v.begin());
    c_it = my_rit2;
}