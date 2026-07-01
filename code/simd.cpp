void vector_dot_product(const int16_t *pSrc1, const int16_t *pSrc2, int32_t *pDest, const size_t len) {
	*pDest = 0;
	for(size_t i=0; i<len; ++i){
		*pDest += (int32_t)(pSrc1[i])*(int32_t)(pSrc2[i]);
	}

	*pDest = 0;
	const int32_t *const pS1Vec = reinterpret_cast<const int32_t *const>(pSrc1);
	const int32_t *const pS2Vec = reinterpret_cast<const int32_t *const>(pSrc2);
	for(size_t i=0; i<(len>>1); ++i){
		*pDest = __SMLAD(pS1Vec[i], pS2Vec[i], *pDest);
	}// Do the rest with iterative loop, if length is not a factor of 4.
	for(size_t i=len&(~0b1U); i<len; ++i){
		*pDest += (uint32_t)(pSrc1[i]) * (uint32_t)(pSrc2[i]);
	}
}
// TODO : Maybe make it more compact by removing all the consts