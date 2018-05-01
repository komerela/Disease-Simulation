#include "simulation.h"
#include <iostream>
#include<time.h>

/*Handles simulation objects 

*/
diseaseSim::Simulation::Simulation(diseaseSim::Population& population, diseaseSim::Disease& disease, int maxDays)
{
	this->population = population;
	this->disease = disease;
	this->maxDays = maxDays;
	daysPassed = 1;
}

void diseaseSim::Simulation::simulateDisease(bool consoleOutput)
{
	std::cout << disease;
	std::cout << population;
	data = disease.getCdlData(); 
	unsigned int start, end;
	start = clock();
	while (daysPassed <= maxDays && population.getNumInfected() > 0)
	{
		population.interact();
		

		if (consoleOutput)
		{
			std::cout << "day: " << daysPassed << '/' << maxDays << '\n';
			std::cout << population;
		}
	data += population.getCdlData(); 
		daysPassed++;
		
	}
	end = clock();
	std::cout << "Execution time: " <<  (end - start) / (CLOCKS_PER_SEC)  << "Seconds" <<  std::endl;

}

std::string diseaseSim::Simulation::getCDLData()
{
	return data;
}
