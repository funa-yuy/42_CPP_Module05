#include"Bureaucrat.hpp"
#include"AForm.hpp"
#include"PresidentialPardonForm.hpp"
#include"RobotomyRequestForm.hpp"
#include"ShrubberyCreationForm.hpp"

int main()
{
	{
		std::cout << "------ 失敗: gradeの値が無効 ------" << std::endl;
		try {
			Bureaucrat b("官僚", 155);
			ShrubberyCreationForm s("太郎");//必要なgrade: sign 145, exec 137
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "----- 成功: PresidentialPardonForm ------" << std::endl;
		try {
			Bureaucrat b("官僚", 5);
			PresidentialPardonForm s("太郎");//必要なgrade: sign 25, exec 5
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 成功: RobotomyRequestForm ------" << std::endl;
		try {
			Bureaucrat b("官僚", 5);
			RobotomyRequestForm s("太郎");//必要なgrade: sign 72, exec 45
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 成功: ShrubberyCreationForm ------" << std::endl;
		try {
			Bureaucrat b("官僚", 5);
			ShrubberyCreationForm s("太郎");//必要なgrade: sign 145, exec 137
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
		{
		std::cout << "----- 失敗: 署名できない ------" << std::endl;
		try {
			Bureaucrat b("官僚", 30);//gradeが25以上
			PresidentialPardonForm s("太郎");//必要なgrade: sign 25, exec 5
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 失敗: 署名はできるが実行ができない ------" << std::endl;
		try {
			Bureaucrat b("官僚", 60);//gradeが45以上72以下
			RobotomyRequestForm s("太郎");//必要なgrade: sign 72, exec 45
			b.signForm(s);//署名
			b.executeForm(s);//実行
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 失敗: 署名も実行もできない ------" << std::endl;
		try {
			Bureaucrat b("官僚", 150);
			ShrubberyCreationForm s("太郎");//必要なgrade: sign 145, exec 137
			b.signForm(s);//署名
			b.executeForm(s);//実行
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
