#ifndef SUBJECT_H
	#define SUBJECT_H
	#include "observer.h"

	/**
	 * The interface for the subject
	 */

	typedef struct __subject
	{
		int type;
		/**
		 * Destructor for the Subject
		 */
		void (*destroy)(struct __subject *);
		/**
		 * Referente to the concrete Subject object
		 */
		void * impl;
		/**
		 * A list of observes have ben are registered for this subject
		 * object.
		 */
		Observer * observers[MAX_OBSERVERS];
		/**
		 * The method that allows observers to register for this
		 * subject object.
		 */
		int (*registerObserver)(struct __subject*, Observer*);
		/**
		 * Lets observes unregister from this subject
		 */
		int (*unregisterObserver)(struct __subject *, Observer*);
		/**
		 * When fired, triggers notify method of all of the registered
		 * observers.
		 */
		void (*notifyObservers)(struct __subject*);
	} Subject;

	/**
	 * Constructor for the Subject
	 */
	Subject * subjectNew(void*, int);

#endif
