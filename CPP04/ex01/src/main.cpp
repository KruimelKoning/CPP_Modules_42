#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/Brain.hpp"

int	main()
{

	Animal*	_Animal[10];

	for (int i = 0; i < 5; i++)
	{
		_Animal[i] = new Cat();
	}
	for (int i = 5; i < 10; i++)
	{
		_Animal[i] = new Dog();
	}
	for (int i = 0; i < 10; i++)
	{
		_Animal[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
	{
		delete _Animal[i];
	}

	std::cout << std::endl;

	Cat*	_Cat = new Cat();
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " " << _Cat->getIdeas(i) << std::endl;
	}
	Cat*	_Cat2 = new Cat();

	_Cat2 = _Cat;

	for (int i = 0; i < 10; i++)
	{
		std::cout  << i << " " << _Cat2->getIdeas(i) << std::endl;
	}
	delete _Cat;
	delete _Cat2;

	return 0;
}