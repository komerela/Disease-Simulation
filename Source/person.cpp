#include "person.h"

namespace diseaseSim {

// Default person for disease simulation
int Person::numPeople = 0;

Person::Person() {
    numPeople++;       // Number of object instances
    id = numPeople;    // Each has an id
    alive = 1;         // Start out as alive
    infected = false;  // Are they infected
    daysInfected = 0;  // Helps determine death given incubation period
    timesInfected = 0; // How many times did they survive the disease
    interactions = 0;  // Number of one on one interactions

    // Zero same as null
}

// Copy constructor for dynamic memory in population
Person::Person(const Person &person) {
    numPeople++;
    this->alive = person.alive;
    this->daysInfected = person.daysInfected;
    this->infected = person.infected;
    this->id = person.id;
    this->interactions = person.interactions;
    this->timesInfected = person.timesInfected;
}

// Returns true if living
bool Person::isAlive() {
	return alive;
}

// Can set them to dead
void Person::setAlive(bool alive) {
	this->alive = alive;
}

// Make infected
void Person::setInfected(bool infected) {
	this->infected = infected;
}

// days individual was infected
int Person::getDaysInfected() {
	return daysInfected;
}

// Probably should not be used(remove?)
void Person::setDaysInfected(int daysInfected) {
    this->daysInfected = daysInfected;
}

int Person::getTimesInfected() {
	return timesInfected;
}

int Person::getInteractions() {
	return interactions;
}

void Person::setInteractions(int interactons) {
    this->interactions = interactions;
}

bool Person::isInfected() {
	return infected;
}

// returns pointer to next person
Person &Person::getNext() {
	return *next;
}

// Set next person
void Person::setNext(Person *person) {
	next = person;
}

Person &Person::getPrev() {
	return *prev;
}

void Person::setPrev(Person *person) {
	prev = person;
}

} // namespace diseaseSim
