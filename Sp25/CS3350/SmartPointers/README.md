##STL Smart Pointers

###IN-Class Activity:

####Let’s design and implement our own Smart Pointer template class. Fill in the missing data member and prototypes for methods.


```cpp
template <typename T>
class smartPtr {
private:
    T* pData; // Pointer to mystery type T data
public:
    smartPtr(T* ptr=nullptr) : pData(ptr); // ctor
    smartPtr(const smartPtr<T> &); // copy ctor
    ~smartPtr(); // dtor
    T& operator*(); // deref op
    T* operator->(); // arrow op
    const smartPtr<T>& operator=(const smartPtr<T> &); // ass op
};
```

####Complete the copy constructor and the overloaded assignment operator methods.
```cpp
// copy constructor
//
template ____________
___________ smartPtr(const smartPtr<T> &spRight){
if (&spRight){
if (!pData)
pData = new T; // allocate memory
*pData = *spRight.pData; // copy data
}
}
// overloaded assignment operator
template ____________
const smartPtr<T>& smartPtr<T>::operator=(const smartPtr<T>& spRight)
{
// avoid self-assignment
if (this != &spRight)
{
if (&spRight){
if
(!pData) // was memory allocated?
pData = new T;
*pData = *spRight.pData; // copy data
}
}
return *this;
}
```
####Define a basic Person class and use it with our SmartPtr class. The class should have one string data member to hold name, and overloaded constructor accepting the name with empty string default value, and getName() accessort method returning the name.

```cpp
// Person class
//
class Person{
private:
string name;
public:
Person(string name=""){this->name=name;}
string getName()const{return name;}
};
Demonstrate use of smartPtr class with Person objects.
int main(){
// Using the smartPtr instead of raw pointer
{
}
return 0;
}
```