# Competitive Programming

Practice solutions in C++, one file per problem, grouped by site.

```
cses/         CSES Problem Set
codeforces/   Codeforces
usaco/        USACO contests (bronze/, silver/) and training gateway (training/)
misc/         everything else
template.cpp  starting file
```

Compile and run (Homebrew GCC; Apple clang has no `bits/stdc++.h`):

```sh
g++-16 -std=c++20 -O2 -Wall -fsanitize=address,undefined file.cpp && ./a.out < input.txt
```

Resources: [USACO Guide](https://usaco.guide), [Competitive Programmer's Handbook](https://cses.fi/book/book.pdf), [cp-algorithms](https://cp-algorithms.com).
