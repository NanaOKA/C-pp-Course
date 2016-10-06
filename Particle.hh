#include "Screen.hh"

#ifndef Particle_hh
#define Particle_hh

extern const int minColumn;
extern const int maxColumn;

class Particle
{
	public:
		Particle(char particleSymbol_, double particlePosition_, double particleSpeed_);

		Particle();

		void draw(Screen &display) const; //Pass screen by reference not value. See copy constructor

		void move();

		Particle& operator=(const Particle& otherparticle_);

	private:
		char particleSymbol;
		double particlePosition;
		double particleSpeed;
};

#endif
