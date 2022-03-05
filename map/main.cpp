// Simple program to create a BST of integers and search an element in it 
// Binary Search Tree - Implemenation in C++
#include <iostream>
#include "./avl_tree.hpp"
#include "../utilities/utility.hpp"
#include <string.h>
#include <iomanip>
#include <map>
#include "Map.hpp"

namespace Color
{
	enum Code {
		FG_RED      = 31,
		FG_GREEN    = 32,
		FG_BLUE     = 36,
		FG_YELLOW   = 33,
		FG_DEFAULT  = 39,
		BG_RED      = 41,
		BG_GREEN    = 42,
		BG_BLUE     = 44,
		BG_DEFAULT  = 49
	};
	class Modifier {
		Code code;
	public:
		Modifier(Code pCode) : code(pCode) {}
		friend std::ostream&
		operator<<(std::ostream& os, const Modifier& mod) {
			return os << "\033[" << mod.code << "m";
		}
	};
}

time_t get_time(void)
{
	struct timeval time_now;

	gettimeofday(&time_now, NULL);
	time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
	return(msecs_time);
}

void	print_time(time_t start, time_t end)
{
	Color::Modifier yellow(Color::FG_YELLOW); // right answer
	Color::Modifier def(Color::FG_DEFAULT);
	char esc_char = 27;
	time_t res = end - start;
	std::cout << std::setw(5) << "\t"<< yellow << res << "msecs " << def ;
}

int main()
{
	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier blue(Color::FG_BLUE);
	Color::Modifier yellow(Color::FG_YELLOW); // right answer
	Color::Modifier red(Color::FG_RED); // false answer
	Color::Modifier def(Color::FG_DEFAULT);
	{
		try
		{
			std::cout << blue << "-----------------------------------------------------------" << def << std::endl;
			std::cout << blue << "------------------------ Map Tests ------------------------" << def << std::endl;
			std::cout << std::left << std::setw(15) << std::left <<"\nFill Constructor ";			
			{
				time_t start, end, diff;
				bool	tle;
				std::vector<int> v(1e7, 10);
				ft::Vector<int> ft_v(1e7, 10);
				start = get_time();
				std::map<int, int> m(v.begin(), v.end());
				end = get_time();
				print_time(start, end);
				diff = (end - start) + 1;
				start = get_time();
				ft::map<int, int> ft_m(ft_v.begin(), ft_v.end());
				end = get_time();
				print_time(start, end);
				size_t s, ft_s;
				s = m.size();
				ft_s = ft_m.size();
				ft::map<int, int>::iterator it = ft_m.begin();
				ft::map<int, int>::iterator end_it = ft_m.end();

				ft::map<int, int>::iterator it = ft_m.begin();
				ft::map<int, int>::iterator end_it = ft_m.end(); 
				if ((end - start) > (diff * 20))
					std::cout << "\t\t" <<blue << "TL" << def << std::endl;
				else if ((s == ft_s) && (m.begin() == ft_m.begin()) && (m.end() == ft_m.end()))
					std::cout <<"\t\t" << green << "OK" << def << std::endl;
				else	
					std::cout << "\t\t" << red << "KO" << def << std::endl;
			}
		} 
		catch (std::exception &e){}
	}
	return EXIT_SUCCESS;
}



// void printBT(const std::string& prefix,  ft::avl_tree<ft::pair<int, std::string> >::node_type* node, bool isLeft)
// {
// 	if( node != nullptr )
// 	{
// 		std::cout << prefix;
// 		std::cout << (isLeft ? "├──" : "└──" );
// 		// print the value of the node
// 		std::cout << node->data.first << std::endl;
// 		// enter the next tree level - left and right branch
// 		printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
// 		printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
// 	}
// }

// void print_parent( ft::avl_tree<ft::pair<int , std::string> >::node_type* root)
// {
// 	if (root->left != NULL)
// 		print_parent(root->left);
// 	if (root->right != NULL)
// 		print_parent(root->right);
// 	if (root->rootPtr != NULL)
// 		std::cout << "parent of " << root->data.first << " is : " << root->rootPtr->data.first << "  "<< root->Height  << std::endl;
// 	else
// 		std::cout << "node " << root->data.first << " is root of the tree" << ":" << root->Height << std::endl;
// }