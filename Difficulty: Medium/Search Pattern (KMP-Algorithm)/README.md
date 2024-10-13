<h2><a href="https://www.geeksforgeeks.org/problems/search-pattern0205/1?page=1&category=Strings&difficulty=Medium&status=unsolved&sortBy=submissions">Search Pattern (KMP-Algorithm)</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings, one is a text string,&nbsp;<strong>txt</strong> and the other is a pattern string, <strong>pat</strong>. The task is to print the indexes of <strong>all the occurrences</strong> of pattern string in the text string. Use one-based indexing while returning the indices.&nbsp;<br><strong>Note:&nbsp;</strong>Return an empty list in case of no occurences of pattern. The driver will print -1 in this case.<br></span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>txt = "geeksforgeeks", pat = "geek"
<strong>Output:</strong> 1 9
<strong>Explanation</strong>: The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. </span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: txt = "abesdu", pat = "edu"
<strong>Output:</strong> -1
<strong>Explanation</strong>: There's not substring "edu" present in txt.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(txt.size()).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(txt.size()).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ txt.size() ≤ 10<sup>6</sup><br>1 ≤ pat.size() &lt; txt.size()<br>Both the strings consist of lowercase English alphabets.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Pattern Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;