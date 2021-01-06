#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct el {
	int duom;
	struct el *kitas;
};

void addElem(struct el **start, int value);
void deletElem(struct el **start, int value);
void printList(struct el **start, int value);

#endif
