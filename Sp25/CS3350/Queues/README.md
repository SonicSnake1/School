#Queues
**First in First out** 
##Time complexity
###O(1) 
##Types of queues:  
1. Normal queue (FIFO)  
2. Circular Queue (Normal Queue)  
3. Double-ended Queue (Deque)  
4. Priority Queue  

##Array-Based
Use and array of size *N*  
**Three Variables keep track of the front and the rear**  
*f* index of the front element  
*r* index imeditatley past the rear element  
*q* the front of the queue  

###Queue Operations  
1. size()  
2. isEmpty()  
3. peek()
4. enqueue
5.
##In-Class Exercise:  
```
template <typename ID>
class QueInterface {
 public:
	virtual int size() const = 0;
	virtual bool isEmpty() const =0;
	virtual T peek() const =0;
	virtual void enqueue (const &T) =0;
	virtual void dequeue () =0;
};
```

```
template <typename T>
class ArrayQueue : public QueueInterface<T> {
private:
	T Q[MAX_QUEUE];
	int front;
	int rear;
	int count;
public:
	ArrayQueue () : front (0), rear (0), count (0) {}
	int size() const{return count;}
	bool isEmpty() const {return count == 0;}
	bool enqueue (const &T) {}
	bool dequeue ()
```
##Linked List Queue
pFront, pRear and pNew/pTemp  
###Class Definition
```
template <typename T>
class LinkedQueue : public QueueInterface<T>{
private:
	Node<T>* pFront;
	Node<T>* pRear;
	int count;
public:
	LinkedQueue() : pFront(nullptr), pRear(nullptr), count(0) {}
	LinkedQueue (const T &data) : pFront(new Node<T>(data)) {} // overload const
	~LinkedQueue() {/* tod*/}
	bool isEmpty....
```
  
##Array Vs Linked
###Array
1. May waste space
2. Operations very simple/fast  
3. O(1)
###Linked List
1. Always just enough space
2. More space per element
3. ...

##False-Overflow issue
###Circular Queue
Circular Queue allows for the rear pointer to not run out of space.   
*f* increases by one modulo capacity after each dequeue():  
```
front = (front+1)% capacity
```
   *r* increases by modulo...
  
  

###Round robin Scheduler:
1. e = Q.peek(); Q.dequeue()
2. ...
  
###Double Ended Queue
**DEQUE**  
Another Abstract data type  
The deque ADT ...  
###DEQUE ADT
insert in front  
insert in back  
remove from front  
remove from back  
...
  
```
DEQUE INTERFACE
```
  
##STL Containers
There are two major STL container types:  
Sequence containers:  
deque #include <deque>  
queue #include <queue>  
  
Both are Adaptive Patterns
  
##Deque Impl. Choices:
Array: ...  
##Review of Modulus
**Modulus (%)**   
7 % 3 = 1
3 % 7 = 3

