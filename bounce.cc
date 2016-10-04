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

	void initialize(char particleSymbol, double particlePosition, double particleSpeed)
	{
		this->particleSymbol = particleSymbol;
		this->particlePosition = particlePosition;
		this->particleSpeed = particleSpeed;
	}

	void draw(char * const screen) 
	{
		screen[static_cast<int>(this->particlePosition)] = this->particleSymbol;
	}

	void move()
	{
		this->particlePosition += this->particleSpeed;
		if (this->particlePosition >= maxColumn) 
		{
	  		this->particlePosition = maxColumn;
	    	this->particleSpeed = -this->particleSpeed;
		} 
		else if (this->particlePosition < minColumn) 
		{
			this->particlePosition = minColumn;
			this->particleSpeed = -this->particleSpeed;
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
  p[1].initialize('*', minColumn, 3.5);
  p[2].initialize('*', minColumn, 5.9);

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


