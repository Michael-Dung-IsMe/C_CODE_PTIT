#include <stdio.h>
#include <math.h>

//Please copy code blocks of each exercises to another program and F11(Compile & Run)

//Bài 3
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if (b!=0){
		printf("%d %d %d %.2f %d", a+b, a-b, a*b, 1.00*a/b, a%b);
	}
	else{
		printf("0");
	}
	return 0;
}

//Bài 4
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int a; scanf("%d", &a);
		printf("%d\n", a*a);
	}
	return 0;
}

//Bài 5
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int n;
		scanf("%d", &n);
		printf("%.15lf\n", 1.00/n);
		}
	return 0;
}

//Bài 6
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a == 0 && b!=0){
		printf("No solution");
	}
	else if(a == 0 && b == 0){
		printf("Infinite solutions");
	}
	else{
		printf("%.2f", 1.00*(-b)/a);
	}
	return 0;
}

//Bài 7
int main(){
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if((a<=1000 && b<=1000 && c<=1000) && (a!=0 || b!=0 || c!=0))
		if(a == 0 && b == 0 && c != 0){
			printf("NO");
		}
		else if(a == 0 && c == 0 && b != 0){
			printf("Infinite solutions");
		}
		else{
			float delta = (b*b)-4*a*c;
			if(delta<0){
				printf("NO");
				}
			else if(delta>0){
				printf("%.2f", (-b+sqrt(delta))/(2*a));
				printf(" %.2f",(-b-sqrt(delta))/(2*a));
				}
			else{
				printf("%.2f", -b/(2*a));
				}
			}
		else
			printf("NO");
		return 0;
		}
		
//Bài 8
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int a;
		scanf("%d", &a);
		float sqroot = 1.00*sqrt(a);
		if(sqroot - (int)sqroot == 0)
			printf("YES\n");
		else
			printf("NO\n");
		}
	return 0;
}

//Bài 9
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for (int i = 1; i <= test_cases; i++){
			unsigned int a, b, sum = 0, remainder;
			scanf("%d", &a);
			b = a;
			while(b != 0){
				remainder = b%10;
				sum += remainder;
				b /= 10;
			}
		printf("%d\n", sum);
		}
	return 0;
}
//Bài 10
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for (int i = 1; i <= test_cases; i++){
		unsigned int a, firstDigit, lastDigit;
		scanf("%d", &a);
		lastDigit = a%10;
		while(a >= 10){
			a = a/10;
			firstDigit = a;
		}
		if(firstDigit == lastDigit)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

