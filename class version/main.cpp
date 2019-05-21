#include <iostream>
#include "ExtensionClass.h"

int main(int argc, char ** argv)
{
    Extension x(argv[1]);
    std::cout << x.getExtension() << std::endl;
    x.detectSignature();
    return 0;
}