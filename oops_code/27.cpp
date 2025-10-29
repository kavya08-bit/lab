#include <iostream>
#include <cstring> 
#include <cctype>  

using namespace std;

class my_string {
private:
    char str[256]; 

public:
    my_string(const char* s = "") {
        strcpy(str, s);
    }

    void display() {
        cout << str << endl;
    }

    my_string operator+(const my_string& other) {
        my_string temp;
        strcpy(temp.str, this->str); 
        strcat(temp.str, other.str); 
        return temp;
    }

    void operator=(const my_string& other) {
        if (this == &other) {
            return;
        }
        strcpy(this->str, other.str);
    }

    bool operator<=(const my_string& other) {
        return (strcmp(this->str, other.str) <= 0);
    }

    void display_length() {
        cout << "Length: " << strlen(str) << endl;
    }

    void to_lower() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = std::tolower(str[i]);
        }
    }

    void to_upper() {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = std::toupper(str[i]);
        }
    }
};

int main() {
    my_string s1("Hello");
    my_string s2("World");
    my_string s3;

    cout << "s1: "; s1.display();
    cout << "s2: "; s2.display();
    
    cout << "\n--- Testing + (Concatenation) ---" << endl;
    s3 = s1 + " " + s2 + "!"; 
    cout << "s3 (s1 + s2): ";
    s3.display();

    cout << "\n--- Testing = (Copy) ---" << endl;
    my_string s4;
    s4 = s3;
    cout << "s4 (copied from s3): ";
    s4.display();

    cout << "\n--- Testing <= (Comparison) ---" << endl;
    my_string s_apple("Apple");
    my_string s_banana("Banana");
    if (s_apple <= s_banana) {
        cout << "Apple <= Banana is TRUE" << endl;
    }
    if (s_banana <= s_apple) {
        cout << "Banana <= Apple is TRUE" << endl;
    } else {
        cout << "Banana <= Apple is FALSE" << endl;
    }

    cout << "\n--- Testing Length ---" << endl;
    s3.display_length();

    cout << "\n--- Testing toupper() ---" << endl;
    s3.to_upper();
    cout << "s3 (uppercase): ";
    s3.display();

    cout << "\n--- Testing tolower() ---" << endl;
    s3.to_lower();
    cout << "s3 (lowercase): ";
    s3.display();


    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}