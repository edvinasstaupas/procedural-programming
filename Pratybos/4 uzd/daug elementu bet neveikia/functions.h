#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct el {
	int duom;
	struct el *kitas;
};

void addElem(struct el **start, int value);
void deletElem(struct el **start, struct el *elem, int value, int *found, struct el **latest);
void printList(struct el *elem);

#endif
