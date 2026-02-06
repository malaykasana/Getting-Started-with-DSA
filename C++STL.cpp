/*
================================================================================
                    C++ STL (Standard Template Library) TUTORIAL
                        Comprehensive Guide for Beginners
================================================================================

This file contains detailed explanations and examples of all major STL containers
and data structures. Each function demonstrates a different container with:
- Clear comments explaining what each line does
- Time complexity analysis
- Use cases and best practices
- When to use each container

CONTENTS:
1. explainPair()          - Storing two values together
2. explainArray()         - Fixed-size array fundamentals
3. explainVector()        - Dynamic arrays (most commonly used)
4. explainList()          - Doubly linked list
5. explainDeque()         - Double-ended queue
6. explainStack()         - LIFO (Last In First Out)
7. explainQueue()         - FIFO (First In First Out)
8. explainPQ()            - Priority Queue (Heap)
9. explainSet()           - Unique elements, sorted
10. explainMultiSet()      - Allows duplicates, sorted
11. explainUnorderedSet() - Unique elements, fast, no order
12. explainMap()          - Key-value pairs, sorted by keys
13. explainMultiMap()     - Duplicate keys allowed, sorted
14. explainUnorderedMap() - Key-value pairs, fast, no order
15. explainExtra()        - Custom sorting and STL algorithms

QUICK DECISION GUIDE:
- Need fast random access? → vector
- Need fast insert/delete at both ends? → deque
- Need sorted unique elements? → set
- Need fast lookup (no order needed)? → unordered_set
- Need key-value pairs sorted by key? → map
- Need key-value pairs with fast lookup? → unordered_map
- Need LIFO (last in, first out)? → stack
- Need FIFO (first in, first out)? → queue
- Need always get min/max element? → priority_queue

HOW TO USE THIS FILE:
1. Read each function in order
2. Uncomment code examples to test them
3. Run the program to see output
4. Modify examples to understand better

To compile and run:
    g++ -std=c++17 c++stl.cpp -o c++stl && ./c++stl

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;

// ============================================================================
// PAIR: Used to store two values together as a single unit
// ============================================================================
void explainPair(){
    // Time Complexity: O(1) for all operations
    
    // Creating a simple pair with two integers
    pair<int, int> p = {1, 3};
    cout << "Simple pair: " << p.first << ' ' << p.second << endl;  // Output: 1 3
    // p.first = first element, p.second = second element
    
    // Creating a nested pair (pair inside a pair)
    pair<int, pair<int, int>> q = {1, {3, 4}};
    cout << "Nested pair: " << q.first << ' ' << q.second.first << ' ' << q.second.second << endl;  // Output: 1 3 4
    // q.first = 1, q.second is another pair containing {3, 4}
    
    // Array of pairs - useful for storing coordinates, key-value pairs, etc.
    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << "Second element of second pair: " << arr[1].second << endl;  // Output: 5
    // arr[1] = {2, 5}, so arr[1].second = 5
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// ARRAY: Fixed-size collection of elements (foundation for dynamic arrays)
// ============================================================================
void explainArray(){
    // Time Complexity: O(1) for access, insertion/deletion in middle requires shifting
    
    cout << "=== ARRAY (Fixed-size, static memory allocation) ===" << endl;
    
    // Creating an array
    int arr[5];  // Creates array of 5 integers (values are uninitialized/garbage)
    
    // Array initialization - important to do this to avoid garbage values
    int arr1[5] = {1, 2, 3, 4, 5};  // Explicitly initialize all elements
    cout << "Array initialized: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;
    
    // Partial initialization - remaining elements are set to 0
    int arr2[5] = {1, 2, 3};  // {1, 2, 3, 0, 0}
    cout << "Partial initialization: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << ' ';
    }
    cout << endl;
    
    // Array with all zeros
    int arr3[5] = {};  // All elements initialized to 0
    cout << "All zeros: ";
    for (int i = 0; i < 5; i++) {
        cout << arr3[i] << ' ';
    }
    cout << endl;
    
    // Accessing array elements
    cout << "First element (arr1[0]): " << arr1[0] << endl;   // Index 0
    cout << "Third element (arr1[2]): " << arr1[2] << endl;   // Index 2
    cout << "Last element (arr1[4]): " << arr1[4] << endl;    // Index 4
    
    // IMPORTANT: Array indexing starts from 0
    // For array of size 5, valid indices are 0, 1, 2, 3, 4
    // Accessing arr1[5] is OUT OF BOUNDS (undefined behavior!)
    
    // Getting array size
    int size = sizeof(arr1) / sizeof(arr1[0]);  // Size = 5
    cout << "Array size: " << size << endl;
    
    // IMPORTANT: This trick only works for static arrays declared on stack
    // Does NOT work for arrays passed as function parameters or allocated on heap
    
    // Modifying array elements
    arr1[0] = 100;  // Change first element to 100
    arr1[4] = 200;  // Change last element to 200
    cout << "After modifications: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;
    
    // Iterating through arrays
    cout << "--- Different ways to iterate ---" << endl;
    
    // Method 1: Using index (traditional way)
    cout << "Index loop: ";
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << ' ';
    }
    cout << endl;
    
    // Method 2: Using pointer arithmetic
    cout << "Pointer arithmetic: ";
    for (int* p = arr1; p < arr1 + 5; p++) {
        cout << *p << ' ';  // *p dereferences the pointer to get value
    }
    cout << endl;
    
    // Method 3: Range-based for loop (C++11 and later)
    cout << "Range-based loop: ";
    for (int x : arr1) {
        cout << x << ' ';
    }
    cout << endl;
    
    // Multidimensional arrays (2D array)
    cout << "\n--- 2D ARRAYS ---" << endl;
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    cout << "2D array (2 rows x 3 columns):" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    
    // Accessing 2D array elements
    cout << "Element at matrix[0][1]: " << matrix[0][1] << endl;  // 2
    cout << "Element at matrix[1][2]: " << matrix[1][2] << endl;  // 6
    
    // Using range-based loop with 2D arrays
    cout << "2D array with range loop: ";
    for (auto& row : matrix) {  // row is reference to each row
        for (int val : row) {
            cout << val << ' ';
        }
    }
    cout << endl;
    
    // Array of pairs (useful for storing coordinate data)
    pair<int, int> coords[3] = {{1, 2}, {3, 4}, {5, 6}};
    cout << "\nArray of pairs:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "{" << coords[i].first << ", " << coords[i].second << "} ";
    }
    cout << endl;
    
    // KEY PROPERTIES OF ARRAYS:
    cout << "\n--- KEY PROPERTIES ---" << endl;
    cout << "1. Fixed size: Cannot grow or shrink after creation" << endl;
    cout << "2. Contiguous memory: All elements stored consecutively" << endl;
    cout << "3. Fast random access: O(1) to access any element by index" << endl;
    cout << "4. Slow insertion/deletion: O(n) in middle due to shifting" << endl;
    cout << "5. Stack allocation: Array size must be known at compile time" << endl;
    cout << "6. Type homogeneous: All elements must be same type" << endl;
    
    // ARRAYS vs VECTORS:
    cout << "\n--- ARRAYS vs VECTORS ---" << endl;
    cout << "Arrays:  Fixed size, fast, simpler, limited flexibility" << endl;
    cout << "Vectors: Dynamic size, flexible, slightly slower, more features" << endl;
    cout << "Use ARRAY when: Size is known and fixed at compile time" << endl;
    cout << "Use VECTOR when: Size may change, or you need flexibility" << endl;
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// VECTOR: Dynamic array that can grow or shrink in size
// ============================================================================
void explainVector(){
    // Time Complexity: O(1) average for push_back/emplace_back, O(n) for erase/insert in middle, O(1) for pop_back
    
    cout << "=== VECTOR BASICS ===" << endl;
    
    // Creating an empty vector
    vector<int> v;
    
    // Adding elements to the end
    v.push_back(1);      // Adds 1 to the end: {1}
    v.emplace_back(2);   // Adds 2 to the end: {1, 2} (slightly more efficient than push_back)
    v.push_back(10);     // {1, 2, 10}
    v.push_back(20);     // {1, 2, 10, 20}
    
    // Different ways to create vectors
    // vector<int> v0(5, 100);    // Creates a vector with 5 elements, all initialized to 100: {100, 100, 100, 100, 100}
    // vector<int> v01(5);        // Creates a vector with 5 elements, all initialized to 0: {0, 0, 0, 0, 0}
    // vector<int> vtemp1(5, 20); // Creates a vector with 5 elements, all initialized to 20: {20, 20, 20, 20, 20}
    // vector<int> vtemp2(vtemp1);// Copy constructor - creates a copy of vtemp1
    
    // Vector of pairs - useful for storing coordinates or key-value pairs
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});     // Add pair using braces
    vec.emplace_back(3, 4);    // Add pair directly without braces (more efficient)
    
    cout << "Vector contents: ";
    
    // Method 1: Using iterator (traditional way)
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *(it) << ' ';  // *it dereferences the iterator to get the value
    }
    cout << endl;
    
    // Method 2: Using auto keyword (cleaner, compiler deduces the type)
    cout << "Using auto: ";
    for (auto it = v.begin(); it != v.end(); it++){
        cout << *(it) << ' ';
    }
    cout << endl;
    
    // Method 3: Range-based for loop (simplest and most readable)
    cout << "Range-based: ";
    for (auto element : v){
        cout << element << ' ';
    }
    cout << endl;
    
    // Accessing elements
    cout << "First element (v[0]): " << v[0] << endl;          // Using [] operator
    cout << "First element (v.at(0)): " << v.at(0) << endl;    // Using at() - safer, throws exception if out of bounds
    cout << "Last element (v.back()): " << v.back() << endl;   // Get last element
    cout << "First element (v.front()): " << v.front() << endl; // Get first element
    
    // IMPORTANT: Iterator positions
    // v.begin()  - points to the first element
    // v.end()    - points AFTER the last element (not to the last element!)
    // v.rbegin() - reverse begin, points to the last element
    // v.rend()   - reverse end, points before the first element
    
    // Using iterators to access specific positions
    auto it = v.begin();
    cout << "Element at begin: " << *it << endl;
    it++;  // Move to next element
    cout << "Element at begin+1: " << *it << endl;
    it = it + 2;  // Jump 2 positions forward
    cout << "Element at begin+3: " << *it << endl;
    
    // Accessing from end (remember: end() points AFTER the last element)
    auto it_end = v.end();
    cout << "Last element: " << *(it_end - 1) << endl;  // Go back 1 position from end
    
    // Reverse iterators - traverse vector backwards
    cout << "Reverse iteration: ";
    for (auto it = v.rbegin(); it != v.rend(); it++){
        cout << *it << ' ';
    }
    cout << endl;
    
    // Erasing elements
    vector<int> v3 = {10, 20, 12, 23};
    cout << "Before erase: ";
    for (auto x : v3) cout << x << ' ';
    cout << endl;
    
    v3.erase(v3.begin() + 1);  // Removes element at index 1 (20): {10, 12, 23}
    cout << "After erasing index 1: ";
    for (auto x : v3) cout << x << ' ';
    cout << endl;
    
    // Erase range [start, end) - note: 'end' is not included
    vector<int> v4 = {10, 20, 12, 23, 35};
    v4.erase(v4.begin() + 2, v4.begin() + 4);  // Removes elements at index 2 and 3: {10, 20, 35}
    cout << "After erasing range [2,4): ";
    for (auto x : v4) cout << x << ' ';
    cout << endl;
    
    // Insert function - adds elements at specific positions
    vector<int> vins(2, 100);  // {100, 100}
    vins.reserve(10);  // Add this line before the inserts to not show the fking error
    vins.insert(vins.begin(), 300);  // Insert 300 at the beginning: {300, 100, 100}
    cout << "After inserting 300 at begin: ";
    for (auto x : vins) cout << x << ' ';
    cout << endl;
    
    vins.insert(vins.begin() + 1, 2, 10);  // Insert two 10's at position 1: {300, 10, 10, 100, 100}
    cout << "After inserting two 10s at position 1: ";
    for (auto x : vins) cout << x << ' ';
    cout << endl;
    
    // Insert range from another vector
    vector<int> copy = {50, 50};
    vins.insert(vins.begin(), copy.begin(), copy.end());  // Insert all elements of 'copy' at beginning
    cout << "After inserting copy vector: ";
    for (auto x : vins) cout << x << ' ';
    cout << endl;
    
    // Utility functions
    cout << "Size of vector: " << vins.size() << endl;  // Returns number of elements
    
    vins.pop_back();  // Removes the last element
    cout << "After pop_back: ";
    for (auto x : vins) cout << x << ' ';
    cout << endl;
    
    // Swap two vectors
    vector<int> vec1 = {10, 20};
    vector<int> vec2 = {30, 40};
    cout << "Before swap - vec1: ";
    for (auto x : vec1) cout << x << ' ';
    cout << ", vec2: ";
    for (auto x : vec2) cout << x << ' ';
    cout << endl;
    
    vec1.swap(vec2);  // Swap contents of vec1 and vec2
    cout << "After swap - vec1: ";
    for (auto x : vec1) cout << x << ' ';
    cout << ", vec2: ";
    for (auto x : vec2) cout << x << ' ';
    cout << endl;
    
    vins.clear();  // Removes all elements, size becomes 0
    cout << "Is vector empty after clear? " << (vins.empty() ? "Yes" : "No") << endl;  // Returns true if empty
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// LIST: Doubly linked list - allows fast insertion/deletion at both ends
// ============================================================================
void explainList(){
    // Time Complexity: O(1) for push_back, push_front, pop_back, pop_front; O(n) for access by index
    
    cout << "=== LIST (Doubly Linked List) ===" << endl;
    
    list<int> ls;
    
    // Adding elements
    ls.push_back(2);      // Add at end: {2}
    ls.emplace_back(4);   // Add at end (more efficient): {2, 4}
    
    ls.push_front(5);     // Add at beginning: {5, 2, 4}
    ls.emplace_front(8);  // Add at beginning: {8, 5, 2, 4}
    
    cout << "List contents: ";
    for (auto x : ls) cout << x << ' ';
    cout << endl;
    
    // Key Difference from Vector:
    // - List allows O(1) insertion/deletion at both front and back
    // - Vector only allows O(1) at back, O(n) at front
    // - List doesn't support random access (can't do ls[i])
    // - List uses more memory (stores prev/next pointers)
    
    // Common functions (same as vector):
    // begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap(), empty()
    
    cout << "Size: " << ls.size() << endl;
    ls.pop_front();  // Remove first element: {5, 2, 4}
    ls.pop_back();   // Remove last element: {5, 2}
    cout << "After pops: ";
    for (auto x : ls) cout << x << ' ';
    cout << endl;
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// DEQUE: Double-ended queue - combines benefits of vector and list
// ============================================================================
void explainDeque(){
    // Time Complexity: O(1) for push_back, push_front, pop_back, pop_front, random access; O(n) for erase/insert in middle
    
    cout << "=== DEQUE (Double-Ended Queue) ===" << endl;
    
    deque<int> dq;
    
    // Adding elements
    dq.push_back(1);      // Add at end: {1}
    dq.emplace_back(2);   // Add at end: {1, 2}
    
    dq.push_front(4);     // Add at beginning: {4, 1, 2}
    dq.emplace_front(3);  // Add at beginning: {3, 4, 1, 2}
    
    cout << "Deque contents: ";
    for (auto x : dq) cout << x << ' ';
    cout << endl;
    
    // Removing elements
    dq.pop_back();   // Remove from end: {3, 4, 1}
    dq.pop_front();  // Remove from front: {4, 1}
    
    cout << "After pops: ";
    for (auto x : dq) cout << x << ' ';
    cout << endl;
    
    // Accessing elements
    cout << "Back element: " << dq.back() << endl;   // Get last element
    cout << "Front element: " << dq.front() << endl; // Get first element
    cout << "Element at index 1: " << dq[1] << endl; // Random access like vector
    
    // Note: back() and front() return references that can be modified
    // dq.back() = 10;  // This would modify the last element
    
    // Key Features:
    // - Fast insertion/deletion at BOTH ends (unlike vector which is slow at front)
    // - Supports random access like vector (can use dq[i])
    // - Slightly more overhead than vector due to its internal structure
    
    // Common functions same as vector:
    // begin(), end(), rbegin(), rend(), clear(), insert(), size(), swap(), empty()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// STACK: LIFO (Last In First Out) data structure
// ============================================================================
void explainStack(){
    // Time Complexity: O(1) for push, pop, top, size, empty
    
    cout << "=== STACK (LIFO - Last In First Out) ===" << endl;
    
    stack<int> st;
    
    // Adding elements - all go on top
    st.push(1);       // Stack: [1]
    st.push(2);       // Stack: [1, 2]
    st.push(3);       // Stack: [1, 2, 3]
    st.push(4);       // Stack: [1, 2, 3, 4]
    st.emplace(5);    // Stack: [1, 2, 3, 4, 5] - top is 5
    
    // Think of stack like a stack of plates: you can only add/remove from the top
    
    cout << "Top element: " << st.top() << endl;  // Prints 5 (last added element)
    
    st.pop();  // Removes top element (5): [1, 2, 3, 4]
    cout << "Top after pop: " << st.top() << endl;  // Prints 4
    
    cout << "Size: " << st.size() << endl;  // Prints 4
    cout << "Is empty? " << (st.empty() ? "Yes" : "No") << endl;  // Prints No (0 = false)
    
    // Swapping two stacks
    stack<int> st1, st2;
    st1.push(10);
    st2.push(20);
    st1.swap(st2);  // Now st1 has 20, st2 has 10
    
    // IMPORTANT: Stack doesn't support:
    // - Iterators (can't loop through elements)
    // - Random access (can't access middle elements)
    // - Only top() is accessible
    
    // Use cases: Function call stack, undo operations, expression evaluation, backtracking
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// QUEUE: FIFO (First In First Out) data structure
// ============================================================================
void explainQueue(){
    // Time Complexity: O(1) for push, pop, front, back, size, empty
    
    cout << "=== QUEUE (FIFO - First In First Out) ===" << endl;
    
    queue<int> q;
    
    // Adding elements - all added at back
    q.push(1);       // Queue: [1]
    q.push(2);       // Queue: [1, 2]
    q.emplace(3);    // Queue: [1, 2, 3]
    
    // Think of queue like a line at a store: first person in line is first to be served
    
    cout << "Front element: " << q.front() << endl;  // Prints 1 (first added)
    cout << "Back element: " << q.back() << endl;    // Prints 3 (last added)
    
    q.back() += 5;  // Modify the last element: 3 + 5 = 8
    cout << "Back after modification: " << q.back() << endl;  // Prints 8
    
    // Removing elements - always from front
    q.pop();  // Remove first element (1): [2, 8]
    cout << "Front after pop: " << q.front() << endl;  // Prints 2
    
    cout << "Size: " << q.size() << endl;
    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;
    
    // IMPORTANT: Queue doesn't support:
    // - Iterators (can't loop through elements)
    // - Random access (can't access middle elements)
    // - Only front() and back() are accessible
    
    // Use cases: BFS traversal, task scheduling, buffering, order processing
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// PRIORITY QUEUE: Elements are served based on priority (highest first)
// ============================================================================
void explainPQ(){
    // Time Complexity: O(log n) for push, pop; O(1) for top; O(n) for construction
    
    cout << "=== PRIORITY QUEUE (Max Heap by default) ===" << endl;
    
    // MAX HEAP (default): Largest element has highest priority
    priority_queue<int> pq;
    
    pq.push(5);       
    pq.push(2);       
    pq.push(8);       
    pq.emplace(10);   
    
    // Elements are automatically sorted internally: largest element stays on top
    // Internal structure: {10, 8, 5, 2} (not exactly, it's a heap structure)
    
    cout << "Top element (largest): " << pq.top() << endl;  // Prints 10
    
    pq.pop();  // Removes 10 (the largest element)
    cout << "Top after pop: " << pq.top() << endl;  // Prints 8
    
    cout << "Size: " << pq.size() << endl;
    
    // Common functions: size(), swap(), empty()
    
    cout << endl << "=== MIN HEAP (Smallest element has highest priority) ===" << endl;
    
    // MIN HEAP: Smallest element has highest priority
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    minPQ.push(5);
    minPQ.push(2);
    minPQ.push(8);
    minPQ.emplace(10);
    
    // Internal structure: smallest on top: {2, 5, 8, 10}
    
    cout << "Top element (smallest): " << minPQ.top() << endl;  // Prints 2
    
    minPQ.pop();  // Removes 2 (the smallest)
    cout << "Top after pop: " << minPQ.top() << endl;  // Prints 5
    
    // How it works:
    // - Max heap: parent >= children (root is maximum)
    // - Min heap: parent <= children (root is minimum)
    // - Not sorted completely, only maintains heap property
    
    // Use cases: 
    // - Dijkstra's algorithm
    // - Finding kth largest/smallest element
    // - Merge K sorted arrays
    // - Task scheduling by priority
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// SET: Stores UNIQUE elements in SORTED order
// ============================================================================
void explainSet(){
    // Time Complexity: O(log n) for insert, erase, find, count, lower_bound, upper_bound
    
    cout << "=== SET (Unique elements in sorted order) ===" << endl;
    
    set<int> st;
    
    // Adding elements
    st.insert(1);     // {1}
    st.emplace(2);    // {1, 2} - emplace is slightly more efficient
    st.insert(2);     // {1, 2} - duplicate 2 is NOT added (set stores unique elements only)
    st.insert(4);     // {1, 2, 4}
    st.insert(3);     // {1, 2, 3, 4} - automatically sorted!
    st.insert(5);     // {1, 2, 3, 4, 5}
    
    cout << "Set contents (automatically sorted): ";
    for (auto x : st) cout << x << ' ';
    cout << endl;
    
    // Key Properties:
    // 1. Stores only UNIQUE elements (no duplicates)
    // 2. Elements are automatically SORTED
    // 3. Implemented using Red-Black Tree (balanced BST)
    // 4. All operations are O(log n)
    
    // Common functions (same as others): begin(), end(), rbegin(), rend(), size(), swap(), empty()
    
    // Finding elements
    auto itf = st.find(3);  // Returns iterator to element 3
    if (itf != st.end()) {
        cout << "Found element: " << *itf << endl;
    }
    
    auto itf2 = st.find(6);  // Returns st.end() since 6 is not present
    if (itf2 == st.end()) {
        cout << "Element 6 not found" << endl;
    }
    
    // Erasing elements
    st.erase(5);  // Removes element 5: {1, 2, 3, 4}
    cout << "After erasing 5: ";
    for (auto x : st) cout << x << ' ';
    cout << endl;
    
    // Count - returns 1 if present, 0 if not (since set has unique elements)
    size_t cnt = st.count(1);  
    cout << "Count of 1: " << cnt << endl;  // Prints 1
    cnt = st.count(10);
    cout << "Count of 10: " << cnt << endl;  // Prints 0
    
    // Erase using iterator
    auto it3 = st.find(3);
    if (it3 != st.end()) {
        st.erase(it3);  // Removes element 3: {1, 2, 4}
    }
    
    // Erase range [start, end)
    set<int> st2 = {1, 2, 3, 4, 5};
    auto it_start = st2.find(2);
    auto it_end = st2.find(4);
    st2.erase(it_start, it_end);  // Removes 2 and 3 (4 is not included): {1, 4, 5}
    cout << "After range erase: ";
    for (auto x : st2) cout << x << ' ';
    cout << endl;
    
    // Lower bound and Upper bound - VERY IMPORTANT for competitive programming
    set<int> st3 = {1, 3, 5, 7, 9};
    
    // lower_bound(x): returns iterator to first element >= x
    auto lb = st3.lower_bound(5);  // Returns iterator to 5
    cout << "Lower bound of 5: " << *lb << endl;
    
    lb = st3.lower_bound(4);  // Returns iterator to 5 (first element >= 4)
    cout << "Lower bound of 4: " << *lb << endl;
    
    // upper_bound(x): returns iterator to first element > x
    auto ub = st3.upper_bound(5);  // Returns iterator to 7 (first element > 5)
    cout << "Upper bound of 5: " << *ub << endl;
    
    ub = st3.upper_bound(4);  // Returns iterator to 5 (first element > 4)
    cout << "Upper bound of 4: " << *ub << endl;
    
    // Use cases:
    // - Remove duplicates from data
    // - Maintain sorted unique elements
    // - Fast lookup, insertion, deletion
    // - Range queries using bounds
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// MULTISET: Like SET but allows DUPLICATE elements
// ============================================================================
void explainMultiSet(){
    // Time Complexity: O(log n) for insert, erase, find, count, lower_bound, upper_bound
    
    cout << "=== MULTISET (Sorted with duplicates allowed) ===" << endl;
    
    multiset<int> ms;
    
    // Adding elements (duplicates are allowed)
    ms.insert(1);     // {1}
    ms.emplace(2);    // {1, 2}
    ms.insert(2);     // {1, 2, 2} - duplicate 2 IS added
    ms.insert(1);     // {1, 1, 2, 2}
    ms.insert(1);     // {1, 1, 1, 2, 2}
    ms.insert(3);     // {1, 1, 1, 2, 2, 3}
    
    cout << "Multiset contents: ";
    for (auto x : ms) cout << x << ' ';
    cout << endl;
    
    // Key Difference from SET:
    // - Set: stores UNIQUE elements only
    // - Multiset: allows DUPLICATE elements
    // - Both maintain sorted order
    
    // Count - returns the number of occurrences
    size_t cnt = ms.count(1);
    cout << "Count of 1: " << cnt << " occurrences" << endl;  // Prints 3
    
    // IMPORTANT: Erase behavior difference
    
    // 1. Erase by value - removes ALL occurrences
    multiset<int> ms1 = {1, 1, 1, 2, 2, 3};
    ms1.erase(1);  // Removes ALL 1's: {2, 2, 3}
    cout << "After erasing all 1's: ";
    for (auto x : ms1) cout << x << ' ';
    cout << endl;
    
    // 2. Erase by iterator - removes only ONE occurrence
    multiset<int> ms2 = {1, 1, 1, 2, 2, 3};
    auto it = ms2.find(1);  // Find first occurrence of 1
    if (it != ms2.end()) {
        ms2.erase(it);  // Removes only one 1: {1, 1, 2, 2, 3}
    }
    cout << "After erasing one 1: ";
    for (auto x : ms2) cout << x << ' ';
    cout << endl;
    
    // 3. Erase range - removes multiple occurrences within range
    multiset<int> ms3 = {1, 1, 1, 2, 2, 3};
    
    // To remove exactly 2 occurrences of 1:
    // IMPORTANT: Multiset iterators are bidirectional, NOT random-access
    // So we CANNOT use iterator + 2 directly
    
    auto first = ms3.find(1);  // Iterator to first 1
    if (first != ms3.end()) {
        auto last = first;
        // Advance iterator by 2 positions safely
        int count = 0;
        while (last != ms3.end() && count < 2) {
            ++last;
            count++;
        }
        ms3.erase(first, last);  // Removes first 2 elements: {1, 2, 2, 3}
    }
    
    cout << "After erasing two 1's: ";
    for (auto x : ms3) cout << x << ' ';
    cout << endl;
    
    // Alternative: Using std::next (cleaner way)
    multiset<int> ms4 = {1, 1, 1, 2, 2, 3};
    auto start = ms4.find(1);
    if (start != ms4.end()) {
        // Ensure we don't go past end
        auto end = start;
        for (int i = 0; i < 2 && end != ms4.end(); i++) {
            ++end;
        }
        ms4.erase(start, end);
    }
    cout << "Alternative method: ";
    for (auto x : ms4) cout << x << ' ';
    cout << endl;
    
    // Lower bound and upper bound - same as set
    multiset<int> ms5 = {1, 1, 1, 3, 3, 5};
    auto lb = ms5.lower_bound(1);  // Points to first 1
    auto ub = ms5.upper_bound(1);  // Points to first element > 1 (which is 3)
    
    cout << "Elements between lower_bound(1) and upper_bound(1): ";
    for (auto it = lb; it != ub; it++) {
        cout << *it << ' ';  // Prints all 1's
    }
    cout << endl;
    
    // Use cases:
    // - When you need sorted data with duplicates
    // - Frequency counting with sorted order
    // - Sliding window problems with sorted elements
    
    // All other functions same as set: begin(), end(), rbegin(), rend(), size(), swap(), empty()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// UNORDERED_SET: Stores UNIQUE elements in NO particular order (uses hashing)
// ============================================================================
void explainUnorderedSet(){
    // Time Complexity: O(1) average for insert, erase, find, count; O(n) worst case (rare collisions)
    
    cout << "=== UNORDERED_SET (Unique elements, no order, fast operations) ===" << endl;
    
    unordered_set<int> st;
    
    // Adding elements
    st.insert(1);     // {1}
    st.emplace(2);    // {1, 2} or {2, 1} - order not guaranteed
    st.insert(2);     // Still {1, 2} - duplicates not allowed
    st.insert(4);     // {1, 2, 4} (any order)
    st.insert(3);     // {1, 2, 3, 4} (any order)
    st.insert(5);     // {1, 2, 3, 4, 5} (any order)
    
    cout << "Unordered_set contents (random order): ";
    for (auto x : st) cout << x << ' ';
    cout << endl;
    
    // Key Differences from SET:
    // 1. Set: sorted order, O(log n) operations
    // 2. Unordered_set: no order, O(1) average operations (faster!)
    
    // IMPORTANT: lower_bound() and upper_bound() do NOT exist in unordered_set
    // (because elements are not sorted)
    
    // Finding elements - O(1) average
    auto it1 = st.find(3);
    if (it1 != st.end()) {
        cout << "Found element: " << *it1 << endl;
    }
    
    auto it2 = st.find(6);
    if (it2 == st.end()) {
        cout << "Element 6 not found" << endl;
    }
    
    // Erasing - O(1) average
    st.erase(5);
    cout << "After erasing 5: ";
    for (auto x : st) cout << x << ' ';
    cout << endl;
    
    // Count - returns 1 if present, 0 otherwise
    size_t cnt_uset = st.count(1);
    cout << "Count of 1: " << cnt_uset << endl;
    
    // How it works:
    // - Uses hash table internally
    // - Hash function converts element to index
    // - Average O(1) operations, but worst case O(n) if many collisions
    // - In practice, almost always O(1)
    
    // When to use:
    // - Use UNORDERED_SET when you only need fast lookup and don't care about order
    // - Use SET when you need sorted order or range queries (lower_bound/upper_bound)
    
    // Common functions: begin(), end(), size(), swap(), empty(), insert(), erase(), find(), count()
    // NOT available: lower_bound(), upper_bound(), rbegin(), rend()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// MAP: Stores key-value pairs with UNIQUE keys in SORTED order
// ============================================================================
void explainMap(){
    // Time Complexity: O(log n) for insert, erase, find, count, lower_bound, upper_bound
    
    cout << "=== MAP (Key-Value pairs, unique keys, sorted by keys) ===" << endl;
    
    // Map stores data as {key: value} pairs
    map<int, int> mp;
    
    // Different ways to store complex data
    map<int, pair<int, int>> mp1;  // Key -> pair of values
    map<pair<int, int>, int> mp2;  // Pair as key -> value
    
    // Adding elements (different methods)
    mp[1] = 2;           // {1: 2}
    mp.emplace(3, 4);    // {1: 2, 3: 4}
    mp.insert({2, 4});   // {1: 2, 2: 4, 3: 4} - automatically sorted by keys!
    
    // Updating value for existing key
    mp[1] = 3;           // {1: 3, 2: 4, 3: 4} - value updated from 2 to 3
    
    cout << "Map contents (sorted by keys):" << endl;
    for (auto it : mp){
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }
    
    // Accessing elements
    cout << "Value at key 1: " << mp[1] << endl;  // Prints 3
    
    // IMPORTANT: Be careful with []
    cout << "Value at key 5 (not present): " << mp[5] << endl;  // Inserts {5: 0} and prints 0
    cout << "Map size after accessing non-existent key: " << mp.size() << endl;  // Size increased!
    
    // Safe access using at() - throws exception if key doesn't exist
    try {
        cout << mp.at(10) << endl;  // Will throw an exception
    } catch (...) {
        cout << "Key 10 doesn't exist - at() is safer!" << endl;
    }
    
    // Finding elements
    auto it1 = mp.find(3);
    if (it1 != mp.end()) {
        cout << "Found key 3 with value: " << it1->second << endl;
    }
    
    auto it2 = mp.find(6);
    if (it2 == mp.end()) {
        cout << "Key 6 not found" << endl;
    }
    
    // Erasing elements
    mp.erase(3);  // Removes key 3
    cout << "After erasing key 3: ";
    for (auto it : mp) cout << "{" << it.first << ": " << it.second << "} ";
    cout << endl;
    
    // Count - returns 1 if key exists, 0 otherwise
    size_t cnt_map = mp.count(1);
    cout << "Key 1 exists? " << (cnt_map ? "Yes" : "No") << endl;
    
    // Lower bound and upper bound (operates on KEYS, not values)
    map<int, int> mp3 = {{1, 10}, {3, 30}, {5, 50}, {7, 70}};
    
    auto lb = mp3.lower_bound(3);  // Iterator to key >= 3 (points to {3, 30})
    cout << "Lower bound of key 3: {" << lb->first << ": " << lb->second << "}" << endl;
    
    auto ub = mp3.upper_bound(3);  // Iterator to key > 3 (points to {5, 50})
    cout << "Upper bound of key 3: {" << ub->first << ": " << ub->second << "}" << endl;
    
    // Key Properties:
    // 1. Keys are UNIQUE (each key appears only once)
    // 2. Keys are SORTED in ascending order
    // 3. Fast lookup, insertion, deletion: O(log n)
    // 4. Implemented using Red-Black Tree
    
    // Use cases:
    // - Dictionary (word -> meaning)
    // - Frequency map (element -> count)
    // - Graph adjacency list (node -> neighbors)
    // - Caching, memoization
    
    // Common functions: begin(), end(), rbegin(), rend(), size(), swap(), empty()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// MULTIMAP: Like MAP but allows DUPLICATE keys
// ============================================================================
void explainMultiMap(){
    // Time Complexity: O(log n) for insert, erase, find, count, lower_bound, upper_bound
    
    cout << "=== MULTIMAP (Duplicate keys allowed, sorted by keys) ===" << endl;
    
    multimap<int, int> mp;
    
    // Adding elements (duplicate keys are allowed)
    mp.insert({1, 2});    // {1: 2}
    mp.emplace(3, 4);     // {1: 2, 3: 4}
    mp.insert({1, 4});    // {1: 2, 1: 4, 3: 4} - duplicate key 1 allowed!
    mp.insert({1, 6});    // {1: 2, 1: 4, 1: 6, 3: 4}
    
    // IMPORTANT: mp[key] = value syntax does NOT work in multimap
    // Because [] operator requires unique keys
    
    cout << "Multimap contents:" << endl;
    for (auto it : mp){
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }
    
    // Key Differences from MAP:
    // 1. Map: unique keys only, can use mp[key]
    // 2. Multimap: duplicate keys allowed, CANNOT use mp[key]
    
    // Finding elements - returns iterator to first occurrence
    auto it1 = mp.find(1);
    if (it1 != mp.end()) {
        cout << "Found key 1 with value: " << it1->second << endl;
    }
    
    auto it2 = mp.find(6);
    if (it2 == mp.end()) {
        cout << "Key 6 not found" << endl;
    }
    
    // Count - returns NUMBER of occurrences
    size_t cnt_mmap = mp.count(1);
    cout << "Number of times key 1 appears: " << cnt_mmap << endl;  // Prints 3
    
    // IMPORTANT: Erase by value removes ALL occurrences
    multimap<int, int> mp2 = {{1, 2}, {1, 4}, {1, 6}, {3, 4}};
    mp2.erase(1);  // Removes ALL key-value pairs with key 1: {3: 4}
    cout << "After erasing all key 1's: ";
    for (auto it : mp2) cout << "{" << it.first << ": " << it.second << "} ";
    cout << endl;
    
    // To remove only one occurrence, use iterator
    multimap<int, int> mp3 = {{1, 2}, {1, 4}, {1, 6}, {3, 4}};
    auto to_erase = mp3.find(1);
    if (to_erase != mp3.end()) {
        mp3.erase(to_erase);  // Removes only first occurrence: {1: 4, 1: 6, 3: 4}
    }
    cout << "After erasing one key 1: ";
    for (auto it : mp3) cout << "{" << it.first << ": " << it.second << "} ";
    cout << endl;
    
    // Lower bound and upper bound - works on keys
    multimap<int, int> mp4 = {{1, 10}, {1, 20}, {3, 30}, {5, 50}};
    
    auto lb = mp4.lower_bound(1);  // Points to first pair with key >= 1
    auto ub = mp4.upper_bound(1);  // Points to first pair with key > 1
    
    cout << "All values for key 1: ";
    for (auto it = lb; it != ub; it++) {
        cout << it->second << ' ';  // Prints all values associated with key 1
    }
    cout << endl;
    
    // Use cases:
    // - When same key needs multiple values
    // - Student ID -> multiple course grades
    // - Graph with multiple edges between same nodes
    // - Event timestamp -> multiple events at same time
    
    // Common functions: begin(), end(), rbegin(), rend(), size(), swap(), empty()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// UNORDERED_MAP: Like MAP but NO order, uses hashing (faster!)
// ============================================================================
void explainUnorderedMap(){
    // Time Complexity: O(1) average for insert, erase, find, count; O(n) worst case (rare)
    
    cout << "=== UNORDERED_MAP (Key-Value pairs, no order, fast operations) ===" << endl;
    
    unordered_map<int, int> mp;
    
    // Adding elements
    mp[1] = 2;           // {1: 2}
    mp.emplace(3, 4);    // {1: 2, 3: 4} or {3: 4, 1: 2} - order not guaranteed
    mp.insert({2, 4});   // {1: 2, 2: 4, 3: 4} (any order)
    mp[1] = 3;           // {1: 3, 2: 4, 3: 4} - value updated
    
    cout << "Unordered_map contents (random order):" << endl;
    for (auto it : mp){
        cout << "Key: " << it.first << ", Value: " << it.second << endl;
    }
    
    // Key Differences from MAP:
    // 1. Map: sorted by keys, O(log n) operations
    // 2. Unordered_map: no order, O(1) average operations (much faster!)
    
    // Accessing elements
    cout << "Value at key 1: " << mp[1] << endl;
    
    // IMPORTANT: Same warning as map
    cout << "Value at key 5 (not present): " << mp[5] << endl;  // Creates {5: 0}
    
    // Safe access using at()
    try {
        cout << mp.at(10) << endl;
    } catch (...) {
        cout << "Key 10 doesn't exist - at() is safer!" << endl;
    }
    
    // Finding elements - O(1) average
    auto it1 = mp.find(3);
    if (it1 != mp.end()) {
        cout << "Found key 3 with value: " << it1->second << endl;
    }
    
    auto it2 = mp.find(6);
    if (it2 == mp.end()) {
        cout << "Key 6 not found" << endl;
    }
    
    // Erasing - O(1) average
    mp.erase(3);
    cout << "After erasing key 3: ";
    for (auto it : mp) cout << "{" << it.first << ": " << it.second << "} ";
    cout << endl;
    
    // Count
    size_t cnt_umap = mp.count(1);
    cout << "Key 1 exists? " << (cnt_umap ? "Yes" : "No") << endl;
    
    // IMPORTANT: lower_bound() and upper_bound() do NOT exist
    // (because keys are not sorted)
    
    // How it works:
    // - Uses hash table internally
    // - Hash function converts key to index
    // - Average O(1) for all operations
    // - Worst case O(n) if many hash collisions (very rare)
    
    // When to use:
    // - Use UNORDERED_MAP when you need fast lookup and don't care about order
    // - Use MAP when you need sorted keys or range queries
    // - In competitive programming, unordered_map is usually faster
    
    // Common use case: Frequency counting
    unordered_map<int, int> freq;
    vector<int> arr = {1, 2, 1, 3, 2, 1, 4};
    for (int x : arr) {
        freq[x]++;  // Count frequency of each element
    }
    cout << "Frequency map:" << endl;
    for (auto p : freq) {
        cout << p.first << " appears " << p.second << " times" << endl;
    }
    
    // Common functions: begin(), end(), size(), swap(), empty(), insert(), erase(), find(), count()
    // NOT available: lower_bound(), upper_bound(), rbegin(), rend()
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// CUSTOM COMPARATOR: Sort data in custom ways
// ============================================================================

// Custom comparator function for sorting
// Returns true if p1 should come BEFORE p2 in sorted order
bool comp(pair<int, int> p1, pair<int, int> p2){
    // Sort by second element in ascending order
    if (p1.second < p2.second) return true;
    
    // If second elements are equal, sort by first element in descending order
    else if (p1.second == p2.second) {
        if (p1.first > p2.first) return true;
    }
    
    return false;
}

void explainExtra(){
    // Custom sorting in STL
    
    cout << "=== CUSTOM SORTING ===" << endl;
    
    // Example: Using bool comp() comparator function
    // The comp() function sorts by second element (ascending),
    // and if second elements are equal, sorts by first element (descending)
    cout << "--- Example of bool comp() function ---" << endl;
    cout << "Comparator rule: Sort by 2nd element ASC, if equal then by 1st element DESC" << endl;
    
    vector<pair<int, int>> v;
    v.push_back({1, 3});
    v.push_back({2, 2});
    v.push_back({3, 1});
    v.push_back({4, 2});
    
    cout << "Before sorting:" << endl;
    for (auto it : v){
        cout << "{" << it.first << ", " << it.second << "} ";
    }
    cout << endl;
    
    // Sort using custom comparator
    // Sorts by second element (ascending), if tie then by first element (descending)
    sort(v.begin(), v.end(), comp);
    
    cout << "After custom sorting:" << endl;
    for (auto it : v){
        cout << "{" << it.first << ", " << it.second << "} ";
    }
    cout << endl;
    // Output: {3, 1} {4, 2} {2, 2} {1, 3}
    // Explanation:
    // - {3, 1} comes first (second element = 1, smallest)
    // - {4, 2} and {2, 2} both have second element = 2, but 4 > 2, so {4, 2} comes first
    // - {1, 3} comes last (second element = 3, largest)
    
    // Working example: Demonstrating comp() function directly
    cout << "\n--- Direct usage of comp() function ---" << endl;
    pair<int, int> p1 = {2, 2};
    pair<int, int> p2 = {4, 2};
    pair<int, int> p3 = {1, 3};
    pair<int, int> p4 = {3, 1};
    
    cout << "comp({2, 2}, {4, 2}) = " << (comp(p1, p2) ? "true" : "false") << endl;
    cout << "  -> {4, 2} comes before {2, 2} (both have 2nd element = 2, but 4 > 2)" << endl;
    
    cout << "comp({1, 3}, {4, 2}) = " << (comp(p3, p2) ? "true" : "false") << endl;
    cout << "  -> {4, 2} comes before {1, 3} (2nd element 2 < 3)" << endl;
    
    cout << "comp({3, 1}, {4, 2}) = " << (comp(p4, p2) ? "true" : "false") << endl;
    cout << "  -> {3, 1} comes before {4, 2} (2nd element 1 < 2)" << endl;
    
    // Default sort (without comparator) - sorts in ascending order
    vector<int> v2 = {5, 2, 8, 1, 9};
    sort(v2.begin(), v2.end());  // {1, 2, 5, 8, 9}
    cout << "Default sort (ascending): ";
    for (auto x : v2) cout << x << ' ';
    cout << endl;
    
    // Sort in descending order using greater<int>()
    sort(v2.begin(), v2.end(), greater<int>());  // {9, 8, 5, 2, 1}
    cout << "Sort descending: ";
    for (auto x : v2) cout << x << ' ';
    cout << endl;
    
    // Lambda function as comparator (modern C++ way)
    vector<pair<int, int>> v3 = {{1, 3}, {2, 2}, {3, 1}, {4, 2}};
    sort(v3.begin(), v3.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second < b.second;  // Sort by second element only
    });
    cout << "Lambda sort (by second element): ";
    for (auto it : v3) cout << "{" << it.first << ", " << it.second << "} ";
    cout << endl;
    
    // Other useful STL algorithms
    
    // reverse - reverses the elements
    vector<int> v4 = {1, 2, 3, 4, 5};
    reverse(v4.begin(), v4.end());  // {5, 4, 3, 2, 1}
    cout << "After reverse: ";
    for (auto x : v4) cout << x << ' ';
    cout << endl;
    
    // max_element and min_element
    vector<int> v5 = {5, 2, 8, 1, 9};
    auto max_it = max_element(v5.begin(), v5.end());
    auto min_it = min_element(v5.begin(), v5.end());
    cout << "Max element: " << *max_it << endl;  // 9
    cout << "Min element: " << *min_it << endl;  // 1
    
    // accumulate - sum of all elements
    int sum = accumulate(v5.begin(), v5.end(), 0);  // 0 is initial value
    cout << "Sum of elements: " << sum << endl;  // 25
    
    // count - count occurrences
    vector<int> v6 = {1, 2, 1, 3, 1, 4};
    int cnt = static_cast<int>(count(v6.begin(), v6.end(), 1));
    cout << "Count of 1: " << cnt << endl;  // 3
    
    // find - find first occurrence
    auto find_it = find(v6.begin(), v6.end(), 3);
    if (find_it != v6.end()) {
        cout << "Found 3 at index: " << (find_it - v6.begin()) << endl;
    }
    
    // next_permutation - generates next permutation
    vector<int> v7 = {1, 2, 3};
    cout << "All permutations of {1, 2, 3}:" << endl;
    do {
        for (auto x : v7) cout << x << ' ';
        cout << endl;
    } while (next_permutation(v7.begin(), v7.end()));
    
    // __builtin_popcount() - counts the number of set bits (1s) in binary representation
    cout << "\n--- __builtin_popcount() - Count set bits ---" << endl;
    cout << "Number: 5 (binary: 101)" << endl;
    cout << "  __builtin_popcount(5) = " << __builtin_popcount(5) << endl;  // 2 (two 1s)
    
    cout << "Number: 7 (binary: 111)" << endl;
    cout << "  __builtin_popcount(7) = " << __builtin_popcount(7) << endl;  // 3 (three 1s)
    
    cout << "Number: 15 (binary: 1111)" << endl;
    cout << "  __builtin_popcount(15) = " << __builtin_popcount(15) << endl;  // 4 (four 1s)
    
    cout << "Number: 8 (binary: 1000)" << endl;
    cout << "  __builtin_popcount(8) = " << __builtin_popcount(8) << endl;  // 1 (one 1)
    
    // Practical example: counting set bits in a mask
    int mask = 0b10101010;  // Binary: 10101010 = 170
    cout << "\nMask: 0b10101010 (decimal: " << mask << ")" << endl;
    cout << "  Number of set bits: " << __builtin_popcount(static_cast<unsigned int>(mask)) << endl;  // 4
    
    cout << "-----------------------------------" << endl;
}

// ============================================================================
// MAIN FUNCTION: Test all data structures
// ============================================================================
int main(){
    cout << "\n";
    cout << "========================================" << endl;
    cout << "    C++ STL COMPREHENSIVE GUIDE" << endl;
    cout << "========================================" << endl;
    cout << "\n";
    
    explainPair();
    explainArray();
    explainVector();
    explainList();
    explainDeque();
    explainStack();
    explainQueue();
    explainPQ();
    explainSet();
    explainMultiSet();
    explainUnorderedSet();
    explainMap();
    explainMultiMap();
    explainUnorderedMap();
    explainExtra();
    
    cout << "\n";
    cout << "========================================" << endl;
    cout << "  QUICK REFERENCE SUMMARY" << endl;
    cout << "========================================" << endl;
    cout << "\n";
    
    cout << "CONTAINERS COMPARISON:" << endl;
    cout << "┌────────────────────┬──────────────┬──────────────┬─────────────┐" << endl;
    cout << "│ Container          │ Duplicates   │ Ordered      │ Time        │" << endl;
    cout << "├────────────────────┼──────────────┼──────────────┼─────────────┤" << endl;
    cout << "│ set                │ No           │ Yes          │ O(log n)    │" << endl;
    cout << "│ multiset           │ Yes          │ Yes          │ O(log n)    │" << endl;
    cout << "│ unordered_set      │ No           │ No           │ O(1) avg    │" << endl;
    cout << "│ map                │ Unique keys  │ Yes          │ O(log n)    │" << endl;
    cout << "│ multimap           │ Dup keys     │ Yes          │ O(log n)    │" << endl;
    cout << "│ unordered_map      │ Unique keys  │ No           │ O(1) avg    │" << endl;
    cout << "└────────────────────┴──────────────┴──────────────┴─────────────┘" << endl;
    cout << "\n";
    
    cout << "WHEN TO USE WHAT:" << endl;
    cout << "• Use VECTOR for: Dynamic arrays, frequent random access" << endl;
    cout << "• Use LIST for: Frequent insertions/deletions in middle" << endl;
    cout << "• Use DEQUE for: Fast operations at both ends" << endl;
    cout << "• Use STACK for: LIFO operations (undo, backtracking)" << endl;
    cout << "• Use QUEUE for: FIFO operations (BFS, scheduling)" << endl;
    cout << "• Use PRIORITY_QUEUE for: Always need min/max element" << endl;
    cout << "• Use SET for: Unique sorted elements, range queries" << endl;
    cout << "• Use UNORDERED_SET for: Unique elements, fast lookup" << endl;
    cout << "• Use MAP for: Key-value pairs, sorted keys" << endl;
    cout << "• Use UNORDERED_MAP for: Key-value pairs, fast lookup" << endl;
    cout << "\n";
    
    return 0;
}
