# **42.push_swap**


Run:
----
- make  *(compiles the program)*
- ./push_swap input   *(where input is a random list of [integers](https://en.wikipedia.org/wiki/Integer))*

-------------------------------------------------------------------

[42 The Network](https://www.42network.org/) Assignment:
-----------
Create an [algorithm](https://en.wikipedia.org/wiki/Algorithm) to sort data.

Requirements:
-------------
You have 2 stacks named **a** and **b**.

At the beginning:
 - Stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
 - Stack **b** is empty.

The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
- **sa** (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
- **sb** (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
- **ss** : **sa** and **sb** at the same time.
- **pa** (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- **pb** (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
- **ra** (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- **rb** (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- **rr** : **ra** and **rb** at the same time.
- **rra** (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb** (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr** : **rra** and **rrb** at the same time.
---
- Allowed external functions: read, write, malloc, free, exit, [ft_printf](https://github.com/Janeway42/42.printf) 
-------------------------------------------------------------------

Code format: 
------------
The code must be written in accordance to the 42 set of norms.  
These include for example a maximum of 25 lines per function, at most 80 columns per line, comments included and a maximum of five functions per file. 

-------------------------------------------------------------------

Usefull info:
------------
[Linked Lists](https://www.youtube.com/watch?v=R9PTBwOzceo&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=31)

-------------------------------------------------------------------
