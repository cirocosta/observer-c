/* cat.h */

#ifndef CAT_H
#define CAT_H

/*#include "../observer/observer.h"
#include "../observer/subject.h"
*/

/*
  typedef enum __cat_event
  {
    SPEAK
  } CatEvent;
*/

typedef struct cat
{
  char* name;
} Cat;

Cat *cat_make(const char * const name);
void cat_destroy(Cat *theCat);

void cat_speak(const Cat * const theCat);

/*

CatEvent event;
CatEvent (*getEvent)(struct __cat*);


Subject * subject;
int (*registerObserver)(struct __cat*, Observer*);
int (*unregisterObserver)(struct __cat *, Observer*);

*/

#endif
