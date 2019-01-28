#include "../Includes/fileoutput.h"

void diseaseSim::writeToFile(std::string name, std::string data)
{
	data += '\0';	
	std::string file  = name + ".txt";
	std::ofstream out("name.txt", std::ofstream::out);	
	
	
	
	out << data;

	
		
	out.close();
}
