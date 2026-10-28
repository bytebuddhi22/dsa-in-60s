# #07 Hashing: Two Sum

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Two Sum, 10 lakh numbers. Do loops = 4,99,99,95,00,000 pair checks. Hashing: har number ek baar dekho, aur pucho "mujhe kya chahiye?" Sirf 10 lakh steps.

## Idea
- Hash = number se seedha uska box: `box = number % 7` (real hash maps use a smarter function)
- Har number par: `need = target − a[i]`. Map mein `need` hai? → pair mil gaya
- Nahi hai? → `seen[a[i]] = i` store karo, aage badho

## Example from the video
`[8, 3, 16, 6, 12]`, target 20:
- 8 → need 12, nahi → store 8
- 3 → need 17, nahi → store 3
- 16 → need 4, nahi → store 16
- 6 → need 14, nahi → store 6
- 12 → need 8, **mil gaya** (index 0) → `(0, 4)`

## Complexity
- Lookup: **O(1)** average (worst case O(n), jab sab ek hi box mein)
- Time: **O(n)**, one pass
- Space: O(n) for the hash map

## Code
- [two_sum.cpp](two_sum.cpp): the video's code (`unordered_map<int,int> seen`)
- [two_sum.py](two_sum.py): Python version
- Tests: [test_two_sum.cpp](test_two_sum.cpp), [test_two_sum.py](test_two_sum.py)

## Practice
- [LeetCode 1: Two Sum](https://leetcode.com/problems/two-sum/)
- [LeetCode 217: Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [LeetCode 49: Group Anagrams](https://leetcode.com/problems/group-anagrams/)
