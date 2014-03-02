#include <stdio.h>

// sqrt
#include <math.h>

// DBL_MAX constant
#include <float.h>

// maximum number of points
#define NUM_POINTS  1000

// actually should not be of TXT extension because of binary mode
#define DATA_FILE   "3d_points.txt"

struct Point
{
    double x, y, z;
};

void ShowMenu()
{
    printf("Possible actions:\n");
    printf("   1 - Add point\n");
    printf("   2 - Dump all points\n");
    printf("   3 - Load data from file\n");
    printf("   4 - Save data to file\n");
    printf("   5 - Find 2 points with min distance\n");
    printf("   6 - Find 2 points with max distance\n");
    printf("   0 - Exit\n");
    printf("Your choice? ");
}

inline double GetDistance(struct Point a, struct Point b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

void AddPoint(struct Point points[], unsigned *num) // pointer needed here!
{
    if (*num >= NUM_POINTS)
    {
        printf("\nAlready at point limit.\n\n");
        return;
    }

    printf("\nEnter the x, y, z coordinates separated by spaces: ");

    // if read 3 floats from stdin
    if (scanf("%lf %lf %lf", &points[*num].x, &points[*num].y, &points[*num].z) == 3)
        // increase number of points
        ++(*num);

    printf("\n");
}

void DumpPoints(struct Point points[], unsigned num)
{
    printf("\nDumping all points: %u\n", num);

    unsigned i;
    for (i = 0; i < num; ++i)
        printf("   %u. %.2f, %.2f, %.2f\n", i + 1, points[i].x, points[i].y, points[i].z);

    printf("\n");
}

void Load(struct Point points[], unsigned *num) // ptr needed!
{
    FILE *data = fopen(DATA_FILE, "rb"); // read binary
    
    if (!data)
    {
        perror("\nERROR: Cannot open data file for reading");
        printf("\n");
        return;
    }

    *num = 0; // reset number of points

    // load at most NUM_POINTS entries from data file
    while (*num < NUM_POINTS && fread(&points[*num], sizeof(struct Point), 1, data))
        ++(*num);

    fclose(data);
    printf("\nLoaded points: %u\n\n", *num);
}

void Save(struct Point points[], unsigned num)
{
    FILE *data = fopen(DATA_FILE, "wb"); // write binary

    if (!data)
    {
        perror("\nERROR: Cannot open data file for writing");
        printf("\n");
        return;
    }

    unsigned i;
    for (i = 0; i < num; ++i)
        fwrite(&points[i], sizeof(struct Point), 1, data);

    fclose(data);
    printf("\nSaved points: %u\n\n", i);
}

void MinDistance(struct Point points[], unsigned num)
{
    if (num < 2)
    {
        printf("\nThere have to be at least 2 points to calculate distance.\n\n");
        return;
    }

    double min = DBL_MAX, dist;
    unsigned i, j;

    for (i = 0; i < num; ++i)
        for (j = i + 1; j < num; ++j)
            if ((dist = GetDistance(points[i], points[j])) < min)
                min = dist;

    printf("\nMinimum distance between points: %.2f\n\n", min);
}

void MaxDistance(struct Point points[], unsigned num)
{
    if (num < 2)
    {
        printf("\nThere have to be at least 2 points to calculate distance.\n\n");
        return;
    }

    double max = 0, dist;
    unsigned i, j;

    for (i = 0; i < num; ++i)
        for (j = i + 1; j < num; ++j)
            if ((dist = GetDistance(points[i], points[j])) > max)
                max = dist;

    printf("\nMaximum distance between points: %.2f\n\n", max);
}

int main()
{
    unsigned num = 0;                   // number of points
    struct Point points[NUM_POINTS];    // array of points

    while (true)
    {
        ShowMenu();

        switch (getchar())
        {
            case '1':   AddPoint(points, &num);     break;  // add
            case '2':   DumpPoints(points, num);    break;  // dump
            case '3':   Load(points, &num);         break;  // load
            case '4':   Save(points, num);          break;  // save
            case '5':   MinDistance(points, num);   break;  // min distance
            case '6':   MaxDistance(points, num);   break;  // max distance
            case '0':   return 0;                           // exit
        }

        getchar(); // get \n from stdin
    }

    return 0;
}
