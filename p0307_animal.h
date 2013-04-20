#ifndef P0307_ANIMAL
#define P0307_ANIMAL

#include <string>
#include <queue>
using namespace std;

class Animal{
public:
	string ID;
	int order;
	Animal(string id="", int odr = 0):ID(id),order(odr){
	}
	~Animal(){
	}
};

class AnimalAdopter{
private:
	queue<Animal> dog;
	queue<Animal> cat;
public:
	bool empty() const{
		return dog.empty() && cat.empty();
	}
	bool emptyDog() const{
		return dog.empty();
	}
	bool emptyCat() const{
		return cat.empty();
	}
	int size() const{
		return dog.size() +  cat.size() ;
	}
	int currentOrder();
	void pushDog(Animal);
	void pushCat(Animal);
	void pop();
	void popDog();
	void popCat();
};

#endif	// define P0307_ANIMAL
