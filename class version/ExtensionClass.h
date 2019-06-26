#include <fstream>
class Extension
{
    public:
        Extension();
        // constructor requires a c-string 
        // containing the name of the file
        Extension(char *);

        // getters
        const char * getExtension() const;
        const char * getSignature() const;
        bool getFileStatus() const;

        // detects and assigns the correct
        // file signature to the Extension object
        bool detectSignature();
    private:
        bool count2compare(int[], int[], char[]);
        bool count4compare(int[], int[], char[]);
        bool count8compare(int[], int[], char[]);
        std::fstream file;
        char extension[50];
        char signature[50];
};