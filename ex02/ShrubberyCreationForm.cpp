#include"ShrubberyCreationForm.hpp"

/*
 * デフォルトコンストラクタ
 */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << this->getName() << ": ShrubberyCreationForm デフォルトコンストラクタが呼ばれました" << std::endl;
}

/*
 * コンストラクタ
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << this->getName() << ": ShrubberyCreationForm コンストラクタが呼ばれました" << std::endl;
}


/*
 * コピーコンストラクタ
 */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << this->getName() << ": ShrubberyCreationForm コピーコンストラクタが呼ばれました" << std::endl;
}

/*
 * コピー代入演算子 (A copy assignment operator overload.)
 */
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
	std::cout << this->getName() << ": ShrubberyCreationForm コピー代入演算子が呼ばれました" << std::endl;
	if (this != &copy) {
		AForm::operator=(copy);
		_target = copy._target;
	}
	return (*this);
}

/*
 * デストラクタ
 */
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getName() << ": ShrubberyCreationForm デストラクタが呼ばれました" << std::endl;
}

// ↑↑↑ Orthodox Canonical Form --------------------------------------

// 作業ディレクトリにファイル <target>_shrubbery を作成し、その中に ASCII ツリーを書き込みます。
void	ShrubberyCreationForm::actionExecute() const {
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file)
	{
		std::cout << "Error: Open failed." << std::endl;
		return ;
	}
	file << "         v" << std::endl;
	file << "        >X<" << std::endl;
	file << "         A" << std::endl;
	file << "        d$b" << std::endl;
	file << "      .d$$$b." << std::endl;
	file << "    .d$i$$$$b." << std::endl;
	file << "       d$$@b" << std::endl;
	file << "      d$$$$ib" << std::endl;
	file << "    .d$$$$$$$b" << std::endl;
	file << "  .d$$@$$$$$$$ib." << std::endl;
	file << "      d$$$$$b" << std::endl;
	file << "    .d$$$$$$$b" << std::endl;
	file << "   .d$$@$$$$$$$ib." << std::endl;
	file << " .d$$$$i$$$$$$$$$$b." << std::endl;
	file << "         ##" << std::endl;
	file << "         ##" << std::endl;
	file << "         ##" << std::endl;
	file.close();
}
