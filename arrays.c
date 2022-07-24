#include <stdio.h>
#include <stdlib.h>

void push(int tab[], int size, int var)
{
	// add in the last of the table
	tab[size - 1] = var;

	// int i=0;
	// while (tab[i]!=0)
	// {
	// 	i++;
	// }
	//  tab[i]=var;
}
void insert_into_pos(int tab[], int size, int var, int pos)
{
	if (pos < 1 || pos >= size)
		return; // imposible
	// 1 2 3 4 5 6 -  and we want insert 7 in 4 position
	// 1 2 3 7 4 5 6

	// 1 2 3 4 5 6 -  and we want insert 5 in 2 position  i=6  i=2
	// 1 2 2 7 4 4 5

	for (int i = size - 1; i >= pos; i--)
	{
		tab[i] = tab[i - 1];
	}
	tab[pos - 1] = var;
}
void print(int tab[], int size)
{

	for (int i = 0; i < size; i++)
	{
		printf("%d\n", tab[i]);
	}
}

int pop(int tab[], int size)
{

	// there is nothing called pop a table ( a static allocation ) we can just resize it
	tab[size - 1] = 0;

	return size - 1;
}
int main()
{
	int tab[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = sizeof(tab) / sizeof(tab[0]);
	push(tab, size, 1);
	size = pop(tab, size);
	insert_into_pos(tab, size, -99, 2);
	print(tab, size);

	return 0;
}