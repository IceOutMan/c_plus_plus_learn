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

  return 0;
}
