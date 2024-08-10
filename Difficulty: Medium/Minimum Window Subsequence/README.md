<h2><a href="https://www.geeksforgeeks.org/problems/minimum-window-subsequence/0">Minimum Window Subsequence</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p dir="ltr"><span style="font-size: 18px;">Given strings <strong>str1</strong> and <strong>str2</strong>, find the <strong>minimum (contiguous) substring</strong> W of str1, so that str2 is a <strong>subsequence</strong> of W.</span></p>
<p dir="ltr"><span style="font-size: 18px;">If there is <strong>no such window in str1</strong> that covers all characters in str2, return the <strong>empty string</strong> "". If there are <strong>multiple</strong> such minimum-length windows, return the one with the <strong>left-most starting index</strong>.</span><br>&nbsp;</p>
<p dir="ltr"><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> </span>
<span style="font-size: 18px;">str1: geeksforgeeks</span>
<span style="font-size: 18px;">str2: eksrg</span>
<strong><span style="font-size: 18px;">Output: </span></strong>
<span style="font-size: 18px;">eksforg</span>
<strong><span style="font-size: 18px;">Explanation: </span></strong>
<span style="font-size: 18px;">"eksforg" satisfies all required conditions. str2 is its subsequence and it is longest and leftmost among all possible valid substrings of str1.</span>
</pre>
<p dir="ltr"><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> </span>
<span style="font-size: 18px;">str1: <code>abcdebdde</code></span> <br><span style="font-size: 18px;">str2: bde</span> <br><strong><span style="font-size: 18px;">Output: </span></strong> <span style="font-size: 18px;">bcde</span> <br><strong><span style="font-size: 18px;">Explanation: </span></strong> <span style="font-size: 18px;"><code>"bcde" is the answer and "deb" is not a smaller window because the elements in the window must occur in order.</code></span></pre>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong></p>
<p dir="ltr"><span style="font-size: 18px;">Complete the function string minWindow(string str1, string str2), which takes two strings as input and returns the required valid string as output.</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(</span><span style="font-size: 18px;">str1.length *&nbsp;</span><span style="font-size: 18px;">str2.length</span><span style="font-size: 18px;">).</span></p>
<p dir="ltr"><span style="font-size: 18px;"><strong>Expected Auxiliary Space:</strong> O(</span><span style="font-size: 18px;">str1.length *&nbsp;</span><span style="font-size: 18px;">str2.length</span><span style="font-size: 18px;">).</span></p>
<p dir="ltr"><strong><span style="font-size: 18px;">Constraints:</span></strong></p>
<p dir="ltr"><span style="font-size: 18px;">1 &lt;= str1.length &lt;= 10<sup>4</sup></span></p>
<p dir="ltr"><span style="font-size: 18px;">1 &lt;= str2</span><span style="font-size: 18px;">.length</span><span style="font-size: 18px;"> &lt;= 50</span></p>
<p>&nbsp;</p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Arrays</code>&nbsp;<code>Algorithms</code>&nbsp;