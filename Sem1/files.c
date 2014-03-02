#include <stdio.h>

// file to operate on
#define path "some.txt"
#define path2 "lorem.txt"

int main()
{
	// a pointer to our file
	FILE *f;

	// create an empty file
	if (f = fopen(path, "w")) // shorthand for: f = fopen(...); if (f != NULL) ...;
		fclose(f);

	// writing values 0-9 to file, a = appending
	if (f = fopen(path, "a"))
	{
		int i;

		for (i = 0; i < 10; ++i)
			fprintf(f, "%d\n", i);

		fclose(f);
	}

	// read and print numbers from file
	if (f = fopen(path, "r"))
	{
		int i;

		while (!feof(f)) // while end not reached
			if (fscanf(f, "%d", &i)) // if fscanf returned more than 0
				printf("%d\n", i); // print

		fclose(f);
	}

	// word count
	if (f = fopen(path2, "r"))
	{
		int count = 0;

		while (!feof(f)) // didn't we reach end of file?
			if (fgetc(f) == ' ') // if character is space
				++count; // increment counter

		fclose(f);

		// we have to ++count because there are s+1 words in file where s is the count of spaces
		printf("There are %d words in %s.\n", ++count, path2);
	}

	// terminate successfully
	return 0;
}
