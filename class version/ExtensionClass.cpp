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
    strcpy(extension, strtok(NULL, "\0"));
    char assign[] = "\0";
	strcpy(signature, assign);
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
					char assign[] = "JPG";
					strcpy(signature, assign);
					sigFound = 1;
					return sigFound;
				}
				
				else if (arr [0] == BMP[0] && arr[1] == BMP[1])
				{
					char assign[] = "BMP";
					strcpy(signature, assign);
					sigFound = 1;
					return sigFound;
				}
			}
			else if (count == 4)
			{
				// this double if is bad practice but it improves readability
				if (arr[0] == PDF[0] &&  arr[1] == PDF[1])
				{
					if (arr[2] == PDF[2] && arr[3] == PDF[3])
					{
							char assign[] = "PDF";
							strcpy(signature, assign);
							sigFound = 1;
							return sigFound;
					}
				}
				
				if (arr[0] == MKV[0] && arr[1] == MKV[1])
				{
					if(arr[2] == MKV[2] && arr[3] == MKV[3])
					{
						char assign[] = "MKV or WEBM";
						strcpy(signature, assign);
						sigFound = 1;
						return sigFound;
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
						char assign[] = "PNG";
						strcpy(signature, assign);
						sigFound = 1;
						return sigFound;
					}
				}
			}
			count--;
		} while (!sigFound && count > 0);
		if (!sigFound && count == 0) 
		{
			strcpy(signature, "File signature not supported or unknown file type");
			return sigFound;
		}
	}
	else std::cout << "File does not exist" << std::endl;
	return false;
}