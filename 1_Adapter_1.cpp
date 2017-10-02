// Classical implementation of the Adapter pattern
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
class ConcreteStudent : public Person{
  string lastName;
  Student* student;
public:
  ConcreteStudent(string fName, string lName){
    student = new Student(fName);
    lastName = lName;
  }
  ~ConcreteStudent(){
    delete student;
  }

  virtual void name(){
    cout << "First ";
    student->name();
    cout << "Last name " << lastName << endl;
  }
};

int main()
{
    Person* p = new ConcreteStudent("Viktor", "Zinoviev");
    p->name();

}
