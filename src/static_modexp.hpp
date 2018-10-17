#pragma once

#include <cmath>
#include <assert.h>

long double calculateModularExponent(const u_int32_t b, const u_int32_t p, const u_int32_t m)
{
    return fmod(pow((long double)b, (long double)p), (long double)m);
}

constexpr u_int32_t powermod(const u_int32_t b, const u_int32_t p, const u_int32_t m)
{
    // init const
    constexpr auto base = b;
    constexpr auto power = p;
    constexpr auto modulo = m;
    
    // check ranges
    static_assert(base > 0);
    static_assert(base < 1000000000u);
    
    static_assert(power > 0);
    static_assert(power < 1000000u);
    
    static_assert(modulo > 0);
    static_assert(modulo < 1000000000u);
    
    u_int64_t res = 1u;
    u_int64_t tmp = base % modulo;
    u_int32_t pwr = power;
    while (pwr != 0)
    {
	if (pwr & 1u)
	{
	    res = (res * tmp) % modulo;
	}
	tmp = (tmp * tmp) % modulo;
	pwr >>= 1;
    }
    
    return res;
}
