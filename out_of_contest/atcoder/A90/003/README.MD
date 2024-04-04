# [Longest Circular Road (4 stars)](https://atcoder.jp/contests/typical90/tasks/typical90_c)
There are N cities, each of which is numbered from 1 to N. There are also N-1 roads, the first ($1 \le i \le N-1$) connecting a city, can and city in both directions. All cities can be reached via several roads. \
Now, you are free to choose an integer floor (1 mi company kuru) and build only one new road connecting city u and city v in both directions. The score is then the value defined below. \
Output the maximum possible value of the score for the number of roads taken (this value can only be one) on the path from one city back to the same city without taking the same road twice.

# Constraints
- $3 \le N \le 100,000$
- $1 \le A_i < B_i \le N (1 \le i \le N - 1)$
- Several roads can be used to travel between any of the cities
- All inputs given are integers