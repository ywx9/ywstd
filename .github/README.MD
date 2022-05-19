YwStandard(YwStd, Ywstd, ywstd) is a dummy of C++ Standard Library.
It is designed to enable comfortable coding with no compiler required.

## Installation

Copy this repository into your include directory.

## Usage

1. Include ywstd headers instead of the Standard headers.

```C++
// Standard
#include <string>
#include <iostream>
int main() {
  std::cout << "Hello World."s << std::endl;
}

// Ywstd
#include "ywstd/string.hh"
#include "ywstd/iostream.hh"
int main() {
  std::cout << "Hello World."s << std::endl;
}
```

2. Define `_ywstd_` macro at compiling.
   Then, ywstd headers are replaced with compiler-specific ones.
