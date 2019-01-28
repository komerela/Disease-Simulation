#ifndef DISEASE_H
#define DISEASE_H

#include "diseaseSim.h"
#include <string>
#include <fstream>
#include <iostream>
namespace diseaseSim
{

	class Disease
	{
		int deathRate;
		int infectionRate;
		int incubation;
		std::string name;

	public:
		Disease();
		Disease(std::string name, int infectionRate, int deathRate,int incubation);
		void setDeathRate(int deathRate);
		int getDeathRate();
		std::string getName();
		void setName(std::string name);
		void setInfectionRate(int infectionRate);
		int getInfectionRate();
		int getIncubationTime();
		void setIncubationTime(int incubation);
		std::string getCdlData();
		void printStats();
		

	};
}

#endif
