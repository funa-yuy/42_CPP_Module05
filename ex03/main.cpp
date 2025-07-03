#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"Intern.hpp"

int main()
{
	{
		std::cout << "------ 課題分の例 ------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << &rrf << std::endl;

		delete rrf;
	}
	std::cout << std::endl;
	return 0;
}
