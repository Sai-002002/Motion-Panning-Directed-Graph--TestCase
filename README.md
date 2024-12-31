This is code to to solve pyramid problem. 
You will be given a triangle input (which is a directed graph) and you need to find the path that provides
the maximum possible sum of the numbers per the given rules below:
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
<img width="87" alt="image" src="https://github.com/user-attachments/assets/87a51b31-0fa1-421d-a3e7-f10991950a3a" />

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
Per the above rules, what is the maximum sum of the below input? Please take this pyramid as an
input (as a file, or constants directly inside the code) for your implementation and solve it.

<img width="453" alt="image" src="https://github.com/user-attachments/assets/a8e6d24e-6b8c-49c6-bbd8-5b1b407ef5a3" />

Note that, each node has only two children here (except the bottom row). As an example, you can
walk from 215 to 124 or 192, and then from 124 to 269, since 442 is even just like its parent. From
124 you cannot go to 117 because it is not a direct child of 124.
