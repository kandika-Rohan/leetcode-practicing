<h2><a href="https://www.geeksforgeeks.org/problems/pairs-violating-bst-property--212515/1?page=2&category=Binary%20Search%20Tree&sortBy=submissions">Pairs violating the BST property</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a binary tree with&nbsp;<strong>n</strong>&nbsp;nodes, find the number of&nbsp;<strong>pairs violating the BST property</strong>.<br>BST has the following properties:-</span></p>
<ul>
<li><span style="font-size: 14pt;">Every node is greater than its left child and less than its right child.</span></li>
<li><span style="font-size: 14pt;">Every node is greater than the maximum value of in its left subtree and less than the minimum value in its right subtree.</span></li>
<li><span style="font-size: 14pt;">The maximum in the left sub-tree must be less than the minimum in the right subtree.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input : </strong>
n = 5
Input tree
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861883/Web/Other/blobid0_1709054479.png" alt="" width="351" height="245">    
<strong>Output :</strong>
5
<strong>Explanation : </strong>
Pairs violating BST property are:-
(10,50), 10 should be greater than its left child value.
(40,30), 40 should be less than its right child value.
(50,20), (50,30) and (50,40), maximum of left subtree of 10 is 50 greater than 20, 30 and 40 of its right subtree.</span></pre>
<p><span style="font-size: 14pt;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input : </strong>
n = 6<br>Input tree
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/861883/Web/Other/blobid1_1709055216.png" alt="" width="402" height="219">
<strong>Output :</strong>
9
<strong>Explanation :</strong>
There are total 9 pairs { (80,30),(80,60),(80,70),(30,60),(40,70),(40,30),(70,30),(70,60),(70,70) } which violate the BST properties.</span></pre>
<div><span style="font-size: 14pt;"><strong>Your task :</strong></span></div>
<div><span style="font-size: 14pt;">You don't have to read input or print anything. Your task is to complete the function&nbsp;<strong>pairsViolatingBST</strong><strong>()</strong>&nbsp;that takes the root of the tree and&nbsp;<strong>n</strong>&nbsp;as input and returns number of pairs violating BST property.<br></span></div>
<div>&nbsp;</div>
<div><span style="font-size: 14pt;"><strong>Expected Time Complexity:&nbsp;</strong>O(n*logn)</span></div>
<div><span style="font-size: 14pt;"><strong>Expected Space Complexity:&nbsp;</strong>O(n)</span></div>
<div>&nbsp;</div>
<div><span style="font-size: 14pt;"><strong>Your Task :</strong></span></div>
<div><span style="font-size: 14pt;">1 &lt;= n &lt;= 2*10<sup>4</sup></span></div>
<div><span style="font-size: 14pt;">-10<sup>9</sup>&nbsp;&lt;= node-&gt;data &lt;= 10<sup>9</sup></span></div></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Merge Sort</code>&nbsp;<code>Traversal</code>&nbsp;<code>Data Structures</code>&nbsp;