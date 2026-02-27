#include <iostream>
#include <stdexcept>

struct ThrowInCtor 
{
    ThrowInCtor()
    {
        std::cout << "ThrowInCtor::ctor\n";
        throw std::runtime_error("exception from constructor");
    }
    ~ThrowInCtor() noexcept(false)
    {
        std::cout << "ThrowInCtor::dtor\n";
    }
};

struct ThrowInDtor 
{
    ThrowInDtor() { std::cout << "ThrowInDtor::ctor\n"; }
    ~ThrowInDtor() noexcept(false) 
    {
        std::cout << "ThrowInDtor::dtor (about to throw)\n";
        throw std::runtime_error("exception from destructor");
    }
};

int main() 
{
    // 1) Throwing in a constructor
    try 
    {
        ThrowInCtor a;                         // ctor throws
        std::cout << "constructed\n";         // never reached
    } 
    catch (const std::exception& e)
    {
        std::cout << "caught constructor exception: " << e.what() << '\n';
    }

    // 2) Throwing in a destructor during normal exit of scope
    try 
    {
        ThrowInDtor b;                        // constructed normally
    }
    catch (const std::exception& e)
    {
        // The exception thrown by the destructor is caught here
        std::cout << "caught destructor exception (normal unwind): " << e.what() << '\n';
    }

    // 3) Throwing in a destructor while another exception is active
    try
    {
        ThrowInDtor c;
        throw std::runtime_error("primary exception");
        // stack unwinding begins -> ~ThrowInDtor will run and throw a second exception
    }
    catch (const std::exception& e) 
    {
        // This catch will NOT be reached if the destructor throws during stack unwinding.
        std::cout << "caught: " << e.what() << '\n';
    }

    std::cout << "end of main (may not be reached in case 3)\n";

    return 0;
}

//If a constructor throws, the object was never fully constructed and its destructor is not called; the exception can be caught by the surrounding try / catch.
//If a destructor throws during normal stack unwinding(no other active exception), that exception propagates normally and can be caught.
//If a destructor throws while another exception is already being propagated(double exception during stack unwinding), the C++ runtime calls std::terminate() and the program ends immediately.Throwing from destructors during stack unwinding is therefore dangerous — prefer noexcept destructors and handle errors inside destructors without throwing.
