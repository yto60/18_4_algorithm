#include "header.h"

void sort(Item a[], int l, int r) {
	int i;

	for (i = r; i > l; i--) {
		compexch(a[i - 1], a[i]); // put the smallest into first position
	}
	for (i = l + 2; i <= r; i++) {
		int j = i;
		Item v = a[i];

		while (less(v, a[j - 1])) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}