## Map

### Motivation & Example

#### Search Specific
- **Binary Search**: A search algorithm that finds the position of a target value within a sorted array.  
- **Linear Search**: A search algorithm that checks each element in a list sequentially.

#### Complexity Specific
- **Log(n)**: Refers to the time complexity of algorithms such as binary search, where the problem size reduces by half at each step.
- **Linear (O(n))**: Refers to the time complexity of algorithms such as linear search, where the algorithm checks each element in the collection.

### Sort and Search Keys

#### Sort Key
- The data you use to **sort** or order elements in a collection.

#### Search Key
- The data you use to **search** for a specific element in a collection, often based on the sorted order.

### Map ADT

- **Map** is a value-based container, similar to a sorted list, binary search tree, priority queue, or a heap.  
- It maps a **key** to a **value** with no duplicates allowed.  
- The key-value pair is called an **entry**.

### Dictionary ADT

- The **Dictionary ADT** is a searchable Abstract Data Type (ADT), commonly used to store and manage key-value pairs.  
- Examples of dictionary usage include word-definition pairs, credit card authentication, and DNS mapping (Domain-to-IP address).

#### Dictionary ADT Methods:
- `contains(k)`: Checks if the dictionary contains the key `k`.
- `add(k, v)`: Adds a key-value pair `(k, v)` to the dictionary.
- `remove(k)`: Removes the entry with the key `k`.
- `size()`: Returns the number of entries in the dictionary.
- `isEmpty()`: Checks if the dictionary is empty.
- `clear()`: Removes all entries from the dictionary.
- `getItem(k)`: Retrieves the value associated with key `k`.

#### Entry

- `getKey()`: Returns the key of the entry.
- `getValue()`: Returns the value of the entry.

### Hash Table
- A **hash table** is an array storing data values at specific array indices.  
- The index is calculated by a **hash function** that converts the search key into a location in the array.  
- **Time complexity**: Constant time O(1), assuming a good hash function and minimal collisions.  
- `h` is a hash function that maps keys to specific integer values. The output of the hash function determines the index of the key-value pair in the hash table. A good hash function evenly distributes keys to minimize collisions.
- A **hash function** `h` maps keys of a given type to integers in a fixed interval `[0, N-1]`, where `N` is the size (or capacity) of the hash table. This is done to ensure that the keys are uniformly distributed across the array indices.

#### Collision Handling
- **Collision** occurs when two different keys hash to the same index in the hash table.  
- Collisions are typically handled by chaining, where each table index stores a linked list of key-value pairs.  
- In this case, multiple entries that map to the same index are stored in a linked list connected to that index.

### Hash Functions
A **hash function** is an algorithm that takes an input (or "key") and returns an integer, which represents the index in the hash table. The goal of the hash function is to distribute the keys as evenly as possible across the hash table, minimizing collisions. Some common properties of a good hash function include:
- **Deterministic**: The same key will always produce the same hash value.
- **Efficient**: The computation should be fast and not require excessive resources.
- **Uniform distribution**: The hash values should be uniformly distributed across the available array indices to reduce clustering and collisions.

Some common hash functions include:
- **Division method**: `h(k) = k % N`, where `k` is the key and `N` is the size of the hash table.
- **Multiplicative method**: Uses a constant `A` to multiply the key and then extracts the fractional part before multiplying by the table size.

### Hash Table Implementation
- **Array of pointers to linked lists**: The hash table is typically an array where each element points to a linked list (or another structure) that holds the key-value pairs.
- **Hash Function**: The hash function computes the index for a given key using the formula `hash_code = h(k) % capacity`, where `h(k)` is the hash function applied to the key `k`, and `capacity` is the size of the table.
- **Key and Value**: `k` and `v` are typically integers, though more complex types can also be used as long as a suitable hash function is defined. In some implementations, `k` may be equal to `v` in certain scenarios, such as for storing mappings where the key is the same as the value.

Example:
```cpp
class HashTable {
    private:
        LinkedList[] table;
        int capacity;
    
    public:
        HashTable(int capacity) {
            this->capacity = capacity;
            table = new LinkedList[capacity];
        }

        int hash(int key) {
            return key % capacity;
        }

        void insert(int key, int value) {
            int index = hash(key);
            table[index].insert(key, value);
        }

        int get(int key) {
            int index = hash(key);
            return table[index].get(key);
        }
};
