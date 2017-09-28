// Ptototype pattern implementation based on the generalized constructor
#include <iostream>
#include <vector>
#include <map>
using namespace std;

enum Person_ID{ Student_ID, Professor_ID };

class Person;
typedef map<Person_ID, Person*> PersonMap;

// The prototype registry is defined as Singleton Meyers
PersonMap& getPersonMap(){
  static PersonMap instance;
  return instance;
}

// The only purpose of this class is to help in
// choosing the right constructor when creating prototypes
class Dummy{};

//Polymorphic base class
class Person{
public:
  virtual Person* clone() = 0;
  virtual void info() = 0;
  virtual ~Person(){}

  static Person* createPerson(Person_ID id){
    PersonMap& Map = getPersonMap();
    if(Map.find(id) != Map.end())
      return Map[id]->clone();

    return 0;
  }

protected:
  static void addPrototype( Person_ID id, Person* prototype){
    PersonMap& Map = getPersonMap();
    Map[id] = prototype;
  }

  static removePrototype(Person_ID id){
    PersonMap& Map = getPersonMap();
    Map.erase( Map.find(id) );
  }
};

class Student: public Person{
private:
  static Student prototype;
  Student(){}
  Student( Dummy ){
    Person::addPrototype( Student_ID, this );
  }

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
  static Professor prototype;
  Professor(){}
  Professor( Dummy ){
    Person::addPrototype( Professor_ID, this );
  }

public:
  Person* clone(){
    return new Professor(*this);
  }
  void info(){
    cout << "Professor" << endl;
  }
};

Student Student::prototype = Student( Dummy() );
Professor Professor::prototype = Professor( Dummy() );

int main()
{
  vector<Person*> v;

  v.push_back(Person::createPerson( Student_ID) );
  v.push_back(Person::createPerson( Professor_ID) );

  for(int i = 0; i < v.size(); ++i)
    v[i]->info();

  cout << endl;
}








































