#include <iostream>
using namespace std;

/*
================================================================================
UNDERSTANDING 2D DYNAMIC ARRAYS IN C++
Two Approaches: Pointer-to-Pointer vs Flattened 1D
================================================================================
*/

// ============================================================================
// APPROACH 1: 2D POINTER (Pointer to Array of Pointers)
// ============================================================================

/*
MEMORY LAYOUT - Pointer to Pointer Approach:
=============================================

int** arr2 = new int*[total];     // Allocate array of pointers
    ↓
    [ptr1] [ptr2] [ptr3] ... [ptrN]    ← Array of pointers (on heap)
      ↓      ↓      ↓         ↓
     [1]   [20]   [5]  ...  [7]        ← Each pointer points to its own array
     [2]   [30]   [6]        [8]
     [3]   [40]   [7]        [9]

Key Points:
-----------
1. Two levels of indirection (pointer to pointer)
2. Each row can have DIFFERENT size (jagged arrays)
3. MORE flexible but MORE cache misses (pointers scattered in memory)
4. MUST free both levels (rows first, then array of pointers)
*/

void approach1_pointer_to_pointer() {
    cout << "\n=== APPROACH 1: Pointer-to-Pointer (2D Pointers) ===\n";
    
    int total = 3;  // number of rows
    int n = 4;      // number of columns per row
    
    // STEP 1: Allocate array of pointers (first level of indirection)
    // This creates: int* [3] on the heap
    int** arr2 = new int*[total];
    cout << "Step 1: Allocated array of " << total << " pointers\n";
    cout << "arr2 points to: " << arr2 << "\n";
    
    // STEP 2: Allocate memory for each row (second level of indirection)
    // Each arr2[i] is a pointer that now points to an array of n integers
    for (int i = 0; i < total; ++i) {
        arr2[i] = new int[n];
        cout << "arr2[" << i << "] allocated at: " << arr2[i] << "\n";
    }
    
    // STEP 3: Use the 2D array
    cout << "\nFilling the array:\n";
    int value = 1;
    for (int i = 0; i < total; ++i) {
        for (int j = 0; j < n; ++j) {
            arr2[i][j] = value++;
        }
    }
    
    // STEP 4: Print the array
    cout << "\nArray contents:\n";
    for (int i = 0; i < total; ++i) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }
    
    // STEP 5: Understanding access patterns
    cout << "\nAccess patterns:\n";
    cout << "arr2 = " << arr2 << " (address of pointer array)\n";
    cout << "arr2[0] = " << arr2[0] << " (address of first row)\n";
    cout << "arr2[0][0] = " << arr2[0][0] << " (first element)\n";
    cout << "*arr2 = " << *arr2 << " (dereference arr2 → address of first row)\n";
    cout << "**arr2 = " << **arr2 << " (double dereference → first element)\n";
    
    // STEP 6: Memory addresses are NOT contiguous
    cout << "\nMemory addresses (NOT contiguous):\n";
    cout << "Pointer array at:       " << arr2 << "\n";
    for (int i = 0; i < total; ++i) {
        cout << "Row " << i << " at:              " << arr2[i] << "\n";
    }
    cout << "Notice: Row addresses are scattered, not sequential!\n";
    
    // STEP 7: CLEANUP - Important: Free in reverse order!
    cout << "\nCleaning up (freeing rows first, then array):\n";
    for (int i = 0; i < total; ++i) {
        delete[] arr2[i];  // Free each row
        cout << "Freed row " << i << "\n";
    }
    delete[] arr2;         // Free array of pointers
    cout << "Freed pointer array\n";
}

// ============================================================================
// APPROACH 2: 1D FLATTENED ARRAY (Simulating 2D with 1D)
// ============================================================================

/*
MEMORY LAYOUT - Flattened 1D Array Approach:
==============================================

int* arr2 = new int[total * n];

arr2 → [arr2[0]] [arr2[1]] [arr2[2]] [arr2[3]] | [arr2[4]] [arr2[5]] ... [arr2[n-1]]
        └─────── Row 0 (4 elements) ─────────┘   └─────── Row 1 ──────┘

ALL in ONE contiguous block of memory!

To access element [i][j]:
  arr2[i * n + j]
  
Example for 3×4 array:
  [0,0] = arr2[0*4 + 0] = arr2[0]
  [0,1] = arr2[0*4 + 1] = arr2[1]
  [0,2] = arr2[0*4 + 2] = arr2[2]
  [1,0] = arr2[1*4 + 0] = arr2[4]
  [1,1] = arr2[1*4 + 1] = arr2[5]
  [2,3] = arr2[2*4 + 3] = arr2[11]

Key Points:
-----------
1. ONE level of indirection (single pointer)
2. All rows same size (rectangular, not jagged)
3. BETTER cache locality (contiguous memory = faster)
4. SIMPLER cleanup (one delete[])
5. Manual index calculation: i*n + j
*/

