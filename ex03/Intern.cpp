#include"Intern.hpp"

/*
 * デフォルトコンストラクタ
 */
Intern::Intern() {}

/*
 * コピーコンストラクタ
 */
Intern::Intern(const Intern& copy) {
	(void)copy;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Intern &Intern::operator=(const Intern& copy) {
	(void)copy;
	return (*this);
}

/*
 * デストラクタ
 */
Intern::~Intern() {}

// ↑↑↑ Orthodox Canonical Form --------------------------------------

AForm*	Intern::_createPresidentialPardonForm(const std::string& target) {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::_createRobotomyRequestForm(const std::string& target) {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::_createShrubberyCreationForm(const std::string& target) {
	return (new ShrubberyCreationForm(target));
}


AForm*	Intern::makeForm(const std::string& form, const std::string& target) {
	std::string formNames[3] = {
		"presidential pardonForm",
		"robotomy request",
		"shrubbery creationForm"
	};
	AForm*	(Intern::*func[])(const std::string&) = {
		&Intern::_createPresidentialPardonForm,
		&Intern::_createRobotomyRequestForm,
		&Intern::_createShrubberyCreationForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == form)
		{
			std::cout << "\x1b[36mIntern creates " << form << "\x1b[39m" << std::endl;
			return ((this->*func[i])(target));
		}
	}
	std::cout << "\x1b[36mIntern was unable to create form \"" << form << "\" .\x1b[39m" << std::endl;
	return (NULL);
}
