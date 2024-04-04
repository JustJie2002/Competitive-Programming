# [CP Classes (3 stars)](https://atcoder.jp/contests/typical90/tasks/typical90_g)
ABC Competitive Programming School has N classes, and the class with number i ($1 \le i \le N$) is for students with rating $A_i$. \
Now, Q students are about to enter the school. The student with the id j ($1 \le j \le Q$) has rating of $B_j$. Each student is dissatisfied if he or she goes to a class at a level that does not suit him or her. For each student, the level of dissatisfaction is defined as the absolute difference between their rating and the class's rating: |a - b| \
For each j=1,2,3,...,Q, find the minimum possible dissatisfaction level for the student with number j. However, it is assumed that it is acceptable to have a class that does not contain any one student, or a class consisting of multiple students.

# Constraints
- $1 \le N \le 300,000$
- $1 \le Q \le 300,000$
- $0 \le A_i \le 10^9$
- $0 \le B_i \le 10^9$
- All given inputs are integers