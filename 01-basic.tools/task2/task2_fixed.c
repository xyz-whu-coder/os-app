#include <stdio.h>

typedef struct
{
	char *data;
	int key;
} item;

item array[] = {
	{"bill", 3},
	{"neil", 4},
	{"john", 2},
	{"rick", 5},
	{"neil", 4},
	{"alex", 1},
}; 

void sort(item * a, int n)
{
	int i = 0, j = 0;
	int s = 1;
	for (; i < n && s != 0; i++)
	{
		s = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j].key > a[j + 1].key)
			{
				item t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				s++;
			}
		}
		// n--;
	}
}

void print_arr(item *arr, int arr_size) {
	int i;
	for (i = 0; i < arr_size; i++) {
		printf("%s, %d\n", arr[i].data, arr[i].key);
	}
}

int main()
{
	sort(array, 6);
	
	print_arr(array, 6);

	return 0;
}
