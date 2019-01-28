#ifndef SIMULATION_H
#define SIMULATION_H

#include "population.h"
#include "disease.h"
#include <iostream>
namespace diseaseSim
{

	class Simulation
	{
		private:
			diseaseSim::Population population;
			diseaseSim::Disease disease;
			int daysPassed;
			int maxDays;
			std::string data;
		public:
			Simulation(diseaseSim::Population &population, diseaseSim::Disease &disease, int maxDays);
			void simulateDisease(bool consoleOutput);
			void simulatDay();
			std::string getCDLData();
	};

}
#endif
