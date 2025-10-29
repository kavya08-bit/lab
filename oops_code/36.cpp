#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void append(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Appended: " << val << endl;
    }

    void display_forward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "List (forward): ";
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void display_reverse() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        
        cout << "List (reverse): ";
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "--- Creating Doubly Linked List of Integers ---" << endl;
    DoublyLinkedList<int> intList;
    intList.append(10);
    intList.append(20);
    intList.append(30);

    cout << "\n";
    intList.display_forward();
    intList.display_reverse();

    cout << "\n\n--- Creating Doubly Linked List of Strings ---" << endl;
    DoublyLinkedList<string> stringList;
    stringList.append("Hello");
    stringList.append("World");
    stringList.append("!");

    cout << "\n";
    stringList.display_forward();
    stringList.display_reverse();
    
    cout << "\n";
    cout << "Kavya Pal Singh" << endl << " 03476803124";

    return 0;
}