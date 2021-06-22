#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, k, i, j, t;

	scanf("%d", &t);

	int count = 0;
	// while (count < t)    {

	scanf("%d %d", &n, &k);

	int array[n];
	int distinct[n][2];

	for (i = 0; i < n; i++) {
		distinct[i][1] = 0;
	}

	for (i = 0; i < n; i++) {
		fscanf(stdin, "%d", &array[i]);
	}

	int index = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (array[i] == distinct[j][0]) {
				distinct[j][1]++;
				break;
			}
		}

		distinct[index][0] = array[i];

		distinct[index][1]++;
		index++;
	}

	for (i = 0; i < k; i++) {
		for (j = 0; j < index - 1; j++) {
			if (distinct[j][0] > distinct[j + 1][0]) {
				int temp = 0;
				temp = distinct[j][0];
				distinct[j][0] = distinct[j + 1][0];

				distinct[j + 1][0] = temp;
			}
		}
	}

	int sum = 0;
	for (i = 0; i < k; i++) {
		sum += (distinct[index - i][0]) * distinct[index - i][1];
	}

	printf("%d", sum);
	count++;

	//}

	return 0;
}
