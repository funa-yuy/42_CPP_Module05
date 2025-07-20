#include"RobotomyRequestForm.hpp"

/*
 * デフォルトコンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

/*
 * コンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : AForm("RobotomyRequestForm", 72, 45), _target(target){}


/*
 * コピーコンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target){}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

/*
 * デストラクタ
 */
RobotomyRequestForm::~RobotomyRequestForm() {}

// ↑↑↑ Orthodox Canonical Form --------------------------------------

// ドリルのような音を立てた後、<target> のロボット化が 50% の確率で成功したことを通知します。
// それ以外の場合は、ロボット化が失敗したことを通知します。
void	RobotomyRequestForm::actionExecute() const {
	std::cout << "\x1b[32mGagagagaga.........."<< std::endl;
	static	int	num = 0;
	if (num++ % 2 == 0 )
		std::cout << _target << " has been successfully robotized.\x1b[39m"<< std::endl;
	else
		std::cout << "Failed to robotize " << _target << ".\x1b[39m" << std::endl;
}
