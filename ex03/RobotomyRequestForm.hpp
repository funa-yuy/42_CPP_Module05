#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include"AForm.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

// RobotomyRequestForm: 必要なgrade: sign 72, exec 45
class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		void	actionExecute() const;

	private:
		std::string	_target;
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
