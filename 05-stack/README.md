# #05 Stack: Valid Parentheses

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Undo = Stack. Plates ka dher: last in, first out. Interview ka favourite sawaal: ye brackets valid hain?

## Idea
- Stack = LIFO. Push / Pop, dono O(1)
- Opening bracket → push. Closing bracket → top se match? pop : invalid
- End mein stack khaali → valid

## Example from the video
- `{[()]}`: push `{ [ (`, then `)` `]` `}` each match the top and pop → stack empty → **valid**
- `(]`: `]` doesn't match `(` → **invalid**
- `(()`: one `(` left on the stack → **invalid**

## Complexity
- Time: **O(n)**
- Space: O(n) for the stack

## Code
- [valid_parentheses.cpp](valid_parentheses.cpp): the video's code, plus the `open(c)` helper the video only describes in a comment
- [valid_parentheses.py](valid_parentheses.py): Python version
- Tests: [test_valid_parentheses.cpp](test_valid_parentheses.cpp), [test_valid_parentheses.py](test_valid_parentheses.py)

## Practice
- [LeetCode 20: Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- [LeetCode 155: Min Stack](https://leetcode.com/problems/min-stack/)
- [LeetCode 739: Daily Temperatures](https://leetcode.com/problems/daily-temperatures/) (monotonic stack)
