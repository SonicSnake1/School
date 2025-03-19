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
    smartPtr(const smartPtr<T> &sp) {
        pData = nullptr;
        if (sp.pData) {
            pData = new T; // Allocate memory
            *pData = *sp.pData; // Copy data
        }
    }

    // Destructor
    ~smartPtr() {
        delete pData; // Deallocate memory when the object goes out of scope
    }

    // Dereference Operator
    T& operator*() {
        if (pData) {
            return *pData;
        }
        throw runtime_error("Dereferencing a null pointer");
    }

    // Arrow Operator
    T* operator->() {
        if (pData) {
            return pData;
        }
        throw runtime_error("Accessing a null pointer");
    }

    // Assignment Operator
    const smartPtr<T>& operator=(const smartPtr<T>& sp) {
        if (this != &sp) {
            delete pData; // Free existing memory
            if (sp.pData) {
                pData = new T(*sp.pData); // Copy data from sp
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
