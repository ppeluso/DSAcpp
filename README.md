# Data Structures and Algorithms 

## Linked List
* Each node is linked to the next node 
* Indexing is O(n) time, must walk from one node to the next
* Inserting at head or deleting at head is O(1) time but inserting at tail or deleting at tail can take O(n) time if you have to walk through list, will be O(1) to insert and O(n) to delete if pointer to tail

### Advantages
* Can grow dynamically 
* Can isert and delete quickly
* Can also insert or delete in middle if needed

### Disadvantages 
* Use more memory than array
* Nodes must be accessed sequentially 
* Must walk through linked list to index, where an array can index in constant time

## Doubly Linked List 
* Each node links to next and previous node 
* Indexing is O(n) time, must walk list
* Inserting and deleting at head is O(1), inserting and deleting at tail is O(1) if there is a pointer to tail and O(n) if not

### Advantages
* Can move foward and backwards through the list
* When deleting a node, we have pointer to both previous and next node, makes easier for deleting tail

### Disadvantages
* Uses more memeory than singly linked list 
* Must deal with two pointers for each node 

## Circularly Linked list
* Instead of last node pointing to NULL it points to the head 
### Advantages 
* Some data is circular so this will seem more natural 
* Easier to traverse from middle of list since the tail will point back to the head
* Fewer special cases
### Disadvantages 
* Could be difficult to add to head of list 
* Loop control can be more difficult

## Stacks
* Data is added (push) to  and removed (pop) from 'top' of the stack, other end is known as base
* Stack follows "First in Last off" FILO, this mean that the newest item put on stack is removed
* Can add and remove from stack in O(1)

## Queues
* Data is added (enqueue) to the end of the queue and removed (dequeue) from the front of the queue
* Queue follows "First in First off" FIFO, oldest item is removed from the queue first
* Enqueue and dequeue are both done in O(1)

