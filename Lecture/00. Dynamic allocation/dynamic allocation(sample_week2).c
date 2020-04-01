#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct addr {
    char* city;
    char* street;
    char* detail;
} address;

typedef struct tag {
    char* name;
    int age;
    address* addr;
} person;

void read_person(person* p);
void print_person(person* p);

int main(void) {
    person* p[20];
    p[0] = (person*)malloc(sizeof(person));

    read_person(p[0]);
    print_person(p[0]);
    return 0;
}

void read_person(person* p) {
    /*
    buf 변수는 재활용 가능
    입력 받으면서 덮어씌움

    */

    // person 
    char buf[20];
    scanf_s("%s", buf, 20);
    p->name = (char*)malloc(strlen(buf) + 1);
    strcpy_s(p->name, strlen(buf)+1, buf);
    scanf_s("%d", &p->age);

    // addr
    p->addr = (address*)malloc(sizeof(address));

    scanf_s("%s", buf, 20);
    p->addr->city = (char*)malloc(strlen(buf) + 1);
    strcpy_s(p->addr->city, strlen(buf) + 1, buf);

    scanf_s("%s", buf, 20);
    p->addr->street = (char*)malloc(strlen(buf) + 1);
    strcpy_s(p->addr->street, strlen(buf) + 1, buf);

    scanf_s("%s", buf, 20);
    p->addr->detail = (char*)malloc(strlen(buf) + 1);
    strcpy_s(p->addr->detail, strlen(buf) + 1, buf);
}

void print_person(person* p) {
    printf("이름: %s (%d세) 주소: %s %s %s",
        p->name, p->age, p->addr->city, p->addr->street, p->addr->detail);
}

