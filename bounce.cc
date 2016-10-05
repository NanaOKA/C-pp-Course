// N.B. This program contains a bug, on purpose.

#include <iostream>

using std::cout; 
using std::endl;

const int minColumn = 0;
const int maxColumn = 80;

class Screen
{
	public:
		Screen(unsigned screenSize_) //Constructor
		{
			screenSize = screenSize_;
			screen = new char[screenSize];
		} 

		void clear_screen()
		{
			for (int i = 0; i < screenSize; i++)
			{
				screen[i] = ' ';
			}
		}

		// Screen(const Screen& givenname)
		// {
		// 	cout << "Screen copy constructor running" << endl;
		// }

		Screen(const Screen &given) //Copy constructor to create own copy
		{
			cout << "Copy constructor creating local copy" << endl;
			
			this->screenSize = given.screenSize;
			this->screen = new char[screenSize];
			
			std::copy(given.screen, given.screen+screenSize, this->screen);
		}

		void print_screen()
		{
			for (int i = 0; i < screenSize; i++)
			{
				std::cout << screen[i];
			}
			std::cout << std::endl;
		}	

		~Screen()
		{
			delete [] screen;
		}

		void put(int particlePosition_, char particleSymbol_)
		{
			screen[(particlePosition_)] = particleSymbol_;
		}

	private:
		char * screen; //this instead of screen[] because dynamic
		unsigned screenSize;
};

class Particle
{
	public:
		void initialize(char particleSymbol_, double particlePosition_, double particleSpeed_)
		{
			particleSymbol = particleSymbol_;
			particlePosition = particlePosition_;
			particleSpeed = particleSpeed_;
		}

		void draw(Screen &display) const //Pass screen by reference not value. See copy constructor
		{
			display.put(particlePosition,particleSymbol);
		}

		void move()
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

	private:
		char particleSymbol;
		double particlePosition;
		double particleSpeed;
};

int main() 
{
  Particle p[3];
  Screen display(maxColumn + 1); //Also for 1 parameter, Screen display = maxColumn

  p[0].initialize('*', minColumn, 1);
  p[1].initialize('o', minColumn, 3.5);
  p[2].initialize('+', minColumn, 5.9);

  int timeStep = 0;
  const int stopTime = 100;

  while (timeStep < stopTime) 
  {
   	display.clear_screen();

   	for (int i = 0 ; i < 3; i++)
   	{	
   		p[i].draw(display);
   		p[i].move();
   	}

    display.print_screen();

    timeStep++;
  }
	//display.destroy_screen(); //Function replaced delete [] screen
}



