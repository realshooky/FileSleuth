class ExtensionList
{
public:
	// constructor
	ExtensionList(); // constructs object with values 
			 // sizeOfList = 0, maxSize = 5, *list[5]
	~ExtensionList();

	// getter
	int getSize(const ExtensionList& list);
	char * getListObject(int index);

	// mutator
	void add(char *); // adds an element to list
	void remove(int index); // removes an element from list
	void grow(); // grows maxSize by 5, use when sizeOfList == maxSize
	void shrink(); // shrinks maxSize by 1, use when sizeOfList <= maxSize - 5
private:
	int sizeOfList; // current size of list
	int maxSize; // max size of list
	char * list[]; // array of c-strings containing possible sigs
};
