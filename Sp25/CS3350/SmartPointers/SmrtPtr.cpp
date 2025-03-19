#include <iostream>
#include <string>
using namespace std;

// Person class
class Person {
private:
    string name;
public:
    Person(string name = "") : name(name) {}
    string getName() const { return name; }
};

template <typename T>
class smartPtr {
private:
    T* pData; // Pointer to mystery type T data
public:
    // Constructor
    smartPtr(T* ptr = nullptr) : pData(ptr) {}

    // Copy Constructor
    smartPtr(const smartPtr<T>& spRight) {
        if (spRight.pData) {
            pData = new T(*spRight.pData); // Create a new object and copy the data
        } else {
            pData = nullptr;
        }
    }

    // Destructor
    ~smartPtr() {
        delete pData; // Deallocate memory when the object goes out of scope
    }

    // Dereference Operator
    T& operator*() {
        return *pData;
    }

    // Arrow Operator
    T* operator->() {
        return pData;
    }

    // Assignment Operator
    const smartPtr<T>& operator=(const smartPtr<T>& spRight) {
        if (this != &spRight) {
            delete pData; // Free existing memory
            if (spRight.pData) {
                pData = new T(*spRight.pData); // Copy data from spRight
            } else {
                pData = nullptr;
            }
        }
        return *this;
    }
};

int main() {
    // Using the smartPtr instead of raw pointer

    // Create sp1 with "Alex" as name
    smartPtr<Person> sp1(new Person("Alex"));
    cout << sp1->getName() << endl; // Should print "Alex"

    // Create sp2 with "Eva" as name and print name
    smartPtr<Person> sp2(new Person("Eva"));
    cout << sp2->getName() << endl; // Should print "Eva"

    // Copy sp1 object to sp2 object
    sp2 = sp1;
    cout << sp2->getName() << endl; // Should print "Alex" after assignment

    // Create sp3 initialized with sp1 object and print name
    smartPtr<Person> sp3 = sp1;
    cout << sp3->getName() << endl; // Should print "Alex" after copy constructor

    return 0;
}
