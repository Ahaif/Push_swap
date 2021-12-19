# Push_swap
Algorithmetic Project with Language C

Implementation of a non-recursive quick-sort algorithm to sort one stack by use of another stack.

The aim of push swap is to sort a stack of numbers using another stack in the least commands possible. The educational aim of the project was to introduce students to advanced sorting algorithms and the concept of complexity. This project earned maximum available marks for the algortihm's efficacy.

The stacks can be rotated, have their top two elements swapped, or be pushed onto each other, the full command list is as follows:

Rotating commands
RA - rotate stack A (send top number on stack to bottom)
RB - rotate stack B (send top number on stack to bottom)
RR - rotate both stack A and B at the same time
RRA - counter-rotate stack A (send bottom number of stack to top)
RRB - counter-rotate stack B (send bottom number of stack to top)
RRR - counter-rotate stack A and stack B at the same time

Swapping commands
SA - swap top two numbers at top of stack A
SB - swap top two numbers at top of stack B

Pushing commands
PA - push top element from stack A onto stack B
PB - push stack B


Learnings

the stacks are created as double linked list, so I had to develop a strong grasp of list manipulation to managed both the sorting stacks, and also the linked-list stacks I used to mark the partitions.

I learnt about complexity and (O)n notation.

I studied all major sorting algorithms in order to pick the one I felt best fit the task. It was very interesting to get my head around how they working recursively, and particularly enjoyable to then try and figure out how one could dissect the algorithm to perform it iteratively.
