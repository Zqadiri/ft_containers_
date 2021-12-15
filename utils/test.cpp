

#include <iostream>

int count;

class test
{

public:
    int val;
    //heap
    test()
    {

    }
    
    test(const test & obj)
    {
        std::cout << "copy" << std::endl;
        
        *this = obj;
    };
    
    ~test() {};

    test    &operator = (const test & obj)
    {
        std::cout << "here"<< std::endl;
        this->val = obj.val;
        return *this;
    };
};


int main(int argc, char const *argv[])
{
    test a;
    // test c;
    test b;


    a = b;

    std::cout << a.val << std::endl;
    return 0;
}
