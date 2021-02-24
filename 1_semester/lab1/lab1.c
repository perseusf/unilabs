#include <stdio.h>

int main(){
	int number;
	int result;
	printf("vvedite chislo\n");
	scanf("%d", &number);
	if (number > 99) {
		result = number / 100;
		result = result % 10;
		printf("kolichestvo soten v chisle %d\n", result);
	} else {
		printf("chislo ne podhodit\n");
	}
	return 0;
}
