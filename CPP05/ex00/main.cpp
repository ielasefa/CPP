#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Ali", 42);
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("Sara", 0);
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat c("Omar", 1);
        std::cout << c << std::endl;

        c.incrementGrade(); 
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
