#include <iostream>
#include "Screen.hh"

Screen::Screen(unsigned screenSize_) //Constructor
: screen(new char [screenSize_]), screenSize(screenSize_)
{} 

void Screen::clear_screen()
{
	for (int i = 0; i < screenSize; i++)
	{
		screen[i] = ' ';
	}
}

Screen::Screen(const Screen &given) //Copy constructor to create own copy
: screen(new char [given.screenSize]), screenSize(given.screenSize)
{
	std::cout << "Copy constructor creating local copy" << std::endl;			
	std::copy(given.screen, given.screen+screenSize, this->screen);
}

void Screen::print_screen()
{
	for (int i = 0; i < screenSize; i++)
	{
		std::cout << screen[i];
	}
	std::cout << std::endl;
}	

Screen::~Screen()
{
	delete [] screen;
}

void Screen::put(int particlePosition_, char particleSymbol_)
{
	screen[(particlePosition_)] = particleSymbol_;
}

char & Screen::operator[](unsigned const particlePosition_)
{
	return this->screen[particlePosition_];
} 

Screen& Screen::operator=(Screen given)
{
	swap(*this, given);
	return *this;
}

void swap(Screen& lhs, Screen& rhs)
{
	using std::swap;
	swap(lhs.screenSize, rhs.screenSize);
	swap(lhs.screen, rhs.screen);
}



