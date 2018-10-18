//#include "static_modexp.hpp"
#include <iostream>
#include <tuple>

template<class ArgsType>
constexpr auto power_mod(const ArgsType args) {
    constexpr auto bv = std::get<0>(args());
    static_assert(bv > 0);
    static_assert(bv < 1000000000);
	
    constexpr auto pv = std::get<1>(args());
    static_assert(pv > 0);
    static_assert(pv < 1000000);
	
    constexpr auto mv = std::get<2>(args());
    static_assert(mv > 0);
    static_assert(mv < 1000000000);
	
    u_int64_t res = 1u;
    u_int64_t tmp = bv % mv;
    u_int32_t pwr = pv;
	
    while (pwr != 0)
    {
        if (pwr & 1u)
        {
	    res = (res * tmp) % mv;
	}
	tmp = (tmp * tmp) % mv;
	pwr >>= 1u;
    }
	
    return res;
}

constexpr auto make_args = [](const u_int32_t b, const u_int32_t p, const u_int32_t m) constexpr
{
    return std::make_tuple(b, p, m);
};

#define INIT_ARGS(B, P, M) []{return std::make_tuple<u_int32_t>(B, P, M);}
    
int main(void)
{
//    constexpr auto args = make_args(131999920, 234979, 991540365);
    constexpr auto e = power_mod(INIT_ARGS(131999920, 234979, 991540365));
    static_assert(e == 682771105);
    return 0;
}
