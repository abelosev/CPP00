#include <iostream>
#include <string>

#define noteCountMax 10

class Notebook {
	std::string name;
	std::string note[noteCountMax];
	int noteCount;
};