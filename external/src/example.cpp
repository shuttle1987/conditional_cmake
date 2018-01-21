#include <array>
#include "example.h"

/** Compute a dot product of 2 vectors */
float dot_product(vec4_t a, vec4_t b){
	return dot_product_impl(a, b)
}

#ifdef ACCELERATED
//SSE2 version of dot product

//See: https://stackoverflow.com/a/42924346/296460
static inline float CalcDotProductSse(__m128 x, __m128 y) {
    __m128 mulRes, shufReg, sumsReg;
    mulRes = _mm_mul_ps(x, y);

    // Calculates the sum of SSE Register - https://stackoverflow.com/a/35270026/195787
    shufReg = _mm_movehdup_ps(mulRes);        // Broadcast elements 3,1 to 2,0
    sumsReg = _mm_add_ps(mulRes, shufReg);
    shufReg = _mm_movehl_ps(shufReg, sumsReg); // High Half -> Low Half
    sumsReg = _mm_add_ss(sumsReg, shufReg);
    return  _mm_cvtss_f32(sumsReg); // Result in the lower part of the SSE Register
}

inline float dot_product_impl(vec4_t a, vec4_t b){
	__m128 x = _mm_load_ps(&a[0]);	
	__m128 y = _mm_load_ps(&b[0]);	
	return CalcDotProductSse(x, y);
}

#else

//default implementation with no hardware acceleration
inline float dot_product_impl(vec4_t a, vec4_t b){
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3]; 
}
#endif
