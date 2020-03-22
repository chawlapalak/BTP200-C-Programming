//Name : Palak Chawla
//ID: 118834175
//Email : pchawla5@myseneca.ca
//Sub : BTP200SAA
//Date : 22 March 2018


#include <cstring>
#include <iostream>
#include "Hero.h"


using namespace std;
namespace sict {
	void Hero::set_safe_empty()
	{
		hero_name[0] = '\0';
		hero_health = 0;
		hero_attack_strength = 0;
	}

	Hero::Hero()
	{
		set_safe_empty();
	}

	Hero::Hero(const char* nm, int hlth, int attck)
	{
		if (nm == nullptr || nm[0] == 0 || hlth<0 || attck<0)
		{
			set_safe_empty();

		}
		else
		{
			strcpy(hero_name, nm);
			hero_name[39] = '\0';
			hero_health = hlth;
			hero_attack_strength = attck;
		}
	}

	void Hero::operator-=(int attack)
	{
		hero_health = hero_health - attack;

		if (hero_health < 0)
		{
			hero_health = 0;
		}
	}

	bool Hero::isAlive() const
	{
		if (hero_health > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Hero::attackStrength() const
	{
		return hero_attack_strength;
	}

	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.hero_name == '\0') {
			os << "No hero";
		}
		else {
			os << hero.hero_name;
		}
		return os;
	}
	const Hero& operator*(const Hero& first, const Hero& second) {
		
		Hero one = first;
		Hero two = second;
		const Hero *winner = nullptr;
		int rounds = 0;

		while (one.isAlive() && two.isAlive() && rounds < max_rounds) {
			
			one -= two.attackStrength();
			two -= one.attackStrength();
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
		cout << "Ancient Battle! " << first << " vs " << second << " : "
			<< "Winner is " << *winner << " in " << rounds << " rounds." << endl;

		return *winner;

	}
}



