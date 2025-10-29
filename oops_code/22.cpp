#include <iostream>
#include <cmath> 

using namespace std;

class shape {
public:
    virtual void get_data() = 0;
    virtual float calculate_area() = 0;
};

class triangle : public shape {
private:
    float base;
    float height;

public:
    void get_data() override {
        cout << "--- Enter Triangle Details ---" << endl;
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
    }

    float calculate_area() override {
        return 0.5 * base * height;
    }
};

class rectangle : public shape {
private:
    float length;
    float width;

public:
    void get_data() override {
        cout << "--- Enter Rectangle Details ---" << endl;
        cout << "Enter length: ";
        cin >> length;
        cout << "Enter width: ";
        cin >> width;
    }

    float calculate_area() override {
        return length * width;
    }
};

class circle : public shape {
private:
    float radius;

public:
    void get_data() override {
        cout << "--- Enter Circle Details ---" << endl;
        cout << "Enter radius: ";
        cin >> radius;
    }

    float calculate_area() override {
        return M_PI * radius * radius;
    }
};

int main() {
    shape* shape_ptr;

    triangle t;
    rectangle r;
    circle c;

    shape_ptr = &t; 
    shape_ptr->get_data();
    cout << "Area of Triangle is: " << shape_ptr->calculate_area() << endl;

    cout << "\n";
    shape_ptr = &r; 
    shape_ptr->get_data();
    cout << "Area of Rectangle is: " << shape_ptr->calculate_area() << endl;

    cout << "\n";
    shape_ptr = &c; 
    shape_ptr->get_data();
    cout << "Area of Circle is: " << shape_ptr->calculate_area() << endl;

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}