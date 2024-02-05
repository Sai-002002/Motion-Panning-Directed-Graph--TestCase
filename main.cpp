//
//  main.cpp
//  Test12
//
//  Created by Sai La on 2024-02-05.
//
//

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
   // 
        {1},
       {8, 9},
        {1, 5, 9},
        {4, 5, 2, 3}
    };
    
    //
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

