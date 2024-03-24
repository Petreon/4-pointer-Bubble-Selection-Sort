#include "bubble-selection.hpp"
#include <iostream>
#include <algorithm>
#include <chrono>
#include "array1.hpp"
#include "array2.hpp"
#include "array3.hpp"
#include <iomanip>
#include "array4.hpp"
#include "bubble_selectionV2.cpp"

// the explaination of this algorithm is on the header file
void Bubble_Selection_Sort(std::vector<int> *arr)
{

    int minor_value = (*arr)[0];
    int min_pointer = 0;
    int max_value = (*arr)[(*arr).size() - 1];
    int max_pointer = (*arr).size() - 1;

    int pointer_initial = 0;
    int pointer_final = (*arr).size() - 1;

    int changes = 0;
    int comparisons = 0;
    int buffer;

    while (true)
    {
        for (int i = pointer_initial; i <= pointer_final; i++)
        {
            // bubble algorithm
            if ((*arr)[i] > (*arr)[i + 1] && i != pointer_final)
            {
                buffer = (*arr)[i];
                (*arr)[i] = (*arr)[i + 1];
                (*arr)[i + 1] = buffer;
                changes++;
            }
            // preparing for selection
            if ((*arr)[i] < minor_value && i != pointer_final)
            {
                minor_value = (*arr)[i];
                min_pointer = i;
                comparisons++;
            }
            else if ((*arr)[i] > max_value && i != pointer_final)
            {
                max_value = (*arr)[i];
                max_pointer = i;
                comparisons++;
            }
        }
        int buffer1 = (*arr)[pointer_initial];
        int buffer2 = (*arr)[pointer_final];

        (*arr)[pointer_initial] = minor_value;
        (*arr)[pointer_final] = max_value;

        (*arr)[min_pointer] = buffer1;
        (*arr)[max_pointer] = buffer2;

        pointer_initial++;
        pointer_final--;
        minor_value = (*arr)[pointer_initial];
        max_value = (*arr)[pointer_final];

        if (changes == 0)
        {
            // break the outter loop
            break;
        }
        changes = 0;
        comparisons = 0;
    }
}

std::vector<int> Bubble_Selection_Sort_debug(std::vector<int> arr)
{

    int minor_value = arr[0];
    int min_pointer = 0;
    int max_value = arr[arr.size() - 1];
    int max_pointer = arr.size() - 1;

    int pointer_initial = 0;
    int pointer_final = arr.size() - 1;

    int changes = 0;
    int comparisons = 0;
    int buffer;

    while (true)
    {
        for (int i = pointer_initial; i <= pointer_final; i += 2)
        {
            // bubble algorithm
            if (arr[i] > arr[i + 1] && i != pointer_final)
            {
                buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                changes++;
                // preparing for selection
                if (arr[i] < minor_value)
                {
                    minor_value = arr[i];
                    min_pointer = i;
                    comparisons++;
                }
                if (arr[i + 1] > max_value)
                {
                    max_value = arr[i + 1];
                    max_pointer = i + 1;
                    comparisons++;
                }
            }
            else if (arr[i] > max_value)
            {
                max_value = arr[i];
                max_pointer = i;
                comparisons++;
            }
        }
        int buffer1 = arr[pointer_initial];
        int buffer2 = arr[pointer_final];

        arr[pointer_initial] = minor_value;
        arr[pointer_final] = max_value;

        arr[min_pointer] = buffer1;
        arr[max_pointer] = buffer2;

        pointer_initial++;
        pointer_final--;
        minor_value = arr[pointer_initial];
        max_value = arr[pointer_final];

        if (changes == 0)
        {
            // break the outter loop
            break;
        }
        changes = 0;
        comparisons = 0;
    }

    return arr;
}

void bubbleSort(std::vector<int> *arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if ((*arr)[j] > (*arr)[j + 1])
            {
                std::swap((*arr)[j], (*arr)[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

int main()
{
    auto start0 = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    bubbleSort(&array3, array3.size());
    auto end0 = std::chrono::high_resolution_clock::now();

    // std::vector<int> arr = {12, 3, 31, 19, 1, 7, 8, 11, 20, 17, 10, 0};

    std::ios_base::sync_with_stdio(true);
    auto start1 = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    Bubble_Selection_Sort(&array1);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::ios_base::sync_with_stdio(true);
    auto start4 = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    Bubble_Selection_SortV2(&array4);
    auto end4 = std::chrono::high_resolution_clock::now();

    std::ios_base::sync_with_stdio(true);
    std::cout << '\n';

    auto start2 = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);
    std::sort(array2.begin(), array2.end());
    auto end2 = std::chrono::high_resolution_clock::now();

    double time_taken1 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count();
    time_taken1 *= 1e-9;

    double time_taken2 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count();
    time_taken2 *= 1e-9;

    double time_taken3 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end0 - start0).count();
    time_taken3 *= 1e-9;

    double time_taken4 =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4).count();
    time_taken4 *= 1e-9;

    std::cout << std::endl;

    std::cout << "Time taken by bubble_selection is : " << std::fixed
              << time_taken1 << std::setprecision(9);
    std::cout << " sec" << std::endl;

    std::cout << "Time taken by sort is : " << std::fixed
              << time_taken2 << std::setprecision(9);
    std::cout << " sec" << std::endl;

    std::cout << "Time taken by bubble_sort is : " << std::fixed
              << time_taken3 << std::setprecision(9);
    std::cout << " sec" << std::endl;

    std::cout << "Time taken by bubble_selectionV2 is : " << std::fixed
              << time_taken4 << std::setprecision(9);
    std::cout << " sec" << std::endl;

    return 0;
}
