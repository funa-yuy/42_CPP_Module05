#ifndef FORM_HPP
# define FORM_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include <cstdlib>
#include"Bureaucrat.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

class	Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string& name, int grade_for_sign, int grade_for_exec);
		Form& operator=(const Form& copy);
		Form(const Form& copy);
		~Form();

		const std::string&	getName() const;
		const bool&	getIsSigned() const;
		const int&	getGradeForSign() const;
		const int&	getGradeForExec() const;


		void	beSigned(const Bureaucrat& b);

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

	protected:
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_for_sign;//署名に必要な定数grade
		const int			_grade_for_exec;//実行に必要な定数grade
};

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif
