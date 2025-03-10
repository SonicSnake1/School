#Map
##Motivation & Example
###Search specific
Binary search
###Complexity  specific
Log(n)
###Search Broad
Linear search
##Sort and search keys
###Sort key
The data you use to search
###Search key
arrange data based on data of search key
##Map ADT
Value based container; like sorted list, binary search tree, priority queue and a heap  
Maps a key to a value, no duplicates allowed.  
The key value pair is called an entry  
##Dictionary ADT
The dictionary ADT is a searchable ADT  
Word-def pairs, credit card auth, DNS mapping (Domain -ip address)
###Dictionary ADT Methods:
Contains()  
add()  
remove()  
size()  
isEmpty()  
clear()  
getItem(k)  
###Entry
getKey  
getValue  
setKey  
setValue  
###insert new item
O(1)
###find and erase  worst case
O(n)
###search table
Implemented in a sorted array 
find: O(log n)
put: O(n)
erase: O(n)
##STL Associative containers
Sorted and unsorted map <key, value>
