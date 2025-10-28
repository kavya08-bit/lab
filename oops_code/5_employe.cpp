#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int Empno;
    string Ename;
    float Basic, Hra, Da, Netpay;

public:
    // To input employee details
    void Havedata() {
        cout << "Enter Employee Number:";
        cin >> Empno;
        cout << "Enter Employee Name: ";
        cin >> Ename;
        cout << "Enter Basic Salary: ";
        cin >> Basic;
    }


    void Calculate() {
        Hra = 0.10 * Basic;  
        Da = 0.20 * Basic;  
        Netpay = Basic + Hra + Da;
    }

    void Display() {
        cout << "Employee Number : " << Empno<<endl ;
        cout << "Employee Name   : " << Ename<<endl;
        cout << "Basic Salary    : " << Basic<<endl;
        cout << "HRA (10%)       : " << Hra<<endl;
        cout << "DA (20%)        : " << Da<<endl;
        cout << "Net Pay         : " << Netpay << endl;
    }
};

int main() {
    Employee e;

    e.Havedata();    
    e.Calculate();  
    e.Display();     
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";

    return 0;
}
