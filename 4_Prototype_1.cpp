// Implementing the Prototype Pattern Using Factory Class
#include <iostream>
#include <vector>
using namespace std;

//Polymorphic base class
class Person{
public:
  virtual Person* clone() = 0;
  virtual void info() = 0;
  virtual ~Person(){}
};

class Student: public Person{
private:
  friend class Prototype;
  Student(){}

public:
  Person* clone(){
    return new Student(*this);
  }
  void info(){
    cout << "Student" << endl;
  }
};

class Professor: public Person{
private:
  friend class Prototype;
  Professor(){}

public:
  Person* clone(){
    return new Professor(*this);
  }
  void info(){
    cout << "Professor" << endl;
  }
};

class Prototype{
public:
  Person* createStudent(){
    static Student prototype;
    return prototype.clone();
  }
  Person* createProfessor(){
    static Professor prototype;
    return prototype.clone();
  }
};

int main()
{
  Prototype prototype;
  vector<Person*> v;

  v.push_back(prototype.createStudent());
  v.push_back(prototype.createProfessor());

  for(int i = 0; i < v.size(); ++i)
    v[i]->info();

  cout << endl;
}








































