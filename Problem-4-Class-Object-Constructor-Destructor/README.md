# Introduction

![image](https://user-images.githubusercontent.com/42372844/49738756-2559c180-fccb-11e8-8c1c-ebdd45f8f65b.png)

In this lab, we will implement a List, but this time with a dynamically allocated and "resizable" array (Note: It's not really resizable, but to create a new array of larger size, copy all the content of the old array over to the new array, and make the new array pointed by a data member (is called "data" in this lab) in class), instead of nodes and next pointers. We call this ArrayList in order to differentiate it from Linked List. This time, we will be using OOP concepts and class instead of struct for our implementation. 

This ArrayList behaves similarly to a standard raw array, except that we will be using C++ OOP class features such as constructors, destructor, data members, and member functions to add more functionality and versatility. 

The biggest feature of ArrayList compared to a regular array, is that ArrayList can support **insertion/deletion** at specified index like Linked List, will automatically shift the data so that there are no gaps in the array index, but still can be accessed via subscript[] operators just like a regular array. Furthermore, it can automatically plus efficiently **resize itself to become bigger/smaller after insertion/deletion**. 

**Dynamic Memory Management** can be automated by using constructors and destructor, to automatically call new and delete whenever an ArrayList is declared and goes out-of-scope. Data members will keep track of the internal state of ArrayList and will coordinate with member functions to deal with efficient resizing. The only missing feature would be index-checking, which we leave out as the complexity of such error-handling code is outside the scope of one lab. 

We will only be implementing an ArrayList of int for simplicity. Future lectures will teach Templating and Generic Programming, which would allow us to extend this code to implementing ArrayList that can store different data types, and even other user-defined structs and classes. 

As a side note, this ArrayList implementation is actually quite similar to the C++ Standard Template Library (STL) vector. More details about STL will be elaborated in class.

The following shows the details of the ArrayList class, which can be found in the skeleton code ArrayList.h. 

    class ArrayList {
    private:
      unsigned int arraySize;   // Current Capacity of the data array.
      unsigned int numElements; // Actual number of non-garbage elements in the data array.
      int* data;                // Dynamically allocated array. Set to nullptr if arraySize is 0.

      void resizeArray(unsigned int newSize);

    public:
      ArrayList(unsigned int arraySize = 0);            // Constructor
      ArrayList(const ArrayList& arrayList);            // Copy Constructor	
      ~ArrayList();                                     // Destructor

      // --- Out of the scope of this lab -------------	
      ArrayList& operator=(const ArrayList& arrayList); // Copy Assignment Operator	
      int& operator[](unsigned int index);              // Overloaded Subscript Operator
      const int& operator[](unsigned int index) const;  // Overloaded Subscript Operator
      // ----------------------------------------------		

      unsigned int getNumElements() const;
      unsigned int getArraySize() const;
      void insert(unsigned int index, int data);
      void remove(unsigned int index);
      void removeAll();
      void print() const;
      };

# Task

**IMPORTANT NOTE**: You are NOT allowed to define your own helper functions for this lab.

### Completed Functions

The ArrayList subscript[] operator and print() function have already been implemented. You may access the ArrayList elements just like a normal array, i.e. arrayList[index];. 
print() will simply print all the non-garbage elements in ArrayList (i.e., based on the number of elements (numElements) stored in the ArrayList). 

**IMPORTANT NOTE**: If arraySize > numElements, then the extra space will contain garbage data!!! The subscript[] operator has been implemented to cerr (cout but for error messages) an Error message if you access ArrayList[garbageIndex], where **numElements <= garbageIndex < arraySize**, but you will still access this garbage int data. However, it can't check against garbageIndex >= arraySize, in which case the program would likely crash during runtime.

## Task 1 - Constructor, Copy Constructor, Copy Assignment Operator, and Destructor

In ArrayList.cpp, these 4 functions deal with creating and deallocating ArrayList instances. 

Try to use **Member Initialization Lists** whenever possible, as these are faster and more efficient compared to initializing inside the constructor function body. 
ArrayList(unsigned int arraySize = 0) is both the default and conversion constructor. It is called whenever an ArrayList is declared in these ways: 

    ArrayList arrayList; ArrayList arrayList(10);. 

It creates a new ArrayList instance with the specified starting array size. You will need to initialize arraySize and numElements with the correct values, as well as allocate data with the correct dynamic array size. 

**ArrayList(const ArrayList& arrayList)** is the copy constructor. It creates a new ArrayList instance which is a copy of the other specified ArrayList instance. It is called whenever an ArrayList is declared in this ways: 

    ArrayList arrayList1(arrayList2);. 

Straightforwardly, arraySize and numElements will just copy the values from arrayList2. You have to do a **deep-copy** of the ArrayList data elements, by manually copying them one-by-one. Doing arrayList1.data = arrayList2.data will **only copy the array head pointer**, but not the data elements itself, so modifying arrayList1[index] will ALSO modify arrayList2[index]. 

**ArrayList& operator=(const ArrayList& arrayList)** is the Copy-Assignment Operator. It is called whenever we assign an ArrayList to another ArrayList: 

    arrayList1 = arrayList2; 

It re-assigns ArrayList to become a copy of the right-hand-side ArrayList. Differently from regular array assignment, in this case we will do a deep-copy of the data elements. The behavior is similar to the copy-constructor above.

**~ArrayList()** is the Destructor. It is called automatically whenever an ArrayList instance goes out-of-scope, like when reaching the end of a function body for a local variable. 

As we have dynamically allocated memory to the internal data array, we have to deallocate it to **avoid memory leak**. 

A destructor is convenient as it is called automatically whenever a class instance goes out-of-scope. This means that, if correctly implemented, we no longer need to manually keep track of each object's dynamic memory.

## Task 2 - Public accessors (getter functions)

Since arraySize and numElements are private, they cannot be accessed from outside the ArrayList class. Therefore, we need to provide public accessors (getter functions), getArraySize() and getNumElements() respectively, in order to read their values.

However, we return the data members by value so that these getter functions are read-only, in order to prevent unauthorized modification to these important internal state variables.


## Task 3 - Element Insertion and Removal

Similar to linked list, we provide functions insert(), remove(), and removeAll(), to respectively insert and remove elements from ArrayList to/from the specified index. 

However, there are a few important implementation details for an array-based implementation that are quite different from a linked-list-based implementation.

Every time we insert and/or remove a single element, we must make sure to shift the elements accordingly, and also ensure that there are no gaps in the ArrayList[] indexing. 

For example, if arrayList has 10 elements, and we call arrayList.insert(5, 100), then we must also make sure that the existing data elements at arrayList[5] to arrayList[9] are all shifted by 1 until arrayList[6] to arrayList[10] respectively.

Another important implementation detail is about resizing the internal data array. If it becomes full, then we will need to resize it into a larger size before we can insert another element. On the other hand, if it becomes too empty, we should resize it to be smaller, so that we don't waste dynamic memory. For these cases, we can call the private member function resizeArray(), the implementation details of which will be given in Task 4. 

An efficient algorithm for resizing the internal data array is as follows: 

    Before each insertion, if the data array is completely full, then we double (x2) the size.
    After each single element removal, if the data array is only quarter (1/4) full, then we halve (/2) the size.
    Before each single element removal, if the data array is already empty, then we deallocate the data array and set it to nullptr.
    After removeAll(), we also deallocate the data array and set it to nullptr.
    
This algorithm strikes a balance between time-efficiency and memory-efficiency, as we try to avoid resizing the data array too often, but also deallocate most of the unused memory.

## Task 4 - Array Resizing

This time, resizeArray() is a private member function, so that there is no unauthorized access, and we can more easily maintain internal state consistency and integrity of ArrayList, since the internal data array is the most important part of ArrayList. 

Unfortunately, as an array requires a contiguous block of memory, the most efficient way to resize is still quite intensive: 

    Allocate a new dynamic array.
    Deep-copy the data elements to this new dynamic array.
    De-allocate the old dynamic array.
    Set data to point to this new dynamic array.
    
There are also a few edge cases to handle: 

--> If newSize < numElements, then we will drop the excess elements at the end of the array, and reduce numElements accordingly.

--> If newSize == 0, then we also need to set data to nullptr.

## Bonus Task - Implement removeAll() with only 1 line of code

1 bonus point if you can successfully implement removeAll() with only 1 line of code. 

It has to be a single statement, meaning only a single semicolon, i.e. code_statement; so no cheating by just removing all the newlines. 

This single line of code **CAN** be a single function call. However, as stated at the beginning, you are also NOT allowed to define your own helper functions.
