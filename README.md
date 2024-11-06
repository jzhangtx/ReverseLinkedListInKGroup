Reverse a Linked List in k-groups


Given a linked list and a positive number k, reverse the nodes in groups of k.

All the remaining nodes after multiples of k should be left as it is.

Example
k: 3
Linked list: 1→2→3→4→5→6→7→8→9
Result: 3→2→1→6→5→4→9→8→7
k: 3
Linked list: 1→2→3→4→5→6→7→8
Result: 3→2→1→6→5→4→7→8
Note: Solve using O(1) extra space.

Testing
Input Format
The first line contains an integer ‘T’ denoting the number of independent test cases.

For each test case the input has three lines:

An integer ‘n’ denoting the length of the linked list.
n space-separated integers denoting elements of the linked list.
An integer 'k' denoting the group size.
Output Format
For each test case, a line containing ‘n’ space-separated integers denoting the resultant linked list elements.

Sample Input
3
9
1 2 3 4 5 6 7 8 9
3
8
1 2 3 4 5 6 7 8
3
9
1 2 3 4 5 6 7 8 9
12
Expected Output
3 2 1 6 5 4 9 8 7
3 2 1 6 5 4 7 8
1 2 3 4 5 6 7 8 9