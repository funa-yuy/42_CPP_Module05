#include"Bureaucrat.hpp"

int main()
{
	{
		std::cout << "------ 正常 ------" << std::endl;
		try {
			Bureaucrat b("ok", 1);
			std::cout << b << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 無効なgrade(1以下) ------" << std::endl;
		try {
			Bureaucrat b("high", 0);
			std::cout << b << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 無効なgrade(150以上) ------" << std::endl;
		try {
			Bureaucrat b("low", 151);
			std::cout << b << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ インクリメントして無効なgrade(1以下) ------" << std::endl;
		try {
			Bureaucrat b("ok", 1);
			std::cout << b << std::endl;
			b.increaseGrade();
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ デクリメントして無効なgrade(150以上) ------" << std::endl;
		try {
			Bureaucrat b("ok", 150);
			std::cout << b << std::endl;
			b.decrementGrade();
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "------ 正常の後に異常の後に正常 ------" << std::endl;
		try {
			Bureaucrat ok1("ok_10", 10);
			std::cout << ok1 << std::endl;
			Bureaucrat ng("low", 151);
			std::cout << ng << std::endl;
			Bureaucrat ok2("ok_20", 20);
			std::cout << ok2 << std::endl;
		} catch(std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
