#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

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

// RobotomyRequestForm: 必要なgrade: sign 72, exec 45
// ドリルのような音を立てた後、<target> のロボット化が 50% の確率で成功したことを通知します。
// それ以外の場合は、ロボット化が失敗したことを通知します。
class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& copy);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		//todo フォームのアクションを実行する関数
		void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << this->getName() << ": RobotomyRequestForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getName() << ": RobotomyRequestForm デストラクタが呼ばれました" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	(void)executor;
	std::cout << ": RobotomyRequestForm のexecuteが呼ばれました" << std::endl;
}

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
