// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;


const int minColumn = 0;
const int maxColumn = 80;


struct Particle
{
	char particleSymbol;
	double particlePosition;
	double particleSpeed;

	void initialize(char particleSymbol_, double particlePosition_, double particleSpeed_)
	{
		particleSymbol = particleSymbol_;
		particlePosition = particlePosition_;
		particleSpeed = particleSpeed_;
	}

	void draw(char * const screen) const
	{
		screen[static_cast<int>(particlePosition)] = particleSymbol;
	}

	void move()
	{
		particlePosition += particleSpeed;
		if (particlePosition >= maxColumn) 
		{
	  		particlePosition = maxColumn;
	    	particleSpeed = -particleSpeed;
		} 
		else if (particlePosition < minColumn) 
		{
			particlePosition = minColumn;
			particleSpeed = -particleSpeed;
		}
	}
};

struct Screen
{
	char * screen;
	unsigned screenSize;

	void initialize_screen(unsigned screenSize_)
	{
		screenSize = screenSize_;
		screen = new char[screenSize];
	} 

	void clear_screen()
	{
		for (int i = 0; i < screenSize; i++)
		{
			screen[i] = ' ';
		}
	}

	void print_screen()
	{
		for (int i = 0; i < screenSize; i++)
		{
			std::cout << screen[i];
		}
		std::cout << std::endl;
	}	
};

int main() 
{
  Particle p[3];
  Screen display;

  p[0].initialize('*', minColumn, 1);
  p[1].initialize('o', minColumn, 3.5);
  p[2].initialize('+', minColumn, 5.9);

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
  	display.initialize_screen(maxColumn+1);
   	display.clear_screen();

   	for (int i = 0 ; i < 3; i++)
   	{
   		p[i].draw(display.screen);
   		p[i].move();
   	}

    display.print_screen();

    timeStep++;
  }
	delete [] display.screen;
}



