#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <fstream>
#include "boost/tuple/tuple.hpp"

using std::cout;
using std::vector;
using boost::tuple;
using std::endl;
using std::string;
using std::array;
using std::ofstream;

typedef vector<tuple<string, float, float, float, float, float, float>> driver; // Drivers have identical stats for speed and handling in all environments
typedef vector<tuple<string,vector<float>, float, float, vector<float>, float, float>> parts; //vehicle parts all have differing stats for each environment so these must be accounted for when calculating an average.
typedef vector<tuple<string, float, float, float, float, float, float, float>> loadout; // as above, so below, only now we add another field to hold the total stats of the character build.




// WARNING - FORMATTING IN REAR-VIEW MAY LOOK MORE ABOMINABLE THAN IT APPEARS...
int main() {
	driver driverClasses;
	// Name, Speed, Accel, Weight, Handling, Traction, Mini-Turbo
		// Mini-Turbo is a hidden stat in MK8 and MK8D that describes the length of a character's speed boost when they release a mini-turbo...
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Baby Peach", 0, 4, 0, 10, 5, 5)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Baby Rosalina", 0, 5, 0, 9, 3, 5)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Baby Mario", 1, 5, 1, 8, 4, 4)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Toadette", 2, 5, 2, 7, 2, 4)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Toad", 3, 4, 3, 7, 4, 3)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Cat Peach", 4, 4, 3, 6, 3, 3)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Peach", 5, 3, 4, 5, 3, 3)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Tanooki Mario", 5, 4, 5, 5, 1, 3)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Mario", 6, 2, 6, 4, 2, 2)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Luigi", 6, 2, 6, 5, 1, 2)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Metal Mario", 8, 1, 10, 3, 1, 1)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Rosalina", 7, 1, 7, 3, 3, 2)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("DK", 9, 1, 8, 2, 0, 1)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Wario", 10, 0, 9, 1, 1, 0)));
	driverClasses.push_back((tuple<string, float, float, float, float, float, float>("Bowser", 10, 0, 10, 0, 0, 0)));

	parts kartClasses;
	
	// Name, Speed{Land, Water, Air, Antigravity}, Accel, Weight, Handling{Land, Water, Air, Antigravity}, Traction, Miniturbo
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Standard Kart", { 3, 3, 3, 3 }, 4, 2, {3,2,3,3},3,4));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Pipe Frame", {1,3,1,1}, 6, 1, {5,4,2,4}, 4, 6));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Mach 8", {3,3,4,5}, 3, 3, {2,2,2,4},4,4));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Steel Driver", {4,5,0,2}, 1, 4, {1,5,1,1}, 3, 2));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Cat Cruiser", {2,2,4,3}, 5, 2, {4,2,4,3 }, 3, 5));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Circuit", {5,1,2,4}, 1, 3, { 1,1,0,2 }, 1, 1));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Badwagon", {5,2,1,3}, 0, 4, { 0,1,0,1 },5, 0));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Prancer", { 4,3,3,3}, 2, 1, { 3,3,3,2 }, 2, 3));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Biddybuggy", {0,1,1,2}, 7,0, {5,4,4,5}, 4, 7));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Landship", {1,5,2,0}, 6, 0, {4,5,3,2}, 6, 6));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Sneeker", {4,2,3,3}, 2,2, {3,2,2,3},0,3));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Standard Bike", { 2, 2, 3, 4}, 5, 1, { 4,3,3,4}, 5, 5));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Blue Falcon", {4,2,3,4}, 3, 0, { 2,3,1,5 }, 3, 3));
	kartClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Tanooki Kart", {2,4,3,3}, 2, 3, {4,4,3,3}, 7, 3));

	
	parts tireClasses;
	// Name, Speed{Land, Water, Air, Antigravity}, Accel, Weight, Handling{Land, Water, Air, Antigravity}, Traction, Miniturbo
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Standard Tire", {2,3,3,2}, 4, 2, {3,3,3,3}, 5, 3));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Monster", {2,2,1,2}, 2, 4, {0,1,1,0}, 7, 2));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Roller", {0,3,3,0}, 6, 0, {4,4,4,4}, 4, 6));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Slim", {3,2,2,4}, 2, 2, { 4,4,4,3 }, 1, 2));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Slick", {4,0,0,4}, 1, 3, {2,0,1,2}, 0, 0));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Metal", { 4, 3,2,1 }, 0, 4, {2,2,0,1}, 2, 0));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Button", {1,2,2,2 }, 5, 0, { 3,3,2,4 }, 3, 5));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Offroad", {3,4,1,2}, 3, 3, { 1,1,2,2 }, 6, 1));
	tireClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Sponge", {1,1,3,1}, 4, 1, { 2,1,3,2}, 6, 4));


	parts gliderClasses;
