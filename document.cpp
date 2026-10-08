#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> printerqueue;
    int choice;
    string document;

    do
    {
        cout << "\nPRINTER QUEUE\n";
        cout << "1. Add Document\n";
        cout << "2. Print Next Document\n";
        cout << "3. Display Pending Documents\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the document name: ";
                cin >> document;
                printerqueue.push(document);
                cout << "Document added to queue.\n";
                break;

            case 2:
                if (printerqueue.empty())
                {
                    cout << "No documents to print.\n";
                }
                else
                {
                    cout << "Printing: " << printerqueue.front() << endl;
                    printerqueue.pop();
                }
                break;

            case 3:
                if (printerqueue.empty())
                {
                    cout << "No pending documents.\n";
                }
                else
                {
                    queue<string> temp = printerqueue;

                    cout << "Pending Documents:\n";
                    while (!temp.empty())
                    {
                        cout << temp.front() << endl;
                        temp.pop();
                    }
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
