// N.B. This program contains a bug, on purpose.

#include <iostream>

char particleSymbol = 'x';
int minColumn = 0;
double particlePosition = minColumn;
double particleSpeed = 6.3;
int maxColumn = 80;

void draw(double particlePosition, char particleSymbol) 
{
	for (int i = 0; i < particlePosition; i++) 
		{
      std::cout << " ";
  	}
    	std::cout << particleSymbol << std::endl;
}

void move(double particlePosition, double particleSpeed)
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

int main() {

  int timeStep = 0;
  int stopTime = 60;

  while (timeStep < stopTime) {
   
    draw(particlePosition,particleSymbol);
    move(particlePosition,particleSpeed);
    timeStep++;
  
	}

    for (int i = 0; i < particlePosition; i++) {
      std::cout << " ";
    }
    std::cout << particleSymbol << std::endl;
}
