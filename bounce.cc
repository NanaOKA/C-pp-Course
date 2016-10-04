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
};

// char screen[screenSize];
char* const screen = new char[screenSize];

void draw(Particle* const, char* const);
void move(Particle* const);
void clear_screen(char* const);
void print_screen(char* const);

int main() 
{
   Particle p[] = {{'*',minColumn,1},
                   {'+',minColumn,3.5},
                   {'^',minColumn,5.9}};		
  
  // char particleSymbol[] = {'*','+','^','o','*'};
  // double particlePosition[] = {minColumn,minColumn+3,minColumn+5,minColumn+7,minColumn+11};
  // double particleSpeed[] = {1,3,5,7,11};
  
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
   	for (int i = 0 ; i < 3; i++)
   	{
   		draw(&p[i], screen);
   		move(&p[i]);

   		// draw(*(particlePosition+i),*(particleSymbol+i),screen);
   		// move(*(particlePosition+i),*(particleSpeed+i));

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

void draw(Particle* const p, char* const screen) 
{
	//screen[(int)particlePosition] = particleSymbol
	screen[static_cast<int>(p->particlePosition)] = p->particleSymbol;
	// for (int i = 0; i < particlePosition; i++) 
	// 	{
 //      		std::cout << " ";
 //  	}
 //    std::cout << particleSymbol << std::endl;
}

void move(Particle* const p)
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

void clear_screen(char* const screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		screen[i] = ' ';
	}
}

void print_screen(char* const screen)
{
	for (int i = 0; i < screenSize; i++)
	{
		std::cout << screen[i];
	}
	std::cout << std::endl;
}


