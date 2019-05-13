#include <iostream>
#include <fstream>
using namespace std;

// global vars
int JPG[] = {-1, -40};
int BMP[] = {66, 77};
int PDF[] = {37, 80, 68, 70};
int PNG[] = {-119, 80, 78, 71, 13, 10, 26, 10};
int MKV[] = {26, 69, -33, -93};

int main(int argc, char ** argv)
{	
	// declaring vars
	fstream file;
	char read[16];
	int arr[16], value;
	
	if (argc == 1)
	{
		cout << "No args provided. Appropriate amount is 1." << endl;
		exit(1);
	}
	if (argc > 2)
	{
		cout << "Too many args. Appropriate amount is 1." << endl;
		exit(1);
	}

	file.open(argv[1], ios::in | ios::binary);
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
			{;
				if (arr[0] == JPG[0] && arr[1] == JPG[1])
				{
					cout << "File is a JPG" << endl;
					sigFound = 1;
				}
				
				else if (arr [0] == BMP[0] && arr[1] == BMP[1])
				{
					cout << "File is a BMP" << endl;
					sigFound = 1;
				}
			}
			else if (count == 4)
			{
				//for(int i = 0; i < 4; i++)
					//cout << arr[i] << " ";
				// this double if is bad practice but it improves readability
				if (arr[0] == PDF[0] &&  arr[1] == PDF[1])
				{
					if (arr[2] == PDF[2] && arr[3] == PDF[3])
					{
							cout << "File is a PDF" << endl;
							sigFound = 1;
					}
				}
				
				if (arr[0] == MKV[0] && arr[1] == MKV[1])
				{
					if(arr[2] == MKV[2] && arr[3] == MKV[3])
					{
						cout << "File is an MKV or WEBM" << endl;
						sigFound = 1;
					}
				}
				//cout << endl;
			}
			else if (count == 8)
			{
				for (int i = 0; i < 8; i++)
				{
					if (arr[i] != PNG[i])
						break;
					if (i == 7 && arr[7] == PNG[7])
					{
						cout << "File is a PNG" << endl;
						sigFound = 1;
					}
				}
			}
			count--;
		} while (!sigFound && count > 0);
	}
	else cout << "File does not exist" << endl;
	
	
	file.close();
	return 0;
}