<h2><a href="https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article">Count Palindrome Sub-Strings of a String</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a string <strong>s</strong>, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2.&nbsp;</span></p>
<p><span style="font-size: 14pt;"><strong>Note:&nbsp; </strong>The string contains only lowercase english characters.</span></p>
<p><span style="font-size: 18px;"><strong>Example</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>
n = 5
s = "abaab"
<strong>Output</strong>
3
<strong>Explanation</strong>:
All palindromic substrings are : "aba" , "aa" , "baab"<br></span></pre>
<p><strong><span style="font-size: 18px;">Example</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>
n = 7
s = "abbaeae"
<strong>Output</strong>
4
<strong>Explanation</strong>:
All palindromic substrings are : "bb" , "abba" , "aea", "eae"<br><br></span></pre>
<p style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;"><span style="font-size: 18px;"><strong style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: 18px; white-space: normal;">Your Task:&nbsp;&nbsp;</strong><br><span style="font-size: 18px;">You don't need to read input or print anything. Your task is to complete the function CountPS() which takes a string and n, the length of the string, as input and returns the count of all palindromic sub-string of string which length is greater than 1.</span><br></span></p>
<p style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;">&nbsp;</p>
<p style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;"><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong>&nbsp;O(|s|<sup>2</sup>)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(</span><span style="font-size: 18px;">|s|</span><sup>2</sup><span style="font-size: 18px;">)</span></p>
<p style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;">&nbsp;</p>
<p style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif; font-size: medium; white-space: normal;"><span style="font-size: 18px;"><strong>Constraints:</strong><br>2 ≤ </span><span style="font-size: 18px;">|s|</span><span style="font-size: 18px;"> ≤ 500</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>SAP Labs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;