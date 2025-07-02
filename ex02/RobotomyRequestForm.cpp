#include"RobotomyRequestForm.hpp"

/*
 * デフォルトコンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << this->getName() << ": RobotomyRequestForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

/*
 * コンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << this->getName() << ": RobotomyRequestForm コンストラクタが呼ばれました" << std::endl;
}


/*
 * コピーコンストラクタ
 */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << this->getName() << ": RobotomyRequestForm コピーコンストラクタが呼ばれました" << std::endl;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
	std::cout << this->getName() << ": RobotomyRequestForm コピー代入演算子が呼ばれました" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

/*
 * デストラクタ
 */
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << this->getName() << ": RobotomyRequestForm デストラクタが呼ばれました" << std::endl;
}

// ↑↑↑ Orthodox Canonical Form --------------------------------------

// ドリルのような音を立てた後、<target> のロボット化が 50% の確率で成功したことを通知します。
// それ以外の場合は、ロボット化が失敗したことを通知します。
void	RobotomyRequestForm::actionExecute() const {
	std::cout << "\x1b[32mGagagagaga.........."<< std::endl;
	//todo 直す
	srand(time(NULL)); // 乱数の初期化
	if (rand() % 2 == 0 )
		std::cout << _target << " has been successfully robotized.\x1b[39m"<< std::endl;
	else
		std::cout << "Failed to robotize " << _target << ".\x1b[39m" << std::endl;
}
