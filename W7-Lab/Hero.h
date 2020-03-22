//Name : Palak Chawla
//ID: 118834175
//Email : pchawla5@myseneca.ca
//Sub : BTP200SAA
//Date : 22 March 2018

#ifndef SICT_HERO_ACCOUNT_H
#define SICT_HERO_ACCOUNT_H


namespace sict {
	const int max_rounds = 100;
class Hero
	{

	private:
		char hero_name[41];
		int hero_health;
		int hero_attack_strength;
		void set_safe_empty();

	public:
		Hero();
		Hero(const char* nm, int hlth, int attck);

		void operator-= (int attack);
		bool isAlive()const;
		int attackStrength()const;

		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif




















