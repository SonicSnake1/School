#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

const int CAPACITY = 11;

class Entry {
private:
    string key;
    string value;

public:
    // Constructor to initialize the key-value pair
    Entry(string k, string v) : key(k), value(v) {}

    // Accessor methods to get key and value
    string getKey() const { return key; }
    string getValue() const { return value; }

    // Function to display Entry
    void display() const {
        cout << "(" << key << ", " << value << ")";
    }
};

class HashTable {
private:
    list<Entry>* pTable; // Pointer to the Hash Table

public:
    HashTable();
    ~HashTable();

    void insertItem(const string& key, const string& value);
    void deleteItem(const string& key);

    int hashFunction(const string& key);

    void displayHash() const;
};

HashTable::HashTable() {
    pTable = new list<Entry>[CAPACITY];
}

HashTable::~HashTable() {
    delete[] pTable;
}

// Hash function to compute index for string keys
int HashTable::hashFunction(const string& key) {
    int hashCode = 0;
    int length = key.length();
    
    // Applying the hash function s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]*31^0
    for (int i = 0; i < length; i++) {
        hashCode = hashCode * 31 + key[i];
    }

    return hashCode % CAPACITY;
}

// Insert an Entry (key-value pair) into the hash table
void HashTable::insertItem(const string& key, const string& value) {
    int index = hashFunction(key);
    Entry newEntry(key, value);
    pTable[index].push_back(newEntry);
}

// Delete an Entry by its key
void HashTable::deleteItem(const string& key) {
    int index = hashFunction(key);
    list<Entry>::iterator it;
    bool isFound = false;

    // Locate the value in the linked list of values
    for (it = pTable[index].begin(); it != pTable[index].end(); ++it) {
        if (it->getKey() == key) {
            isFound = true;
            pTable[index].erase(it);  // Delete the found Entry
            break;
        }
    }

    if (!isFound) {
        cout << "Key '" << key << "' not found in the hash table." << endl;
    }
}

// Display the hash table content
void HashTable::displayHash() const {
    for (int i = 0; i < CAPACITY; i++) {
        cout << i << ": ";
        if (pTable[i].empty()) {
            cout << "null";  // Empty bucket, display "null"
        } else {
            for (const auto& entry : pTable[i]) {
                entry.display();
                cout << " --> ";
            }
        }
        cout << endl;
    }
}

int main() {
    HashTable hashTable;
    
    // Initialize vectors for keys and values
    vector<string> keys = {"190", "123", "321", "555", "777"};
    vector<string> values = {"SpongeBob", "Patrick", "Sandy", "Squidward", "Gary"};
    
    // Insert key-value pairs into the hash table
    for (size_t i = 0; i < keys.size(); i++) {
        hashTable.insertItem(keys[i], values[i]);
    }

    // Display hash table
    cout << "Hash table after insertions:" << endl;
    hashTable.displayHash();

    // Delete the 3rd element (key "321" -> "Sandy")
    hashTable.deleteItem("321");

    // Display hash table after deletion
    cout << "\nHash table after deletion of key '321':" << endl;
    hashTable.displayHash();

    // Try deleting a non-existing key
    cout << "\nTrying to delete a non-existing key '999':" << endl;
    hashTable.deleteItem("999");

    return 0;
}
