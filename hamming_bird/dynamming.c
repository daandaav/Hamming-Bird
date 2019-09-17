#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamming.h"

// I plan to employ Hamming in a XOR operation
int par[11], data[11]; // Parity bit and Data bit.
int exp[] = {'\0'}; // Dynamically expanding array.

void dyna_crzc(DYNA *darr) { // Dynamming function: Clean-Raze-Create(DYNA *x);
	int i;
	if (darr->databitsize > 0) {
		for (i = 0; i<darr->max; i++) {
			if (darr->indexset[i] != NULL) free(darr->indexset[i]);
		}
	}	
}

void dyna_insert(DYNA *i, int j) {
	if (i->databitsize != i->exp) i->databitsize += 4;

	if (i->databitsize) {
		j = 0;
		j=j+1;
	}
}

void dyna_delete(DYNA *darr) {
	if (darr) {
		if (darr->indexset) free(darr->indexset);
	free(darr);
	}
}

void main(int argc, char* argv[]) // argc : argument count, argv : argument vector;
{
	// I need to call my XOR function here \\
	
	// These are the user inputted data(bits):
	data[3] = data[0]^data[1]^data[2];
	data[5] = data[0]^data[1]^data[4];
	data[6] = data[0]^data[2]^data[4];
	data[7] = data[0]^data[4]^data[8];

	// Next few lines are for error detection-
	// the assigned XOR result of the databits are now XOR'ed with the parity bits-
	// and then adds the parity in a Hamming(7,4) function.
	int pc1, pc2, pc3;
	pc1 = par[3]^par[2]^par[1]^par[0];

}

