/**
 * Main program that uses the Observer implementation.
 */

#include <stdio.h>
#include "models/cat.h"
#include "models/dog.h"

/**
 * Defining the basic DOG class/interface-a-like
 */

int main(int argc, char const *argv[])
{

	Cat* hopkins = CAT_create("Hopkins");
	Dog* alfred = DOG_create("Alfred");

	alfred->smell(alfred, hopkins);
	hopkins->speak(hopkins);

	hopkins->destroy(hopkins);
	alfred->destroy(alfred);

	return 0;
}
