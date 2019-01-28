#include "../Includes/disease.h"


//Constructor
diseaseSim::Disease::Disease()
{
	name = "";
	infectionRate = 50;
	deathRate = 40;
	incubation = 7;
}
diseaseSim::Disease::Disease(std::string name, int infectionRate, int deathRate,int incubation)
{
	this->name = name;
	this->infectionRate = infectionRate; 
	this->deathRate = deathRate;
	this->incubation = incubation;
	
}

//geters and setters
int diseaseSim::Disease::getInfectionRate()
{
	return infectionRate;
}

int diseaseSim::Disease::getIncubationTime()
{
	return incubation;
}

void diseaseSim::Disease::setIncubationTime(int incubation)
{
	this->incubation = incubation;
}

void diseaseSim::Disease::setInfectionRate(int infectionRate)
{
	this->infectionRate = infectionRate;
}

int diseaseSim::Disease::getDeathRate()
{
	return deathRate;
}

void diseaseSim::Disease::setDeathRate(int deatRate)
{
	this->deathRate = deathRate;
}

std::string diseaseSim::Disease::getName()
{
	return name;
}

void diseaseSim::Disease::setName(std::string name)
{
	this->name = name;
}

//Output disease data to console
void diseaseSim::Disease::printStats()
{
	std::cout << "\n";
	std::cout << "Disease Name: " << name << '\n' << "InfectionRate: ";
	std::cout  << infectionRate << "%\n" << "death Rate: " << deathRate <<'%';
	std::cout << "\nDisease incubation: " << incubation << "days\n\n";

}

//for comma Delimited file
std::string diseaseSim::Disease::getCdlData()
{
	std::string cdlData = " ";
	cdlData += "Disease,Infection Rate, Death Rate, Incubation\n" + name;
	cdlData +=  ',' + infectionRate + ',' + deathRate + ',' + incubation + "\n\n";
	return cdlData;
}
