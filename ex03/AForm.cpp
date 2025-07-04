#include"AForm.hpp"

/*
 * デフォルトコンストラクタ
 */
AForm::AForm() : _is_signed(false), _grade_for_sign(0), _grade_for_exec(0) {}

/*
 * コンストラクタ
 * 例外は投げるだけで、エラー検知や処理は呼び出し元(mian関数)で行う。
 */
AForm::AForm(const std::string& name, int grade_for_sign, int grade_for_exec)
	 : _name(name), _is_signed(false), _grade_for_sign(grade_for_sign), _grade_for_exec(grade_for_exec)
{
	if (grade_for_sign < 1 || grade_for_exec < 1)
		throw AForm::GradeTooHighException();
	else if (grade_for_sign > 150 || grade_for_exec > 150)
		throw AForm::GradeTooLowException();
}

/*
 * コピーコンストラクタ
 */
AForm::AForm(const AForm& copy)
	: _name(copy._name), _is_signed(copy._is_signed), _grade_for_sign(copy._grade_for_sign), _grade_for_exec(copy._grade_for_exec) {}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
AForm &AForm::operator=(const AForm& copy) {
	if (this != &copy) {
		_is_signed = copy._is_signed;
	}
	return (*this);
}

/*
 * デストラクタ
 */
AForm::~AForm() {}


// ↑↑↑ Orthodox Canonical Form --------------------------------------

const std::string&	AForm::getName() const {
	return (_name);
}

const bool&	AForm::getIsSigned() const {
	return (_is_signed);
}

const int&	AForm::getGradeForSign() const {
	return (_grade_for_sign);
}

const int&	AForm::getGradeForExec() const {
	return (_grade_for_exec);
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _grade_for_sign)//必要なgradeよりも低い値(150に近ければ)の場合、例外を投げる.ex)grade 11 > must 10
		throw AForm::GradeTooLowException();
	_is_signed = true;// gradeが必要な等級以上であれば、フォームのステータスを署名付きに変更。
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!_is_signed)
		throw AForm::FormIsNotSigned();
	if (executor.getGrade() > _grade_for_exec)
		throw AForm::GradeTooLowException();
	actionExecute();
}


// カスタム例外クラス ---------------------------------------------
//1以下
const char*	AForm::GradeTooHighException::what() const throw() {
	return ("\x1b[31mThe grade is too high.\x1b[39m");
}

//150以上
const char*	AForm::GradeTooLowException::what() const throw() {
	return ("\x1b[31mThe grade is too low.\x1b[39m");
}

//formのis_signedがfalseだった時
const char*	AForm::FormIsNotSigned::what() const throw() {
	return ("\x1b[31mThe form is not signed.\x1b[39m");
}

//  ストリーム挿入演算子のオーバーロード ---------------------------------------------

std::ostream &operator<<(std::ostream &os, const AForm &rhs) {
	std::cout << rhs.getName() << " signature is " << rhs.getIsSigned()
				<< ", required grade for signing is " << rhs.getGradeForSign()
				<< ", required grade for execution is " << rhs.getGradeForExec() << ".";
	return os;
}

