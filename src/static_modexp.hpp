#pragma once

#include <cmath>
#include <assert.h>

long double calculateModularExponent(const u_int32_t b, const u_int32_t p, const u_int32_t m)
{
    return fmod(pow((long double)b, (long double)p), (long double)m);
}

u_int32_t powermod(const u_int32_t b, const u_int32_t p, const u_int32_t m)
{
    // check ranges
    assert(b > 0);
    assert(b < 1000000000u);
    
    assert(p > 0);
    assert(p < 1000000u);
    
    assert(m > 0);
    assert(m < 1000000000u);
    
    u_int64_t res = 1u;
    u_int64_t tmp = b % m;
    u_int32_t power = p;
    while (power != 0)
    {
	if (power & 1u)
	{
	    res = (res * tmp) % m;
	}
	tmp = (tmp * tmp) % m;
	power >>= 1;
    }
    
    return res;
}
