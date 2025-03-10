# Queues
**First In, First Out (FIFO)**

## Time Complexity
- **O(1)**: Most queue operations such as enqueue and dequeue can be done in constant time.

## Types of Queues:
1. **Normal Queue (FIFO)**  
2. **Circular Queue (Normal Queue)**  
3. **Double-ended Queue (Deque)**  
4. **Priority Queue**

---

## Array-Based Queue
An array of size *N* is used to implement a queue.  
**Three Variables** are used to keep track of the front and rear of the queue:  
- `f`: The index of the front element  
- `r`: The index immediately past the rear element  
- `q`: The front of the queue  

### Queue Operations
1. `size()`: Returns the number of elements in the queue.
2. `isEmpty()`: Checks if the queue is empty.
3. `peek()`: Returns the element at the front of the queue without removing it.
4. `enqueue()`: Adds an element to the rear of the queue.
5. `dequeue()`: Removes the element at the front of the queue.

---

## In-Class Exercise:
```
template <typename ID>
class QueInterface {
 public:
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual T peek() const = 0;
        virtual void enqueue(const T&) = 0;
        virtual void dequeue() = 0;
};

template <typename T>
class ArrayQueue : public QueueInterface<T> {
private:
        T Q[MAX_QUEUE];
        int front;
        int rear;
        int count;
public:
        ArrayQueue() : front(0), rear(0), count(0) {}
        
        int size() const { return count; }
        
        bool isEmpty() const { return count == 0; }
        
        bool enqueue(const T& item) {
            // Implementation of enqueue operation
        }
        
        bool dequeue() {
            // Implementation of dequeue operation
        }
};
```
---

## Linked List Queue
Uses pointers `pFront`, `pRear`, and `pNew/pTemp` for managing the queue.

### Class Definition:
```
template <typename T>
class LinkedQueue : public QueueInterface<T> {
private:
        Node<T>* pFront;
        Node<T>* pRear;
        int count;
public:
        LinkedQueue() : pFront(nullptr), pRear(nullptr), count(0) {}
        LinkedQueue(const T& data) : pFront(new Node<T>(data)) {}  // Constructor overload
        ~LinkedQueue() { /* Destructor implementation */ }
        
        bool isEmpty() { return count == 0; }
        // Additional methods like enqueue and dequeue would go here.
};
```
---

## Array vs. Linked List
### Array-Based Queue
1. May waste space if the queue doesn't fill completely.
2. Operations are simple and fast, usually **O(1)**.
3. Fixed size based on array length.

### Linked List-Based Queue
1. Always uses just enough space.
2. More space per element (due to pointers).
3. Dynamic sizing, no wasted space.

---

## False Overflow Issue
### Circular Queue
In a **Circular Queue**, the rear pointer can wrap around and reuse space. This prevents wasted space in the array.
- The `front` index increases by one modulo the capacity after each dequeue operation:
  front = (front + 1) % capacity;
- Similarly, the `rear` index increases by modulo capacity.

---

### Round Robin Scheduler:
1. `e = Q.peek(); Q.dequeue()`  // Process the element at the front.
2. Repeat this process in a round-robin manner for all elements.

---

### Double Ended Queue (Deque)
**Deque** is another abstract data type that allows insertion and removal of elements from both ends (front and rear).

### DEQUE ADT Operations:
- `insertFront()`: Insert an element at the front of the deque.
- `insertBack()`: Insert an element at the back of the deque.
- `removeFront()`: Remove an element from the front.
- `removeBack()`: Remove an element from the back.
```
// DEQUE Interface (simplified)
template <typename T>
class DequeInterface {
    virtual void insertFront(const T&) = 0;
    virtual void insertBack(const T&) = 0;
    virtual void removeFront() = 0;
    virtual void removeBack() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
};
```
---

## STL Containers
There are two major STL container types:
1. **Sequence containers**:
   - `deque`: `#include <deque>`
   - `queue`: `#include <queue>`

Both of these containers are adaptive, meaning their structure changes according to the operations performed.

---

## Deque Implementation Choices:
- **Array-based Deque**: Elements are stored in a circular array.
- **Linked List-based Deque**: Each element is stored in a node with pointers to the next and previous nodes.

---

## Review of Modulus
**Modulus (%)**:
- `7 % 3 = 1` (Remainder when 7 is divided by 3)
- `3 % 7 = 3` (Remainder when 3 is divided by 7)
