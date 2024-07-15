<h2><a href="https://www.geeksforgeeks.org/problems/path-in-matrix3805/1?page=3&category=Dynamic%20Programming&sortBy=submissions">Maximum path sum in matrix</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <strong>n</strong> x <strong>n</strong> matrix of positive integers. There are only three possible moves from a cell <strong>mat[r][c]</strong>.</span></p>
<ol>
<li><span style="font-size: 18px;">mat[r+1] [c]</span></li>
<li><span style="font-size: 18px;">mat[r+1] [c-1]</span></li>
<li><span style="font-size: 18px;">mat [r+1] [c+1]</span></li>
</ol>
<p><span style="font-size: 18px;">Starting from any column in row 0 return the largest sum of any of the paths up to row n -1. R</span><span style="font-size: 18px;">eturn the highest maximum path sum.</span></p>
<p><span style="font-size: 18px;"><strong>Note :</strong> We can start from any column in zeroth row and can end at any column in (n-1)th row.</span><br><br><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, mat = [[348, 391],[618, 193]]
<strong>Output:</strong> 1009
<strong>Explaination:</strong> The best path is 391 -&gt; 618. It gives the sum = 1009.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, mat = [[2, 2],[2, 2]]
<strong>Output:</strong> 4
<strong>Explaination:</strong> No matter which path is chosen, the output is 4.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n * n)<br><strong>Expected Auxiliary Space:</strong> O(n * n)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 500<br>1 ≤ mat[i][j] ≤ 1000</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Samsung</code>&nbsp;<code>MakeMyTrip</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;