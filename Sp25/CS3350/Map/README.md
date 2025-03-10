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
