#include "static_modexp.hpp"
#include <iostream>

int main(void)
{
//    constexpr auto args = make_args(131999920, 234979, 991540365);
    constexpr auto e = power_mod(INIT_ARGS(131999920, 234979, 991540365));
    static_assert(e == 682771105);
    return 0;
}
