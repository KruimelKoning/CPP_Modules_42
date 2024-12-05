#include "../header/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	setIdeas();
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other.ideas[i].substr(0, other.ideas[i].length());
	}
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		other.ideas[i].copy(this->ideas[i], other.ideas[i].length(), 0);
	}
	return *this;
}

void	Brain::setIdeas()
{
	std::string	str1[4] = {"I am ", "He is ", "I am not ", "I feel "};
	std::string	str2[3] = {"very ", "a little bit ", "soooo "};
	std::string	str3[4] = {"hungry", "stupid", "sleepy", "fat"};

	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = str1[rand() % 4] + str2[rand() % 3] + str3[rand() % 4];
	}
}