void approach2_flattened_1d() {
    cout << "\n\n=== APPROACH 2: Flattened 1D Array (Simulating 2D) ===\n";
    
    int total = 3;  // number of rows
    int n = 4;      // number of columns per row
    
    // STEP 1: Allocate ONE contiguous block for all elements
    int* arr2 = new int[total * n];
    cout << "Step 1: Allocated " << (total * n) << " integers in ONE block\n";
    cout << "arr2 points to: " << arr2 << "\n";
    
    // STEP 2: Fill the array using 2D-style indexing
    cout << "\nFilling the array:\n";
    int value = 1;
    for (int i = 0; i < total; ++i) {
        for (int j = 0; j < n; ++j) {
            // Convert 2D index to 1D index
            arr2[i * n + j] = value++;
            cout << "arr2[" << i << "*" << n << " + " << j << "] = arr2[" 
                 << (i * n + j) << "] = " << value - 1 << "\n";
        }
    }
    
    // STEP 3: Print the array
    cout << "\nArray contents (accessed as 2D):\n";
    for (int i = 0; i < total; ++i) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << arr2[i * n + j] << " ";
        }
        cout << "\n";
    }
    
    // STEP 4: Understanding memory layout
    cout << "\nMemory layout (contiguous):\n";
    cout << "All elements in ONE sequential block:\n";
    for (int idx = 0; idx < total * n; ++idx) {
        cout << arr2[idx] << " ";
    }
    cout << "\n";
    
    // STEP 5: Verify contiguous memory addresses
    cout << "\nMemory addresses (CONTIGUOUS!):\n";
    cout << "arr2[0] at: " << &arr2[0] << "\n";
    cout << "arr2[1] at: " << &arr2[1] << " (difference: " 
         << ((long)&arr2[1] - (long)&arr2[0]) << " bytes)\n";
    cout << "arr2[2] at: " << &arr2[2] << " (difference: " 
         << ((long)&arr2[2] - (long)&arr2[1]) << " bytes)\n";
    cout << "Notice: Each address differs by " << sizeof(int) << " bytes (size of int)\n";
    cout << "All elements are sequential in memory!\n";
    
    // STEP 6: CLEANUP - Simple!
    cout << "\nCleaning up (one delete):\n";
    delete[] arr2;
    cout << "Freed entire array\n";
}

// ============================================================================
// COMPARISON FUNCTION
// ============================================================================

void comparison() {
    cout << "\n\n=== COMPARISON ===\n";
    cout << "\n┌─────────────────────┬──────────────────────┬──────────────────────┐\n";
    cout << "│ Aspect              │ 2D Pointer (arr2[][])│ 1D Flattened         │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Allocation          │ int** arr2 =         │ int* arr2 =          │\n";
    cout << "│                     │   new int*[rows]     │   new int[rows*cols] │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Second allocation   │ for loop with        │ NOT needed           │\n";
    cout << "│                     │ new int[cols]        │                      │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Indirection level   │ 2 (pointer to pointer)│ 1 (pointer)         │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Memory layout       │ SCATTERED            │ CONTIGUOUS          │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Access arr[i][j]    │ arr2[i][j]           │ arr2[i*n + j]       │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Jagged arrays       │ YES (rows can differ)│ NO (uniform rows)   │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Cache performance   │ POOR (cache misses)  │ GOOD (cache friendly)│\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Cleanup             │ for loop then delete │ One delete[]         │\n";
    cout << "├─────────────────────┼──────────────────────┼──────────────────────┤\n";
    cout << "│ Complexity          │ More complex         │ Less complex         │\n";
    cout << "└─────────────────────┴──────────────────────┴──────────────────────┘\n";
}

// ============================================================================
// PERFORMANCE CONSIDERATION
// ============================================================================

