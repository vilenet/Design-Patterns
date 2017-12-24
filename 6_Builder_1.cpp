#include <iostream>
using namespace std;

//-----------------------------------------------------------
/* Interface that will be returned as the product from builder */
class HousePlan{
public:
 virtual void setWindow(string window)=0;
 virtual void setDoor(string door)=0;
 virtual void setBathroom(string bathroom)=0;
 virtual void setKitchen(string kitchen)=0;
 virtual void setFloor(string floor)=0;
};

//-----------------------------------------------------------
/* Concrete class for the HousePlan interface */
class House: public HousePlan{
private :
 string window, door, kitchen, bathroom, floor;

public:
 void setWindow(string Window)    { window = Window;     }
 void setDoor(string Door)        { door = Door;         }
 void setBathroom(string Bathroom){ bathroom = Bathroom; }
 void setKitchen(string Kitchen)  { kitchen = Kitchen;   }
 void setFloor(string Floor)      { floor = Floor;       }

 void info(){
   cout << "Window: "   << window   << endl
        << "Door: "     << door     << endl
        << "Kitchen: "  << kitchen  << endl
        << "Bathroom: " << bathroom << endl
        << "Floor: "    << floor    << endl << endl;
 }
};

//-----------------------------------------------------------
/* Builder Class */
class HouseBuilder
{
public:
 /* Abstract functions to build parts */
 virtual void buildWindow()=0;
 virtual void buildDoor()=0;
 virtual void buildKitchen()=0;
 virtual void buildBathroom()=0;
 virtual void buildFloor()=0;
 /* The product is returned by this function */
 virtual House* getHouse()=0;
};

//-----------------------------------------------------------
/* Concrete class for the builder interface */
class FrenchHouse:public HouseBuilder{
private:
 House *house;
public:
 FrenchHouse(){house = new House();}

 void buildWindow()  { house->setWindow("French Window");    }
 void buildDoor()    { house->setDoor("Wooden Door");        }
 void buildBathroom(){ house->setBathroom("Modern Bathroom");}
 void buildKitchen() { house->setKitchen("Modular Kitchen"); }
 void buildFloor()   { house->setFloor("Wooden Floor");      }

 House* getHouse(){return this->house;}
};

//-----------------------------------------------------------
/* Another Concrete class for the builder interface */
class DefaultHouse:public HouseBuilder{
private:
 House *house;
public:
 DefaultHouse(){house = new House();}

 void buildWindow()  { house->setWindow("Normal Window");     }
 void buildDoor()    { house->setDoor("Metal Door");          }
 void buildBathroom(){ house->setBathroom("Regular Bathroom");}
 void buildKitchen() { house->setKitchen("Regular Kitchen");  }
 void buildFloor()   { house->setFloor("Mosaic Floor");       }

 House* getHouse(){return this->house;}
};

//-----------------------------------------------------------
/* The Director. Constructs the house */
class Director{
private:
 HouseBuilder *houseBuilder;

public:
 Director(HouseBuilder *houseBuilder){
  this->houseBuilder = houseBuilder;
 }

 House *getHouse(){
  return houseBuilder->getHouse();
 }

 void buildHouse(){
  houseBuilder->buildWindow();
  houseBuilder->buildDoor();
  houseBuilder->buildBathroom();
  houseBuilder->buildKitchen();
  houseBuilder->buildFloor();
 }
};

/* Example on how to use the Builder design pattern */
int main()
{
 HouseBuilder *frenchHouseBldr = new FrenchHouse();
 HouseBuilder *defaultHouseBldr = new DefaultHouse();

 Director *dir1 = new Director( frenchHouseBldr );
 Director *dir2 = new Director( defaultHouseBldr );

 dir1->buildHouse();
 House *house1 = dir1->getHouse();
 cout << "French plan constructed\n\n";
 house1->info();


 dir2->buildHouse();
 House *house2 = dir2->getHouse();
 cout << "Default plan constructed\n\n";
 house2->info();
}
