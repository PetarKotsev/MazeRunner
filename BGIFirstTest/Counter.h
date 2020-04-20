#pragma once
static unsigned int __counter = 0;

int incrGlobalCounter() {
	if (__counter + 1 > UINT_MAX) {
		__counter = 0;
		return 0;
	}
	return ++__counter;
}

int getGlobalCounter() {
	return __counter;
}