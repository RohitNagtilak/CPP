/*
Pseudocode / Plan:
- Create a function `Divide` that:
  - sets example operands `x` and `y`
  - checks if `y` is zero and throws a `std::runtime_error` if so
  - performs the division and prints the result otherwise
  - catches and prints any `std::exception` thrown inside the function
- In `main`:
  - call `Divide()` inside a try/catch to demonstrate upstream handling of unexpected exceptions
  - return an appropriate exit code (0 on success, 1 on unhandled exception)
- Rename original misleading function name `Add` to `Divide`.
*/

#include <iostream>
#include <stdexcept>

// Perform a simple division with error checking.
// This replaces the original misleadingly named `Add` function.
void Divide()
{
    int x = 10; // numerator (example)
    int y = 0;  // denominator (example)

    try
    {
        // Prevent division by zero by validating `y` first.
        if (y == 0)
        {
            // Throw an exception with a clear message that can be caught by callers.
            throw std::runtime_error("Division by zero is not allowed.");
        }

        int result = x / y; // safe to divide here because y != 0
        std::cout << "Result = " << result << std::endl;
    }
    catch (const std::exception& ex)
    {
        // Handle expected exceptions locally and print the reason.
        std::cout << "Exception occurred: " << ex.what() << std::endl;
    }
}

int main()
{
    try
    {
        // Call the division demo. Most exceptions are handled inside `Divide`,
        // but this outer try/catch protects against unexpected exceptions.
        Divide();
    }
    catch (const std::exception& ex)
    {
        // If an unexpected exception propagates here, report and return an error code.
        std::cerr << "Unhandled exception: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}