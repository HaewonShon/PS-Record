# [Gold III] Secrets of Legendary Treasure - 21927 

[문제 링크](https://www.acmicpc.net/problem/21927) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2024년 9월 18일 02:48:26

### 문제 설명

<p>Finally, you have discovered the document with two integer sequences, the final keys to unlocking the secret of the legendary treasure! The ink on the document, however, has faded so much that some of the numbers in the sequences are too faint to read. Fortunately, you have heard of a legend on the characteristics of the key sequences that (1) the numbers in the two sequences are all different and are between 1 and the sum of the lengths of the two sequences, and (2) both sequences are arranged in ascending order.</p>

<p>Please restore the original sequences from the readable numbers and the legend.</p>

### 입력 

 <p>The input consists of a single test case of the following format.</p>

<pre>n m
a<sub>1</sub> . . . a<sub>n</sub>
b<sub>1</sub> . . . b<sub>m</sub></pre>

<p>The first line consists of two integers n (1 ≤ n ≤ 100) and m (1 ≤ m ≤ 100). They are the lengths of the two sequences A and B, respectively. The second line describes the sequence A. Each a<sub>i</sub> is either 0, meaning that the i-th element of A is unreadable, or a positive integer 1 ≤ a<sub>i</sub> ≤ n + m meaning that the element reads a<sub>i</sub>. The third line describes the sequence B in the same fashion.</p>

### 출력 

 <p>Print a pair of restored sequences A and B in two lines. The sequences should be consistent with the input and the legendary characteristics of the sequences.</p>

<p>The elements of the sequence A should be printed in the first line, separated by a space character. Then the elements of the sequence B should be printed in the second line, in the same manner.</p>

<p>If there are multiple possibilities, print any one of such pairs. At least one sequence pair consistent with the input and conforming to the legend is guaranteed to exist.</p>

