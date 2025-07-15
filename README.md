# Using Data Structures and Algorithms on Exoplanets
For this project, I am working with read-world data from NASA's Exoplanet Archive (https://exoplanetarchive.ipac.caltech.edu/), which catalogs thousands of confirmed exoplanets discovered outside of our solar system. My goal is to take this dataset and apply sorting algorithms that organize the exoplanets based on their mass.

The focus here isn't just on sorting - it's about understanding the behavior and efficiency of different algorithms when applied to scientific data. I am starting with one of the most beginner-friendly sorting techniques, Insertion Sort, to establish a baseline for future comparisons with more advanced algorithms like Merge Sort or Quick Sort.

By visualizing and analyzing how each algorithm processes the exoplanet data, especially with varying sizes and distributions, I aim to highlight the strengths and limitations of each method. This project blends basic algorithm design with astronomical data, making it a great learning experience and a practical demonstration of computer science in action.

# Insertion Sort
The Insertion Sort algorithm is a straightforward sorting algorithm that sorts a list one element at a time. It works similarly to how you would sort playing cards in your hand - by dividing them into two groups: a sorted group and an unsorted group. You then take one card from the unsorted group and insert it into the correct position in the sorted group. Here is how the algorithm works:

1. You start with the second element in the list because you can assume that the first element is already sorted.
2. Compare the second element with the first element. If the second element is smaller, then you swap their positions.
3. Move on to the third element in the list and compare it with the first two elements before it. Then, you insert the third element into its correct position.
4. Continue this process for each element in the entire list until the list is sorted.
  
<br>
Since the data I used is randomly ordered, the Time Complexity of this Insertion Sort algorithm is O(n<sup>2</sup>). The Insertion Sort algorithm is a simple and easy program to implement, but its efficiency drops as the list grows larger, especially when compared to other sorting algorithms.<br/><br/>

More information on the Insertion Sort algorithm: https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/

# Selection Sort
The Selection Sort algorithm is a comparison-based sorting algorithm that sorts a list by repeatedly selecting the smallest (or largest) element from the unsorted portion of the list and swapping it with the first unsorted element. This process continues until the entire array is sorted:

1. You start by finding the smallest element and swap it with the first element to get the smallest element at its correct position.
2. Find the second smallest element and swap it with the second element.
3. Continue this process until all elements are moved to their correct positions.

<br>
The Time Complexity of this Selection Sort algorithm is O(n<sup>2</sup>). The Selection Sort algorithm is a straightforward algorithm to implement; however, it does not maintain the relative order of equal elements making it not stable.

More information on the Selection Sort algorithm: https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
