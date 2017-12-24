// Classical implementation of the Factory Method pattern
#include <iostream>
#include <vector>
using namespace std;

class Person{
  public:
    virtual void info() = 0;
    virtual ~Person(){}
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

// Factory methods -------------------------

class Factory{
public:
    virtual Person* create() = 0;
    virtual ~Factory(){}
};

class ProgrammerFactory: public Factory{
public:
    Person* create(){
      return new Programmer;
    }
};

class BuilderFactory: public Factory{
public:
    Person* create(){
      return new Builder;
    }
};

class DoctorFactory: public Factory{
public:
    Person* create(){
      return new Doctor;
    }
};

int main()
{
  ProgrammerFactory* progFactory  = new ProgrammerFactory;
  BuilderFactory*    builFactory  = new BuilderFactory;
  DoctorFactory*     doctFactory  = new DoctorFactory;

  vector<Person*> workers;
  workers.push_back(progFactory->create());
  workers.push_back(builFactory->create());
  workers.push_back(doctFactory->create());

  for(int i = 0; i < workers.size(); ++i)
    workers[i]->info();

}








