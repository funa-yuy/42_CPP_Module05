#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

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

// ShrubberyCreationForm: 必要なgrade: sign 145, exec 137
// 作業ディレクトリにファイル <target>_shrubbery を作成し、その中に ASCII ツリーを書き込みます。
class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		//todo フォームのアクションを実行する関数
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << this->getName() << ": ShrubberyCreationForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getName() << ": ShrubberyCreationForm デストラクタが呼ばれました" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::cout << ": ShrubberyCreationForm のexecuteが呼ばれました" << std::endl;
}

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
