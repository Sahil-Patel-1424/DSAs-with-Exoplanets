// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "exoplanet.h"

#define MAX_PLANETS 4389    // this is the actual number of exoplanets in the csv file

int main(void) {
    // initialize variables
    struct exoplanet struct_array[MAX_PLANETS];      // a list of structs
    const char *file_name = "PS_2025.06.02_17.07.37 - PS_2025.06.02_17.07.37.csv";      // the csv file
    struct exoplanet insertion_struct[MAX_PLANETS];     // used for insertion sort
    clock_t start, end;     // these are to calculate the start and end times for each algorithm
    double cpu_time_used;   // this calculates the total computational time each algorithm used

    // load the csv file and return a number to see if the data was stored
    int count = load_exoplanets(file_name, struct_array, MAX_PLANETS);
    if (count < 0) {
        return -1;
    }

    // print the first and last 10 elements in unsorted list
    print_list(struct_array, count, "UNSORTED");

    // create multiple copies of the unsorted list
    for (int i = 0; i < count; i++) {
        insertion_struct[i] = struct_array[i];
    }

    // create directory to store the results
    create_directory();

    // perform insertion sort
    start = clock();
    struct_insertion_sort(insertion_struct, count);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort Results (Time (seconds): [%0.5f]):\n", cpu_time_used);
    print_list(insertion_struct, count, "SORTED");
    store_results(insertion_struct, count, "Insertion");

    // exit the program
    return 0;
}