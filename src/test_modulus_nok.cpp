#include "static_modexp.hpp"

int main(void)
{
    // bad modulus test
    __attribute__ ((unused)) constexpr auto modulus_nok1 = power_mod(INIT_ARGS(9643209, 90874, 0));
    __attribute__ ((unused)) constexpr auto modulus_nok2 = power_mod(INIT_ARGS(9643209, 90874, 8706423060));
    
    return 0;
}
