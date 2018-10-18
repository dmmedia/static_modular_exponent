#pragma once

/**
 * \file static_modexp.hpp
 * \brief Compile-time exponent module calculation
 *
 * This file contains a function \a power_mod which is able to calculate an
 * exponent module during compilation time.
 * Utility macro \a INIT_ARGS helps to initialize function parameters easily.
 */

#include <assert.h>
#include <tuple>

/**
 * \def INIT_ARGS(B, P, M)
 * \brief packs parameters into an std::tuple and into lambda expression
 * \param B Base number
 * \param P Power to raise the base to
 * \param M Modulus
 */
#define INIT_ARGS(B, P, M) []{return std::make_tuple<u_int32_t>(B, P, M);}

/**
 * \fn power_mod(args)
 * \brief Calculates an exponent module at compilation time
 * \param args Lambda expression, wrapping std::tuple returning expression with three u_int32_t values: base, power and modulus
 *
 * Function power_mod() is able to perform compile-time modular exponentiation
 * which reduces run-time computation overhead.
 * Macro \a INIT_ARGS can be used for convenienlty passing values to this function.
 * Values are limited as follows:
 * Base and modulus should be greater than 0 and less than 10^9
 * Power should be greater than 0 and less than 10^6
 *
 * Example usage:
 *	auto result = power_mod(INIT_ARGS(98634296, 43280, 643026));
 */
template<class ArgsType>
constexpr auto power_mod(const ArgsType args) {
    constexpr auto bv = std::get<0>(args());
    static_assert(bv > 0, "Base should be greater than zero");
    static_assert(bv < 1000000000, "Base should be less than 1 000 000 000");
	
    constexpr auto pv = std::get<1>(args());
    static_assert(pv > 0, "Power should be greater than zero");
    static_assert(pv < 1000000, "Power should be less than 1 000 000");
	
    constexpr auto mv = std::get<2>(args());
    static_assert(mv > 0, "Modulus should be greater than zero");
    static_assert(mv < 1000000000, "Modulus should be less than 1 000 000 000");
	
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
