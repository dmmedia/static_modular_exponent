# Compilation time calculated modular exponent
Function that calculates modular exponent at compile time

Input parameters are limited to the folowing values:

0 < base < 10<sup>9</sup> (1 000 000 000)

0 < power < 10<sup>6</sup> (1 000 000)

0 < modulus < 10<sup>9</sup> (1 000 000 000)

# Example usage:
```c++
#include "static_modexp.hpp"

constexpr auto result = power_mod(INIT_ARGS(8734246, 9786, 5647389));
```

# Running unit tests:
```
cmake .
make test_ok
make test_base_nok
make test_power_nok
make test_modulus_nok
```
