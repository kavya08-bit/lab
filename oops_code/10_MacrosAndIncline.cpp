#include <iostream>
using namespace std;

// Macro function to find maximum of two numbers
#define MAX(a,b) ((a) > (b) ? (a) : (b))

class Largest {
private:
    int a, b, c;

public:
    // Function to input numbers
    void input() {
        cout << "Enter three numbers: ";
        cin >> a >> b >> c;
    }

    inline int findLargest() {
        return (a > b && a > c) ? a : (b > c ? b : c);
    }

    // Function using macro to find largest
    int findLargestMacro() {
        return MAX(a, MAX(b, c));
    }
};

int main() {
    Largest obj;

    obj.input();

    cout << "Largest using Inline function : " << obj.findLargest() << endl;
    cout << "Largest using Macro : " << obj.findLargestMacro() << endl;
    cout << "Kavya Pal Singh   03476803124" << endl;


    return 0;
}
