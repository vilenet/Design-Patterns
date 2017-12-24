// Implementing the Factory Method pattern based on the generic constructor
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

enum PersonID{ builder, programmer, doctor};

class Person{
  public:
    virtual void info() = 0;
    virtual ~Person(){}
    static Person* create(PersonID id);
};

class Builder: public Person{
public:
    void info() {
      cout << "Builder" << endl;
    }
};

class Programmer: public Person{
public:
    void info() {
      cout << "Programmer" << endl;
    }
};

class Doctor: public Person{
public:
    void info() {
      cout << "Doctor" << endl;
    }
};

// Factory method to create objects of different types.
Person* Person::create(PersonID id){
      Person* person;
      switch(id){
        case builder: person    = new Builder(); break;
        case programmer: person = new Programmer(); break;
        case doctor: person     = new Doctor(); break;
        default: assert(false);
      }
}

int main()
{
  vector<Person*> workers;
  workers.push_back(Person::create(programmer));
  workers.push_back(Person::create(doctor));
  workers.push_back(Person::create(builder));

  for(int i = 0; i < workers.size(); ++i)
    workers[i]->info();

}








