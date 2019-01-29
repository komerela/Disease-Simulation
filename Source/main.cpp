#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

#include "consoleinput.h"
#include "disease.h"
#include "fileoutput.h"
#include "population.h"
#include "simulation.h"

int main(int argc, char *argv[]) {
    srand(time(0));

    // Input Check
    if (!diseaseSim::isValidInput(argc, argv))
        return EXIT_FAILURE;

    // Disease parameters
    std::string name = argv[1];
    int infectionRate = atoi(argv[2]);
    int deathRate = atoi(argv[3]);

    // get paramaters from console(Include more options) input is ignored for
    // debug

    // new disease
    diseaseSim::Disease disease(name, infectionRate, deathRate, 7);

    // population inputs
    int populationSize = 1000000;
    int minInteractions = 1;
    int maxInteractions = 3;
    diseaseSim::Population population(populationSize, 1, minInteractions,
                                      maxInteractions, disease);

    // make simuation
    diseaseSim::Simulation simulation(population, disease, 365);
    simulation.simulateDisease(true);
    // name += (clock()/1000000);
    diseaseSim::writeToFile(name, simulation.getCDLData());

    return 0;
}
