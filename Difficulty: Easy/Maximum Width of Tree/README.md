<h2><a href="https://www.geeksforgeeks.org/problems/maximum-width-of-tree/1?page=6&company=Flipkart&sortBy=submissions">Maximum Width of Tree</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Binary Tree, find the maximum width of it.&nbsp;<strong>Maximum width </strong>is defined as the maximum number of nodes at any level.<br></span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [1, 2, 3]
<strong>&nbsp;&nbsp;&nbsp;</strong>&nbsp;&nbsp;&nbsp;&nbsp;1
 &nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;\
 &nbsp; &nbsp;2&nbsp; &nbsp; &nbsp;&nbsp;3
<strong>Output: </strong>2
<strong>Explanation: </strong>On the first level there is only one node 1. On the second level there are two nodes 2, 3 clearly it is the maximum number of nodes at any level</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [10, 20, 30, 40, 60]
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 10
 &nbsp;&nbsp;&nbsp;&nbsp; /&nbsp;&nbsp;&nbsp;&nbsp; \
&nbsp;&nbsp;&nbsp;&nbsp;20&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 30
 &nbsp; /&nbsp;&nbsp;&nbsp;&nbsp;\
 &nbsp;40&nbsp;&nbsp;&nbsp; 60
<strong>Output: </strong>2<br></span><span style="font-size: 18px;"><strong>Explanation: </strong>There is one node on level 1(10) There is two node on level 2(20, 30) There is two node on level 3(40, 60) Hence the answer is 2</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(width of the tree).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= number of nodes&lt;= 10<sup>5</sup><br>0 &lt;= node-&gt;data &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>VMWare</code>&nbsp;<code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;