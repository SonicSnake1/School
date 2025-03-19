## STL Smart Pointers
### Creating A SmartPtr Object

[Smart Pointer Template Class](SmrtPtr.cpp)  

### Lecture

  Smart Pointers are Class objects that behave like built-in pointers, but manage the memory created with **New**.  
#### Unique Ownership
- You can create a unique pointer ti an allocated object, then when the unique_ptr goes out of scope , the pointed to object gets deleted  

```cpp
void somefunction(){
    unique_ptr<Thing> p(new Thing);
    do_somehting_with(p);
    p->defrangualte();
    }
```
- reset() ->
- **Fill in later**    

#### Under the Hood
- Can only use smart pointers to refer to objects allocated with **New**  
- 



### IN-Class Activity:

#### Let’s design and implement our own Smart Pointer template class. Fill in the missing data member and prototypes for methods.


```cpp
template <typename T>
class smartPtr {
private:
    T* pData; // Pointer to mystery type T data
public:
    smartPtr(T* ptr=nullptr) : pData(ptr); // ctor
    smartPtr(const smartPtr<T> &); // copy ctor
    ~smartPtr() { delete pData;} // dtor
    T& operator*(){return *pData;} // deref op
    T* operator->(){return pData;} // arrow op
    const smartPtr<T>& operator=(const smartPtr<T> &); // ass op
};
```

#### Complete the copy constructor and the overloaded assignment operator methods.
```cpp
// Copy constructor
template <typename T>
smartPtr<T>::smartPtr(const smartPtr<T>& spRight) {
    if (spRight.pData) {  
        pData = new T;           // Allocate memory for the new object
        *pData = *spRight.pData; // Perform a deep copy of the data
    } else {
        pData = nullptr; // If spRight is empty, set pData to nullptr
    }
}

// Overloaded assignment operator
template <typename T>
const smartPtr<T>& smartPtr<T>::operator=(const smartPtr<T>& spRight) {
    // Avoid self-assignment
    if (this != &spRight) {
        delete pData; // Clean up existing memory

        if (spRight.pData) {  
            pData = new T;           // Allocate new memory for the object
            *pData = *spRight.pData; // Perform a deep copy of the data
        } else {
            pData = nullptr; // If spRight is empty, set pData to nullptr
        }
    }
    return *this;
}

```
#### Define a basic Person class and use it with our SmartPtr class. The class should have one string data member to hold name, and overloaded constructor accepting the name with empty string default value, and getName() accessort method returning the name.

```cpp
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
            pData = new T;           // Allocate memory for the new object
            *pData = *spRight.pData; // Perform a deep copy of the data
        } else {
            pData = nullptr; // If spRight is empty, set pData to nullptr
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

    // Overloaded Assignment Operator
    const smartPtr<T>& operator=(const smartPtr<T>& spRight) {
        // Avoid self-assignment
        if (this != &spRight) {
            delete pData; // Clean up existing memory

            if (spRight.pData) {  
                pData = new T;           // Allocate new memory for the object
                *pData = *spRight.pData; // Perform a deep copy of the data
            } else {
                pData = nullptr; // If spRight is empty, set pData to nullptr
            }
        }
        return *this;
    }
};

int main() {
    // Using the smartPtr instead of raw pointer

    // Create sp1 with "Alex" as name
    smartPtr<Person> sp1(new Person("Alex"));
    cout << "sp1 Name: " << sp1->getName() << endl; // Should print "Alex"

    // Create

```