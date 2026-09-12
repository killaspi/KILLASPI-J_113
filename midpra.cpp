#include <iostream>
#include <string>
using namespace std;

char getgrade(float average)
{
    if (average >= 90) return 'A';
    if (average >= 80) return 'B';
    if (average >= 70) return 'C';
    if (average >= 60) return 'D';
    if (average >= 50) return 'E';
    return 'F';
}

class Student
{
public:
    int rollnumber;
    string name;
    float mark[5];

    float getaverage() const
    {
        float sum = 0;
        for (int i = 0; i < 5; i++)
        {
            sum += mark[i];
        }
        return sum / 5.0f;
    }

    void display() const
    {
        float avg = getaverage();
        cout << "rollnumber: " << rollnumber << endl;
        cout << "name: " << name << endl;
        cout << "average: " << avg << endl;
        cout << "grade: " << getgrade(avg) << endl;
    }
};

int main()
{
    Student students[50];
    int count = 0;
    int choice;

    do
    {
        cout << "Add student" << endl;
        cout << "2. Student details" << endl;
        cout << "3. Class topper" << endl;
        cout << "4. All students" << endl;
        cout << "5. Exit" << endl;
        cout << "enter choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (count >= 50)
            {
                cout << "capacity full" << endl;
                continue;
            }
            int roll;
            cout << "enter student roll no: ";
            cin >> roll;

            bool exists = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].rollnumber == roll)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "roll number already exists" << endl;
            }
            else
            {
                students[count].rollnumber = roll;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, students[count].name);
                cout << "Enter 5 subject marks: ";
                for (int i = 0; i < 5; i++)
                {
                    cin >> students[count].mark[i];
                }
                count++;
                cout << "Student added successfully!" << endl;
            }
        }
        else if (choice == 2)
        {
            int roll;
            cout << "enter student roll no: ";
            cin >> roll;

            bool found = false;
            for (int i = 0; i < count; i++)
            {
                if (students[i].rollnumber == roll)
                {
                    cout << endl;
                    students[i].display();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "student not found" << endl;
            }
        }
        else if (choice == 3)
        {
            if (count == 0)
            {
                cout << "No students available." << endl;
                continue;
            }

            float maxAvg = students[0].getaverage();
            for (int i = 1; i < count; i++)
            {
                if (students[i].getaverage() > maxAvg)
                {
                    maxAvg = students[i].getaverage();
                }
            }

            cout << " CLASS TOPPER" << endl;
            for (int i = 0; i < count; i++)
            {
                if (students[i].getaverage() == maxAvg)
                {
                    students[i].display();
                    cout << endl;
                }
            }
        }
        else if (choice == 4)
        {
            if (count == 0)
            {
                cout << "No students available." << endl;
                continue;
            }

            Student temp[50];
            for (int i = 0; i < count; i++)
            {
                temp[i] = students[i];
            }

            for (int i = 0; i < count - 1; i++)
            {
                for (int j = 0; j < count - i - 1; j++)
                {
                    if (temp[j].getaverage() < temp[j + 1].getaverage())
                    {
                        Student t = temp[j];
                        temp[j] = temp[j + 1];
                        temp[j + 1] = t;
                    }
                }
            }

            cout << "all students" << endl;
            for (int i = 0; i < count; i++)
            {
                temp[i].display();
                cout << endl;
            }
        }

    } while (choice != 5);

    return 0;
}
