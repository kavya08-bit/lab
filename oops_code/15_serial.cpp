#include <iostream>
#include <cstring>  
using namespace std;

class Serial {
private:
    int serialCode;
    char title[20];
    float duration;
    int noOfEpisodes;

public:
    Serial() {
        duration = 30;
        noOfEpisodes = 10;
        strcpy(title, "Untitled"); 
        serialCode = 0;
    }
    void Newserial(int code, const char t[]) {
        serialCode = code;
        strcpy(title, t);
    }


    void Otherentries(float d, int n) {
        duration = d;
        noOfEpisodes = n;
    }


    void Disp_data() {
        cout << "\nSerial Code: " << serialCode;
        cout << "\nTitle: " << title;
        cout << "\nDuration: " << duration;
        cout << "\nNumber of Episodes: " << noOfEpisodes << endl;
    }

    ~Serial() {
        cout << "\nDestructor called for Serial: " << serialCode << endl;
    }
};

int main() {
    Serial s1;

    s1.Newserial(101, "The Great Show");

    s1.Otherentries(45.5, 20);

    cout << "\n--- Serial Details ---";
    s1.Disp_data();
    cout<<"Kavya Pal Singh"<<endl<< " 03476803124";
    return 0;
}
