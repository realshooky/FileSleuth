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

bool Extension::getFileStatus() const
{
  return file.is_open();
}

bool Extension::detectSignature()
{
  char read[16];
	int arr[16], value;

  // length 2
  int JPG[] = {-1, -40};
	int BMP[] = {66, 77};
  int TAR_LZW[] = {31, -99};
  int TAR_LZH[] = {31, -96};
  
  // length 4
	int PDF[] = {37, 80, 68, 70};
	int MKV[] = {26, 69, -33, -93};
  int MIDI[] = {77, 84, 104, 100};
  int DAT[] = {67, 82, 69, 71};

  // length 8
  int PNG[] = {-119, 80, 78, 71, 13, 10, 26, 10};
  int FLAC[] = {102, 76, 97, 67, 0, 0, 0, 34};

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

      //  Future Implementations should break each of the sections
      //  up by length and give each a discrete function call
      //  simplifying and shortening the detectSignature() function

			if (count == 2)
			{
        if (count2compare(arr, JPG, "JPG")) return sigFound = true;
        else if (count2compare(arr, BMP, "BMP")) return sigFound = true;
        else if (count2compare(arr, TAR_LZW, "TAR_LSW")) return sigFound = true;
        else if (count2compare(arr, TAR_LZH, "TAR_LZH")) return sigFound = true;
			}
			else if (count == 4)
			{
				// this double if is bad practice but it improves readability
        if (count4compare(arr, PDF, "PDF")) return sigFound = true;			
        else if (count4compare(arr, MKV, "MKV or WEBM")) return sigFound = true;		
        else if (count4compare(arr, MIDI, "MIDI")) return sigFound = true;
        else if (count4compare(arr, DAT, "DAT")) return sigFound = true;
			}

      // count 8 seems to be very inefficient
      // try to find a better way
			else if (count == 8)
			{
        if (count8compare(arr, PNG, "PNG")) return sigFound = true;
        else if (count8compare(arr, FLAC, "FLAC")) return sigFound = true;
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

bool Extension::count2compare(int carr[], int farr[], char assign[])
{
  if (carr[0] == farr[0] && carr[1] == farr[1])
  {
    strcpy(signature, assign);
    return true;
  }
  return false;
}

bool Extension::count4compare(int carr[], int farr[], char assign[])
{
  if (carr[0] == farr[0] && carr[1] == farr[1])
  {
    if (carr[2] == farr[2] && carr[3] == farr[3])
    {
      strcpy(signature, assign);
      return true;
    }
  }
  return false;
}

// count 8 seems to be very inefficient
// try to find a better way
bool Extension::count8compare(int carr[], int farr[], char assign[])
{
  for (int i = 0; i < 8; i++)
  {
    if (carr[i] != farr[i])
      break;
    if (i == 7 && carr[7] == farr[7])
    {
      strcpy(signature, assign);
      return true;
    }
  }
  return false;
}