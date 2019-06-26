#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ExtensionClass.h"

int main(int argc, char ** argv)
{
	Extension x(argv[1]);
	if(x.getFileStatus())
	{
		std::cout << "This file's extension is " << x.getExtension() << std::endl;
    	if (x.detectSignature())
    	{
			std::cout << "According to its signature, this file is a(n) ";
    		std::cout << x.getSignature() << std::endl;
		}
		else
		{
			std::cout << x.getSignature() << std::endl;
		}
		
	}
	else std::cout << "No file found at provided path: " << argv[1] << std::endl;
    return 0;
}