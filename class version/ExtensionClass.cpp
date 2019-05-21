#include "ExtensionClass.h"
#include <cstring>
#include <iostream>

Extension::Extension()
{
    strcpy(extension, "\0");
    strcpy(signature, "\0");
}

Extension::Extension(char * filename)
{
    file.open(filename, std::ios::in | std::ios::binary);
    strtok(filename, ".");
    extension = strtok(NULL, "\0");
    signature = NULL;
}

void Extension::setExtension(char * filename)
{
    extension = strtok(filename, ".");
}

void Extension::setSignature(char * sig)
{
    strcpy(signature, sig);
}

const char * Extension::getExtension() const
{
    return extension;
}

const char * Extension::getSignature() const
{
    return signature;
}

bool Extension::detectSignature()
{
    char read[16];
	int arr[16], value;

    int JPG[] = {-1, -40};
	int BMP[] = {66, 77};
	int PDF[] = {37, 80, 68, 70};
	int PNG[] = {-119, 80, 78, 71, 13, 10, 26, 10};
	int MKV[] = {26, 69, -33, -93};

    if (file.is_open())
	{
		int count = 16;
		bool sigFound = 0;
		file.read(read, 16);
		do
		{
			value = 0;
			for (int i=0; i < count; i++)
			{
				arr[i] = read[i];
				value += arr[i];
			}
			if (count == 2)
			{
				if (arr[0] == JPG[0] && arr[1] == JPG[1])
				{
					std::cout << "File is a JPG" << std::endl;
					sigFound = 1;
				}
				
				else if (arr [0] == BMP[0] && arr[1] == BMP[1])
				{
					std::cout << "File is a BMP" << std::endl;
					sigFound = 1;
				}
			}
			else if (count == 4)
			{
				// this double if is bad practice but it improves readability
				if (arr[0] == PDF[0] &&  arr[1] == PDF[1])
				{
					if (arr[2] == PDF[2] && arr[3] == PDF[3])
					{
							std::cout << "File is a PDF" << std::endl;
							sigFound = 1;
					}
				}
				
				if (arr[0] == MKV[0] && arr[1] == MKV[1])
				{
					if(arr[2] == MKV[2] && arr[3] == MKV[3])
					{
						std::cout << "File is an MKV or WEBM" << std::endl;
						sigFound = 1;
					}
				}
			}
			else if (count == 8)
			{
				for (int i = 0; i < 8; i++)
				{
					if (arr[i] != PNG[i])
						break;
					if (i == 7 && arr[7] == PNG[7])
					{
						std::cout << "File is a PNG" << std::endl;
						sigFound = 1;
					}
				}
			}
			count--;
		} while (!sigFound && count > 0);
	}
	else std::cout << "File does not exist" << std::endl;
}