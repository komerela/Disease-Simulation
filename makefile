all:
	g++ -O3 Source/main.cpp Source/consoleinput.cpp Source/fileoutput.cpp Source/disease.cpp Source/person.cpp Source/population.cpp Source/simulation.cpp -o disease