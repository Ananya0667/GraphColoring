#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        //Defined a structure to represent a node in the list.
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };
    Node* head;// Pointer to the head of the list.
    int size = 0;// The size of the list.

public:
    //Constructor: Creates an empty list with an optional initial size.
    List(int initialSize = 0) : head(nullptr), size(0) {
        //Set the size of the list and initialize elements to default values.
        size = initialSize;
        for (int i = 0; i < initialSize; ++i) 
            push_back(T());// Initialize the elements to default values.  
    }

    // Adds a new element with the given value to the end of the list.
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } 
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        size = size+1;// Increment the size of the list.
    }

     //Returns the value at the specified index in the list.
    T get(int index) const {
        if (index < 0 || index >=size){
            cout<<"Given index out of range"<<endl;
            exit(1);
        }    
        Node* current = head;
        for (int i = 0; i < index; ++i) 
            current = current->next;
        return current->data;
    }

    // Sets the value at the specified index in the list.
    void set(int index, const T& value) {
        if (index < 0 || index >=size){ 
            cout<<"Given index out of range"<<endl;
            exit(1);
        }
        Node* current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;
        
        current->data = value;
    }

   //Prints the elements of the list.
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    // Returns the size of the list.
    int getSize() const {
        return size;
    }

    //Destructor: Frees memory by deleting all nodes in the list.
   ~List() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};