// Name, Speed{Land, Water, Air, Antigravity}, Accel, Weight, Handling{Land, Water, Air, Antigravity}, Traction, Miniturbo
	gliderClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Standard Glider", { 1,1,2,0 }, 1, 1, {1,0,1,1}, 1, 1));
	gliderClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Cloud", {0,1,1,1}, 2, 0, { 1,0,2,1 }, 1, 2));
	gliderClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Wario Glider", {1,0,2,1 }, 1, 2, {1,1,1,0}, 0, 1));
	gliderClasses.push_back(tuple<string, vector<float>, float, float, vector<float>, float, float>("Parasol", { 0,0,1,1 }, 2, 1, {1,1,2,0}, 0, 2));

	loadout totalLoadouts;



	for (driver::const_iterator i = driverClasses.begin(); i != driverClasses.end(); ++i) {
		// Let's go through all the character classes first...
		for(parts::const_iterator j = kartClasses.begin(); j != kartClasses.end(); ++j) {
			// Then the karts/bikes...
			for (parts::const_iterator k = tireClasses.begin(); k != tireClasses.end(); ++k) {
					//The tires...
				for (parts::const_iterator l = gliderClasses.begin(); l != gliderClasses.end(); ++l) {
					//And finally the gliders...
					string name = i->get<0>() + " & " + j->get<0>() + " & " + k->get<0>() + " & " + l->get<0>() + ",";
					// feed iterators into the vector function 'get' to return the value at position i.
					// As an example, the first time this nested loop will run, name will hold a reference to the string "Baby Peach & Standard Kart & Standard Tire & Standard Glider".
					float totalSpeed = (
						((i->get<1>() + j->get<1>().at(0) + k->get<1>().at(0) + l->get<1>().at(0)) / 4) +
						((i->get<1>() + j->get<1>().at(1) + k->get<1>().at(1) + l->get<1>().at(1)) / 4) +
						((i->get<1>() + j->get<1>().at(2) + k->get<1>().at(2) + l->get<1>().at(2)) / 4) +
						((i->get<1>() + j->get<1>().at(3) + k->get<1>().at(3) + l->get<1>().at(3))/4)
						// We go through each of the Speed and Handling vectors and return the mean speed.
						// This metric should convey how much a character/vehicle combination performs on average. Some vehicles will perform better on tracks than others...
						// e.g. Landship has an underwater Speed stat of 5, so it should perform better on tracks that have large water sections like Dolphin Shoals.
						// On the other hand, it also has an Antigravity Speed stat of 1, meaning it doesn't do you any favours on Dragon Driftway, which is 99% antigravity.
						+ 12 ) / 4;
					float totalAcceleration = (i->get<2>() + j->get<2>() + k->get<2>() + l->get<2>() + 3) / 4;
					float totalWeight = (i->get<3>() + j->get<3>() + k->get<3>() + l->get<3>() + 3) / 4;
					float totalHandling = (
						((i->get<4>() + j->get<4>().at(0) + k->get<4>().at(0) + l->get<4>().at(0)) / 4) +
						((i->get<4>() + j->get<4>().at(1) + k->get<4>().at(1) + l->get<4>().at(1)) / 4) +
						((i->get<4>() + j->get<4>().at(2) + k->get<4>().at(2) + l->get<4>().at(2)) / 4) +
						((i->get<4>() + j->get<4>().at(3) + k->get<4>().at(3) + l->get<4>().at(3)) / 4)

						+ 12) / 4;
					float totalTraction = (i->get<5>() + j->get<5>() + k->get<5>() + l->get<5>() + 3)/ 4;
					float totalMiniTurbo = ((i->get<6>() + j->get<6>() + k->get<6>() + l->get<6>()) + 3) / 4;
					float totalOverall = totalSpeed + totalAcceleration + totalWeight + totalHandling + totalTraction + totalMiniTurbo;

					totalLoadouts.push_back(tuple<string, float, float, float, float, float, float, float>(name, totalSpeed,totalAcceleration, totalWeight, totalHandling,totalTraction,totalMiniTurbo,totalOverall));
				}
			}
		}
		
	} 


	loadout groundLoadouts;


	// And this abomination of a nested loop only factors in ground speed, unlike the previous where we take the average across all terrains.
	for (driver::const_iterator i = driverClasses.begin(); i != driverClasses.end(); ++i) {
		for (parts::const_iterator j = kartClasses.begin(); j != kartClasses.end(); ++j) {
			for (parts::const_iterator k = tireClasses.begin(); k != tireClasses.end(); ++k) {
				for (parts::const_iterator l = gliderClasses.begin(); l != gliderClasses.end(); ++l) {
					string name = i->get<0>() + " & " + j->get<0>() + " & " + k->get<0>() + " & " + l->get<0>() + ",";
				
					float groundSpeed = ((i->get<1>() + j->get<1>().at(0) + k->get<1>().at(0) + l->get<1>().at(0)) + 3) / 4;

					if (name == "Baby Mario & Standard Bike & Standard Tire & Standard Glider,") {
						cout << name << endl;
						cout << i->get<1>() << " + " << j->get<1>().at(0) << " + " << k->get<1>().at(0) << " + " << +l->get<1>().at(0) << " + 3 / 4 = " << groundSpeed << "\n";
					}

					float groundAcceleration = (i->get<2>() + j->get<2>() + k->get<2>() + l->get<2>() + 3 )  / 4;
					float groundWeight = (i->get<3>() + j->get<3>() + k->get<3>() + l->get<3>() + 3) / 4;
					float groundHandling = (((i->get<4>() + j->get<4>().at(0) + k->get<4>().at(0) + l->get<4>().at(0))) + 3) / 4;
					float groundTraction = (i->get<5>() + j->get<5>() + k->get<5>() + l->get<5>() + 3) / 4;
					float groundMiniTurbo = ((i->get<6>() + j->get<6>() + k->get<6>() + l->get<6>()) + 3) / 4;
					float groundOverall = groundSpeed + groundAcceleration + groundWeight + groundHandling + groundTraction + groundMiniTurbo;

					groundLoadouts.push_back(tuple<string, float, float, float, float, float, float, float>(name, groundSpeed, groundAcceleration, groundWeight, groundHandling, groundTraction, groundMiniTurbo, groundOverall));
				}
			}
		}

	}


	// Output results to a CSV file. 
	// I think it's more intuitive to use Excel or LibreOffice Calculator to find the most optimal spreads rather than sorting them umpteen different ways, but maybe that's just me.
	ofstream outputFile;
	outputFile.open("KartCombos.csv");
	if (outputFile.is_open()) {
		outputFile << "Character Combo,Speed (Avg.),Accel,Weight,Handling(Avg.),Traction,Mini-Turbo,Overall Stats\n";
		for (loadout::const_iterator i = totalLoadouts.begin(); i != totalLoadouts.end(); ++i) {
			outputFile << i->get<0>() << i->get<1>() << "," << i->get<2>() << "," << i->get<3>() << "," << i->get<4>() << "," << i->get<5>() << "," << i->get<6>() << "," << i->get<7>() << "\n";
		}
		outputFile.close();
	}
	else cout << "Couldn't open file!";


	outputFile.open("KartCombosGround.csv");
	if (outputFile.is_open()) {
		outputFile << "Character Combo,Speed (Avg.),Accel,Weight,Handling(Avg.),Traction,Mini-Turbo,Overall Stats\n";
		for (loadout::const_iterator i = groundLoadouts.begin(); i != groundLoadouts.end(); ++i) {
			outputFile << i->get<0>() << i->get<1>() << "," << i->get<2>() << "," << i->get<3>() << "," << i->get<4>() << "," << i->get<5>() << "," << i->get<6>() << "," << i->get<7>() << "\n";
		}
		outputFile.close();
	}
	else cout << "Couldn't open file!";

	return 0;
}

