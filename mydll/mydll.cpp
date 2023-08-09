#include <iostream>
#include "mydll.h"  // Include your own header file

// Exported function from the DLL
void HelloWorldFromDLL()
{
    std::cout << "Hello from DLL!" << std::endl;
}
