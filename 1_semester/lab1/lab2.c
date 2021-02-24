#include <stdio.h>
int main(){

int number;
int result;

writef("Enter a number");
scanf("%d", &number);

if (number > 99) {
	result = number/100;
	writef(result);
	}
else {
writef("You have entered number less than 99");
}

return 0;
}
