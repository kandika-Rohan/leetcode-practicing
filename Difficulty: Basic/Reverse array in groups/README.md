<h2><a href="https://www.geeksforgeeks.org/problems/reverse-array-in-groups0255/1?page=3&sortBy=submissions">Reverse array in groups</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array <strong>arr </strong>of positive integers. Reverse every sub-array group of size <strong>k.</strong></span></p>
<p><span style="font-size: 18px;"><em>Note: </em>If at any instance, k is greater or equal to the array size, then reverse the entire array. You shouldn't return any array, modify the given array in place.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>k = 3, arr= [1, 2, 3, 4, 5]
<strong>Output:</strong> [3, 2, 1, 5, 4]<strong>
Explanation: </strong>First group consists of elements 1, 2, 3. Second group consists of 4,5.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>k = 5, arr = [5, 6, 8, 9]
<strong>Output: </strong>[9, 8, 6, 5]<br><strong>Explnation: </strong>Since k is greater than array size, the entire array is reversed.</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size(), k ≤ 10<sup>7</sup><br>1 ≤ arr[i] ≤ 10<sup>18</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;