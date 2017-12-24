// Implementing the Abstract Factory Pattern
#include <iostream>
#include <vector>
using namespace std;

// kind of work -----------------------
class BrainWorker{
public:
    virtual void info() = 0;
    virtual ~BrainWorker() {}
};

class ManualWorker{
public:
    virtual void info() = 0;
    virtual ~ManualWorker() {}
};

// USA workers professions ------------------------
class USA_Builder: public ManualWorker{
public:
  void info() {
    cout << "USA_Builder" << endl;
  }
};

class USA_Writer: public BrainWorker{
public:
  void info() {
    cout << "USA_Writer" << endl;
  }
};

// RUS workers professions ------------------------
class RUS_Builder: public ManualWorker{
public:
  void info() {
    cout << "RUS_Builder" << endl;
  }
};

class RUS_Writer: public BrainWorker{
public:
  void info() {
    cout << "RUS_Writer" << endl;
  }
};

// Abstract factory for the production of type workers --
class WorkersFactory{
public:
  virtual ManualWorker* createManualWorker() = 0;
  virtual BrainWorker*  createBrainWorker() = 0;
  virtual ~WorkersFactory(){}
};

// Factory for the production of USA workers
class WorkersFactoryUSA: public WorkersFactory{
public:
  ManualWorker* createManualWorker(){
    return new USA_Builder;
  }
  BrainWorker* createBrainWorker(){
    return new USA_Writer;
  }
};

// Factory for the production of RUS workers
class WorkersFactoryRUS: public WorkersFactory{
public:
  ManualWorker* createManualWorker(){
    return new RUS_Builder;
  }
  BrainWorker* createBrainWorker(){
    return new RUS_Writer;
  }
};

// company in which workers from two countries work
class Company{
public:
  vector<BrainWorker*>  vb;
  vector<ManualWorker*> vm;

  void info(){
    for(int i=0; i < vb.size(); ++i)
      vb[i]->info();
    for(int i=0; i < vm.size(); ++i)
      vm[i]->info();
  }

  ~Company(){
    for(int i=0; i < vb.size(); ++i)
      delete vb[i];
    for(int i=0; i < vm.size(); ++i)
      delete vm[i];
  }
};

// Here is created a worker of one of the countries
class Worker{
public:
  Company* create(WorkersFactory& factory){
    Company* company = new Company;
    company->vb.push_back( factory.createBrainWorker());
    company->vm.push_back( factory.createManualWorker());
    return company;
  }
};

int main()
{
  Worker worker;

  WorkersFactoryUSA usa_factory;
  WorkersFactoryRUS rus_factory;

  Company* company1 = worker.create(usa_factory);
  Company* company2 = worker.create(rus_factory);

  cout << "------usa workers-----" << endl;
  company1->info();
  cout << endl;

  cout << "------rus workers-----" << endl;
  company2->info();
  cout << endl;
}





