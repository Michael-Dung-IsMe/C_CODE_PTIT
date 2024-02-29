#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



//BÀI 141 - C02015: TAM GIAC SO - 1
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < 2*i; j++)
			printf("%d", j);
		printf("\n");
	}
}

//BÀI 142 - C02016: TAM GIAC SO - 2
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		if(i%2 == 0){
			for(int j = 2; j <= 2*i; j+=2)
				printf("%d", j);
		}
		else{
			for(int j = 1; j < 2*i; j+=2)
				printf("%d", j);
		}
		printf("\n");
	}
}

//BÀI 143 - C02017: TAM GIAC SO - 3
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < 2*(i-1); j+=2)
			printf("%d", j);
		for(int j = 2*i-1; j >= 1; j-=2)
			printf("%d", j);
		printf("\n");
	}
}

//BÀI 144 - C02018: TAM GIAC SO - 4
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++){
			printf("~");
		}
		int dem = 1;
		for(int j = 1; j <= i; j++){
			printf("%d", dem);
			dem += 2;
		}
		dem -= 4;
		for(int j = 1; j < i; j++){
			printf("%d", dem);
			dem -= 2;
		}
		printf("\n");
	}
}

//BÀI 145 - C02019: TAM GIAC SO - 5
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= 2*i; j+=2)
			printf("%d", j);
		for(int j = 2*(i-1); j >= 2; j-=2)
			printf("%d", j);
		printf("\n");
	}
}

//BÀI 146 - C02020: TAM GIAC SO - 6
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++){
			printf("~");
		}
		for(int j = 2; j <= 2*i; j+=2)
			printf("%d", j);
		for(int j = 2*(i-1); j >= 2; j-=2)
			printf("%d", j);
		printf("\n");
	}
}

//BÀI 147 - C02021: TAM GIAC SO - 7
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int cnt = 1 + i - 1;
		int check = n;
		for(int j = 1; j <= i; j++){
			printf("%d ", cnt);
			cnt = cnt + check - j;
		}
		printf("\n");
	}
	return 0;
}

//BÀI 148 - C02022: TAM GIAC SO - 8
int main(){
	int n; scanf("%d", &n);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		if(i%2 != 0){
			for(int j = 1; j <= i; j++){
				printf("%d ", cnt++);
			}
		}
		else{
			cnt = cnt + i - 1;
			for(int j = i; j >= 1; j--){
				printf("%d ", cnt--);
			}
			cnt = cnt + i + 1;
		}
		printf("\n");
	}
	return 0;
}

//BÀI 149 - C02027: TAM GIAC KI TU - 1
int main(){
	int n; scanf("%d", &n);
	int cnt = 97;
	for(int i = 1; i <= n; i++){
		if(i%2 != 0){
			for(int j = 1; j <= i; j++){
				printf("%c ", (char)cnt++);
			}
		}
		else{
			cnt = cnt + i - 1;
			for(int j = i; j >= 1; j--){
				printf("%c ", (char)cnt--);
			}
			cnt = cnt + i + 1;
		}
		printf("\n");
	}
	return 0;
}

//BÀI 150 - C02029: TAM GIAC KI TU - 3
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		char cnt = 'A' + i - 1;
		int check = n;
		for(int j = 1; j <= i; j++){
			printf("%c ", (char)(cnt));
			cnt = cnt + check - j;
		}
		printf("\n");
	}
	return 0;
}

//END
