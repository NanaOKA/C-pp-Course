// N.B. This program contains a bug, on purpose.

#include <iostream>


const char particleSymbol = 'x';
const int minColumn = 0;
const int maxColumn = 80;

double particlePosition = minColumn;
double particleSpeed = 6.3;


void draw(const double particlePosition, const char particleSymbol) 
{
	for (int i = 0; i < particlePosition; i++) 
		{
      std::cout << " ";
  	}
    	std::cout << particleSymbol << std::endl;
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

int main() 
{

  int timeStep = 0;
  const int stopTime = 60;

  while (timeStep < stopTime) 
  {
   
    draw(particlePosition,particleSymbol);
    move(particlePosition,particleSpeed);
    
    timeStep++;
  
	}

}
