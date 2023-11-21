//
// Created by xmly on 2023/11/20.
//

#ifndef C_PLUS_PLUS_LEARN_TEMPLATE_CLASS_H
#define C_PLUS_PLUS_LEARN_TEMPLATE_CLASS_H

// 定义一个模版
template<class T>
class Box {
public:
    void insert(const T &) {}
};

// 定义另外一个模版
template<class U>
class Box2 {
private:
    U data;
public:
    Box2(const U &val) : data(val * 2) {}

    U getData() const { return data; }
};

// 一个负责的案例 tuple
template<typename... Values>
class tuple {
};
// 这是对上述模板的一个特化（Specialization）。
// 这个特化表示当模板参数为空时，也就是没有类型参数时，使用这个特定的实现。
// 在这个情况下，tuple<> 表示一个空元组
template<>
class tuple<> {
};

// 这个类通过继承自 tuple<Tail...>（使用 private 继承）
// tuple<Tail...> 的声明在 template <typename... Values> class tuple{};
template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
typedef tuple<Tail...> inherited;
public:
    tuple() {}
    tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {}

    Head head() { return m_head; }

    // *this 实际上指向的是当前对象，但是由于派生类对象可以隐式地转换为基类对象的引用或指针
    // 所以 *this 可以被返回作为 tuple<Tail...> 类型的引用
    inherited &tail() { return *this; }

protected:
    Head m_head;
};

#endif //C_PLUS_PLUS_LEARN_TEMPLATE_CLASS_H
