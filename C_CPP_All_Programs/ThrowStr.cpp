#include <iostream>
#include <vector>
#include <stdexcept>

int main()
{
    std::cout << "\nEnter Size: ";
    int n;
    if (!(std::cin >> n))
    {
        std::cerr << "Input error reading size.\n";
        return 1;
    }

    try
    {
        if (n <= 0)
            throw std::invalid_argument("Exception: Bad Memory Allocation - size must be > 0.");

        std::vector<int> values;
        values.reserve(n);
        std::cout << "\nEnter valus:\n";
        for (int i = 0; i < n; ++i)
        {
            int v;
            if (!(std::cin >> v))
                throw std::runtime_error("Input error reading values.");
            values.push_back(v);
        }

        std::cout << "\nValues Are:\n";
        for (int v : values)
            std::cout << ' ' << v;
        std::cout << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}