#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    void getPersonDetails()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter age: ";
        cin >> age;
    }

    void displayPersonDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Superhero : public Person
{
private:
    string superpower;

public:
    void getSuperheroDetails()
    {
        getPersonDetails();

        cout << "Enter superpower: ";
        cin >> superpower;
    }

    void displaySuperheroDetails()
    {
        displayPersonDetails();
        cout << "Superpower: " << superpower << endl;
    }
};

int main()
{
    Superhero s;

    s.getSuperheroDetails();

    cout << "\n--- Superhero Details ---\n";
    s.displaySuperheroDetails();

    return 0;
}
