<h2><a href="https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1?page=3&category%5B%5D=Dynamic%20Programming&sortBy=">Wildcard Pattern Matching</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given two strings</span><span style="font-size: 18px;">&nbsp;</span><strong style="font-size: 18px;">pat&nbsp;</strong><span style="font-size: 18px;">and&nbsp;</span><strong style="font-size: 18px;">txt</strong><span style="font-size: 18px;"> which may be of different sizes, You have to return <strong>true</strong> if the wildcard pattern i.e. <strong>pat,&nbsp;</strong>matches&nbsp;with&nbsp;<strong>txt</strong> else return <strong>false</strong>. All characters of the string&nbsp;<strong>pat</strong> and <strong>txt</strong> always belong to the Alphanumeric characters</span><span style="font-size: 18px;">.</span></p>
<p><span style="font-size: 18px;">The wildcard pattern&nbsp;<strong>pat</strong>&nbsp;can include the characters '<strong>?</strong>' and '<strong>*</strong>'.<br>'<strong>?</strong>' – matches any single character.<br>'<strong>*</strong>' – matches any sequence of characters (including the empty sequence).</span></p>
<p><span style="font-size: 18px;">Note:<strong>&nbsp;</strong>The matching should cover the entire&nbsp;<strong>txt</strong>&nbsp;(not partial&nbsp;<strong>txt</strong>).</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> txt = "abcde", pat = "a?c*"
<strong>Output:</strong> true
<strong>Explanation: </strong>'?' matches with 'b' and '*' matches with "de".
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> txt = "baaabab", pat = "a*ab"
<strong>Output:</strong> false
<strong>Explanation</strong>: Because in string <strong>pat</strong> character 'a' at first position, <strong>pat</strong> and <strong>txt</strong> can't be matched.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input</strong>: txt = "abc", pat = "*"
<strong>Output:</strong> true
<strong>Explanation</strong>: '*' matches with whole text "abc".</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= txt.size(),pat.size() &lt;= 200</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Zoho</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Ola Cabs</code>&nbsp;<code>Walmart</code>&nbsp;<code>Google</code>&nbsp;<code>InMobi</code>&nbsp;<code>United Health Group</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Recursion</code>&nbsp;<code>Strings</code>&nbsp;