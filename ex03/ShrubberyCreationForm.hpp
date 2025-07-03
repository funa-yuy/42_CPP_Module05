#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>
#include"AForm.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

// ShrubberyCreationForm: 必要なgrade: sign 145, exec 137
class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		void	actionExecute() const;

	private:
		std::string	_target;
};

// ------------------------------------------------
// function
// ------------------------------------------------

#endif
