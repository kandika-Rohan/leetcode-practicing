<h2><a href="https://www.geeksforgeeks.org/problems/node-at-distance/1?page=6&company=Flipkart&sortBy=submissions">Count the nodes at distance K from leaf</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary tree with <strong>n </strong>nodes and a non-negative integer <strong>k</strong>, the task is to count the number of <strong>special nodes</strong>. <br>A node is considered <strong>special</strong> if there exists at least one leaf in its subtree such that the distance between the node and leaf is exactly <strong>k</strong>.<br></span><span style="font-size: 18px;"><strong>Note:</strong> Any such node should be counted only once. For example, if a node is at a distance <strong>k</strong> from 2 or more leaf nodes, then it would add only 1 to our count.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
        1
&nbsp;     /   \
&nbsp;    2     3
&nbsp;  /  \   /  \
&nbsp; 4   5  6    7
&nbsp;         \ 
&nbsp;          8
k = 2
<strong>Output: </strong>2<strong>
Explanation: </strong>There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct ancestor of node 8.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong><strong><br></strong></span><span style="font-size: 18px;"> &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;1
&nbsp;        /
&nbsp;       3
&nbsp;      /
&nbsp;     5
&nbsp;   /  \
&nbsp;  7    8
         \
&nbsp;         9
k = 4
<strong>Output: </strong>1<strong>
Explanation: </strong>Only one node is there which is at a distance of 4 units from the leaf node.(node 1 for leaf with value 9) </span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;