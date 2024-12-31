//
//  main.cpp
//  Code to Solve triangle problem 
//  Created by Saira(Shabi) Latif on 2024-02-05.

// You will be given a triangle input (which is a directed graph) and you need to find the path that provides..
/*
        {215},
        {192, 124},
        {117 ,269, 442},
        {218, 836, 347 ,235},
         {320 ,805, 522, 417 ,345},
         {229, 601, 728, 835, 133, 124},
         { 248, 202, 277, 433, 207, 263, 257},
         {359, 464, 504, 528, 516, 716, 871, 182},
         {461, 441, 426, 656, 863, 560, 380, 171, 923},
         {381, 348, 573, 533, 448, 632, 387, 176, 975, 449},
         {223, 711, 445, 645, 245, 543, 931, 532, 937, 541, 444},
         {330, 131, 333, 928, 376, 733, 017, 778, 839, 168, 197, 197},
         { 131, 171, 522, 137, 217, 224, 291, 413, 528, 520, 227, 229, 928},
         {223, 626, 034, 683, 839, 052, 627, 310, 713, 999, 629, 817, 410, 121},
         {924, 622, 911, 233, 325, 139, 721, 218, 253, 223, 107, 233, 230, 124, 233}
         };
         Note that, each node has only two children here (except the bottom row). As an example, you can
        walk from 215 to 124 or 192, and then from 124 to 269, since 442 is even just like its parent. From
        124 you cannot go to 117 because it is not a direct child of 124.

...the maximum possible sum of the numbers per the given rules below:
1. You will start from the top and move downwards to the last possible node.
2. You must proceed by changing between even and odd numbers subsequently. Suppose that
you are on an even number, the next number you choose must be odd, or if you are on an odd
number the next number must be even. In other words, the final path would be Odd -> even
-> odd -> even ...
3. You must reach to the bottom of the pyramid.
4. Assume that there is at least one valid path to the bottom.
5. If there are multiple paths, which result in the same maximum amount, you can choose any of
them.
Sample Input:
1
8 9
1 5 9
4 5 2 3
Output:
Max sum: 16
Path: 1, 8, 5, 2
Explanation:
As you can see this triangle has several paths: 1->8->5->2, 1->9->9->3, 1->8->1->4, etc.
The correct answer is 1 + 8 + 5 + 2 = 16. Because since 1 (top most number) is odd we cannot step onto
9 because 9 is an odd number too. The only number we can move to is 8. From 8 we can step to 1 or
5. Only 1 -> 8 -> 5 -> 2 sequence gives us the maximum sum. The other path 1-> 8 -> 1 -> 4 is also a
valid path but it sums up to 14. Since 16 is greater than 14, 16 is the solution. Also, note that the
solution is in the form of odd > even > odd > even.
*/

// Solution:

#include <iostream>
#include <vector>
#include <stdexcept> // For std::runtime_error

using namespace std;

// Function declaration for dfs
void dfs(int row, int col, const vector<vector<int>>& triangle, vector<int>& currentPath, vector<vector<int>>& allPaths);

void dfs(int row, int col,const vector<vector<int>>& triangle, vector<int>& currentPath, vector<vector<int>>& allPaths)
{
    int numRows = static_cast<int>(triangle.size());
    
    // Add the current node to the current path
    currentPath.push_back(triangle[row][col]);
    
    // Check base case if it's the last row
    if (row == numRows - 1) {
        allPaths.push_back(currentPath);
        // Remove the last element when backtracking
        currentPath.pop_back();
        return;
    }
    // Calculate the index of the next row
    int nextRow = row + 1;
    
    // Calculate the indices of the child nodes
    int leftChild=col;
    int rightChild=col+1;
    
    // Determine the valid child node(s) based on the even-odd rules
    vector<int> validChilds;
    int currentNode = triangle[row][col];
    //vector<int> childs;
    
    if (triangle[nextRow][leftChild] % 2 != currentNode % 2) {
        validChilds.push_back(leftChild);
    }
    if (triangle[nextRow][rightChild] % 2 != currentNode % 2) {
        validChilds.push_back(rightChild);
    }
    
    
    
    // Recursively explore valid child nodes
    for (int validChild : validChilds) {
        dfs(nextRow, validChild, triangle, currentPath, allPaths);
    }
    
    // Remove the last element when backtracking
    currentPath.pop_back();
    
    //return 0;
}


vector<vector<int>> findPaths(const vector<vector<int>>& triangle) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    int maxSum = 0;
    dfs(0, 0, triangle, currentPath, allPaths);
    vector<vector<int>> maxPaths;
    for (const vector<int>& path : allPaths) {
        int sum = 0;
        for (int num : path) {
            sum += num;
        }
        if (sum > maxSum) {
            maxSum = sum;
           // cout<<"Valid Path maxSum:"<< maxSum << endl;
            maxPaths.clear();
        }
        if (sum == maxSum) {
            maxPaths.push_back(path);
            //cout<<"maxSum:"<< maxSum << std::endl;
        }
       
    }
    cout <<"MaxSum:"<< endl;

    cout<< maxSum << endl;
   /*
    cout <<"`all valid Path: " <<endl;
    for (const vector<int>& path : allPaths) {
        for (int num : path) {
            cout <<num << " ";
        }
        //cout <<"->MaxSum:"<< maxSum << endl;
    }
    */
    //cout<<"MaxSum:"<< maxSum << endl;
    return maxPaths ;
}





int main() {
    vector<vector<int>> triangle = {
   // Examle 1 to test
        {1},
       {8, 9},
        {1, 5, 9},
        {4, 5, 2, 3}
    };
    
    // Example 2 to test
/*
        {215},
        {192, 124},
        {117 ,269, 442},
        {218, 836, 347 ,235},
         {320 ,805, 522, 417 ,345},
         {229, 601, 728, 835, 133, 124},
         { 248, 202, 277, 433, 207, 263, 257},
         {359, 464, 504, 528, 516, 716, 871, 182},
         {461, 441, 426, 656, 863, 560, 380, 171, 923},
         {381, 348, 573, 533, 448, 632, 387, 176, 975, 449},
         {223, 711, 445, 645, 245, 543, 931, 532, 937, 541, 444},
         {330, 131, 333, 928, 376, 733, 017, 778, 839, 168, 197, 197},
         { 131, 171, 522, 137, 217, 224, 291, 413, 528, 520, 227, 229, 928},
         {223, 626, 034, 683, 839, 052, 627, 310, 713, 999, 629, 817, 410, 121},
         {924, 622, 911, 233, 325, 139, 721, 218, 253, 223, 107, 233, 230, 124, 233}
         };
      */
    vector<vector<int>> maxPaths = findPaths(triangle);
    cout <<"Valid Path: " <<endl;
    for (const vector<int>& path : maxPaths) {
        for (int num : path) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

