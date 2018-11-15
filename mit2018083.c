// Program for nth Catalan Number

//Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

// Here two approaches are discussed one being optimal substructre and the other is dynamic programming.

/* 
Catalan numbers are a sequence of natural numbers that occurs in many interesting counting problems like following.

1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
*/



/* FIRST APPROACH: OPTIMAL SUBSTRUCTRE */

/* EXAMPLE: The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …*/

// Optimal substructure implementation

#include<iostream> 
using namespace std; 
  
unsigned long int catalan(unsigned int n) 
{ 
    // Base case 
    if (n <= 1) return 1; 
  
    unsigned long int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return res; 
} 
  
int main() 
{ 
    for (int i=0; i<10; i++) 
        cout << catalan(i) << " "; 
    return 0; 
} 

/* OUTPUT: 1 1 2 5 14 42 132 429 1430 4862

*/ 

/* Time comlpexity analysis: T(n) = 2(T(1) + T(2) + T(3) + ... + T(n-2) + T(n-1)) + k + (n-1)c
Similarly, 
T(n-1) = 2(T(1) + T(2) + T(3) + ... + T(n-2)) + k + (n-2)c

Reorder T(n) as 2(T(1) + T(2) + T(3) + ... + T(n-2)) + 2T(n-1) + k + (n-2)c + c
T(n) = 2(T(1) + T(2) + T(3) + ... + T(n-2)) + k + (n-2)c + 2T(n-1) + c
T(n) = T(n-1) + 2T(n-1) + c
T(n) = 3T(n-1) + c
T(n) = (3^2)T(n-2) + 3c + c
T(n) = (3^3)T(n-3) + (3^2)c + 3c + c
and so on...
T(n) = (3^(n-1))T(n-(n-1)) + c(3^0 + 3^1 + 3^2 + ... + 3^(n-2))
T(n) = (3^(n-1))T(1) + ((3^(n-1)-1)/2)c

So, the time complexity is O(3 ^ N)

 */



/* SECOND APPROACH: DYNAMIC PROGRAMMING */

/* We can observe that the above recursive implementation does a lot of repeated work (we can the same by drawing recursion tree). Since there are overlapping subproblems, we can use dynamic programming for this. Following is a Dynamic programming based implementation in C++. */

// Dynamic programming implementation

#include<iostream> 
using namespace std; 
  
unsigned long int catalanDP(unsigned int n) 
{ 

    unsigned long int catalan[n+1]; 
  
    catalan[0] = catalan[1] = 1; 
  
    for (int i=2; i<=n; i++) 
    { 
        catalan[i] = 0; 
        for (int j=0; j<i; j++) 
            catalan[i] += catalan[j] * catalan[i-j-1]; 
    } 
  
    return catalan[n]; 
}
 
int main() 
{ 
    for (int i = 0; i < 10; i++) 
        cout << catalanDP(i) << " "; 
    return 0; 
} 

/* OUTPUT: 1 1 2 5 14 42 132 429 1430 4862 
*/ 

/* Time comlpexity analysis: Time Complexity: Time complexity of above implementation is O(n2) */
