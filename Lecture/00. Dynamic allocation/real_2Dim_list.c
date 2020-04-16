#include <stdio.h>
#include <stdlib.h>

/*
메모리 이어서 2차원 배열 할당하기

전체 메모리 크기 할당하고
헤드 메모리 생성
헤드 메모리에서 columns size 만큼만

재료
사이즈 c*r 배열
헤드 위치 포인터

헤드 포인터  // 데이터 저장할 공간
[][][][] [][][] [][][] [][][] [][][]

*/

int main(void) {
    int count = 0;
    int c = 3, r = 5;

    // 헤드 포인터로 쓸 배열 + 데이터 저장할 포인터 배열 = 전체 배열 사이즈
    int len = sizeof(int**) * r + sizeof(int*) * c * r;
    //
    int** arr = (int**)malloc(len);

    // (캐스팅)(arr 첫번째 위치 + 처음 로우  위치) == 데이터가 처음 저장될 위치의 주소
    int* ptr = (int*)(arr + r); // why this point?
    // arr[0] + r 번째 위치

    /*
    printf("%d \n", arr);
    printf("%d \n", arr + r);
    printf("%d \n", ptr);
    */

    for (int i = 0; i < r; i++) {
        arr[i] = (ptr + c * i); // 헤드 포인터 생성
    }

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            arr[i][k] = count++;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            printf("%d\t", arr[i][k]);
        }
        printf("\n");
    }
}
