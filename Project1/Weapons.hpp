#pragma once
#include "AnimatedObject.hpp"

class Weapons : public AnimatedObject
{
	public :	
		
		Weapons();
		~Weapons();

		void initWeapon();

	protected :

		int damagePoints;
};

