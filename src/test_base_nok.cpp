#include "static_modexp.hpp"

int main(void)
{
    // bad base test
    __attribute__((unused)) constexpr auto base_nok1 = power_mod(INIT_ARGS(0, 123456, 469364987));
    __attribute__((unused)) constexpr auto base_nok2 = power_mod(INIT_ARGS(3247863243, 123456, 469364987));
    
    return 0;
}
