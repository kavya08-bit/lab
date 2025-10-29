#include <iostream>

using namespace std;

class LIST {
public:
    virtual void store(int val) = 0;
    virtual int retrieve() = 0;
    virtual ~LIST() {} 
};

class stack : public LIST {
private:
    int arr[100];
    int top;
public:
    stack() {
        top = -1;
    }

    void store(int val) override {
        if (top >= 99) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            arr[top] = val;
            cout << "Stored " << val << " in stack" << endl;
        }
    }

    int retrieve() override {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return -1; 
        } else {
            int val = arr[top];
            top--;
            cout << "Retrieved " << val << " from stack" << endl;
            return val;
        }
    }
};

class queue : public LIST {
private:
    int arr[100];
    int front, rear;
public:
    queue() {
        front = -1;
        rear = -1;
    }

    void store(int val) override {
        if (rear >= 99) {
            cout << "Queue Overflow" << endl;
        } else {
            if (front == -1) { 
                front = 0;
            }
            rear++;
            arr[rear] = val;
            cout << "Stored " << val << " in queue" << endl;
        }
    }

    int retrieve() override {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            front = -1; 
            rear = -1;
            return -1; 
        } else {
            int val = arr[front];
            front++;
            cout << "Retrieved " << val << " from queue" << endl;
            return val;
        }
    }
};

int main() {
    LIST* list_ptr;

    stack s;
    queue q;

    cout << "--- Testing Stack (LIFO) ---" << endl;
    list_ptr = &s;
    list_ptr->store(10);
    list_ptr->store(20);
    list_ptr->store(30);
    list_ptr->retrieve();
    list_ptr->retrieve();

    cout << "\n--- Testing Queue (FIFO) ---" << endl;
    list_ptr = &q;
    list_ptr->store(100);
    list_ptr->store(200);
    list_ptr->store(300);
    list_ptr->retrieve();
    list_ptr->retrieve();

    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}