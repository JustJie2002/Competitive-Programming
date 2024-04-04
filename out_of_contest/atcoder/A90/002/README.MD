# [Encyclopedia of Parentheses (3 stars)](https://atcoder.jp/contests/typical90/tasks/typical90_b)
Output all correct parentheses sequences of N, in lexicographic order.

However, the correct sequence of parentheses is defined as follows:

- () is a correct sequence of parentheses
- Suppose S is the correct parentheses sequence, the string "(" + S + ")" is a correct sequence of parentheses
- If S, T is a correct sequence of parentheses, then the string S + T is a correct sequence of parentheses
- All other strings are not correct parentheses.

For example,

()()() \
(()())())()) \
()()()()()()()()) \
are all correct parentheses sequences, but

)( \
)))()()((()) \
((((a)))) \
are not correct sequences of parentheses.

# Constraints
- "(" is assumed to be earlier in lexicographic order than ")"
- $1 \le N \le 20$
- N is an integer