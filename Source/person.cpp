#include "../Includes/person.h"

//Default person for disease simulation
int diseaseSim::Person::numPeople = 0;
diseaseSim::Person::Person()
{
	numPeople++;		//Number of object instances
	id = numPeople;		//Each has an id 
	alive = 1;			//Start out as alive
	infected = false;	//Are they infected
	daysInfected = 0;	//Helps determine death given incubation period
	timesInfected = 0;	//How many times did they survive the disease
	interactions = 0;	//Number of one on one interactions
	
	//Zero same as null

}

//Copy constructor for dynamic memory in population
diseaseSim::Person::Person(const Person &person)
{
	numPeople++;
	this->alive = person.alive;
	this->daysInfected = person.daysInfected;
	this->infected = person.infected;
	this->id = person.id;
	this->interactions = person.interactions;
	this->timesInfected = person.timesInfected;
}

//Returns true if living
bool diseaseSim::Person::isAlive()
{
	return alive;
}

//Can set them to dead
void diseaseSim::Person::setAlive(bool alive)
{
	this->alive = alive;
}

//Make infected
void diseaseSim::Person::setInfected(bool infected)
{
	this->infected = infected;
}

//days individual was infected
int diseaseSim::Person::getDaysInfected()
{
	return daysInfected;
}

//Probably should not be used(remove?)
void diseaseSim::Person::setDaysInfected(int daysInfected)
{
	this->daysInfected = daysInfected;
}


int diseaseSim::Person::getTimesInfected()
{
	return timesInfected;
}
int diseaseSim::Person::getInteractions()
{
	return interactions;
}

void diseaseSim::Person::setInteractions(int interactons)
{
	this->interactions = interactions;
}


bool diseaseSim::Person::isInfected()
{
	return infected;
}


//returns pointer to next person
diseaseSim::Person& diseaseSim::Person::getNext()
{
	return *next;
}

//Set next person
void diseaseSim::Person::setNext(diseaseSim::Person *person)
{
	next = person;
}

diseaseSim::Person& diseaseSim::Person::getPrev()
{
	return *prev;
}

void diseaseSim::Person::setPrev(diseaseSim::Person *person)
{
	prev = person;
}
