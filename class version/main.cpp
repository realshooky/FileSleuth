#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ExtensionClass.h"

int main(int argc, char ** argv)
{
	std::fstream file;
	file.open(argv[1]);
	if(file.is_open())
	{
		std::string line;
		file >> line;
		char c_line[line.size()];
		strcpy(c_line, line.c_str());
		Extension x(c_line);
		std::cout << "This file claims to be a(n) " << x.getExtension() << std::endl;
    	x.detectSignature();
    	std::cout << "According to its signature, this file is a(n)" 
    		<< x.getSignature() << std::endl;
	}
    return 0;
}