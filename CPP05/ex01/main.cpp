#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat a("Ali", 30);
        Form f("Leave Form", 50, 20);
        a.signForm(f);
        std::cout << f << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try
    {
        Bureaucrat b("Sara", 40);
        Form f2("Work Form", 50, 10);

        b.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try
    {
        Bureaucrat c("Omar", 100);
        Form f3("Secret Form", 20, 5);

        c.signForm(f3); 
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
