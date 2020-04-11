# Modular
---
(a + b) mod m = (a mod m + b mod m) mod m
(a - b) mod m = (a mod m - b mod m) mod m
(a * b) mod m = (a mod m * b mod m) mod m

# Floating Point
---
> Due to precision issue, comparing floating point directly could cause issue
```cpp
if (std::abs(a-b) < 1e-9) {
    // a and b are equal
}
```

# Type Names
---
```cpp
typedef long long int ll;
typedef std::vector<int> vi;
typedef std::pair<int, int> pi;
```

# Marcos
---
```cp
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
```

# Maths
---
- Arithmetic Sequence Sum: n(a+b) / 2
- Geometric Sequence Sum: n(n+1)(2n+1) / 
- TBC

# Complexity Classes
---
> O(1) : The running time of a constant-time algorithm does not depend on the
input size. A typical constant-time algorithm is a direct formula that
calculates the answer

> O(log n): A logarithmic algorithm often halves the input size at each step. The
running time of such an algorithm is logarithmic, because log 2 n equals the
number of times n must be divided by 2 to get 1.

> O(sqrt(n)): A square root algorithm is slower than O (log n) but faster than O (n). A special property of square roots is that n = n / n , so the square root n lies, in some sense, in the middle of the input.



