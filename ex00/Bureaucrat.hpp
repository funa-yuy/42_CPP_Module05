#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>

// ------------------------------------------------
// class
// ------------------------------------------------

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat& copy);
		Bureaucrat(const Bureaucrat& copy);
		virtual ~Bureaucrat();

		const std::string&	getName() const;
		const int&	getGrade() const;

		void	increaseGrade();
		void	decrementGrade();

		//std::exceptionを継承したカスタム例外クラス
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(); //std::exceptionのwhat()をオーバーロード
		};

		//std::exceptionを継承したカスタム例外クラス
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(); //std::exceptionのwhat()をオーバーロード
		};

	private:
		std::string	_name;
		int			_grade;//1(最高)~150(最低)
};

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif
