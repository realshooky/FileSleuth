#include <fstream>
class Extension
{
    public:
        Extension();
        // constructor requires a c-string 
        // containing the name of the file
        Extension(char *);

        // setters
        // these functions require a c-string
        // containing the abbreviation of a file type
        void setExtension(char *);
        void setSignature(char *);

        // getters
        const char * getExtension() const;
        const char * getSignature() const;

        // mutator
        void detectSignature(); // returns true for file signature found
                                // returns false for file signature NOT found
    private:
        std::fstream file;
        char * extension;
        char * signature;
};