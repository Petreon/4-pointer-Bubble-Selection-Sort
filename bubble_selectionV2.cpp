#include <vector>

void Bubble_Selection_SortV2(std::vector<int> *arr)
{

    int minor_value = (*arr)[0];
    int min_pointer = 0;
    int max_value = (*arr)[(*arr).size() - 1];
    int max_pointer = (*arr).size() - 1;

    int pointer_initial = 0;
    int pointer_final = (*arr).size() - 1;

    int changes = 0;
    int buffer;

    while (true)
    {
        for (int i = pointer_initial; i <= pointer_final; i += 2)
        {
            // bubble algorithm
            if ((*arr)[i] > (*arr)[i + 1] && i != pointer_final)
            {
                buffer = (*arr)[i];
                (*arr)[i] = (*arr)[i + 1];
                (*arr)[i + 1] = buffer;
                changes++;
                // preparing for selection
                if ((*arr)[i] < minor_value)
                {
                    minor_value = (*arr)[i];
                    min_pointer = i;
                    changes++;
                }
                if ((*arr)[i + 1] > max_value)
                {
                    max_value = (*arr)[i + 1];
                    max_pointer = i + 1;
                    changes++;
                }
            }
            else if ((*arr)[i] > max_value)
            {
                max_value = (*arr)[i];
                max_pointer = i;
                changes++;
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
    }
}