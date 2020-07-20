#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void setRandomValueForArrayElements(int array[], int length_array)
{
    for(int element = 0; element < length_array; ++element)
        array[element] = getRandomNumber(1, length_array);
}

void sortArray(int array[], int length_array)
{
    for(int startIndex = 0; startIndex < length_array - 1; ++startIndex)
    {
        int minIndex = startIndex;
        for(int currentIndex = startIndex + 1; currentIndex < length_array; ++currentIndex)
        {
            if(array[currentIndex] < array[minIndex])
                minIndex = currentIndex;
        }
        std::swap(array[startIndex] , array[minIndex]);
    }
}

void printArray(int array[], int length_array)
{
    std::cout << "array: \n";
    for(int element = 0; element < length_array; ++element)
    {
        std::cout << array[element] << " ";
        if(element % 10 == 0 && element != 0)
            std::cout << '\n';
    }
    std::cout << '\n';
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    const int length_array{ 100 };
    int array[length_array];

    setRandomValueForArrayElements(array, length_array);
    sortArray(array, length_array);
    printArray(array, length_array);

    return 0;
}
