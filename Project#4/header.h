#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<ctime>
using namespace std;

#define Elements 10000

void print(int* a, int* b) {
	for (int i = 0; i < Elements; i++) {
		a[i] = b[i];
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void insertionSort(int* a, int loc, int item) {
	if (loc >= item) {
		return;
	}

	int i, j, key;
	for (i = loc + 1;i <= item;i++) {
		key = a[i];
		j = i - 1;
		while (j >= loc && a[j] > key) {
			a[j + 1] = a[j];
			j -= 1;
		}
		a[j + 1] = key;
	}

}

int partition1(int* a, int loc, int item) {

	int mid = (loc + item) / 2;
	swap(a[mid], a[item]);
	int i = loc - 1;
	for (int j = loc;j <= item;j++) {
		if (a[j] <= a[item]) {
			i += 1;
			swap(a[i], a[j]);
		}
	}
	return i;

}

int partition2(int* a, int loc, int item) {
	int mid = (loc + item) / 2;

	int b[3]; b[0] = a[loc]; b[1] = a[mid]; b[2] = a[item];
	insertionSort(b, 0, 2);
	int median = b[1];
	int position = 0;
	if (position == a[loc]) {
		position = loc;
	}
	else if (median == a[mid]) {
		position = mid;
	}
	else {
		position = item;
	}

	swap(a[position], a[item]);

	int i = loc - 1;
	for (int j = loc ;j <= item ; ++j) {
		if (a[j] <= a[item]) {
			i += 1;
			swap(a[i], a[j]);
		}
	}
	return i;

}

void quickSort1(int* a, int loc, int item) {
	if (loc >= item) {
		return;
	}
	else {
		int z = partition1(a, loc, item);
		quickSort1(a, loc, z - 1);
		quickSort1(a, z + 1, item);
	}
}

void quickSort2(int* a, int loc, int item) {
	if (loc >= item) {
		return;
	}
	else {
		int z = partition2(a, loc, item);
		quickSort2(a, loc, z - 1);
		quickSort2(a, z + 1, item);
	}
}

void quickSort3(int* a, int loc, int item) {
	if (item - loc < 20) {
		insertionSort(a, loc, item);
	}
	else {
		int z = partition1(a, loc, item);
		quickSort3(a, loc, z - 1);
		quickSort3(a, z + 1, item);
	}
}

void quickSort4(int* a, int loc, int item) {
	if (item - loc < 20) {
		insertionSort(a, loc, item);
	}
	else {
		int z = partition2(a, loc, item);
		quickSort4(a, loc, z - 1);
		quickSort4(a, z + 1, item);
	}
}

