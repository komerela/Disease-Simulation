#include <string>
#include <iostream>
#include "disease.h"
#include "population.h"
#include "simulation.h"
#include "time.h"
#include <cstdlib>
#include "consoleinput.h"



int main(int argc, char* argv[])
{
	srand(time(0));
	//the disease of the simulation
	diseaseSim::Disease* disease;
	diseaseSim::Population* population;

	//Input Check

	if(!diseaseSim::isValidInput(argc, argv))
		return EXIT_FAILURE;
	//Disease parameters
	std::string name = argv[1];
	int infectionRate = atoi(argv[2]);
	int deathRate = atoi(argv[3]);

	//get paramaters from console(Include more options) input is ignored for debug


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
