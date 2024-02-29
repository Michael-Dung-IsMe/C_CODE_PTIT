#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//BÀI 131 - LAB01-0007: GIA TRI TRUNG BINH CUA 1 MANG
int main(){
	int n; scanf("%d", &n);
	int a[n+3];
	float average = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		average += a[i];
	}
	printf("%.3f", average/n);
}

//BÀI 132 - TEST-NHIPHAN: CHUYEN SANG SO NHI PHAN
int main(){
	int n; scanf("%d", &n);
	int a[16] = {0};
	int cnt = 0;
	if(n == 0)
		printf("0");
	while(n){
		a[cnt++] = n%2;
		n /= 2;
	}
	for(int i = cnt-1; i >= 0; --i)
		printf("%d", a[i]);
}

//BÀI 133 - testMD (NOT FOUND)

//BÀI 134 - TST015: BAN GHI (Struct)
struct tamgiac{
	float a, b, c;
	float S;
};

typedef struct tamgiac tg;

int cmp(const void *xp, const void *yp){
	tg *x = (tg *)xp;
	tg *y = (tg *)yp;
	if(x->S < y->S) return -1;
	else return 1;
}

int main(){
	int t; scanf("%d", &t);
	tg m[t+3];
	for(int i = 0; i < t; ++i){
		scanf("%f%f%f", &m[i].a, &m[i].b, &m[i].c);
		float p = (m[i].a + m[i].b + m[i].c)/2;
		m[i].S = sqrt(p * (p - m[i].a) * (p - m[i].b) * (p - m[i].c));
	}
	qsort(m, t, sizeof(tg), cmp);
	for(int i = 0; i < t; ++i)
		printf("%1.f %1.f %1.f\n", m[i].a, m[i].b, m[i].c);
}

//BÀI 135 - TST016: MANG KI TU
int main(){
	char s1[200];
	scanf("\n");
	gets(s1);
	int dem1, dem2, dem3, dem4, dem5, dem6, dem7, dem8;
	dem1 = dem2 = dem3 = dem4 = dem5 = dem6 = dem7 = dem8 = 0;
	for(int i = 0; i < strlen(s1); ++i){
		if(s1[i] == 39)
			dem1++;
		if(s1[i] == '(')
			dem2++;
		if(s1[i] == ')')
			dem3++;
		if(s1[i] == '{')
			dem4++;
		if(s1[i] == '}')
			dem5++;
		if(s1[i] == '[')
			dem6++;
		if(s1[i] == ']')
			dem7++;
		if(s1[i] == '"')
			dem8++;
	}
	if(dem1%2 || dem2%2 || dem3%2 || dem4%2 || dem5%2 || dem6%2 || dem7%2 || dem8%2)
		printf("0");
	else
		printf("1");
}

//BÀI 136 - C01031: PHAN TICH THUA SO NGUYEN TO 2
int main(){
	int n; scanf("%d", &n);
	int k = n;
	for(int i = 2; i*i <= n; ++i){
		while(k%i == 0){
			printf("%d", i);
			k /= i;
			if(k > 1)
				printf("x");
		}
	}
	if(k > 1)
		printf("%d", k);
}

//BÀI 137 - C01032: TICH THUA SO NGUYEN TO
int main(){
	int t; scanf("%d", &t);
		while(t--){
		int n; scanf("%d", &n);
		int k = n, tich = 1;
		for(int i = 2; i*i <= n; ++i){
			int cnt = 0;
			while(k%i == 0){
				if(cnt < 1)
					tich *= i;
				k /= i;
				cnt++;
			}
		}
		if(k > 1)
			tich *= k;
		printf("%d\n", tich);
	}
}

//BÀI 138 - C01054: TONG UOC SO
int main(){
	int t; scanf("%d", &t);
	long long sum = 0;
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i = 2; i*i <= n; i++){
			while(n%i == 0){
				n /= i;
				sum += i;
			}
		}
		if(n > 1)
			sum += n;
	}
	printf("%lld", sum);
}

//BÀI 139 - C01065: DEM CHU SO NGUYEN TO
int main(){
	long long n; scanf("%lld", &n);
	int a[10] = {0};
	while(n){
		a[n%10]++;
		n /= 10;
	}
	for(int i = 0; i < 10; ++i){
		if(a[i] > 0 && (i == 2 || i == 3 || i == 5 || i == 7))
			printf("%d %d\n", i, a[i]);
	}
}

//BÀI 140 - C02014: HINH VUONG
int main(){
    int n; scanf("%d", &n);
    for(int i = n; i > 1; --i){
    	for(int j = n; j > i; --j)
    		printf("%d", j);
    	for(int j = 1; j <= 2*i-1; ++j)
    		printf("%d", i);
    	for(int j = i+1; j <= n; ++j)
    		printf("%d", j);
    	printf("\n");
	}
	for(int i = n; i > 0; --i)
		printf("%d", i);
	for(int i = 2; i <= n; ++i)
		printf("%d", i);
	printf("\n");
	for(int i = 2; i <= n; ++i){
		for(int j = n; j > i; --j)
			printf("%d", j);
		for(int j = 1; j <= 2*i-1; ++j)
			printf("%d", i);
		for(int j = i+1; j <= n; ++j)
			printf("%d", j);
		printf("\n");
	}
}

//END
