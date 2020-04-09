/*
title - 교재 뱅킹 시뮬레이션 코드 수정

원형큐를 이용하여 뱅킹 업무처리 시스템 구현

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUEUE_SIZE 20

// ================ 원형큐 정의부 시작 =================
typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
} element;			// 교체!
// ================ 원형큐 정의부 종료 =================


// ===== 원형큐 코드 시작 ======
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{
	if (is_full(q)) error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q)) error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// 삭제 함수
element peek(QueueType* q)
{
	if (is_empty(q)) error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}
// ===== 원형큐 코드 끝 ======

int main(void) {
	srand(time(NULL)); // 랜덤난수 생성 조건

	QueueType q;
	init_queue(&q);

	int cs_current;
	int cs_number = 0;
	int service_time = 0;
	int total_wait = 0;
	
	for (int clock = 0; clock < 60; clock++) {
		printf("현재 시각: %d분\n", clock);
		// 고객 입장(생성)
		if (rand() % 10 < 3) {
			element cs;
			cs.id = cs_number++;
			cs.arrival_time = clock;
			cs.service_time = rand() % 3 + 1;
			enqueue(&q, cs);
			printf("고객 %d이 %d분에 입장합니다. 업무처리 시간 %d분\n",
				cs.id, clock, cs.service_time);
		}
		// 업무 처리 중
		if (service_time > 0) {
			printf("%d번 고객 업무 처리중입니다.\n", cs_current);
			service_time--;
		}
		// 대기 고객 입장
		else {
			if (!is_empty(&q)) {
				element cs = dequeue(&q);
				service_time = cs.service_time;
				cs_current = cs.id;
				printf("고객 %d이 %d분에 업무를 시작합니다. 대기 시간 %d분이었습니다.\n",
					cs.id, clock, clock - cs.arrival_time);
				total_wait += (clock - cs.arrival_time);
			}
		}
	}
	printf("전체 대기시간 %d분\n", total_wait);
	return 0;
}