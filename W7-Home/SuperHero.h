/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"

namespace sict {

	class SuperHero : public Hero
	{
	private:
		int AttackBonus;
		int DefendStrength;
		void set_safe_empty();

	public:
		SuperHero();
		SuperHero(const char* nm, int hlth, int attck, int attck_bonus, int defnd_strngth);
		int attackStrength() const;
		int defend() const;
	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif