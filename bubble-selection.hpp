#include <vector>

/*
This algorithm uses the two approach at the same time, using 4 pointers, one in the beggining
of the array putting the minimun values to them and changing the pointer with the actual min value
and the same for the end-pointer, putting the max values in the final of the array (Selection)
at the same the we change the order of the minor value for the maximum value with the middles pointers(Bubble)
and the algorithm stops when the times of changes is equal to 0
*/

std::vector<int> Bubble_Selection_Sort(std::vector<int> arr);
