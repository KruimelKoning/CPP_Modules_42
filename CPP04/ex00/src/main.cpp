#include "../header/Animal.hpp"
#include "../header/Cat.hpp"
#include "../header/Dog.hpp"
#include "../header/WrongAnimal.hpp"
#include "../header/WrongCat.hpp"

int	main()
{
	Animal*	_Animal = new Animal();
	Animal*	_Cat = new Cat();
	Animal*	_Dog = new Dog();

	std::cout << _Animal->getType() << std::endl;
	std::cout << _Cat->getType() << std::endl;
	std::cout << _Dog->getType() << std::endl;
	_Animal->makeSound();
	_Cat->makeSound();
	_Dog->makeSound();
	delete _Animal;
	delete _Cat;
	delete _Dog;

	WrongAnimal*	_WrongCat = new WrongCat();

	_WrongCat->makeSound();

	delete _WrongCat;
	return 0;
}