// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;


const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn+1;

struct Particle
{

	//void initialize(Particle * const, char, double, double);
	//void draw(Particle const * const, char * const);
	//void move(Particle * const);

	char particleSymbol;
	double particlePosition;
	double particleSpeed;

	void initialize(Particle * p, char particleSymbol, double particlePosition, double particleSpeed)
	{
		p->particleSymbol = particleSymbol;
		p->particlePosition = particlePosition;
		p->particleSpeed = particleSpeed;
	}

	void draw(Particle const * const p, char * const screen) 
	{
		screen[static_cast<int>(p->particlePosition)] = p->particleSymbol;
	}

	void move(Particle * const p)
	{
		p->particlePosition += p->particleSpeed;
		if (p->particlePosition >= maxColumn) 
		{
	  		p->particlePosition = maxColumn;
	    	p->particleSpeed = -p->particleSpeed;
		} 
		else if (p->particlePosition < minColumn) 
		{
			p->particlePosition = minColumn;
			p->particleSpeed = -p->particleSpeed;
		}
	}
};

char* const screen = new char[screenSize];

void clear_screen(char * const);
void print_screen(char * const);

int main() 
{
  Particle p[3];

  p[0].initialize(&p[0], '*', minColumn, 1);
  p[1].initialize(&p[1], '*', minColumn, 3.5);
  p[2].initialize(&p[2], '*', minColumn, 5.9);

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
   	clear_screen(screen);
   	for (int i = 0 ; i < 3; i++)
   	{
   		p[i].draw(&p[i], screen);
   		p[i].move(&p[i]);
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


