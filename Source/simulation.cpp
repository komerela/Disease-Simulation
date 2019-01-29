#include "simulation.h"

#include <iostream>
#include <ctime>

namespace diseaseSim {

/*
	Handles simulation objects
*/

Simulation::Simulation(Population& population, Disease& disease, int maxDays)
{
	this->population = population;
	this->disease = disease;
	this->maxDays = maxDays;
	daysPassed = 1;
}

void Simulation::simulateDisease(bool consoleOutput)
{
	disease.printStats();
	population.printStats();
	data = disease.getCdlData();
	unsigned int start;
	unsigned int end;
	start = clock();
	end = 0;
	while (daysPassed <= maxDays && population.getNumInfected() > 0)
	{
		population.interact();


		if (consoleOutput)
		{
			std::cout << "day: " << daysPassed << '/' << maxDays << std::endl;
			population.printStats();
		}
		data += population.getCdlData();
		daysPassed++;

	}
	end = clock();
	std::cout << "Execution time: " <<  (end - start) / (CLOCKS_PER_SEC)  << "Seconds" <<  std::endl;

}

std::string Simulation::getCDLData()
{
	return data;
}

}
