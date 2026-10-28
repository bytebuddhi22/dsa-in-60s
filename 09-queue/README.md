# #09 Queue: FIFO + Circular Queue

▶ Watch on [YouTube](https://www.youtube.com/@ByteBuddhi) · [Instagram](https://www.instagram.com/bytebuddhi/)

> Ticket line mein jo pehle aaya, wahi pehle gaya. Array mein shift karoge toh 10 lakh moves. Trick: Circular Queue, koi shift nahi.

## Idea
- Queue = FIFO (first in, first out). Stack tha LIFO (#05)
- Enqueue at **rear**, dequeue from **front**, dono O(1)
- Array ke aage se nikaala toh baaki sab shift: 10 lakh moves. Trick: front aur rear ko ghumao
- `rear = (rear + 1) % N`: end ke baad waapas slot 0 pe

## Example from the video
- Size 5 ring: A B C aaye (front 0, rear 2), A B gaye (front 2)
- D, E aaye (rear 4), phir F: `(4 + 1) % 5 = 0` → F slot 0 mein, **ghoom kar waapas**
- Order out: C D E F, koi shift nahi

## Complexity
- Enqueue / dequeue: **O(1)**
- Space: O(N) fixed

## Where it's used
- Printer jobs, OS scheduling, message queues, and BFS (#11)

## Code
- [circular_queue.cpp](circular_queue.cpp): the STL `queue<int>` code from the video is in `main()`; `CircularQueue` is the ring
- [circular_queue.py](circular_queue.py): Python version
- Tests: [test_circular_queue.cpp](test_circular_queue.cpp), [test_circular_queue.py](test_circular_queue.py)

## Practice
- [LeetCode 232: Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
- [LeetCode 622: Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
- [LeetCode 933: Number of Recent Calls](https://leetcode.com/problems/number-of-recent-calls/)
