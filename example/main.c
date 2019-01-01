/* main.c */

/* Example of the Observer implementation */

#include <stdio.h>
#include "cat.h"
#include "dog.h"

int main()
{
	Cat *hopkins = cat_make("Hopkins");
  Dog *alfred = dog_make("Alfred");

  subject_attach(hopkins->theSubject, alfred->theObserver);

	cat_speak(hopkins);

	cat_destroy(hopkins);
  dog_destroy(alfred);

  return 0;
}
