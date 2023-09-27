#include <__memory/allocator_traits.h>
#include <algorithm>
#include <iostream>
#include <xlocale/_stdio.h>
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

Dog::Dog() { std::cout << "A dog has been constructed\n"; }

void Dog::setName(const std::string &dogsName) { name = dogsName; }

void Dog::setWeight(int dogsWeight) { weight = dogsWeight; }

void Dog::print() const {
  std::cout << "Dog is " << name << " and weight " << weight << "kg\n";
}

Dog::~Dog() { std::cout << "Goodbye " << name << '\n'; }

// ============++++++++++++++++++++++++++++++
class OwnedDog : public Dog {
public:
  void setOwner(const std::string &dogsOwner);

  void print() const override;

private:
  std::string owner;
};

void OwnedDog::setOwner(const std::string &dogsOwner) { owner = dogsOwner; }

void OwnedDog::print() const {
  Dog::print();
  std::cout << "Dog is owned by " << owner << '\n';
}


int main(int argc, char **argv) {

  cout << "hello class inherit" << endl;
  return 0;
}
