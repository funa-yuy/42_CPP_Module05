#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

// ------------------------------------------------
// include
// ------------------------------------------------

#include <iostream>
#include <string>
#include"AForm.hpp"

// ------------------------------------------------
// class
// ------------------------------------------------

class	AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat& operator=(const Bureaucrat& copy);
		Bureaucrat(const Bureaucrat& copy);
		~Bureaucrat();

		const std::string&	getName() const;
		int	getGrade() const;

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

		void	signForm(AForm& f) const;


		//この関数はフォームの実行を試みます。成功した場合は、次のような出力を出力します。
		// `<bureaucrat> executed <form>`
		// そうでない場合は、明示的なエラー メッセージを出力します。
		void	executeForm(AForm const & form) const;

	private:
		const std::string	_name;
		int			_grade;//1(最高)~150(最低)
};

// ------------------------------------------------
// function
// ------------------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif
