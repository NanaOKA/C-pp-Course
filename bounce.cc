// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;


const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn+1;

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

	void draw(char * const screen) 
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

char* const screen = new char[screenSize];

void clear_screen(char * const);
void print_screen(char * const);

int main() 
{
  Particle p[3];

  p[0].initialize('*', minColumn, 1);
  p[1].initialize('o', minColumn, 3.5);
  p[2].initialize('+', minColumn, 5.9);

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
   	clear_screen(screen);
   	for (int i = 0 ; i < 3; i++)
   	{
   		p[i].draw(screen);
   		p[i].move();
   	}

    print_screen(screen);

    timeStep++;
  }
	delete [] screen;
}


void clear_screen(char * const screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		screen[i] = ' ';
	}
}

void print_screen(char * const screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		std::cout << screen[i];
	}
	std::cout << std::endl;
}


