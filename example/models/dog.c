/**
 * Implementation of the DOG stuff!
 *
 * All internal stuff (defined as static) takes the _ prefix.
 */

#include "dog.h"

static void _speak(Dog* dog)
{
	printf("%s\n", "My name is:");
	printf("%s\n", dog->name);
	printf("%s\n", "Wooof!");
}

static void _destroy(Dog* dog)
{
	if (dog != NULL){
		free(dog);
		dog = NULL;
	}
}

/**
 * Observer Method called upon the receiption of an incoming event.
 * @param type
 * @param subject
 */
static void _notify(Dog* this, int numero, void* observable) {
/*	switch (type) {
	case PRINTER:
		_handle_printer_event(this, (Printer*)observable);
		break;
	default:
		break;
	}*/

	printf("%s\n", "BATEU NOTIFY DO CAO");
}


Dog* DOG_create(char* dogsName)
{
	Dog* this = (Dog*) malloc(sizeof(this));

	this->name = dogsName;
	this->speak = _speak;
	this->destroy = _destroy;
	this->observer = observerNew(this, (void (*)(void*, int, void*))_notify);
	return this;
}

