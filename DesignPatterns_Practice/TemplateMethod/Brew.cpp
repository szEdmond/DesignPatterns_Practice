#include "coffee.h"
#include "tea.h"

using std::shared_ptr; using std::make_shared;

int main()
{
	shared_ptr<Beverage> coffee = make_shared<Coffee>();
	shared_ptr<Beverage> tea = make_shared<Tea>();

	tea->prepare();
	std::cout << std::endl;
	coffee->prepare();
}
