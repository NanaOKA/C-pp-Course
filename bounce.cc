// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;

const char particleSymbol = 'x';
const int minColumn = 0;
const int maxColumn = 80;

double particlePosition = minColumn;
double particleSpeed = 6.3;

char screen[maxColumn];

void draw(const double, const char);
void move(double&, double&);
void clear_screen();
void print_screen();


int main() 
{

  int timeStep = 0;
  const int stopTime = 60;

  while (timeStep < stopTime) 
  {
   	clear_screen();
    draw(particlePosition,particleSymbol);
    move(particlePosition,particleSpeed);
    print_screen();

    timeStep++;
  
	}
}

void draw(const double particlePosition, const char particleSymbol) 
{
	//screen[(int)particlePosition] = particleSymbol
	screen[static_cast<int>(particlePosition)] = particleSymbol;
	// for (int i = 0; i < particlePosition; i++) 
	// 	{
 //      		std::cout << " ";
 //  	}
 //    std::cout << particleSymbol << std::endl;
}

void move(double& particlePosition, double& particleSpeed)
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

void clear_screen()
{
	for (int i = 0; i < maxColumn; i++)
	{
		screen[i] = ' ';
	}
}

void print_screen()
{
	for (int i = 0; i < maxColumn; i++)
	{
		std::cout << screen[i];
	}
	std::cout << std::endl;
}


