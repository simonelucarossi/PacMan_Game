#include <iostream>
using namespace std;

class Button {
public:
	string name;
	bool selected;

	inline Button() {
		name = "example";
		selected = false;
	}

	string getNameButton() { return name; }
	bool getSelectedButton() { return selected; }
	void setNameButton(string _name) { name = _name; }
	void setSelectedButton(bool _selected) { selected = _selected; }
};