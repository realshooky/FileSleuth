#include "ExtensionList.h"

ExtensionList::ExtensionList()
{
	sizeOfList = 0;
	maxSize = 5;
	for (int i = 0; i < 5; i++)
	{
		list[i] = new char[5];
		list[i][0] = '\0';
	}
}
ExtensionList::~ExtensionList()
{
	for (int i = 0; i < maxSize; i++)
		delete [] list[i];
}

void ExtensionList::grow()
{
	char * newlist[maxSize + 5];
       	for (int i = 0; i < maxSize; i++)
		newlist[i] = list[i];
}

void ExtensionList::add(char * sig)
{
	if (sizeOfList == maxSize) this->grow();
	list[sizeOfList + 1] = sig;
	sizeOfList++;
}	

void ExtensionList::shrink()
{
	char * newlist[maxSize - 1];
	for (int i = 0; i < maxSize; i++)
		newlist[i] = list[i];
}

void ExtensionList::remove(int index)
{
	if (sizeOfList < maxSize -5) this->shrink();
	for (int i = index; i < (maxSize - 1); i++)
	{
		list[i] = list[i+1];
	}
}

int getSize(const ExtensionList& list)
{
	return list.sizeOfList;
}

char * getListObject(int index)
{
	return list.list[index];
}
