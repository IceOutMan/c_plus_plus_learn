#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {

  class Animal {
  public:
    void voice() { cout << "voice of animal" << endl; }
    virtual void run() { cout << "run of animal" << endl; }
  };

  class Tigger : public Animal {
  public:
    void voice() { cout << "voie of tiger" << endl; }
    void run() { cout << "run of tigger" << endl; }
  };

  class Bear : public Animal {
  public:
    void voice() { cout << "voice of bear" << endl; }
    void run() { cout << "run of bear" << endl; }
  };

  Animal *base = new (Animal);
  Animal *tigger = new (Tigger);
  Animal *bear = new (Bear);
  base->voice();
  tigger->voice();
  bear->voice();
  cout << "==========================" << endl;
  base->run();
  tigger->run();
  bear->run();
  cout << "==========================" << endl;
  ((Tigger *)bear)->run();
  ((Tigger *)bear)->voice();

  return 0;
}
