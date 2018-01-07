#include <array>
#include "example.h"

/** Compute a dot product of 2 vectors */
float dot_product(vec4_t a, vec4_t b){
	return dot_product_impl(a, b)
}

#ifdef ACCELERATED
//SSE2 version of dot product
inline float dot_product_impl(vec4_t a, vec4_t b){
	
}

#else

//default implementation with no hardware acceleration
inline float dot_product_impl(vec4_t a, vec4_t b){
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3]; 
}
#endif
