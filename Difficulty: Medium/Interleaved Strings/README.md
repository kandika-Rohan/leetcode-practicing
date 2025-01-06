<h2><a href="https://www.geeksforgeeks.org/problems/interleaved-strings/1?page=1&category=Dynamic%20Programming&difficulty=Medium&status=unsolved&sortBy=submissions">Interleaved Strings</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given strings <strong>s1</strong>, <strong>s2</strong>, and <strong>s3</strong>, find whether <strong>s3</strong> is formed by an <strong>interleaving </strong>of <strong>s1</strong> and <strong>s2</strong>.<br><strong>Interleaving </strong>of two strings s1 and s2 is a way to mix their characters to form a new string s3, while maintaining the relative order of characters from s1 and s2. Conditions for interleaving:<br></span></p>
<ol>
<li><span style="font-size: 14pt;">Characters from s1 must appear in the same order in s3 as they are in s1.</span></li>
<li><span style="font-size: 14pt;">Characters from s2 must appear in the same order in s3 as they are in s2.</span></li>
<li><span style="font-size: 14pt;">The length of s3 must be equal to the combined length of s1 and s2.</span></li>
</ol>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s1 = "YX", s2 = "X", s3 = "XXY"
<strong>Output: </strong>false<strong>
Explanation: </strong>XXY is not interleaving of YX and X.
</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s1 = "XY", s2 = "X", s3 = "XXY"
<strong>Output: </strong>true<strong>
Explanation: </strong>XXY is interleaving of XY and X.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>s1 = "ABAA", s2 = "ABCA", s3 = "ABACABAA"
<strong>Output: </strong>true</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ s1.length, s2.length ≤ 300<br>1 ≤ s3.length ≤ 600</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>FactSet</code>&nbsp;<code>Google</code>&nbsp;<code>Zillious</code>&nbsp;<code>Yahoo</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;