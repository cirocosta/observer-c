/**
 * Definition of the DOG class stuff!
 */

#ifndef DOG_H
	#define DOG_H
 	#include <stdio.h>
	#include <stdlib.h>
	#include "../../observer/observer.h"

	typedef enum __dog_event
	{
		SPEAK
	} DogEvent;

	typedef struct __dog
	{
		char* name;
		void (*speak)(struct __dog*);
		void (*destroy)(struct __dog*);

		Observer* observer;
	} Dog;

	/**
	 * Creates a dog!
	 */
	Dog* DOG_create(char *);

#endif
