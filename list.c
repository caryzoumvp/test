#include <stdio.h>
#include <stdlib.h>

struct list_item {
	struct _item {
		int a;
	} item;
	struct list_item *prev;
	struct list_item *next;
};

struct list_item* create_list (struct _item* item) {
	struct list_item *head = (struct list_item*)malloc (sizeof(struct list_item));;
	head->item = *item;
	head->prev = NULL;
	head->next = NULL;
	return head;
}

void insert_item_back(struct list_item *head, struct _item* item) {
	struct list_item * tail = head;
	while (tail->next != NULL) {
		tail = tail->next;
		continue;
	}
	struct list_item* p = (struct list_item*)malloc(sizeof(struct list_item));
	p->prev = tail;
	tail->next = p;
	p->item = *item;
	p->next = NULL;
}

void delete_item (struct list_item *head, struct _item* item) {
	struct list_item *p = head;
	while (p->next != NULL) {
		struct _item tmp = p->item;
		if (!memcmp((void*)(&tmp), item)) {
			struct list_item *prev, *next;
			prev = p->prev;
			next = p->next;	
			prev->next = next;
			next->prev = prev;
			free(p);
			break;
		}
		p = p->next;
	}
}

int main () {
	int i;
	struct _item items[] = {
		{1},
		{2},
		{3},
		{4}
	};	
	create_list(items[0]);
	for(i = 0; i < 4; i++) {
		insert_item_back(items[i];
	}
	delete_item(items[2]);
	return 0;
}
	

