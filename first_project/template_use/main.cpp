#include <iostream>
#include "template_function_recursion.h"
#include "template_class.h"


int main() {

    // class template use
    Box<int> intBox;
    intBox.insert(123);

    Box<Box<int> > boxOfBox;
    boxOfBox.insert(intBox);

    // recursion template use
    print(7.5, "hello", std::bitset<16>(377), 42);

    // tuple template use
    tuple<int,float,std::string> t(666,6.66,"hello");
    std::cout << t.head() << std::endl;
    std::cout << t.tail().head() << std::endl;
    std::cout << t.tail().tail().head() << std::endl;

    return 0;
}
