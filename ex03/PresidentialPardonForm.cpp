#include"PresidentialPardonForm.hpp"

/*
 * デフォルトコンストラクタ
 */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << this->getName() << ": PresidentialPardonForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

/*
 * コンストラクタ
 */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
 : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << this->getName() << ": PresidentialPardonForm コンストラクタが呼ばれました" << std::endl;
}


/*
 * コピーコンストラクタ
 */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << this->getName() << ": PresidentialPardonForm コピーコンストラクタが呼ばれました" << std::endl;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
	std::cout << this->getName() << ": PresidentialPardonForm コピー代入演算子が呼ばれました" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

/*
 * デストラクタ
 */
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << this->getName() << ": PresidentialPardonForm デストラクタが呼ばれました" << std::endl;
}

// ↑↑↑ Orthodox Canonical Form --------------------------------------

// <target> が Zaphod Beeblebrox によって恩赦を受けたことを通知します。
void	PresidentialPardonForm::actionExecute() const {
	std::cout << "\x1b[32m" << _target << " has been pardoned by Zaphod Beeblebrox.\x1b[39m"<< std::endl;

}
