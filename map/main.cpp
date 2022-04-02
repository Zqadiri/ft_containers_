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
			std::cout << std::left << std::setw(15) << std::left <<"\nDefault Constructor ";			
			{
				std::map<char, int> m;
				ft::map<char, int> ft_m;

				//! try to insert elem
  				m['a'] = 10;
  				m['b'] = 30;
  				m['c'] = 50;
  				m['d'] = 70;

  				ft_m['a'] = 10;
  				ft_m['b'] = 30;
  				ft_m['c'] = 50;
  				ft_m['d'] = 70;

				size_t size, ft_size;
				size =  m.size();
				ft_size =  ft_m.size();

				if ((size == ft_size) && (m['b'] == ft_m['b']))
					std::cout <<"\t\t" << green << "OK" << def << std::endl;
				else	
					std::cout << "\t\t" << red << "KO" << def << std::endl;
			}

			std::cout << std::left << std::setw(15) << std::left <<"Range Constructor ";			
			{
				//! fill a map
				std::map<int, std::string> sm;
				ft::map<int, std::string> my_m;

				for (size_t i = 0; i < 1e4; i++)
				{
					sm.insert(std::make_pair(i, "range constructor test"));
					my_m.insert(ft::make_pair(i, "range constructor my_test"));
				}

 				std::map<int, std::string> m (sm.begin(),sm.end());
 				ft::map<int, std::string> ft_m (my_m.begin(),my_m.end());
		
				std::map<int, int>::iterator it , it_end;
				ft::map<int, int>::iterator ft_it , ft_it_end;

				size_t size, ft_size;
				size =  m.size();
				ft_size =  ft_m.size();
				if ((size == ft_size) && (m.begin()->first == ft_m.begin()->first) )
					std::cout <<"\t\t" << green << "OK" << def << std::endl;
				else	
					std::cout << "\t\t" << red << "KO" << def << std::endl;
			}

			std::cout << std::left << std::setw(15) << std::left <<"Copy Constructor ";			
			{
				//! fill a map
				std::map<int, std::string> sm;
				ft::map<int, std::string> my_m;

				for (size_t i = 0; i < 1e4; i++)
				{
					sm.insert(std::make_pair(i, "v"));
					my_m.insert(ft::make_pair(i, "v"));
				}
 				std::map<int, std::string> m (sm.begin(),sm.end());
 				ft::map<int, std::string> ft_m (my_m.begin(),my_m.end());

				std::map<int, int>::iterator it , it_end;
				ft::map<int, int>::iterator ft_it , ft_it_end;

				size_t size, ft_size;
				size =  m.size();
				ft_size =  ft_m.size();
				if ((size == ft_size) && (m.begin()->first == ft_m.begin()->first) )
					std::cout <<"\t\t" << green << "OK" << def << std::endl;
				else	
					std::cout << "\t\t" << red << "KO" << def << std::endl;
			}

			std::cout << std::left << std::setw(15) << std::left <<"\nInsert  Method ";			
			{
				time_t start;
				std::map<int, int> m;
				ft::map<int, int> ft_m;
				
				for (int i = 0; i < 1e5; i++)
				{
					m.insert(std::make_pair(i, i));
					ft_m.insert(ft::make_pair(i, i));
				}
				start = get_time();
				std::map<int, int>::iterator it , it_end;
				ft::map<int, int>::iterator ft_it , ft_it_end;
			
				it = m.begin();
				it_end = m.end();

				ft_it = ft_m.begin();
				ft_it_end = ft_m.end();
				// std::map<int, int> m1(, m1.end());
				// ft::map<int, int> ft_m1(ft_m1.begin(), ft_m1.end());
				
			}
		} 
		catch (std::exception &e){}
	}
	return EXIT_SUCCESS;
}
