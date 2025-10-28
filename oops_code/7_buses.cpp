#include <iostream>
using namespace std;


class Buses {
private:
    int passengers;   
    int busCapacity;
    int buses;  

    public:
        void input() {
            cout << "Enter total number of passengers: ";
            cin >> passengers;
            cout << "Enter capacity of one bus: ";
            cin >> busCapacity;
        }

        int cal_Buses() {
            buses = passengers / busCapacity;
            if (passengers % busCapacity != 0) {
                buses++;
            }
            return buses;
        }
        void output() {
            cout << "Total Passengers: " << passengers<<endl;;
            cout << "Bus Capacity: " << busCapacity<<endl;;
            cout << "Buses Required: " << cal_Buses() << endl;
        }
    };


int main() {
    Buses b1;  
    b1.input();
    b1.output();
    cout<<"kavya pal singh"<<endl;
    cout<<"03476803124";

    return 0;
}
