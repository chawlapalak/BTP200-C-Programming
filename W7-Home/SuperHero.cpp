/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#include <cstring>
#include <iostream>
#include "Hero.h"
#include "SuperHero.h"

using namespace std;
namespace sict {
	void SuperHero::set_safe_empty()
	{
		AttackBonus = 0;
		DefendStrength = 0;
	}

	SuperHero::SuperHero() : Hero()
	{
		set_safe_empty();
	}

	SuperHero::SuperHero(const char * nm, int hlth, int attck, 
		int attck_bonus, int defnd_strngth) : Hero(nm, hlth, attck)
	{
		if (attck_bonus >0 && defnd_strngth >= 0) {
			AttackBonus = attck_bonus;
			DefendStrength = defnd_strngth;
		}
		else
		{
			set_safe_empty();
		}
		
	}

	int SuperHero::attackStrength() const
	{
		return Hero::attackStrength() + AttackBonus;
	}

	int SuperHero::defend() const
	{
		return DefendStrength;
	}

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		SuperHero one = first;
		SuperHero two = second;
		const SuperHero *winner = nullptr;
		int Damage1=0;
		int Damage2=0;
		int rounds = 0;

		while (one.isAlive() && two.isAlive() && rounds < max_rounds) {

			Damage1 = two.attackStrength() - one.defend();
			Damage2 = one.attackStrength() - two.defend();

			one -= Damage1;
			two -= Damage2;
			rounds++;

		}

		if (one.isAlive() && two.isAlive())
		{
			winner = &first;
		}
		else if (one.isAlive())
		{
			winner = &first;
		}
		else {
			winner = &second;
		}
		cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;
	}

}

