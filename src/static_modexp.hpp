#pragma once

#include <cmath>

long double calculateModularExponent(const u_int32_t b, const u_int32_t p, const u_int32_t m)
{
    return fmod(pow((long double)b, (long double)p), (long double)m);
}
