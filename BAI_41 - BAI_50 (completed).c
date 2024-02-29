#include <stdio.h>
#include <math.h>

//BÀI 41 - C02008: TAM GIAC VUONG TRAI - RONG
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			if(i == 1 || i == n || j == 1 || j == i)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}

//BÀI 42 - C02009: TAM GIAC VUONG PHAI
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j <= n-i)
				printf("~");
			else
				printf("*");
		}
		printf("\n");
	}
}

//BÀI 43 - C02010: HINH CHU NHAT - 1
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		int cnt = 0;
		if(i <= b){
			for(int j = i; j <= b; j++)
				printf("%d", j); cnt++;
				if(cnt < b){
				for(int k = i-1; k >= 1; k--)
					printf("%d", k);
				}
		}
		else{
			printf("%d", i);
			for(int j = b-1; j >= 1; j--)
				printf("%d", j);
		}
		printf("\n");
	}
}

//BÀI 44 - C02011: HINH CHU NHAT - 2
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		int cnt = 0;
		if(i <= b){
			for(int j = i; j <= b; j++)
				printf("%d", j); cnt++;
				if(cnt < b){
				for(int k = b-1; k > b-i; k--)
					printf("%d", k);
				}
		}
		else{
			printf("%d", i);
			int count = 1;
			for(int j = i-1; ; j--){
				printf("%d", j); count++;
				if(count == b)
					break;
				}
		}
		printf("\n");
	}
}

//BÀI 45 - C02012: HINH CHU NHAT - 3
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		int cnt = 0;
		if(i <= b){
			for(int j = i; j >= 1; j--)
				printf("%d", j); cnt++;
				if(cnt < b){
				for(int k = 2; k <= b-i+1; k++)
					printf("%d", k);
				}
		}
		else{
			int count = 0;
			for(int j = i; ; j--){
				printf("%d", j);
				count++;				
				if(count == b)	break;
			}
		}
		printf("\n");
	}
}

//BÀI 46 - C02013: HINH CHU NHAT - 4
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	int n = fmax(a,b);
	int cnt = 1;
	for(int i = a; (i > 0 || cnt < a); --i){
		int j = n, check = 0;
		while(j > 0){
			printf("%d", j);
			check++;
			if(check >= b)
				break;
			j--;
		}
		j = 1;
		while(check < b){
			printf("%d", ++j);
			check++;
		}
		cnt++;
		n--;
		printf("\n");
	}
}

//BÀI 47 - C02023: HINH CHU NHAT KI TU - 1
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
        int c = fmax(a,b);
        for(int j = 1; j <= b; j++){
            if(j < i)
                printf("%c", 96 + c--);
            else
                printf("%c", 96+c);
		}
		printf("\n");
	}
}

//BÀI 48 - C02024: HINH CHU NHAT KI TU - 2
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		if(i <= b){
			int cnt = 0;
			for(int j = i; j <= b; j++)
				printf("%c", (char)(64+j)); cnt++;
			if(cnt < b){
				for(int k = i-1; k >= 1; k--){
					printf("%c", (char)(64+k));
				}
			cnt = 0;
			}
		}
		else{
			for(int j = b; j >= 1; j--)
				printf("%c", (char)(64+j));
		}
		printf("\n");
	}
}

//BÀI 49 - C02025: HINH CHU NHAT KI TU - 3
int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	for(int i = 1; i <= a; i++){
		if(i <= b){
			int cnt = 0;
			for(int j = i; j <= b; j++)
				printf("%c", (char)(63+j)); cnt++;
			if(cnt < b){
				for(int k = b-i+1; k < b; k++){
					printf("%c", (char)(63+b));
				}
			}
		}
		else{
			for(int j = 1; j <= b; j++)
				printf("%c", (char)(63+b));
		}
		printf("\n");
	}
}

//BÀI 50 - C02026: HINH CHU NHAT KI TU - 4
int main(){
	int a,b; scanf("%d%d", &a, &b);
	for(int i = a; i >= 1; i--){
		if(i >= b){
			for(int j = 1; j <= b; j++)
				printf("%c", (char)(64+b));
		}
		else{
			int cnt = 0;
			for(int j = i; j <= b; j++)
				printf("%c", (char)(64+j)); cnt++;
			if(cnt < b){
				for(int k = b-i+1; k < b; k++)
					printf("%c", (char)(64+b));
			}
		}
		printf("\n");
	}
}

//END
