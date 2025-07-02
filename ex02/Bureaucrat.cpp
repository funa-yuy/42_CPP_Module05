#include"Bureaucrat.hpp"

/*
 * デフォルトコンストラクタ
 */
Bureaucrat::Bureaucrat() : _grade(0) {
	std::cout << _name << ": Bureaucrat デフォルトコンストラクタが呼ばれました" << std::endl;
}

/*
 * コンストラクタ
 * 例外は投げるだけで、エラー検知や処理は呼び出し元(mian関数)で行う。
 */
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	std::cout << _name << ": Bureaucrat コンストラクタが呼ばれました" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

/*
 * コピーコンストラクタ
 * コピー元のオブジェクトは既に有効な状態にあるはずなので、例外は投げない
 */
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << _name << ": Bureaucrat コピーコンストラクタが呼ばれました" << std::endl;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Bureaucrat &Bureaucrat::operator=(const Bureaucrat& copy) {
	std::cout << _name << ": Bureaucrat コピー代入演算子が呼ばれました" << std::endl;
	if (this != &copy) {
		_name = copy._name;
		_grade = copy._grade;
	}
	return (*this);
}

/*
 * デストラクタ
 */
Bureaucrat::~Bureaucrat() {
	std::cout << _name << ": Bureaucrat デストラクタが呼ばれました" << std::endl;
}


// ↑↑↑ Orthodox Canonical Form --------------------------------------

const std::string&	Bureaucrat::getName() const {
	return (_name);
}

const int&	Bureaucrat::getGrade() const {
	return (_grade);
}

//gradeを高くする→今の値より0に近づける
void	Bureaucrat::increaseGrade() {
	if (_grade - 1 < 1) //gradeが範囲外になる場合、例外を投げる
		throw GradeTooHighException();
	_grade = _grade - 1;
}

//gradeを低くする→今の値より150に近づける
void	Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) //gradeが範囲外になる場合、例外を投げる
		throw GradeTooLowException();
	_grade = _grade + 1;
}

void	Bureaucrat::signForm(Form& f) const {
	try {
		f.beSigned(*this);
		//beSignedから例外が投げられたら、これ以下は実行されずに、catchに行く。
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	} catch(std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

//todo
//この関数はフォームの実行を試みます。成功した場合は、次のような出力を出力します。
// `<bureaucrat> executed <form>`
// そうでない場合は、明示的なエラー メッセージを出力します。
void	Bureaucrat::executeForm(Form const & form) const {
	try
	{
		form.execute(*this);//例外が投げられたらエラー
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't executed " << form.getName() << " because " << e.what() << std::endl;
	}

}


// カスタム例外クラス ---------------------------------------------
//1以下
const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high.");
}

//150以上
const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low.");
}


//  ストリーム挿入演算子のオーバーロード ---------------------------------------------

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs) {
	std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

