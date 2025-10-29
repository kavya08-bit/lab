#include <iostream>
#include <cstdlib> // For malloc and free
#include <new>     // For std::bad_alloc

using namespace std;

class CustomMemory {
private:
    int data;
public:
    CustomMemory(int d = 0) {
        data = d;
        cout << "Constructor called. data = " << data << endl;
    }

    ~CustomMemory() {
        cout << "Destructor called. data = " << data << endl;
    }

    // Overloading new
    static void* operator new(size_t size) {
        cout << "Overloaded new: Allocating " << size << " bytes" << endl;
        
        void* p = malloc(size);
        if (!p) {
            throw std::bad_alloc();
        }
        return p;
    }

    // Overloading delete
    static void operator delete(void* ptr) {
        cout << "Overloaded delete: Freeing memory" << endl;
        free(ptr);
    }
};

int main() {
    cout << "--- Creating an object ---" << endl;
    
    // This calls:
    // 1. CustomMemory::operator new()
    // 2. CustomMemory::CustomMemory()
    CustomMemory* p = new CustomMemory(123);

    cout << "\n--- Deleting the object ---" << endl;
    
    // This calls:
    // 1. CustomMemory::~CustomMemory()
    // 2. CustomMemory::operator delete()
    delete p;

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}