<h2><a href="https://www.geeksforgeeks.org/problems/repeated-string-match--141631/0">Repeated String Match</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings <strong>a</strong> and <strong>b</strong>, find the minimum number of times <strong>a</strong> has to be repeated such that <strong>b</strong> becomes a substring of the repeated <strong>a</strong>. If <strong>b</strong> cannot be a substring of <strong>a</strong> no matter how many times it is repeated, return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: a</strong> = "abcd", b = "cdabcdab"</span>
<span style="font-size: 18px;"><strong>Output:</strong> 3</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> After repeating a three times, 
we get "abcdabcdabcd".</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: a</strong> = "aa", b = "a"</span>
<span style="font-size: 18px;"><strong>Output:</strong> 1</span>
<span style="font-size: 18px;"><strong>Explanation:</strong> B is already a substring of a.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task: </strong>&nbsp;<br>You don't need to read input or print anything. Complete the function</span> <span style="font-size: 18px;"><strong>repeatedStringMatch()</strong> which takes strings <strong>a</strong> and <strong>b</strong> as input parameters and returns the minimum number of operations to complete the task. If it is not possible then return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(|a| * |b|)<br><strong>Expected Auxiliary Space:</strong> O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |a|, |b| ≤ 4 * 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;