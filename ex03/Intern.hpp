#ifndef INTERN_HPP
# define INTERN_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

class Intern {
	public:
		Intern();
		// Intern& operator=(const Intern& copy);
		// Intern(const Intern& copy);
		~Intern();

		AForm*	makeForm(const std::string& form, const std::string& target);

	private:
		AForm*	_createPresidentialPardonForm(const std::string& target);
		AForm*	_createRobotomyRequestForm(const std::string& target);
		AForm*	_createShrubberyCreationForm(const std::string& target);

};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
