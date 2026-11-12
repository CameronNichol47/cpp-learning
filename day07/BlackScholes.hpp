#pragma once
#include "OptionParameters.hpp"

double d1(const OptionParameters& option);
double d2(const OptionParameters& option);
double normal_cdf(double x);
double black_scholes_call(const OptionParameters& option);
double black_scholes_put(const OptionParameters& option);
bool check_put_call_parity(const OptionParameters& option);