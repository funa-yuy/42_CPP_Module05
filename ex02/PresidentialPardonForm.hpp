#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include"Form.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

// PresidentialPardonForm: 必要なgrade: sign 25, exec 5
// <target> が Zaphod Beeblebrox によって恩赦を受けたことを通知します。
class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& copy);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		//todo フォームのアクションを実行する関数
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;

};

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
 : Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << this->getName() << ": PresidentialPardonForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getName() << ": PresidentialPardonForm デストラクタが呼ばれました" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::cout << ": PresidentialPardonForm のexecuteが呼ばれました" << std::endl;

}

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
