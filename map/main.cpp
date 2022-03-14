#include "../utilities/utility.hpp"
#include "Map.hpp"

#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
#include <random>

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
			std::cout << std::left << std::setw(15) << std::left <<"\nRange Constructor ";			
			{
				time_t start, end, diff;
				bool	tle;
				std::map<int, int> m;
				ft::map<int, int> ft_m;
				
				for (int i = 0; i < 1e5; i++)
				{
					m.insert(std::make_pair(i, i));
					ft_m.insert(ft::make_pair(i, i));
				}
				
				start = get_time();
				std::map<int, int> m1(m1.begin(), m1.end());
				
				ft::map<int, int> ft_m1(ft_m1.begin(), ft_m1.end());


				
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