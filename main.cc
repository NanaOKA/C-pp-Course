// N.B. This program contains a bug, on purpose.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

#include "Screen.hh"
#include "Particle.hh"

using std::cout; 
using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

int main() 
{
  std::string filename("config");
  std::ifstream config(filename.c_str());
  
  if (!config)
  {
    std::cerr << "Could not open file." << filename << std::endl;
    return EXIT_FAILURE;
  }

  int Nparticles;
  config >> Nparticles;

  Particle* p = new Particle[Nparticles];
  for (unsigned i = 0; i < Nparticles; ++i)
  {
    char sym;
    double pos;
    double speed;
    config >> sym >> pos >> speed;
    p[i] = Particle(sym,pos,speed);
  }

  Screen display(maxColumn + 1); 

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



