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
    struct exoplanet struct_array[MAX_PLANETS];                                         // a list of structs
    const char *file_name = "PS_2025.06.02_17.07.37 - PS_2025.06.02_17.07.37.csv";      // the csv file
    struct exoplanet insertion_struct[MAX_PLANETS];                                     // used for insertion sort
    struct exoplanet selection_struct[MAX_PLANETS];                                     // used for selection sort
    struct exoplanet bubble_struct[MAX_PLANETS];                                        // used for bubble sort
    clock_t start, end;                                                                 // these are to calculate the start and end times for each algorithm
    double cpu_time_used;                                                               // this calculates the total computational time each algorithm used

    // load the csv file and return a number to see if the data was stored
    int count = load_exoplanets(file_name, struct_array, MAX_PLANETS);

    // if the file wasn't loaded, then exit the program to prevent errors
    if (count < 0) {
        return -1;
    }

    // print the first and last 10 elements in unsorted list
    print_list(struct_array, count, "UNSORTED");

    // create multiple copies of the unsorted list for the various implemented algorithms
    for (int i = 0; i < count; i++) {
        insertion_struct[i] = struct_array[i];
        selection_struct[i] = struct_array[i];
        bubble_struct[i] = struct_array[i];
    }

    // this is for storing the results
    create_directory();

    // perform insertion sort
    start = clock();
    struct_insertion_sort(insertion_struct, count);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nInsertion Sort Results (Time (seconds): [%0.5f]):\n", cpu_time_used);
    print_list(insertion_struct, count, "SORTED");
    store_results(insertion_struct, count, "Insertion");

    // perform selection sort
    start = clock();
    struct_selection_sort(selection_struct, count);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nSelection Sort Results (Time (seconds): [%0.5f]):\n", cpu_time_used);
    print_list(selection_struct, count, "SORTED");
    store_results(selection_struct, count, "Selection");

    // perform bubble sort
    start = clock();
    struct_bubble_sort(bubble_struct, count);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nBubble Sort Results (Time (seconds): [%0.5f]):\n", cpu_time_used);
    print_list(bubble_struct, count, "SORTED");
    store_results(bubble_struct, count, "Bubble");

    // exit the program
    return 0;
}