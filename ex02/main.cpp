#include"Bureaucrat.hpp"
#include"Form.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "------ Formが例外を投げるか ------" << std::endl;
		try {
			Bureaucrat b("官僚", 10);
			ShrubberyCreationForm s("home");
			b.signForm(s);
			b.executeForm(s);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}

//官僚クラス executeForm（）
// ↓
// Formクラス execute
// ↓
// 具象クラス フォームのアクションを実行する関数
