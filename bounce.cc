// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;


const int minColumn = 0;
const int maxColumn = 80;
const int screenSize = maxColumn+1;


// char screen[screenSize];
char* screen = new char[screenSize];

void draw(const double, const char, char*);
void move(double&, double&);
void clear_screen(char*);
void print_screen(char*);


int main() 
{
  char particleSymbol[] = {'*','+','^','o','*'};
  double particlePosition[] = {minColumn,minColumn+3,minColumn+5,minColumn+7,minColumn+11};
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
   	clear_screen(screen);
   	for (int i = 0 ; i < 5; i++)
   	{
   		draw(*(particlePosition+i),*(particleSymbol+i),screen);
   		move(*(particlePosition+i),*(particleSpeed+i));
   		// draw(particlePosition[i],particleSymbol[i],screen);
   		// move(particlePosition[i],particleSpeed[i]);
   	}
    // draw(particlePosition,particleSymbol);
    // draw(particlePosition2,particleSymbol2);

    // move(particlePosition,particleSpeed);
    // move(particlePosition2,particleSpeed2);
    print_screen(screen);

    timeStep++;
  
	}
	delete [] screen;
}

void draw(const double particlePosition, const char particleSymbol, char* screen) 
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

void clear_screen(char* screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		screen[i] = ' ';
	}
}

void print_screen(char* screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		std::cout << screen[i];
	}
	std::cout << std::endl;
}


