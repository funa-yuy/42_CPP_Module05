#include"Bureaucrat.hpp"

int main()
{
	{
		std::cout << "------ Formが例外を投げるか ------" << std::endl;
		try {
			Form f("フォーム", 151, 0);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ _is_signedがtrueになるか ------" << std::endl;
		try {
			Bureaucrat b("官僚", 10);
			Form f("フォーム", 20, 10);
			f.beSigned(b);
			std::cout << "is_signedは "<< (f.getIsSigned() ? "true" : "false")<< std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 署名に成功 ------" << std::endl;
		try {
			Bureaucrat b("官僚", 10);
			Form f("フォーム", 10, 20);
			b.signForm(f);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 署名に失敗 ------" << std::endl;
		try {
			Bureaucrat b("官僚", 30);
			Form f("フォーム", 10, 20);
			b.signForm(f);
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
