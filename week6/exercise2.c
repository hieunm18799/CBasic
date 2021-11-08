#include <stdio.h>

int main(){
    int arr[11];

    printf("Input 11 intergers!\n");
    for (int i = 0; i < 11; i++) scanf("%d", &arr[i]);

    for (int i = 0; i < 10; i++) if (arr[i] == arr[10]) {
        printf("The result's index is %d!\n", i + 1);
        return 1;
    }

    printf("No result!\n");
    return 1;
}