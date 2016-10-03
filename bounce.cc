// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;


const int minColumn = 0;
const int maxColumn = 80;



char screen[maxColumn];

void draw(const double, const char);
void move(double&, double&);
void clear_screen();
void print_screen();


int main() 
{
  char particleSymbol[] = {'*','+','^','o','*'};
  double particlePosition[] = {minColumn,minColumn+3,minColumn+3,minColumn+7,minColumn+11};
  double particleSpeed[] = {1,3,5,7,11};
  // const char particleSymbol = 'x';
  // double particlePosition = minColumn;
  // double particleSpeed = 6.3;	

  // const char particleSymbol2 = '+';
  // double particlePosition2 = minColumn;
  // double particleSpeed2 = 8.3;

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
   	clear_screen();
   	for (int i = 0 ; i < 5; i++)
   	{
   		draw(particlePosition[i],particleSymbol[i]);
   		move(particlePosition[i],particleSpeed[i]);
   	}
    // draw(particlePosition,particleSymbol);
    // draw(particlePosition2,particleSymbol2);

    // move(particlePosition,particleSpeed);
    // move(particlePosition2,particleSpeed2);
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


