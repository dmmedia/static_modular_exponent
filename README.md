# static_modular_exponent
Function that calculates modular exponent at compile time

Input parameters are limited to the folowing values:
b = (0; 10^9)
p = (0; 10^6)
m = (0; 10^9)

# Example usage:
#include "static_modexp.hpp"

constexpr auto result = power_mod(INIT_ARGS(8734246, 9786, 5647389));

# Running unit tests:
cmake .
make test_ok
make test_base_nok
make test_power_nok
make test_modulus_nok
