#include "fileoutput.h"

#include <fstream>

namespace diseaseSim {

void writeToFile(std::string name, std::string data) {
    data += '\0';
    std::string file = name + ".txt";

    std::ofstream out("name.txt", std::ofstream::out);
    out << data;
    out.close();
}

} // namespace diseaseSim
