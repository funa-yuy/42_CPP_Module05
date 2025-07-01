#include"Form.hpp"

/*
 * デフォルトコンストラクタ
 */
Form::Form() : _is_signed(false), _grade_for_sign(0), _grade_for_exec(0) {
	std::cout << _name << ": Form デフォルトコンストラクタが呼ばれました" << std::endl;
}

/*
 * コンストラクタ
 * 例外は投げるだけで、エラー検知や処理は呼び出し元(mian関数)で行う。
 */
Form::Form(const std::string& name, int grade_for_sign, int grade_for_exec)
	 : _name(name), _is_signed(false), _grade_for_sign(grade_for_sign), _grade_for_exec(grade_for_exec)
{
	std::cout << _name << ": Form コンストラクタが呼ばれました" << std::endl;
	if (grade_for_sign < 1 || grade_for_exec < 1)
		throw Form::GradeTooHighException();
	else if (grade_for_sign > 150 || grade_for_exec > 150)
		throw Form::GradeTooLowException();
}

/*
 * コピーコンストラクタ
 */
Form::Form(const Form& copy)
	: _name(copy._name), _is_signed(copy._is_signed), _grade_for_sign(copy._grade_for_sign), _grade_for_exec(copy._grade_for_exec)
{
	std::cout << _name << ": Form コピーコンストラクタが呼ばれました" << std::endl;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
Form &Form::operator=(const Form& copy) {
	std::cout << _name << ": Form コピー代入演算子が呼ばれました" << std::endl;
	if (this != &copy) {
		_is_signed = copy._is_signed;
	}
	return (*this);
}

/*
 * デストラクタ
 */
Form::~Form() {
	std::cout << _name << ": Form デストラクタが呼ばれました" << std::endl;
}


// ↑↑↑ Orthodox Canonical Form --------------------------------------

const std::string&	Form::getName() const {
	return (_name);
}

const bool&	Form::getIsSigned() const {
	return (_is_signed);
}

const int&	Form::getGradeForSign() const {
	return (_grade_for_sign);
}

const int&	Form::getGradeForExec() const {
	return (_grade_for_exec);
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _grade_for_sign)//必要なgradeよりも低い値(150に近ければ)の場合、例外を投げる.ex)grade 11 > must 10
		throw Form::GradeTooLowException();
	_is_signed = true;// gradeが必要な等級以上であれば、フォームのステータスを署名付きに変更。
}

// カスタム例外クラス ---------------------------------------------
//1以下
const char*	Form::GradeTooHighException::what() const throw() {
	return ("The grade is too high.");
}

//150以上
const char*	Form::GradeTooLowException::what() const throw() {
	return ("The grade is too low.");
}


//  ストリーム挿入演算子のオーバーロード ---------------------------------------------

std::ostream &operator<<(std::ostream &os, const Form &rhs) {
	std::cout << rhs.getName() << " signature is " << rhs.getIsSigned()
				<< ", required grade for signing is " << rhs.getGradeForSign()
				<< ", required grade for execution is " << rhs.getGradeForExec() << ".";
	return os;
}

