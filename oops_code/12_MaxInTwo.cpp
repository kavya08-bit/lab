#include <iostream>
using namespace std;

class B;   

class A {
private:
    int num1;

public:
    void getData() {
        cout << "Enter first number: ";
        cin >> num1;
    }

    friend void findGreatest(A, B);  
};

class B {
private:
    int num2;

public:
    void getData() {
        cout << "Enter second number: ";
        cin >> num2;
    }

    friend void findGreatest(A, B); 
};

void findGreatest(A obj1, B obj2) {
    if (obj1.num1 > obj2.num2)
        cout << obj1.num1 << " is greater." << endl;
    else if (obj2.num2 > obj1.num1)
        cout << obj2.num2 << " is greater." << endl;
    else
        cout << "Both numbers are equal." << endl;
}

int main() {
    A a;
    B b;

    a.getData();
    b.getData();

    findGreatest(a, b);
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";
    return 0;
}
