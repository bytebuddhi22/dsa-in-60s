# #06 Recursion

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> 4! = 4 × 3!. Badi problem, usi ke chhote version se. Base case bhool gaye toh Stack Overflow.

## Idea
- `fact(n) = n × fact(n − 1)`
- Do rules: **base case** (kab rukna hai) + **smaller problem** (har call thodi chhoti)
- Call stack: neeche jao, base case pe ruko, wapas aate hue answer banao

## Example from the video
`fact(4)` → `fact(3)` → `fact(2)` → `fact(1)` = 1 (base case), then back up:
2 × 1 = 2 → 3 × 2 = 6 → 4 × 6 = **24**

Without the base case: fact(0), fact(−1), … forever → **stack overflow**.

## Complexity
- Time: **O(n)** (n calls)
- Space: O(n) call stack
- `long long` holds up to 20! = 2,432,902,008,176,640,000. `fact(21)` overflows.

## Code
- [recursion.cpp](recursion.cpp): the video's code
- [recursion.py](recursion.py): Python version
- Tests: [test_recursion.cpp](test_recursion.cpp), [test_recursion.py](test_recursion.py)

## Practice
- [LeetCode 509: Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
- [LeetCode 206: Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/) (solve it recursively)
- [LeetCode 70: Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
