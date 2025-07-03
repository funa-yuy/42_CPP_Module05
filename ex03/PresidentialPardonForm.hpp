#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include"AForm.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

// PresidentialPardonForm: 必要なgrade: sign 25, exec 5
class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		void	actionExecute() const;

	private:
		std::string	_target;

};

// ------------------------------------------------
// function
// ------------------------------------------------


#endif
