#include <iostream>
#include <cmath> // For sqrt()

using namespace std;

class Point {
protected:
    float x;
    float y;

public:
    void read_coordinates() {
        cout << "Enter coordinate x: ";
        cin >> x;
        cout << "Enter coordinate y: ";
        cin >> y;
    }

    void display_coordinates() {
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

class PointDistance : public Point {
private:
    float distance;

public:
    void calculate_distance() {
        // Accesses protected members x and y from the base class
        distance = sqrt((x * x) + (y * y));
    }

    void display_distance() {
        cout << "Distance from origin (0,0): " << distance << endl;
    }
};

int main() {
    PointDistance p1;

    cout << "--- Enter Point Details ---" << endl;
    p1.read_coordinates();

    // Calculate the distance
    p1.calculate_distance();

    cout << "\n--- Point Summary ---" << endl;
    p1.display_coordinates();
    p1.display_distance();
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";

    return 0;
}