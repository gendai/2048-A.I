/**
 ** \file ./src/rand.hh
 ** \brief The mersenne twister implementation provided at https://en.wikipedia.org/wiki/Mersenne_Twister.
 */

#pragma once

#include <cstdint>

/// Initialize the generator with a seed.
/// \param seed the seed to initialize the generator.
void Initialize(const uint32_t seed);

/// Get a new random value.
/// \return a random value.
uint32_t next_rand();
