#include <iostream>

void printArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::cout << "Student code: 87863; Task Nr.: " << 87863 % 30 << '\n';
    std::cout << "To manualy fill the array type 1, to fill the array randomly type 2: ";
    int mode = 0;
    std::cin >> mode;

    int h = 0;
    std::cout << "Enter the height of the array: ";
    std::cin >> h;

    int w = 0;
    std::cout << "Enter the width of the array: ";
    std::cin >> w;
    int* arr = new int[h * w];

    srand(time(0));

    if (mode == 1) {


        for (int i = 0; i < h; i++) {
            for (int i2 = 0; i2 < w; i2++) {
                std::cout << "Row " << i << " Column " << i2 << ": ";
                std::cin >> arr[i*(w) + i2];
            }
        }

        printArr(arr, w*h);



    }
    else if (mode == 2) {
        int min = 0;
        std::cout << "Enter the minimum value of the random elements: ";
        std::cin >> min;

        int max = 0;
        std::cout << "Enter the maximum value of the random elements: ";
        std::cin >> max;

        for (int i = 0; i < w*h; i++) {
            double randNum = min + ((double)rand()) / RAND_MAX * (max - min);
            arr[i] = randNum;
        }
        printArr(arr, w*h);


    }
    else {
        std::cout << "Invalid input\n";
        delete[] arr;
        return 0;
    }

    double max_average;
    std::cout << "Maximum average of a row: ";
    std::cin >> max_average;

    double row_sum = 0;
    int output = 0;
    for (int i = 0; i < h; i++) {
        for (int i2 = 0; i2 < w; i2++) {
            row_sum += arr[i * (w)+i2];
        }
        if (row_sum / w < max_average) {
            output++;
        }
        row_sum = 0;
    }


    std::cout << "The number of rows with average value of less than " << max_average << ": " << output;

    delete[] arr;
    return 0;
}