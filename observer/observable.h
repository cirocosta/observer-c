#ifndef OBSERVABLE_H
	#define OBSERVABLE_H
	#include "observer.h"

	/**
	 * The interface for the observable
	 */

	typedef struct __observable
	{
		int type;
		/**
		 * Destructor for the Observable
		 */
		void (*destroy)(struct __observable *);
		/**
		 * Referente to the concrete Observable object
		 */
		void * impl;
		/**
		 * A list of observes have ben are registered for this observable
		 * object.
		 */
		Observer * observers[MAX_OBSERVERS];
		/**
		 * The method that allows observers to register for this
		 * observable object.
		 */
		int (*registerObserver)(struct __observable*, Observer*);
		/**
		 * Lets observes unregister from this observable
		 */
		int (*unregisterObserver)(struct __observable *, Observer*);
		/**
		 * When fired, triggers notify method of all of the registered
		 * observers.
		 */
		void (*notifyObservers)(struct __observable*);
	} Observable;

	/**
	 * Constructor for the Observable
	 */
	Observable * observableNew(void*, int);

#endif
