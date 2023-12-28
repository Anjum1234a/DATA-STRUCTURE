#include <stdio.h>
int main() {
    int arr1[50], n, i, j = 0, larg, larg2nd;
    printf("\n\nFind the second largest element in an array :\n");
    printf("Input the size of the array : ");
    scanf("%d", &n);
    printf("Input %d elements in the array :\n", n);
    for (i = 0; i < n; i++) {
        printf("element %d  ", i);
        scanf("%d", &arr1[i]);
    }
    larg = 0;
    for (i = 0; i < n; i++) {
        if (larg < arr1[i]) {
            larg = arr1[i];
            j = i;
        }
    }
    larg2nd = 0;
    for (i = 0; i < n; i++) {
        if (i == j) {
            i++; 
            i--;
        } else {
            if (larg2nd < arr1[i]) {
                larg2nd = arr1[i];
            }
        }
    }
    printf("The Second largest element in the array is :  %d \n\n", larg2nd);
}

