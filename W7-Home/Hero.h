/*Name : Palak Chawla
ID: 118834175
email : pchawla5@myseneca.ca
Sub: BTP200SAA*/

#ifndef SICT_HERO_H
#define SICT_HERO_H



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




















