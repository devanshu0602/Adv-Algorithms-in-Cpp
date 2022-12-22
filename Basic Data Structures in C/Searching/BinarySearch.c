#include <stdio.h>

int BinarySearch(int array[], int lb, int hb, int x) {
    int mid;
    mid = (lb+hb)/2;
    if (x==array[mid]) {
        return mid;
    }
    else if (x < array[mid]) {
        return BinarySearch(array, lb, mid-1, x);
    }
    else if (x > array[mid]) {
        return BinarySearch(array, mid+1, hb, x);
    }
    else {
        return 100;
    }
}

int main() {
    printf("Devanshu Gupta\n");
    int x, i, j, temp, res;
    int array[100] = {1,3,4,2,10,7,8,5,6,9,11};
    x = 7;
    /*Sorting the array*/
    for (i=0; i<11; i++) {
        for (j=i+1; j<11; j++) {
            if (array[i]>array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    printf("\nSorted array:\n");
    for (i=0;i<11;i++) {
        printf("%d\t", array[i]);
    }
    res = BinarySearch(array, 0, 10, x);
    if (res!=100) {
        printf("\nThe number %d was found at index: %d", x, res);
    }
    else {
        printf("\nThe number %d was not found.", x);
    }
    return 0;
}
