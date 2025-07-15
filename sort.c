// libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "exoplanet.h"

// insertion sort algorithm function
void struct_insertion_sort(struct exoplanet array[], int number_of_elements) {
    // store a struct element
    struct exoplanet element;

    // loop through the array of structs
    for (int i = 1; i < number_of_elements; i++) {
        // initialize variables
        int j = i - 1;          // get the previous struct element
        element = array[i];     // store the current struct element

        // first check if j is greater than -1 to make sure we are accessing inside the list of structs
        // then check to see if the previous struct's element's value (mass) is greater than the current's struct element's value (mass)
        // if the previous element is greater than the current element, then perform a swap (repeat this until all elements are sorted)
        while ((j > -1) && (array[j].mass > element.mass)) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = element;
    }

    return;
}

// selection sort algorithm function
void struct_selection_sort(struct exoplanet array[], int number_of_elements) {

    // loop through the array of structs
    for (int i = 0; i < number_of_elements - 1; i++) {
        // assume that the current position holds the smallest element
        int smallest_index = i;

        // loop through the unsorted portion of the list to find the actual smallest element
        for (int j = i + 1; j < number_of_elements; j++) {
            if (array[j].mass < array[smallest_index].mass) {
                // update the smallest element's index if a smaller element is found
                smallest_index = j;
            }
        }

        // move the smallest element to its correct position
        struct exoplanet temp = array[i];
        array[i] = array[smallest_index];
        array[smallest_index] = temp;
    }

    return;
}