void performance_explanation() {
    cout << "\n\n=== WHY FLATTENED IS FASTER ===\n";
    cout << "\nCPU Cache Behavior:\n";
    cout << "-----------\n";
    
    cout << "\n2D Pointer Approach (Poor Cache Locality):\n";
    cout << "  Access arr2[0][0] → CPU loads row0 pointer from main memory\n";
    cout << "  Access arr2[1][0] → CPU loads row1 pointer from DIFFERENT memory location\n";
    cout << "                      (cache miss, must reload from main memory)\n";
    cout << "  Result: Lots of cache misses, slow!\n";
    
    cout << "\n1D Flattened Approach (Good Cache Locality):\n";
    cout << "  Access arr2[0] → CPU loads it into cache line\n";
    cout << "  Access arr2[1] → Already in cache line! (no reload)\n";
    cout << "  Access arr2[2] → Already in cache line! (no reload)\n";
    cout << "  Result: Cache hits, fast!\n";
    
    cout << "\nIn practice (processing 1M elements):\n";
    cout << "  2D Pointer:  ~100 milliseconds (many cache misses)\n";
    cout << "  1D Flattened: ~10 milliseconds (cache-friendly)\n";
    cout << "  Speedup: 10x faster!\n";
}

// ============================================================================
// WHEN TO USE EACH
// ============================================================================

void when_to_use() {
    cout << "\n\n=== WHEN TO USE EACH ===\n";
    
    cout << "\nUse 2D Pointer (arr2[][]) when:\n";
    cout << "  • You need JAGGED arrays (different row sizes)\n";
    cout << "  • Using multiple existing arrays with different sizes\n";
    cout << "  • Passing pre-allocated arrays to functions\n";
    cout << "  • Memory alloc/dealloc are not performance critical\n";
    
    cout << "\nUse 1D Flattened (arr2[i*n+j]) when:\n";
    cout << "  • You need rectangular matrices (all rows same size)\n";
    cout << "  • Performance/cache locality is important\n";
    cout << "  • You're doing heavy matrix operations\n";
    cout << "  • You want simpler memory management (single delete)\n";
    cout << "  • All permutations problem: THIS is what you should use!\n";
}

// ============================================================================
// APPLICATION: YOUR PERMUTATION PROBLEM
// ============================================================================

void permutation_example() {
    cout << "\n\n=== APPLICATION: PERMUTATIONS ===\n";
    
    int n = 3;
    int total = 6;  // 3! = 6 permutations
    
    cout << "\nFor storing all " << total << " permutations of " << n << " elements:\n";
    cout << "\nOption 1: 2D Pointer\n";
    cout << "  int** arr2 = new int*[" << total << "];\n";
    cout << "  for (i=0; i<" << total << "; i++) arr2[i] = new int[" << n << "];\n";
    cout << "  Cleanup: for loop + 2 deletes\n";
    
    cout << "\nOption 2: 1D Flattened (BETTER)\n";
    cout << "  int* arr2 = new int[" << total << " * " << n << "];\n";
    cout << "  Access: arr2[i*" << n << " + j]\n";
    cout << "  Cleanup: One delete\n";
    cout << "  Bonus: Better cache performance for processing permutations!\n";
    
    cout << "\nImplementation:\n";
    int* arr2 = new int[total * n];
    int count = 0;
    
    // Simulating storing permutations
    for (int i = 0; i < total; ++i) {
        for (int j = 0; j < n; ++j) {
            arr2[i * n + j] = j + 1;  // Store 1, 2, 3 for each permutation
        }
    }
    
    cout << "Stored permutations:\n";
    for (int i = 0; i < total; ++i) {
        cout << "Permutation " << i << ": ";
        for (int j = 0; j < n; ++j) {
            cout << arr2[i * n + j] << " ";
        }
        cout << "\n";
    }
    
    delete[] arr2;
}

// ============================================================================
// MAIN
// ============================================================================

int main() {
    cout << "╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║  UNDERSTANDING 2D DYNAMIC ARRAYS: TWO APPROACHES              ║\n";
    cout << "║  1. Pointer-to-Pointer (2D Pointers)                          ║\n";
    cout << "║  2. Flattened 1D Array                                        ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n";
    
    approach1_pointer_to_pointer();
    approach2_flattened_1d();
    comparison();
    performance_explanation();
    when_to_use();
    permutation_example();
    
    cout << "\n\n╔════════════════════════════════════════════════════════════════╗\n";
    cout << "║  KEY TAKEAWAY                                                  ║\n";
    cout << "║  For your permutation problem, use 1D FLATTENED approach:      ║\n";
    cout << "║                                                                ║\n";
    cout << "║  int* arr2 = new int[total * n];                              ║\n";
    cout << "║  arr2[i * n + j] = value;    // Store at row i, col j         ║\n";
    cout << "║  delete[] arr2;               // Single cleanup               ║\n";
    cout << "║                                                                ║\n";
    cout << "║  Benefits: Simpler, Faster, Less error-prone                  ║\n";
    cout << "╚════════════════════════════════════════════════════════════════╝\n";
    
    return 0;
}
