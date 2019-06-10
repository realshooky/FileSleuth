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
		Extension x(argv[1]);
		std::cout << "This file's extension is " << x.getExtension() << std::endl;
    	x.detectSignature();
    	std::cout << "According to its signature, this file is a(n) ";
    	std::cout << x.getSignature() << std::endl;
	}
    return 0;
}