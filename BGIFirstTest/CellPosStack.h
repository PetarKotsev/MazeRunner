#pragma once
/* Code inspired from: 
https://www.tutorialspoint.com/data_structures_algorithms/stack_program_in_c.htm
added dynamic allocation
*/

//int MAXSIZE = 1600;
//Cell stack[1600];
//int top = -1;

typedef struct {
	int size;
	int top;
	CellPos * stack;
}	CellPosStack;

CellPos * newCellPosStack(CellPosStack * cs, int size) {
	cs->size = size;
	cs->top = -1;
	cs->stack = (CellPos*) calloc(size, sizeof(CellPos));
	if (cs->stack == NULL) {
		perror("Unsuccessfull allocation of memory for the stack");
		return NULL;
	}
	return cs->stack;
}

CellPos * changeCellPosStackSize(CellPosStack * cs, int newSize) {
	cs->stack = realloc(cs->stack, newSize);
	if (cs->stack == NULL) {
		perror("Unsuccessfull allocation of memory for the stack");
		return NULL;
	}
	return cs->stack;
}

bool isEmpty(CellPosStack * cellPosStack) {
	if (cellPosStack->top == -1)
		return true;
	else
		return false;
}

bool isFull(CellPosStack * cellPosStack) {

	if (cellPosStack->top == cellPosStack->size)
		return true;
	else
		return false;
}

CellPos * peek(CellPosStack * cellPosStack) {
	CellPos t;
	setCellPos(&t, cellPosStack->stack[cellPosStack->top].col, cellPosStack->stack[cellPosStack->top].row);
	return &t;
}

CellPos * pop(CellPosStack * cellPosStack) {
	CellPos * data;

	if (!isEmpty(cellPosStack)) {
		data = &cellPosStack->stack[cellPosStack->top];
		cellPosStack->top -= 1;
		return data;
	}
	else {
		printf("Could not retrieve data, Stack is empty.\n");
	}
}

CellPos * push(CellPosStack * to, CellPos * cptr) {

	if (!isFull(to)) {
		to->top += 1;
		setCellPos(&to->stack[to->top], cptr->col, cptr->row);
		return &to->stack[to->top];
	}
	else {
		printf("Could not insert data, Stack is full.\n");
	}
}