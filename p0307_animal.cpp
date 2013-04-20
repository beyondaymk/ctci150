#include "p0307_animal.h"
#include <iostream>

int AnimalAdopter::currentOrder(){
	if(empty())
		return 0;
	else if(dog.empty())
		return cat.back().order;
	else if(cat.empty())
		return dog.back().order;
	else
		return max(dog.back().order,cat.back().order);
}

void AnimalAdopter::pushDog(Animal d){
	d.order = currentOrder()+1;
	dog.push(d);
}

void AnimalAdopter::pushCat(Animal c){
	c.order = currentOrder()+1;
	cat.push(c);
}

void AnimalAdopter::pop(){
	if( dog.empty() )
		popCat();
	else if( cat.empty() )
		popDog();
	else if( dog.front().order < cat.front().order )
		popDog();
	else
		popCat();
}

void AnimalAdopter::popDog(){
	Animal temp = dog.front();
	dog.pop();
	cout<<"pop "<<temp.ID<<endl;
}

void AnimalAdopter::popCat(){
	Animal temp = cat.front();
	cat.pop();
	cout<<"pop "<<temp.ID<<endl;
}
