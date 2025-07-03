#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"
#include"Intern.hpp"


// ```bash
//valgrind --leak-check=full ./Bureaucrat
//```

int main()
{
	try {
		Bureaucrat boss("官僚", 1);
		{
			std::cout << "------ RobotomyRequestForm ------" << std::endl;

			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			if (rrf)
			{
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
				delete rrf;
			}
		}
		std::cout << std::endl;
		{
			std::cout << "------ PresidentialPardonForm ------" << std::endl;

			Intern someRandomIntern;
			AForm* ppf;

			ppf = someRandomIntern.makeForm("presidential pardonForm", "Bender");
			std::cout << *ppf << std::endl;
			if (ppf)
			{
				boss.signForm(*ppf);
				boss.executeForm(*ppf);
				delete ppf;
			}
		}
		std::cout << std::endl;
		{
			std::cout << "------ ShrubberyCreationForm ------" << std::endl;

			Intern someRandomIntern;
			AForm* scf;

			scf = someRandomIntern.makeForm("shrubbery creationForm", "Bender");
			std::cout << *scf << std::endl;
			if (scf)
			{
				boss.signForm(*scf);
				boss.executeForm(*scf);
				delete scf;
			}
		}
		std::cout << std::endl;
		{
			std::cout << "------ 不正なform ------" << std::endl;

			Intern someRandomIntern;
			AForm* scf;

			scf = someRandomIntern.makeForm("Invalid form", "Bender");
			if (scf)
			{
				std::cout << *scf << std::endl;
				boss.signForm(*scf);
				boss.executeForm(*scf);
				delete scf;
			}
		}
		std::cout << std::endl;
		{
			std::cout << "------ Bureaucratのgradeが足りてない ------" << std::endl;

			Bureaucrat boss2("官僚", 150);
			Intern someRandomIntern;
			AForm* rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *rrf << std::endl;
			if (rrf)
			{
				boss2.signForm(*rrf);
				boss2.executeForm(*rrf);
				delete rrf;
			}
		}
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
