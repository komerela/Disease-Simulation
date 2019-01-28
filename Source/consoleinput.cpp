#include "../Includes/consoleinput.h"

bool diseaseSim::isValidInput(int argc, char * argv[])
{
	int valid = true;
	if (argc == 4)
	{
		try
		{
			int deathRate = atoi(argv[2]);
			int infectionRate = atoi(argv[3]);
			if (infectionRate < 1 || infectionRate > 100)
			{
				valid = false;
				std::cerr << "Argument 2 is not an integer between 1 and 100 \n";
			}
			if (deathRate < 1 || deathRate > 100)
			{
				valid = false;
				std::cerr << "Argument 3 is not an integer between 1 and 100\n";
			}
		}
		catch (std::exception e)
		{
			std::cerr << "Arguments do not match type:(string, int, int)\n";

		}
	}

	else
	{
		std::cerr << "Incorrect number of arguments\n";
		valid = false;

	}
	if(!valid)
        {
        	std::cerr<< "Usage:" << argv[0] << " <diseaseName> <infectionRate> <deathRate>\n";
	}

	return valid;
}
