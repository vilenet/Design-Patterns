// Implementing the Adapter Pattern Based on private Inheritance
#include <iostream>
#include <string>
using namespace std;

// the target class
class Person{
 public:
    virtual void name() = 0;
};

// the adaptee class
class Student{
    string Name;
public:
    Student(string s){
      Name = s;
    }
    void name(){
       cout << "name " << Name << endl;
    }
};

// the adapter class
class ConcreteStudent : public Person, private Student {
  string lastName;
public:
  ConcreteStudent(string fName, string lName): Student(fName){
    lastName = lName;
  }

  virtual void name(){
    cout << "First ";
    Student::name();
    cout << "Last name " << lastName << endl;
  }
};

int main()
{
    Person* p = new ConcreteStudent("Viktor", "Zinoviev");
    p->name();

}






