#ifndef OBSERVER_H
	#define OBSERVER_H
	#include "common.h"
	/**
	 * Defining a 'interface-a-like' for the observer
	 */

	typedef struct __observer {
		void (*destroy)(struct __observer *);
		void* impl;
		void (*notify)(struct __observer*, int, void *);
		void (*notifyImpl)(void*, int, void*);
	} Observer;


	/**
	 * Constructor, allocate memory and set up credentials.
	 * @param vendor name of the observer manufacturer
	 * @param serial serial number
	 * @return an instance of Observer
	 */
	Observer * observerNew(void*, void (*)(void*, int, void*));

#endif
