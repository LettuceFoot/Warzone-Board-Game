#pragma once
#include "Map.h"
//#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

/**
* Melina Phan
* 40094159
*
* Code borrowed:
*		Copy constructor & Assignment operator: GeeksForGeeks.org
*/

class Player;

class Territory
{
public:
	Territory(); // Default Constructor
	Territory(int id, string n); //TODO: ADD CONTINENT INDEX TO CONSTRUCTOR
	Territory(const Territory& t); // Copy Constructor
	Territory& operator = (const Territory& t); // Assignment operator
	~Territory(); // Destructor

	void printAdjTerritory();
	Player* getOwner(); // get owner of this Territory
	void setOwner(Player* p); // set the owner of this Territory
	bool isAdjacent(int id);
	bool addTroops(int n);
	static bool containsTerritory(vector<Territory*> territories, Territory* t); // checks if the input Territory is contained in the input vector

	friend bool operator ==(const Territory& t1, const Territory& t2);
	friend ostream& operator << (ostream& out, const Territory& c);

	int index;
	int continentIndex;
	int numberOfArmies;
	string name;
	Player* owner; // player that owns this Territory
	vector<Territory*> listOfAdjTerritories;
};





class Continent
{
public:
	Continent(); // Default Constructor
	Continent(int id, string n, int av);
	Continent(const Continent& c); // Copy Constructor
	Continent& operator = (const Continent& c); // Assignment operator
	~Continent(); // Destructor

	void addTerritory(Territory* t);
	void printTerritories();
	void printAdjContinents(); //not being used
	Territory* getTerritory(int id);

	friend ostream& operator << (ostream& out, const Continent& c);

	int index;
	string name;
	int armyvalue;
	vector<Territory*> listOfTerritories; // per continent
	vector<Continent*> listOfAdjContinents; //Not used ATM
};


// Only 1 map per game, I'm guessing :)
class Map
{
public:
	Map(); // Default Constructor
	Map(string n);
	Map(const Map& m); // Copy Constructor
	Map& operator = (const Map& m); // Assignment operator
	~Map(); // Destructor


	void addContinent(Continent* c);
	void addTerritory(Territory* t);
	void addAdjContinent(Continent* c1, Continent* c2);
	void addAdjTerritory(Territory* t1, Territory* t2); //TODO: maybe move this in Continent ?
	bool isAdjacent(int id1, int id2);
	void printContinents();
	Continent* getContinent(int id);
	Territory* getTerritory(int id);

	//TODO: Might delete. Implemented in Continent and Territory class already
	void printAdjContinents(Continent* c);
	void printAdjTerritory(Territory* t);

	friend ostream& operator << (ostream& out, const Map& m);
	//friend istream & operator >> (istream &in, Map &c);

	string name;
	vector<Continent*> listOfContinents;
	vector<Territory*> listOfTerritories; //all territories


	bool validate(); // goes through a few points to validate the map
};