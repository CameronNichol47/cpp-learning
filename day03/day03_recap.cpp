
#include <iostream>
#include <vector>

// ============================================================
// DAY 3 RECAP — REFERENCES, POINTERS, CONST & PARAMETER PASSING
// ============================================================
//
// 1. PASS-BY-VALUE
// 2. PASS-BY-REFERENCE
// 3. REFERENCES AS ALIASES
// 4. CONST REFERENCES
// 5. PASSING VECTORS
// 6. RANGE-BASED FOR LOOPS
// 7. POINTER BASICS
// 8. ADDRESS-OF (&) AND DEREFERENCE (*)
// 9. PASSING POINTERS TO FUNCTIONS
// 10. POINTERS VS REFERENCES
// 11. nullptr AND POINTER SAFETY
// 12. CONST WITH POINTERS
// 13. IMPORTANT C++ DETAILS
// 14. FINAL CHEAT SHEET
//
// ============================================================


// ============================================================
// 1. PASS-BY-VALUE
// ============================================================
//
// Syntax:
// void function(double x)
//
// - The function receives a COPY of the argument.
// - Changes inside the function do NOT affect the original.
// - The parameter is a separate local variable.
// - Copying small types (int, double, bool, char) is cheap.
// - Copying large objects (e.g., vectors) can be expensive.
// - A function can return a new value using return.
//
// Example:

void by_value(double x) {
    x = 200.0; // Only modifies the local copy
}


// ============================================================
// 2. PASS-BY-REFERENCE
// ============================================================
//
// Syntax:
// void function(double& x)
//
// - The function accesses the ORIGINAL variable.
// - Changes inside the function affect the original.
// - No copy of the underlying object is created.
// - No dereferencing syntax (*) is needed.
// - Useful when a function must modify an argument.
// - A void function can still modify an argument through
//   a non-const reference.
//
// Example:

void by_reference(double& x) {
    x = 200.0; // Modifies the original
}


// ============================================================
// 3. REFERENCES AS ALIASES
// ============================================================
//
// A reference is another name for an existing object.
//
// Example:
//
// double price = 100.0;
// double& ref = price;
//
// ref = 150.0;  // price is now 150.0
//
// Important:
//
// - A reference must be initialized when declared.
// - An ordinary reference cannot be rebound.
// - Assigning to a reference modifies the referenced object.
//
// Example:
//
// double a = 10.0;
// double b = 20.0;
// double& ref = a;
//
// ref = b;
//
// This does NOT make ref refer to b.
// It assigns b's VALUE to a.
//
// Result:
// a = 20.0
// b = 20.0
//
// ref still refers to a.


// ============================================================
// 4. CONST REFERENCES
// ============================================================
//
// Syntax:
// const double& x
//
// - const prevents modification through the reference.
// - & avoids copying the underlying object.
// - Useful for read-only access to large objects.
// - For small types like double, pass-by-value is usually
//   simpler and efficient.
// - The original object can still be changed elsewhere
//   if it was not declared const.
// - A const reference can bind to temporary values.
//
// Example:

void read_only(const double& x) {
    std::cout << x << '\n';

    // x = 200.0; // COMPILER ERROR
}

// Example:
//
// const double& ref = 10.5; // Valid


// ============================================================
// 5. PASSING VECTORS TO FUNCTIONS
// ============================================================
//
// THREE MAIN METHODS:
//
// A) Pass-by-value:
//
// void function(std::vector<double> v)
//
// - Copies the entire vector.
// - Changes to the copy do not affect the original.
//
// B) Pass-by-reference:
//
// void function(std::vector<double>& v)
//
// - Does not copy the vector.
// - Can modify the original vector.
//
// C) Pass-by-const-reference:
//
// void function(const std::vector<double>& v)
//
// - Does not copy the vector.
// - Cannot modify the vector through this reference.
// - Common choice for large, read-only inputs.
//
// Example:

void inspect_vector(const std::vector<double>& v) {
    std::cout << v.size() << '\n';

    // v.push_back(100.0); // COMPILER ERROR
    // v[0] = 200.0;       // COMPILER ERROR
}


