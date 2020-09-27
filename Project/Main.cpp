#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <stdlib.h>

#include "Dogs.h"

using namespace std;

int main() {
	string input;
	string name;
	string breed;
	list<string> dogs;

	cout << setw(20) << "Hello!" << endl;

	cout << "Type 'help' at any time to see a list of commands!" << endl;

	cout << "Command? ";
	cin >> input;
	
	while (input != "quit") {

		if (input == "help") {
			cout << "Type 'add' to get a new dog, 'leave' to send a dog back home, 'quit' to quit!" << endl <<
				"Type 'traits' to add to, remove from, or view, a dog's trait list." << endl <<
				"Type 'dogs' for a list of current dogs, 'pet' to pet them, 'feed' to feed them, type to say what breed the dog is!" << endl <<
				"Type 'random' for a random event." << endl;
		}

		else if (input == "add") {
			cout << "What is the dog's name? ";
			cin >> name;

			dogs.push_front(name);
			Dog name(name);
		}

		else if (input == "type") {
			cout << "What dog are you recording? ";
			cin >> name;

			cout << "What is " << name << "'s breed? ";
			cin >> breed;

			Dog(name).type(breed);
		}
		
		else if (input == "leave") {
			if (dogs.size() != 0) {
				name = dogs.back();
				dogs.pop_back();
				cout << name << " is going home!" << endl;
				Dog(name).~Dog();
			}

			else {
				cout << "There aren't any dogs to leave!" << endl;
			}
		}

		else if (input == "traits") {
			string which;
			cout << "Which dog do you want to view? ";
			cin >> name;

			if (std::find(dogs.begin(), dogs.end(), name) != dogs.end()) {
				cout << "Do you want to 'add' to " << name << "'s traits, 'remove', or 'view'? ";
				cin >> which;

				if (which == "add") {
					Dog(name).attribute();
				}
				else if (which == "remove") {
					Dog(name).remove();
				}
				else if (which == "view") {
					Dog(name).viewAttributes();
				}
				else {
					cout << "Sorry, that isn't a valid input." << endl;
				}
			}

			else {
				cout << "That is not a dog you currently have." << endl;
			}
		}

		else if (input == "dogs") {
			cout << "Current dogs:" << endl;
			for (auto it = dogs.begin(); it != dogs.end(); ++it)
				cout << ' ' << *it;
			cout << endl;
		}

		else if (input == "pet") {
			int rando;

			rando = rand() % dogs.size();

			list<std::string>::iterator it = dogs.begin();
			advance(it, rando);

			Dog(*it).pet();
		}

		else if (input == "feed") {
			int rando;

			rando = rand() % dogs.size();

			list<std::string>::iterator it = dogs.begin();
			advance(it, rando);

			Dog(*it).pet();
		}

		else if (input == "random") {
			int rando;

			rando = rand() % 5 + 1;

			switch (rando) {
				case 1:
					cout << "A dog sneezed and riled up other dogs." << endl;
					break;

				case 2:
					cout << "When one dog starts howling the others follow, a howling match has started." << endl;
					break;

				case 3:
					char resp;
					cout << "The dogs ask to go outside, do you let them? ('y' or 'n') ";
					cin >> resp;

					if (resp == 'y') {
						cout << "You let the dogs out for a while, they seem happy." << endl;
					}

					else {
						cout << "You decide to not let the dogs out, they seem upset." << endl;
					} 
					break;

				case 4:
					cout << "There's a weird smell coming from somewhere..." << endl;
					break;

				case 5:
					cout << "Dogs are very happy all the time, these dogs are no exception." << endl;
					break;
			}

		}

		else {
			cout << "Sorry, that isn't a valid input." << endl;
		}

		cout << "Command? ";
		cin >> input;
	}

	cout << "Goodbye!" << endl;
	return 0;
}