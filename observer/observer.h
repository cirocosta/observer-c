#ifndef OBSERVER_H
	#define OBSERVER_H
	#include "common.h"
	/**
	 * Defining a 'interface-a-like' for the observer
	 */

	typedef struct __observer {
		/**
		 * Method for performing garbage collection
		 */
		void (*destroy)(struct __observer *);
		/**
		 * A reference to the concrete OBSERVER
		 */
		void* impl;
		/**
		 * A method that any subject is able to trigger
		 */
		void (*notify)(struct __observer*, int, void *);
		/**
		 * The notify implementation (the actual function that is going to
		 * be triggered)
		 */
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
