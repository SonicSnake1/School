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

#####Collision Resolution Methods
- Linear Probing: Handles collisions by placeing the colliding item 
- Double Hasing: (k + j * d(k) ) mod n, for ... ; d2(k) = q - k mod q; q < N and q is prime  

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
```
###In Class Exercise

Insert keys  5, 29, 27, 11, 20 , 0 ; h(k) = k % n  

0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|---|---|---|---|---|---|---|---|---|---|----|----|----|
| 0 |   |   |   | 5 |   |   |   |   |   |    |    |    |

####Double Hashing:

## In Class Exercise

### Linear Probing

Given the hash function \( h(k) = k \mod n \), where the table size \( n = 13 \), we need to insert the following keys:

**Keys to Insert:** 5, 29, 27, 11, 20, 0

Let's visualize how the hash table will look after each insertion.

| Index | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |
|-------|----|----|----|----|----|----|----|----|----|----|----|----|----|
| Value |  0 |    |    |    |  5 |    |    |    |    |    |    |    |    |

#### Step-by-step Insertion:

1. **Insert 5:**  
   \( h(5) = 5 \mod 13 = 5 \)  
   Slot 5 is empty, so **5** is inserted at index 5.

2. **Insert 29:**  
   \( h(29) = 29 \mod 13 = 3 \)  
   Slot 3 is empty, so **29** is inserted at index 3.

3. **Insert 27:**  
   \( h(27) = 27 \mod 13 = 1 \)  
   Slot 1 is empty, so **27** is inserted at index 1.

4. **Insert 11:**  
   \( h(11) = 11 \mod 13 = 11 \)  
   Slot 11 is empty, so **11** is inserted at index 11.

5. **Insert 20:**  
   \( h(20) = 20 \mod 13 = 7 \)  
   Slot 7 is empty, so **20** is inserted at index 7.

6. **Insert 0:**  
   \( h(0) = 0 \mod 13 = 0 \)  
   Slot 0 is empty, so **0** is inserted at index 0.

The final hash table after inserting all keys:

| Index | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |
|-------|----|----|----|----|----|----|----|----|----|----|----|----|----|
| Value |  0 | 27 |    | 29 |    |  5 |    | 20 |    |    |    | 11 |    |

---

### Double Hashing

For **Double Hashing**, we are given:

- \( N = 13 \) (hash table size)
- \( h(k) = k \mod 13 \) (primary hash function)
- \( d(k) = 7 - (k \mod 7) \) (secondary hash function)

We need to insert the keys: 18, 41, 22, 44, 59, 32, 31, 73.

| Key  | \( h(k) \) | \( d(k) \) | \( j=0 \) | \( j=1 \) | \( j=2 \) | \( j=3 \) |
|------|------------|------------|-----------|-----------|-----------|-----------|
| 18   | 5          | 3          | 5         | 8         | 11        |           |
| 41   | 2          | 1          | 2         | 3         | 4         |           |
| 22   | 9          | 6          | 9         | 2         | 8         |           |
| 44   | 5          | 5          | 5         | 10        | 2         |           |
| 59   | 7          | 4          | 7         | 11        | 2         |           |
| 32   | 6          | 3          |           |           |           |           |
| 31   | 5          | 4          |           |           |           |           |
| 73   | (empty)    | 4          |           |           |           |           |

#### Step-by-step Insertion:

1. **Insert 18:**  
   \( h(18) = 18 \mod 13 = 5 \), \( d(18) = 7 - (18 \mod 7) = 3 \)  
   Slot 5 is empty, so **18** is inserted at index 5.

2. **Insert 41:**  
   \( h(41) = 41 \mod 13 = 2 \), \( d(41) = 7 - (41 \mod 7) = 1 \)  
   Slot 2 is empty, so **41** is inserted at index 2.

3. **Insert 22:**  
   \( h(22) = 22 \mod 13 = 9 \), \( d(22) = 7 - (22 \mod 7) = 6 \)  
   Slot 9 is empty, so **22** is inserted at index 9.

4. **Insert 44:**  
   \( h(44) = 44 \mod 13 = 5 \), \( d(44) = 7 - (44 \mod 7) = 5 \)  
   Slot 5 is occupied by **18**, so check the next slot using \( j=1 \):  
   \( 5 + 5 = 10 \) → Slot 10 is empty, so **44** is inserted at index 10.

5. **Insert 59:**  
   \( h(59) = 59 \mod 13 = 7 \), \( d(59) = 7 - (59 \mod 7) = 4 \)  
   Slot 7 is empty, so **59** is inserted at index 7.

6. **Insert 32:**  
   \( h(32) = 32 \mod 13 = 6 \), \( d(32) = 7 - (32 \mod 7) = 3 \)  
   Slot 6 is empty, so **32** is inserted at index 6.

7. **Insert 31:**  
   \( h(31) = 31 \mod 13 = 5 \), \( d(31) = 7 - (31 \mod 7) = 4 \)  
   Slot 5 is occupied by **18**, so check the next slot using \( j=1 \):  
   \( 5 + 4 = 9 \) → Slot 9 is occupied by **22**, so check the next slot using \( j=2 \):  
   \( 5 + 2 \times 4 = 13 \mod 13 = 0 \) → Slot 0 is empty, so **31** is inserted at index 0.

8. **Insert 73:**  
   \( h(73) = 73 \mod 13 = 8 \), \( d(73) = 7 - (73 \mod 7) = 3 \)  
   Slot 8 is empty, so **73** is inserted at index 8.

The final hash table after all insertions using Double Hashing:

| Index | 0  | 1  | 2  | 3  | 4  | 5  | 6  | 7  | 8  | 9  | 10 | 11 | 12 |
|-------|----|----|----|----|----|----|----|----|----|----|----|----|----|
| Value | 31 |    | 41 |    |    | 18 | 32 | 59 | 73 | 22 | 44 |    |    |

---

  
Is this hash function valid:  
```cpp
int hashFunction()
{
	return 17;
}
//Everyhting would go into the same bucket and cause collisions
```
  
Preformance of Hashing  
lambda = n/N
lambda = current number of tale entries/   
  
Capacity of 13 contains 9 values:  
lambda = n/N  
lambda = 9/ 13 = 0.7   
Is it ok? ___  
What would be the expected number of probes:  
1  (1 - lambda) = 1/0.3 = 3 probes

####Linear:
  
h(k) = k mod 13  
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
|---|---|---|---|---|---|---|---|---|---|----|----|----|
|   |   | 41  |   |   | 18  | 44  | 59  | 32  | 22  |  31  | 73   |    |


