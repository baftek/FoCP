#include <stdio.h>

// random, srand:
#include <stdlib.h>

// time:
#include <time.h>

// sqrt:
#include <math.h>

// number of vectors
#define COUNT 5

struct Vector
{
    double x, y, z;
};

// vector passed by reference (operate on original, not copy)
void vec_dump(struct Vector *v)
{
    // v->x is a shorthand for (*v).x
    printf("[%10.2lf, %10.2lf, %10.2lf]", v->x, v->y, v->z);
}

double vec_length(struct Vector *v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

struct Vector* vec_get_longest(struct Vector data[], unsigned count)
{
    unsigned i;
    double max = 0, size;
    struct Vector *longest;

    for (i = 0; i < count; ++i)
        if ((size = vec_length(&data[i])) > max)
        {
            max = size;
            longest = &data[i];
        }

    return longest;
}

int main()
{
    struct Vector vectors[COUNT];
    struct Vector* longest;
    unsigned i;

    srand(time(NULL)); // initialize random number generator with current time

    printf("Vectors:\n");
    for (i = 0; i < COUNT; ++i)
    {
        // fill with random datas
        vectors[i].x = (double) rand() * rand() / RAND_MAX;
        vectors[i].y = (double) rand() * rand() / RAND_MAX;
        vectors[i].z = (double) rand() * rand() / RAND_MAX;

        // show on screen
        printf("Vec%u = ", i);
        vec_dump(&vectors[i]);
        printf(" <len: %10.2lf>\n", vec_length(&vectors[i]));
    }

    longest = vec_get_longest(vectors, COUNT);
    printf("\nLongest vector:\nVecX = ");
    vec_dump(longest);
    printf(" <len: %10.2lf>\n", vec_length(longest));

    return 0;
}
