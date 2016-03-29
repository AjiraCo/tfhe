#ifndef LWE_H
#define LWE_H

#define EXPORT extern "C"

struct LWEParams;

struct LWEKey;

struct LWESample;

struct LWEKeySwitchKey;

struct RingLWEParams;

struct RingLWEKey;

struct RingLWESample;

struct RingGSWParams;

struct RingGSWKey;

struct RingGSWSample;

struct LWEBootstrappingKey;

EXPORT void lweKeyGen(LWEKey* result, const LWEParams* params);
EXPORT void lweSymEncrypt(LWESample* result, double message, const LWEKey* key);
EXPORT double lweSymDecrypt(const LWESample* sample, const LWEKey* key);

EXPORT void lweLinearCombination(LWESample* result, const int* combi, const LWESample* samples, const LWEParams* params);

EXPORT void lweKeySwitch(LWESample* result, const LWEKeySwitchKey* ks, const LWESample sample);

// Ring
EXPORT void ringLweKeyGen(LWEKey* result);
EXPORT void ringLweSymEncrypt(LWESample* result, double message, const LWEKey* key);
EXPORT double ringLweSymDecrypt(const LWESample* sample, const LWEKey* key);

EXPORT void ringLwePolyCombination(LWESample* result, const int* combi, const LWESample* samples, const LWEParams* params);

// GSW
EXPORT void ringGswKeyGen(LWEKey* result);
EXPORT void ringGswSymEncrypt(LWESample* result, double message, const LWEKey* key);
EXPORT double ringGswSymDecrypt(const LWESample* sample, const LWEKey* key);

EXPORT void ringGswPolyCombination(LWESample* result, const int* combi, const LWESample* samples, const LWEParams* params);

//extractions Ring LWE -> LWE
EXPORT void keyExtract(LWEKey* result, const RingLWEKey*); //sans doute un param supplémentaire
EXPORT void sampleExtract(LWESample* result, const RingLWESample* x);

//extraction RingGSW -> GSW
EXPORT void gswKeyExtract(RingLWEKey* result, const RingGSWKey* key); //sans doute un param supplémentaire
EXPORT void gswSampleExtract(RingLWESample* result, const RingGSWSample* x);

//bootstrapping
EXPORT void bootstrap(LWESample* result, const LWEBootstrappingKey* bk, double mu1, double mu0, const LWESample* x);

#endif //LWE_H
