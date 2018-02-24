#include <string>
#include <iostream>
#include "disease.h"
#include "population.h"
#include "simulation.h"
#include "time.h"
#include <cstdlib>
#include <sstream>


int main(int argc, char* argv[])
{
	srand(time(0));
	//the disease of the simulation
	diseaseSim::Disease* disease;
	diseaseSim::Population* population;


	//Disease parameters
	std::string name;
	int infectionRate;
	int deathRate;

	//get paramaters from console(Include more options) input is ignored for debug
	if (argc == 4)
	{
		try
		{
	
			name = argv[1];
			std::cout << name;
			infectionRate = (long)argv[2];
			deathRate =  (long)argv[3];
		}
		catch (std::exception e)
		{
			std::cerr << "Arguments do not match type:(string, int, int)";

		}
	}

	else
	{
		std::cerr << "usage: " << argv[0] << "<diseaseName> <infectionRate> <deathChanceForInfected>\n";
	}

	//new disease
	disease = new diseaseSim::Disease(name, infectionRate, deathRate,7);

	//population inputs
	int populationSize = 1000000;
	int minInteractions = 1;
	int maxInteractions = 3;
	population = new  diseaseSim::Population(1000000, 1, 1, 3, *disease);

	//make simuation
	diseaseSim::Simulation* simulation = new  diseaseSim::Simulation(*population, *disease, 365);
	simulation->simulateDisease(true);
	
	return 0;
}
