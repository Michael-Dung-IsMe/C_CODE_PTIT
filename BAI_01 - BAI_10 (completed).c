#include <stdio.h>
#include <math.h>

//BÀI 1 - C01001: GAP DOI
int main(){
	int n;
	scanf("%d", &n);
	printf("%d", n*2);
	return 0;
}

//BÀI 2 - C01002: GAP DOI 2
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%d\n", n*2);
	}
	return 0;
}

//BÀI 3 - C01003: BINH PHUONG
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		printf("%lld\n", (long long)n*n);
	}
	return 0;
}

//BÀI 4 - C01004: SO THAP PHAN
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		printf("%.15lf\n", (double)1/n);
	}
	return 0;
}

//BÀI 5 - C01005: TINH TONG
int main(){
	int a, b; scanf("%d%d", &a, &b);
	printf("%d", a+b);
}

//BÀI 6 - C01006: PHEP TOAN CO BAN 1
int main(){
	int a, b; scanf("%d%d", &a, &b);
	if(b == 0) printf("0");
	else
		printf("%d %d %lld %.2f %d", a+b, a-b, 1ll*a*b, (float)a/b, a%b);
}

//BÀI 7 - C01007: PHEP TOAN CO BAN 2
int main(){
	int a, b; scanf("%d%d", &a, &b);
	printf("%d\n%d\n%lld\n%d\n%d\n%.2f", a+b, a-b, 1ll*a*b, a/b, a%b, (float)a/b);
}

//BÀI 8 - C01009: CHUYEN DOI THANG DO NHIET DO
int main(){
	int c; scanf("%d", &c);
	printf("%.2f", (((float)c*9/5)+32));
}

//BÀI 9 - C01010: CHUYEN DOI NGAY THANG
int main(){
	int n; scanf("%d", &n);
	printf("%d %d %d", n/365, (n%365)/7, (n%365)%7);
}

//BÀI 10 - C01014: PHUONG TRINH BAC NHAT
int main(){
	int a, b; scanf("%d%d", &a, &b);
	if(a == 0 && b != 0)
		printf("Vo nghiem");
	else if(a == 0 && b == 0)
		printf("Vo so nghiem");
	else
		printf("%.2f", (float)(-b)/a);
}

//END
