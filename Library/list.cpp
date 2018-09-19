#include <stdlib.h>
#include "list.h"

struct ListItem
{
	int data;
	ListItem *next;
};

struct List
{
	ListItem *first;
};

List *list_create()
{
	List *list = new List;// выделить память под корень списка
	list->first = NULL;
	return list; // вернуть адрес на корень списка
}

void list_delete(List *list)
{
	ListItem *el_ptr1 = list->first, *el_ptr2;
	while (el_ptr1 != NULL) {
		el_ptr2 = el_ptr1->next;
		delete el_ptr1;
		el_ptr1 = el_ptr2;
	};
	delete list;
}

ListItem *list_first(List *list)
{
    return list->first;
}

int list_item_data(ListItem *item)
{
	return item->data;
}

ListItem *list_item_next(ListItem *item)
{
    return item->next;
}

ListItem *list_item_prev(ListItem *item)
{
    return NULL;
}

ListItem *list_insert(List *list, int data)
{
	ListItem *el = new ListItem;
	el->data = data;
	el->next = NULL;
	if (list->first == NULL)
		list->first=el;
	else {
		el->next = list->first;
		list->first = el;
	}
	return el;
}

ListItem *list_insert_after(List *list, ListItem *item, int data)
{
	ListItem *el = new ListItem;
	el->data = data;
	el->next = item->next;
	item->next = el;
	return el;
}

ListItem *list_erase(List *list, ListItem *item)
{
	if (list->first == NULL) return NULL;
	if (list->first == item) {
		list->first = item->next;
		delete item;
		return list->first;
	}
	else {
		ListItem *el_ptr = list->first;
		while (el_ptr->next != item)
			el_ptr = el_ptr->next;
		el_ptr->next = item->next;
		delete item;
		return el_ptr;
	}
}

ListItem *list_erase_next(List *list, ListItem *item)
{
    return NULL;
}
