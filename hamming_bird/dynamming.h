#ifndef _DYNAMMING_H_
#define _DYNAMMING_H_

#include <stdlib.h>
#include "fmwk/minunit.h"

typedef struct DYNA {
	int darr, exp; // Integer: Dynamic Array, Expansion
	size_t min, max;
	size_t end;
	size_t databitsize, paritysize;
	void **indexset; // Pointer to Pointer, used for larger/longer characters/values;
} DYNA;

DYNA *HMMI_CREATE(int databitsize, int paritysize); // Hamming Code - Bit code create!

int HMMI_INPUT(DYNA * burst);
int HMMI_DELETE(DYNA * burst);
void HMMI_ERASE(DYNA * burst);
void HMMI_CLEAN(DYNA * burst);
void HMMI_NUKE(DYNA * burst);

#define DYNA_LAST(A) ((A)->data[(A)->end - 1])
#define DYNA_FIRST(A) ((A)->data[0])
#define DYNA_END(A) ((A)->end)
#define DYNA_COUNT(A) DYNA_END(A)
#define DYNA_MAX(A) ((A)->max)

#define DEFAULT_EXPAND_RATE	300

static inline void DYNA_SET(DYNA * burst, int i, void *l)
{
	check(i < burst->max, "Trying to set past max.");
	if (i > burst->end)
		burst->end = i;
	burst->indexset[i] = l;
error:
	return;
}

static inline void *DYNA_GET(DYNA * burst, int i)
{
	check(i < burst->max, "Attempting to get past max.");
	return burst->indexset[i];
error:
	return NULL;
}

static inline void *DYNA_REMOVE(DYNA * burst, int i)
{
	void *l = burst->indexset[i];
	burst->indexset[i] = NULL;
	return l;
}

static inline void *DYNA_NEW(DYNA * burst)
{
	check(burst->databitsize > 0,
			"Can't use _NEW fucntion on 0 sized databits.");
	return calloc(1, burst->databitsize);
error:
	return NULL;
}

#define DYNA_FREE(E) free((E))

#endif
