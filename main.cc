// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <algorithm>
#include "Screen.hh"
#include "Particle.hh"

using std::cout; 
using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

int main() 
{
  const int Nparticles=3;

  Particle p[Nparticles];
  //{{'*', minColumn, 1},{'o', minColumn, 3.5},{'+', minColumn, 5.9}};
  p[0] = Particle('*', minColumn, 1);
  p[1] = Particle('o', minColumn, 3.5);
  p[2] = Particle('+', minColumn, 5.9);

  Screen display(maxColumn + 1); //Also for 1 parameter, Screen display = maxColumn

  //p[0].initialize('*', minColumn, 1);
  //p[1].initialize('o', minColumn, 3.5);
  //p[2].initialize('+', minColumn, 5.9);

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
   	display.clear_screen();

   	for (int i = 0 ; i < Nparticles; i++)
   	{	
   		p[i].draw(display);
   		p[i].move();
   	}

    display.print_screen();

    timeStep++;
  }
	//display.destroy_screen(); //Function replaced delete [] screen
}



