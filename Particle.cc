#include <iostream>
#include "Particle.hh"

Particle::Particle(char particleSymbol_, double particlePosition_, double particleSpeed_)
: particleSymbol(particleSymbol_), particlePosition(particlePosition_), particleSpeed(particleSpeed_)
{}

Particle::Particle()
: particleSymbol('x'), particlePosition(4), particleSpeed(10)
{}

void Particle::draw(Screen &display) const //Pass screen by reference not value. See copy constructor
{
	//display.put(particlePosition,particleSymbol);
	//display.operator[](particlePosition) = particleSymbol;
	display[particlePosition]=particleSymbol;
}

void Particle::move()
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

Particle& Particle::operator=(const Particle& otherparticle_)
{
	if (this != &otherparticle_)
	{
		this->particleSymbol = otherparticle_.particleSymbol;
		this->particleSpeed = otherparticle_.particleSpeed;
		this->particlePosition = otherparticle_.particlePosition;
	}
	return *this;
} 
