#include <iostream>
#include <string>
using namespace std;

class Auditorium {
private:
    static int count;   

public:
    void enterPerson(string name) {
        count++; 
        cout << name << " entered. Current count: " << count << endl;
    }

    static void showTotal() {
        cout << "Total people in auditorium: " << count << endl;
    }
};

int Auditorium::count = 0;

int main() {
    Auditorium a;   

    int n;
    cout << "Enter number of people entering: ";
    cin >> n;

    cin.ignore(); 
    for(int i=0; i<n; i++) {
        string name;
        cout << "Enter name of person " << i+1 << ": ";
        getline(cin, name);

        a.enterPerson(name);
    }

    Auditorium::showTotal(); 
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";
    return 0;
}
