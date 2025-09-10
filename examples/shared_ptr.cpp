#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person {
    private:
        string name;
    public:
        Person(string n) : name(n) {};
        string getName() { return name; }
};

int main() {
    string name = "";
    vector<shared_ptr<Person>> people;

    for (int i=0; i<people.size(); i++) {
        cin >> name;
        people.push_back(make_shared<Person>(name));
    }

    for (int i=0; i<people.size(); i++)
        cout << people[i]->getName() << endl;
}
