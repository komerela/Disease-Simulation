#include "disease.h"

#include <iostream>

namespace diseaseSim {

Disease::Disease() {
    name = "";
    infectionRate = 50;
    deathRate = 40;
    incubation = 7;
}

Disease::Disease(std::string name, int infectionRate, int deathRate,
                 int incubation) {
    this->name = name;
    this->infectionRate = infectionRate;
    this->deathRate = deathRate;
    this->incubation = incubation;
}

// geters and setters
int Disease::getInfectionRate() {
	return infectionRate;
}

int Disease::getIncubationTime() {
	return incubation;
}

void Disease::setIncubationTime(int incubation) {
    this->incubation = incubation;
}

void Disease::setInfectionRate(int infectionRate) {
    this->infectionRate = infectionRate;
}

int Disease::getDeathRate() {
	return deathRate;
}

void Disease::setDeathRate(int deatRate) {
	this->deathRate = deathRate;
}

std::string Disease::getName() {
	return name;
}

void Disease::setName(std::string name) {
	this->name = name;
}

// Output disease data to console
void Disease::printStats() {
    std::cout << "\n";
    std::cout << "Disease Name: " << name << '\n' << "InfectionRate: ";
    std::cout << infectionRate << "%\n"
              << "death Rate: " << deathRate << '%';
    std::cout << "\nDisease incubation: " << incubation << "days\n\n";
}

// for comma Delimited file
std::string Disease::getCdlData() {
    std::string cdlData = " ";
    cdlData += "Disease,Infection Rate, Death Rate, Incubation\n" + name;
    cdlData +=
        ',' + infectionRate + ',' + deathRate + ',' + incubation + "\n\n";
    return cdlData;
}

} // namespace diseaseSim
