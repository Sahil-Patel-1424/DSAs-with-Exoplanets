#ifndef EXOPLANET_H
#define EXOPLANET_H

// struct definition for an exoplanet
struct exoplanet {
    int id;     // assign the exoplanet an id for easier identification
    char *name;
    float mass; // this determines how the sorting algorithm will sort the list of structs
};

// function prototypes
int load_exoplanets(const char *file_name, struct exoplanet array[], int max_count);
void print_list(struct exoplanet array[], int number_of_elements, char* string);
void store_results(struct exoplanet array[], int number_of_elements, char *string);
void create_directory();
void struct_insertion_sort(struct exoplanet array[], int number_of_elements);
void struct_selection_sort(struct exoplanet array[], int number_of_elements);
void struct_bubble_sort(struct exoplanet array[], int number_of_elements);

#endif