#include "header.h"

int main() {

	clock_t start;
	clock_t end;
	double time;
	int* a = (int*)malloc(sizeof(int) * Elements);
	int* b = (int*)malloc(sizeof(int) * Elements);

	for (int i = 0;i < Elements;i++) {
		a[i] = rand() % 10000 + 1;
		b[i] = a[i];
	}

	start = clock();
	quickSort1(a, 0, Elements - 1);
	end = clock();

	time = double(end - start) / double(CLOCKS_PER_SEC);

	cout << "1) Time of quick sort 1 =  " << time << " secs" << endl;

	print(a, b);
	start = clock();
	quickSort2(a, 0, Elements - 1);
	end = clock();

	time = double(end - start) / double(CLOCKS_PER_SEC);

	cout << "2) Time of quick sort 2 =  " << time << " secs" << endl;

	print(a, b);
	start = clock();
	quickSort3(a, 0, Elements - 1);
	end = clock();

	time = double(end - start) / double(CLOCKS_PER_SEC);

	cout << "3) Time of quick sort 3 =  " << time << " secs" << endl;

	print(a, b);
	start = clock();
	quickSort4(a, 0, Elements - 1);
	end = clock();

	time = double(end - start) / double(CLOCKS_PER_SEC);

	cout << "4) Time of quick sort 4 =  " << time << " secs" << endl;

	return(0);
}