// ============================================================
// 6. RANGE-BASED FOR LOOPS
// ============================================================
//
// A range-based for loop iterates over collection elements.
//
// Syntax:
//
// for (double x : values) {
//     std::cout << x << '\n';
// }
//
// THREE VARIATIONS:
//
// for (double x : values)
//     - Copies each element into x.
//     - Changing x does not modify the vector.
//
// for (double& x : values)
//     - x refers to the original element.
//     - Changing x modifies the vector.
//
// for (const double& x : values)
//     - No element copy.
//     - Cannot modify the element through x.
//
// IMPORTANT DIFFERENCE:
//
// const std::vector<double>& v
//     Avoids copying the ENTIRE vector.
//
// for (const double& x : v)
//     Avoids copying each INDIVIDUAL element.
//
// For doubles, element copies are inexpensive.
// For large objects, const references are often preferable.
//
// USEFUL VECTOR METHODS:
//
// v.size()   -> number of elements
// v.empty()  -> true if empty
// v.back()   -> last element (requires nonempty vector)
// v.front()  -> first element (requires nonempty vector)
// v.at(i)    -> element at index i, with bounds checking
// v[i]       -> element at index i, without bounds checking
//
// v.size() returns std::size_t.
//
// std::size_t is an unsigned integer type commonly used
// for sizes and indexing.
//
// Example:
//
// for (std::size_t i = 0; i < v.size(); i++) {
//     std::cout << v[i] << '\n';
// }


// ============================================================
// 7. POINTER BASICS
// ============================================================
//
// A pointer is a variable that stores a MEMORY ADDRESS.
//
// Example:
//
// double price = 100.0;
// double* ptr = &price;
//
// price   -> value: 100.0
// &price  -> address of price
// ptr     -> stores the address of price
// *ptr    -> value at that address: 100.0
//
// IMPORTANT:
//
// - A pointer is itself an object with its own memory.
// - A pointer stores an address, not the pointed-to value.
// - Dereferencing accesses the pointed-to object.
// - A pointer can be reassigned to point elsewhere.
// - A pointer can be nullptr.
// - Dereference only pointers that point to valid objects.
//
// Example:
//
// double a = 100.0;
// double b = 200.0;
//
// double* ptr = &a;
//
// *ptr = 150.0; // Changes a
//
// ptr = &b;     // Pointer now points to b
//
// *ptr = 250.0; // Changes b


// ============================================================
// 8. DIFFERENT MEANINGS OF & AND *
// ============================================================
//
// & has different meanings depending on context.
//
// REFERENCE DECLARATION:
//
// double& ref = price;
//
// Here & declares a reference.
//
// ADDRESS-OF OPERATOR:
//
// double* ptr = &price;
//
// Here &price obtains the address of price.
//
// POINTER DECLARATION:
//
// double* ptr;
//
// Here * means "pointer to double".
//
// DEREFERENCE OPERATOR:
//
// *ptr = 200.0;
//
// Here * accesses the pointed-to object.
//
// MULTIPLICATION:
//
// double result = 2.0 * 3.0;
//
// Here * means multiplication.
//
// REMEMBER:
//
// ptr   -> address stored in pointer
// *ptr  -> value at that address
// &x    -> address of variable x


// ============================================================
// 9. PASSING POINTERS TO FUNCTIONS
// ============================================================
//
// Syntax:
//
// void function(double* ptr)
//
// The function receives a COPY of an address.
//
// To pass the address of an existing variable:
//
// function(&price);
//
// Inside the function:
//
// *ptr = 200.0;
//
// This modifies the original object.
//
// Example:

void by_pointer(double* ptr) {
    if (ptr != nullptr) {
        *ptr = 200.0;
    }
}

// IMPORTANT DETAIL:
//
// The pointer itself is passed BY VALUE.
//
// Example:
//
// void redirect(double* ptr) {
//     ptr = nullptr;
// }
//
// Calling redirect(ptr) does NOT change the caller's ptr.
//
// But modifying *ptr CAN modify the pointed-to object.
//
// To modify the caller's pointer itself, a pointer reference
// (double*&) or pointer-to-pointer (double**) can be used.
// These are more advanced concepts.


// ============================================================
// 10. POINTERS VS REFERENCES
// ============================================================
//
// REFERENCES:
//
// double& ref = price;
//
// - Alias for an existing object.
// - Must be initialized.
// - Cannot be rebound.
// - No * needed to access value.
// - Cannot validly refer to no object.
//
// POINTERS:
//
// double* ptr = &price;
//
// - Store an address.
// - Can be reassigned.
// - Can be nullptr.
// - Require * to dereference.
// - Should always be initialized.
//
// BOTH:
//
// - Can access the original object.
// - Can modify the original when not const.
// - Can avoid copying large objects.
//
// GENERAL GUIDELINE:
//
// Use pass-by-value for small inputs.
// Use references to modify required arguments.
// Use const references for large read-only inputs.
// Use pointers when nullability, reassignment, or
// low-level memory access is needed.


