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

        // detects and assigns the correct
        // file signature to the Extension object
        bool detectSignature();
    private:
        std::fstream file;
        char extension[50];
        char signature[50];
};