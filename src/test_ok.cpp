#include "static_modexp.hpp"

int main(void)
{
    // good test
    constexpr auto ok = power_mod(INIT_ARGS(131999920, 234979, 991540365));
    static_assert(ok == 682771105, "Internal calculation is wrong");
    
    return 0;
}
