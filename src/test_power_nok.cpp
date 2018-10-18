#include "static_modexp.hpp"

int main(void)
{
    // bad power test    
    __attribute__ ((unused)) constexpr auto power_nok1 = power_mod(INIT_ARGS(8756234, 0, 94632898));
    __attribute__ ((unused)) constexpr auto power_nok2 = power_mod(INIT_ARGS(8756234, 7896278, 94632898));
    
    return 0;
}
