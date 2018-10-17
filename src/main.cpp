#include "static_modexp.hpp"
#include <iostream>

int main(void)
{
//    std::cout << calculateModularExponent(131999920, 234979, 991540365);
    std::cout << calculateModularExponent(20, 23, 65) << std::endl;
//    std::cout << powermod(20, 23, 65) << std::endl;
//    std::cout << powermod(131999920, 234979, 991540365);
    constexpr u_int32_t e = powermod(131999920, 234979, 991540365);
    static_assert(e == 682771105);
    return 0;
}
