#include <stdio.h>
#include <math.h>

//BÀI 31 - C01052: SO UOC SO CHIA HET CHO 2
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int cnt = 0, dem = 1;
		if(n%2)
			printf("0\n");
		else{
			while(n%2 == 0){
				cnt++;
				n /= 2;
			}
			if(n > 1){
				dem = 2;
				for(int i = 3; i <= sqrt(n); ++i){
					if(n%i == 0){
						dem++;
						if(i*i < n)
							dem++;
					}
				}
			}
			printf("%d\n", cnt*dem);
		}
	}
}

//BÀI 32 - C01056: SO KHONG GIAM
int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		int check = 0;
		while(n){
			int du1 = n%10;
			int du2 = (n/10)%10;
			if(du2 > du1){
				check = 1;
				break;
			}
			n/=10;
		}
		if(check)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

//BÀI 33 - C01066: GIA TRI NHO NHAT TRONG BA SO
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int min = a;
	if(b < min)
		min = b;
	else if(c < min)
		min = c;
	printf("%d", min);
}

//BÀI 34 - C02001: HINH VUONG DAU *
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++)
			printf("*");
		printf("\n");
	}
}

//BÀI 35 - C02002: HINH BINH HANH CAC DAU *
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++)
			printf("~");
		for(int j = n-i+1; j <= 2*n-i; j++)
			printf("*");
		printf("\n");
	}
}

//BÀI 36 - C02003: HINH VUONG RONG VOI DAU *
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == 1 || i == n || j == 1 || j == n)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}

//BÀI 37 - C02004: HINH BINH HANH RONG
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n-i; j++)
			printf("~");
		for(int j = n-i+1; j <= 2*n-i; j++){
			if(j == n-i+1 || j == 2*n-i || i == 1 || i == n)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}

//BÀI 38 - C02005: HINH BINH HANH NGUOC
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++)
				printf("~");
		for(int j = i; j < m+i; j++)
			printf("*");
		printf("\n");
	}
}

//BÀI 39 - C02006: HINH BINH HANH NGUOC - RONG
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++)
			printf("~");
		for(int j = i; j < m+i; j++){
			if(j == i || j == m+i-1 || i == 1 || i == n)
				printf("*");
			else
				printf(".");
		}
		printf("\n");
	}
}

//BÀI 40 - C02007: TAM GIAC VUONG TRAI
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
}

//END
