//
// Created by xmly on 2023/11/20.
//

#ifndef C_PLUS_PLUS_LEARN_TEMPLATE_FUNCTION_RECURSION_H
#define C_PLUS_PLUS_LEARN_TEMPLATE_FUNCTION_RECURSION_H

#include <iostream>

// print()作为边界条件处理
void print() {
}

template<typename T, typename... Types>
void print(const T &firstArg, const Types&... args) {
    std::cout << firstArg << " Remain args nums: "<< sizeof...(args) << std::endl;
    // 此处递归调用
    print(args...);

}


// 一个复杂的示例子
template <typename T>
inline void hash_combine(std::size_t& seed, const T& val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template <typename T>
inline void hash_val(std::size_t& seed, const T& val) {
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types&... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

class Customer {
public:
    std::string fname;
    std::string lname;
    std::size_t no;
};

/**
 * CustomerHash 类重载了 operator()，使得 CustomerHash 的对象可以像函数一样被调用。
 *  这是通过在类中定义 operator() 函数来实现的。
 *  用法->
 *        CustomerHash customerHash;
 *        Customer customer;
 *        customerHash(customer);
 */
class CustomerHash {
public:
    std::size_t operator()(const Customer& c) const {
        return hash_val(c.fname, c.lname, c.no);
    }
};

#endif //C_PLUS_PLUS_LEARN_TEMPLATE_FUNCTION_RECURSION_H
