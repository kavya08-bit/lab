#include <iostream>
using namespace std;

// Global variable
int value = 10;

class Demo {
    public:
        static int value; 

        void show() {
            int value = 30; 
            cout << "Local value: " << value << endl;
            cout << "Class-level value: " << Demo::value << endl;
            cout << "Global value: " << ::value << endl;
        }
};


int Demo::value = 20;

int main() {
    Demo obj;
    obj.show();
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";
    return 0;
}