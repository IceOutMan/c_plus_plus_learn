#include <iostream>
template <class T>
class Box {
public:
  void insert(const T &) {}
};

int main() {

  Box<int> intBox;
  intBox.insert(123);

  Box<Box<int> > boxOfBox;
  boxOfBox.insert(intBox);

  std::cout << "hello" << std::endl;
  return 0;
}
