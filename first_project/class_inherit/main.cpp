#include <iostream>
using namespace std;

class Dog {
  std::string name;
  int weight;

public:
  Dog();
  void setName(const std::string &dogsName);

  void setWeight(int dogsWeight);

  virtual void print() const;
  void bark() const { std::cout << name << " barks!\n"; }

  virtual ~Dog();
};

Dog::Dog()
{
    std::cout << "A dog has been constructed\n";
}

void Dog::setName(const std::string& dogsName)
{
    name = dogsName;
}


int main(int argc, char **argv) {


  cout << "hello" << endl;
  return 0;
}
