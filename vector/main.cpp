
//  Includes

#include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include "vector.hpp"

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

void    vector_tests(void)
{
	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier yellow(Color::FG_YELLOW); // right answer
	Color::Modifier red(Color::FG_RED); // false answer
	Color::Modifier def(Color::FG_DEFAULT);
	try{
		// ! timeLimitTest
	std::cout << std::left << std::setw(15) << std::left <<"\nFill Constructor ";
		time_t start, end, diff= 1;
		bool	tle;
		start = get_time();
		std::vector<int> v(1e7, 10);
		end = get_time();
		print_time(start, end);
		diff = end - start;
		start = get_time();
		ft::Vector<int> ft_v(1e7, 10);
		end = get_time();
		print_time(start, end);

		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v1(10, "f");
		ft::Vector<std::string> ft_v1(10, "f");

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;
		
		for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << green << "TL" << def << std::endl;
		else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout <<"\t\t" << green << "OK" << def << std::endl;
		else	
			std::cout << "\t\t" << red << "KO" << def << std::endl;

	std::cout << std::left << std::setw(15) << std::left <<"Range Constructor ";
	{
		// ! timeLimitTest
		time_t start, end, diff = 1;
		bool	tle;
		std::vector<int>	input(1e6, 10);
		start = get_time();
		std::vector<int> v(input.begin(), input.end());
		end = get_time();
		print_time(start, end);
		diff = end - start;
		ft::Vector<int>		ft_input(1e6, 10);
		start = get_time();
		ft::Vector<int> ft_v(ft_input.begin(), ft_input.end());
		end = get_time();
		print_time(start, end);

		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v2(10, "range");
		std::vector<std::string> v1(v2.begin(), v2.end());
		ft::Vector<std::string> ft_v2(10, "range");
		ft::Vector<std::string> ft_v1(ft_v2.begin(), ft_v2.end());

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;
		
		for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << green << "TL" << def << std::endl;
		if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout << "\t\t" << green << "OK" << def << std::endl;
		else	
			std::cout << "\t\t" << red << "KO" << def << std::endl;
	}
	std::cout << std::left << std::setw(15) << std::left <<"Copy Constructor";
	{
		// ! timeLimitTest
		time_t start, end, diff = 1;
		bool	tle;
		std::vector<int>	copy(1e6, 10);
		start = get_time();
		std::vector<int> v(copy);
		end = get_time();
		print_time(start, end);
		diff = end - start;
		ft::Vector<int>		ft_copy(1e6, 10);
		start = get_time();
		ft::Vector<int> ft_v(ft_copy);
		end = get_time();
		print_time(start, end);

		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v2(10, "range");
		std::vector<std::string> v1(v2);
		ft::Vector<std::string> ft_v2(10, "range");
		ft::Vector<std::string> ft_v1(ft_v2);

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;
		
		for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << green << "TL" << def << std::endl;
		else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout << "\t\t" << green << "OK" << def << std::endl;
		else	
			std::cout << "\t\t" << red << "KO" << def << std::endl;
	}
	std::cout << std::left << std::setw(15) << std::left <<"Assignement Operator";
	{
		time_t start, end, diff = 1;
		std::vector<int>	copy(1e6, 10);
		std::vector<int> v;
		start = get_time();
		v = copy;
		end = get_time();
		print_time(start, end);
		diff = end - start;
		ft::Vector<int>		ft_copy(1e6, 10);
		start = get_time();
		ft::Vector<int> ft_v;
		ft_v = ft_copy;
		end = get_time();
		print_time(start, end);

		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v2(10, "range");
		std::vector<std::string> v1;
		v1 = v2;
		ft::Vector<std::string> ft_v1;
		ft::Vector<std::string> ft_v2(10, "range");
		ft_v1 = ft_v2;

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;
		
		for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << green << "TL" << def << std::endl;
		else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout << "\t\t" << green << "OK" << def << std::endl;
		else	
			std::cout << "\t\t" << red << "KO" << def << std::endl;
	}
	std::cout << std::left << std::setw(15) << std::left <<"Assignement Operator";
	{
		std::string res, ft_res;
		size_t c, ft_c, s, ft_s;

		std::vector<std::string> v2(10, "range");
		std::vector<std::string> v1(5, "string");
		v1 = v2;
		ft::Vector<std::string> ft_v1(5, "string");
		ft::Vector<std::string> ft_v2(10, "range");
		ft_v1 = ft_v2;

		c = v1.capacity();
		ft_c = ft_v1.capacity();
		s = v1.size();
		ft_s = ft_v1.size();
		for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
			res += *it;
		
		for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
			ft_res += *it;
		if ((end - start) > (diff * 20))
			std::cout << "\t\t" << green << "TL" << def << std::endl;
		else if ((res == ft_res) && (s == ft_s) && (c == ft_c))
			std::cout << "\t\t" << green << "OK" << def << std::endl;
		else	
			std::cout << "\t\t" << red << "KO" << def << std::endl;
	}
	}
	catch (std::exception &e){
	}
}

int main() {
	Color::Modifier green(Color::FG_GREEN);
	Color::Modifier blue(Color::FG_BLUE);
	Color::Modifier def(Color::FG_DEFAULT);

	std::cout << blue << "-----------------------------------------------------------" << def << std::endl;
	std::cout << blue << "---------------------- Vector Tests -----------------------" << def << std::endl;
	vector_tests();
	return EXIT_SUCCESS;
}
