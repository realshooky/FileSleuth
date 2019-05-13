#include <iostream>
#include <fstream>
using namespace std;

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
			{
				switch(value)
				{
					case -41:
						if (count == 2)
						{
							cout << "File is a JPEG" << endl;
							sigFound = 1;
						}
						break;
					case 143:
						if (count == 2)
						{
							cout << "File is a BMP" << endl;
							sigFound = 1;
						}
						break;
					default:
						break;
				}
			}
			else if (count == 4)
			{
				switch(value)
				{
					case 255:
						if (count == 4)
						{
							cout << "File is a PDF" << endl;
							sigFound = 1;
						}
						break;
					default:
						break;
				}
			}
			else if (count == 8)
			{
				switch (value)
				{
					case 169:
						if (count == 8)
						{
							cout << "File is a PNG" << endl;
							sigFound = 1;
						}
						break;
					default:
						break;
				}			
			}
			count--;
		} while (!sigFound && count > 0);
	}
	else cout << "File does not exist" << endl;
	
	
	file.close();
	return 0;
}
