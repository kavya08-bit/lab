#include <iostream>
#include <string>

using namespace std;

class publication {
private:
    string title;
    float price;

public:
    void getdata() {
        cin.ignore(); 
        
        cout << "Enter Title: ";
        getline(cin, title);
        
        cout << "Enter Price: ";
        cin >> price;
    }

    void putdata() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class book : public publication {
private:
    int page_count;

public:
    void getdata() {
        publication::getdata(); 
        cout << "Enter Page Count: ";
        cin >> page_count;
    }

    void putdata() {
        publication::putdata(); 
        cout << "Page Count: " << page_count << " pages" << endl;
    }
};

class tape : public publication {
private:
    float playing_time;

public:
    void getdata() {
        publication::getdata(); 
        cout << "Enter Playing Time (in minutes): ";
        cin >> playing_time;
    }

    void putdata() {
        publication::putdata(); 
        cout << "Playing Time: " << playing_time << " minutes" << endl;
    }
};

int main() {
    book b1;
    tape t1;

    cout << "--- Enter Book Data ---" << endl;
    b1.getdata(); 

    cout << "\n--- Enter Tape Data ---" << endl;
    t1.getdata(); 

    cout << "\n\n--- Displaying Book Data ---" << endl;
    b1.putdata();

    cout << "\n--- Displaying Tape Data ---" << endl;
    t1.putdata();
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";

    return 0;
}