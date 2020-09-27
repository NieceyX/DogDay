#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Dog {
	private:
		string name;
		vector<string> attributes;
		string breed;

		int find(string trait) {
			for (int i = 0; i < attributes.size(); i++) {
				if (attributes[i] == trait) {
					return i;
				}
			}
		}

	public:
		Dog(string call) {
			name = call;
			breed;
			attributes;
		}

		~Dog() {
			attributes.clear();
		}
		
		void pet() {
			cout << "You pet " << name << "!" << endl;
		}

		void feed() {
			cout << "You feed " << name << "!" << endl;
		}

		void type(string bread) {
			breed = bread;
			cout << "You put " << breed << " as " << name << "'s breed!" << endl;
		}
		
		void attribute() {
			string trait;
			cout << "What trait would you like to add for " << name << "? ";
			cin >> trait;

			attributes.push_back(trait);
			char response;

			cout << "Add another trait? ('y' or 'n') ";
			cin >> response;

			while (response != 'n') {
				cout << "What other trait to add? ";
				cin >> trait;

				attributes.push_back(trait);

				cout << "Add another trait? ('y' or 'n') ";
				cin >> response;
			}
		}

		void viewAttributes() {
			if (attributes.size() > 0) {
				cout << name << "'s traits are: " << endl;

				for (int i = 0; i < attributes.size(); i++) {
					cout << attributes[i] << ", ";
				}
				cout << endl;
			}

			else {
				cout << name << " does not have any recorded traits." << endl;
			}
		}

		void remove() {
			viewAttributes();
			int pos;

			if (attributes.size() == 0) {
				cout << "You can't remove anything." << endl;
			}
			else {
				string go;

				cout << "What do you want to remove? ";
				cin >> go;
				
				pos = find(go);
				attributes.erase(attributes.begin() + pos);

				char response;

				cout << "Remove another trait? ('y' or 'n') ";
				cin >> response;

				while (response != 'n') {
					viewAttributes();
					cout << "What do you want to remove? ";
					cin >> go;

					pos = find(go);
					attributes.erase(attributes.begin() + pos);

					char response;

					cout << "Remove another trait? ('y' or 'n') ";
					cin >> response;
				}
			}
		}
};