// ============================================================
// 11. nullptr AND POINTER SAFETY
// ============================================================
//
// nullptr represents a pointer that points to no object.
//
// Example:
//
// double* ptr = nullptr;
//
// NEVER DEREFERENCE nullptr:
//
// *ptr = 100.0; // UNDEFINED BEHAVIOR
//
// Safe check:
//
// if (ptr != nullptr) {
//     *ptr = 100.0;
// }
//
// IMPORTANT:
//
// - Dereferencing nullptr is undefined behavior.
// - An uninitialized pointer is unsafe to use.
// - A dangling pointer points to an object whose lifetime
//   has ended.
// - Non-null does NOT automatically mean valid.
// - Always ensure the pointed-to object is still alive.
//
// Example of a dangling pointer:
//
// double* ptr = nullptr;
//
// {
//     double x = 100.0;
//     ptr = &x;
// }
//
// // x no longer exists here.
// // *ptr is invalid.
//
// Prefer:
//
// double* ptr = nullptr;
//
// Or initialize with the address of a valid object.


// ============================================================
// 12. CONST WITH POINTERS
// ============================================================
//
// const double* ptr
//
// POINTER TO CONST DOUBLE
//
// - Cannot modify the double through ptr.
// - Can reassign ptr to another address.
//
// Example:
//
// double a = 100.0;
// double b = 200.0;
//
// const double* ptr = &a;
//
// ptr = &b;     // Allowed
// *ptr = 300;  // COMPILER ERROR
//
//
// double* const ptr = &a;
//
// CONST POINTER TO DOUBLE
//
// - Can modify the pointed-to double.
// - Cannot reassign the pointer.
//
// *ptr = 300;  // Allowed
// ptr = &b;    // COMPILER ERROR
//
//
// const double* const ptr = &a;
//
// CONST POINTER TO CONST DOUBLE
//
// - Cannot modify through ptr.
// - Cannot reassign ptr.
//
// REMEMBER:
//
// const double* ptr        -> read-only pointed-to value
// double* const ptr        -> fixed pointer address
// const double* const ptr  -> both restrictions


// ============================================================
// 13. IMPORTANT SMALL C++ DETAILS
// ============================================================
//
// 1. A reference is not the same thing as a pointer,
//    even though implementations often use addresses.
//
// 2. A reference declaration requires an initializer:
//
//    double& ref = price; // Valid
//    double& ref;         // Invalid
//
// 3. A pointer can be initialized with nullptr:
//
//    double* ptr = nullptr;
//
// 4. const prevents modification through that access path.
//    It does not always make the original object immutable.
//
// 5. Passing a pointer by value copies the address,
//    not the pointed-to object.
//
// 6. Passing a vector by value copies its elements.
//
// 7. Passing a vector by const reference avoids copying
//    the vector and prevents modification through it.
//
// 8. std::size_t is the standard type for object sizes
//    and container indices.
//
// 9. .back() and .front() require a nonempty vector.
//
// 10. Dereferencing invalid pointers is undefined behavior.
//
// 11. A function declared void does not return a value,
//     but can modify objects through references or pointers.
//
// 12. std::cout formatting with std::fixed and
//     std::setprecision(2) persists until changed.
//
// 13. A const reference can bind to a temporary:
//
//     const double& ref = 5.0;
//
// 14. Use const whenever a function should only read data.
//
// 15. In modern C++, raw pointers do not automatically
//     imply ownership of dynamically allocated memory.
//     Smart pointers and RAII are covered later.


// ============================================================
// 14. FINAL DAY 3 CHEAT SHEET
// ============================================================
//
// double x = 100.0;
//
// double y = x;
//     -> Creates a copy.
//
// double& ref = x;
//     -> Alias for x.
//
// const double& cref = x;
//     -> Read-only access to x through cref.
//
// double* ptr = &x;
//     -> Pointer storing x's address.
//
// *ptr = 200.0;
//     -> Modifies x.
//
// ptr = nullptr;
//     -> Pointer no longer points to x.
//
// void f(double x);
//     -> Pass-by-value.
//
// void f(double& x);
//     -> Pass-by-reference.
//
// void f(const double& x);
//     -> Pass-by-const-reference.
//
// void f(double* x);
//     -> Pass pointer by value.
//
// void f(const std::vector<double>& v);
//     -> Efficient read-only vector parameter.
//
// for (double x : v)
//     -> Copy each element.
//
// for (double& x : v)
//     -> Modify original elements.
//
// for (const double& x : v)
//     -> Read elements without copying.
//
// ============================================================
// END OF DAY 3 RECAP
// ============================================================

int main() {
    return 0;
}
