#include <iostream>
#include <string>
#include <exception>

using namespace std;

class myException : public exception {
public:
    myException() { msg = "Space for rent"; }
    myException(string str) { msg = str; }
    
    virtual const char* what() const noexcept override { 
        return msg.c_str(); 
    }

private:
    string msg;
};

// Prototypes
void functionA() noexcept(false);
void functionB() noexcept(false);
void functionC();

int main() {
    try {
        functionA();
    }
    catch (const exception& e) {  // Catch exceptions by reference
        cout << e.what() << endl;
    }
    catch (const myException& me) {
        cout << me.what() << " handled in main()" << endl;
    }

    cin.get();  // Portable alternative to system("pause")
    return 0;
}

void functionA() noexcept(false) { functionB(); }
void functionB() noexcept(false) { 
    try{
        functionC(); 
    }
    catch ( myException &me)

void functionC() {
    string s = "Jack and Jill";
    try {
        cout << s.substr(100, 20) << endl;  // This will throw an exception
    }
    catch (const exception& e) {  // Catch by reference
        myException me("Exception generated in functionC");
        throw me;  // Throwing a custom exception
    }
    cout << "Will not execute if exception is thrown" << endl;
}
