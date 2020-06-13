#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct LinkNode {
    element data;
    struct LinkNode* link;
}LinkNode;

//ADT
LinkNode* insert_first(LinkNode* list, element item);
LinkNode* insert_last(LinkNode* list, LinkNode* pre, element item);
LinkNode* delete_first(LinkNode* list);
LinkNode* delete_last(LinkNode* list, LinkNode* pre);
void print_list(LinkNode* list);

LinkNode* insert_first(LinkNode* list, element item) {
    LinkNode* tmp = (LinkNode*)malloc(sizeof(LinkNode));
    tmp->data = item;
    if (list == NULL) {
        tmp->link = NULL;
        return tmp;
    }
    tmp->link = list;
    return tmp;
}

LinkNode* get_last_node(LinkNode* list) {
    LinkNode* tmp = list;
    while (tmp->link != NULL) {
        tmp = tmp->link;
    }
    return tmp;
}
LinkNode* insert_last(LinkNode* list, LinkNode* pre, element item) {
    LinkNode* tmp = (LinkNode*)malloc(sizeof(LinkNode));
    tmp->data = item;
    if (list == NULL) {
        tmp->link = NULL;
        return tmp;
    }
    if (pre == NULL) {
        LinkNode* point = get_last_node(list);
        point->link = tmp;
        tmp->link = NULL;
    }
    else {
        LinkNode* point = list;
        while (point != pre) {
            point = point->link;
        }
        tmp->link = point->link;
        point->link = tmp;
    }
    return list;
}

LinkNode* delete_first(LinkNode* list) {
    if (list == NULL) return 0;
    LinkNode* tmp = list;
    list = tmp->link;
    free(tmp);
    return list;
}

LinkNode* delete_last(LinkNode* list, LinkNode* pre) {
    if (list == NULL) return 0;
    LinkNode* tmp = list;
    if (pre == NULL) {
        LinkNode* removed = get_last_node(list);
        while (tmp->link != removed) {
            tmp = tmp->link;
        }
        tmp->link = NULL;
        free(removed);
        return list;
    }
    else {
        LinkNode* removed = pre->link;
        pre->link = removed->link;
        free(removed);
        return list;
    }
}

LinkNode* reverse(LinkNode* list) {
    LinkNode* new_head = NULL;
    LinkNode* leader = list;
    LinkNode* tail;

    while (leader != NULL) {
        tail = new_head;
        new_head = leader;
        leader = leader->link;
        new_head->link = tail;
    }
    return new_head;
}


void print_list(LinkNode* list) {
    LinkNode* tmp = list;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}

int main(void) {
    LinkNode* list1 = NULL;
    list1 = insert_first(list1, 1);
    list1 = insert_first(list1, 2);
    list1 = insert_first(list1, 3);
    list1 = insert_last(list1, NULL, 4);
    print_list(list1);

    LinkNode* list2 = NULL;
    list2 = reverse(list1);
    print_list(list2);

    list1 = delete_first(list2);
    print_list(list1);
    list1 = delete_last(list1, NULL);
    print_list(list1);
    return 0;
}
