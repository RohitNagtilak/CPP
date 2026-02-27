#include <iostream>
#include <stdexcept>
#include <string>

void riskyOperation(int choice) 
{
    if (choice == 1)
    {
        throw std::out_of_range("index out of range");
    }
    else if (choice == 2) 
    {
        throw std::invalid_argument("invalid argument provided");
    }
    else if (choice == 3) 
    {
        throw std::runtime_error("runtime error occurred");
    }
    else if (choice == 4) 
    {
        // throw a non-std exception type
        throw 42;
    }
    // otherwise succeed
    std::cout << "riskyOperation(" << choice << ") succeeded\n";
}

int main() 
{
    for (int i = 0; i <= 4; ++i)
    {
        std::cout << "---- Test " << i << " ----\n";
        try 
        {
            riskyOperation(i);
        }
        catch (const std::out_of_range& e) 
        {
            std::cout << "Caught std::out_of_range: " << e.what() << '\n';
        }
        catch (const std::invalid_argument& e)
        {
            std::cout << "Caught std::invalid_argument: " << e.what() << '\n';
        }
        catch (const std::exception& e) 
        {
            std::cout << "Caught std::exception (or derived): " << e.what() << '\n';
        }
        catch (...) 
        {
            std::cout << "Caught unknown exception (non-std)\n";
        }
    }
    return 0;
}