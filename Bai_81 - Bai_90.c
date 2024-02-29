#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//BÀI 81: ENCODING
int main(){
	int t; scanf("%d", &t);
	char s1[105];
	char s2[105];
	getchar();
	while(t--){
		gets(s1);
		strcpy(s2,s1);
		for(int i = 0; i < strlen(s2); ++i){
			int cnt = 0, check = 0;
			for(int j = 0; j < strlen(s1); ++j){
				if(s2[i] == s1[j])
					cnt++;
			}
			for(int j = i-1; j >= 0; --j){
				if(s2[i] == s2[j])
					check = 1;
			}
			if(check == 0)
				printf("%c%d", s2[i], cnt);
		}
		printf("\n");
	}
}

//BÀI 82: MERGING RECTANGLES

//Tham khao youtube & sua cho ngan hon : WA ???
long long check_root(long long n){
	long long cp = sqrt(n);
	if(cp*cp == n)
		return cp;
	cp++;
	if(cp*cp == n)
		return cp;
	return 0;
}

void swap(long long *xp, long long *yp){
	long long tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int main(){
	long long a1, b1, a2, b2, a3, b3;
	scanf("%lld%lld%lld%lld%lld%lld", &a1, &b1, &a2, &b2, &a3, &b3);
	long long area = a1*b1 + a2*b2 + a3*b3;
	long long sqr = check_root(area);
	if(sqr == 0)
		printf("NO");
	else{
		if(a1 < b1)	swap(&a1,&b1);
		if(a2 < b2) swap(&a2,&b2);
		if(a3 < b3) swap(&a3,&b3);
		if(a1 == a2 && a2 == a3 && a3 == sqr)
			printf("%lld\n", sqr);
		else{
			if(a2 == sqr)
				swap(&a1,&a2); swap(&b1,&b2);
			if(a3 == sqr)
				swap(&a1,&a3); swap(&b1,&b3);
			if(a1 == sqr){
				b1 = sqr - b1;
				if((b2==b1 && b3==b1) || (a2==b1 && b3==b1)|| (b2==b1 && a3==b1) || (a2==b1 && a3==b1))
					printf("YES");
				else
					printf("NO");
			}
			else
				printf("NO");
		}
	}
}

//Cach tren mang: AC ???
/*
long long ktcp(long long a) {
    long long b = sqrt(a);
    if (b * b == a) return b;
    b++;
    if (b * b == a) return b;
    return 0;
}

int main() {
    long long a, b, c, d, e, f, x, y;
    scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f);
    x = a * b + c * d + f * e;
    y = ktcp(x);
    if (y == 0) {
        printf("NO");
    } else {
        if (a > b) {
            long long temp = a;
            a = b;
            b = temp;
        }
        if (c > d) {
            long long temp = c;
            c = d;
            d = temp;
        }
        if (e > f) {
            long long temp = e;
            e = f;
            f = temp;
        }
        if (b == d && d == f && f == y) {
            printf("%lld\n", y);
        } else {
            if (d == y) {
                long long temp = a;
                a = c;
                c = temp;
                temp = b;
                b = d;
                d = temp;
            }
            if (f == y) {
                long long temp = a;
                a = e;
                e = temp;
                temp = b;
                b = f;
                f = temp;
            }
            if (b == y) {
                a = y - a;
                if ((c == a && e == a) || (d == a && e == a) || (c == a && f == a) || (d == a && f == a)) {
                    printf("YES");
                } else {
                    printf("NO");
                }
            } else {
                printf("NO");
            }
        }
    }
    return 0;
}
*/


//BÀI 83: PRETTY NUMBERS 1
int fibo(int n){
	int fn_1 = 0, fn_2 = 1, fn;
	while(fn_1 <= n){
		if(fn_1 == n)
			return 1;
		fn = fn_1 + fn_2;
		fn_1 = fn_2;
		fn_2 = fn;
	}
	return 0;
}

int checkP(int n){
	if(n == 2 || n == 3)
		return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0)
		return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i+=6;
	}
	return 1;
}

int main(){
	int l,r;
	scanf("%d%d", &l, &r);
	if(l < r){
		for(int i = l; i <= r; i++){
			int sum = 0;
			int k = i;
			while(k > 0){
				sum += k%10;
				k /= 10;
			}
			if(checkP(i) && fibo(sum))
				printf("%d ", i);
		}
	}
	if(l > r){
		for(int i = r; i <= l; i++){
			int sum = 0;
			int k = i;
			while(k > 0){
				sum += k%10;
				k /= 10;
			}
			if(checkP(i) && fibo(sum))
				printf("%d ", i);
		}
	}
	return 0;
}

//BÀI 84: PRETTY NUMBERS 2 (Cach di vai chuong)
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n;
		scanf("%lld", &n);
		switch(n){
			case 2:
				printf("1\n");
				break;
			case 3:
				printf("9\n");
				break;
			case 4:
				printf("18\n");
				break;
			case 5:
				printf("90\n");
				break;
			case 6:
				printf("180\n");
				break;
			case 7:
				printf("900\n");
				break;
			case 8:
				printf("1800\n");
				break;
			case 9:
				printf("9000\n");
				break;
		}
	}
}

//BÀI 85: PRETTY NUMBERS 3
int palin_num(int n){	//Cach dao cac chu so cua n theo chieu nguoc lai
	int a = n;
	int sum = 0;
	while(n > 0){
		sum = (n%10 + sum)*10;	
		n /= 10;
	}
	sum /= 10;
	if(sum - a == 0)
		return 1;
	else
		return 0;
}

int digit_6(int n){
	int check;
	while(n > 0){
		check = n%10;
		if(check == 6) return 1;
		n /= 10;
	}
	return 0;
}

int last_8(int n){
	int sum = 0;
	while(n > 0){
		sum += n%10;
		n /= 10;
	}
	if(sum%10 == 8)	return 1;
	return 0;
}

int main(){
	int l,r; scanf("%d%d", &l, &r);
	if(l > r){
		int m = l;
		l = r;
		r = m;
	}
	for(int i = l; i <= r; i++){
		if(palin_num(i) && digit_6(i) && last_8(i))
			printf("%d ", i);
	}
	return 0;
}

//BÀI 86: MINIMUM SUM AND MAXIMUM SUM
long long change_5(long long n){
	long long sum_1 = 0;
	long long mul = 0;
	while(n > 0){
		long long r = n%10;
		if(r == 5)
			r = 6;
		sum_1 += r*(long long)pow(10,mul);
		mul++;
		n /= 10;
	}
	return sum_1;
}

long long change_6(long long n){
	long long sum_2 = 0;
	long long mul = 0;
	while(n > 0){
		long long r = n%10;
		if(r == 6)
			r = 5;
		sum_2 += r*(long long)pow(10,mul);
		mul++;
		n /= 10;
	}
	return sum_2;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long a,b; scanf("%lld%lld", &a, &b);
		printf("%lld %lld\n", change_6(a) + change_6(b), change_5(a) + change_5(b));
	}
	return 0;
}

//BÀI 87: COUNTING APPEARANCES 2
int A[100005];
int B[100005] ={0};

int main(){
	int T; scanf("%d", &T);
	for(int i = 1; i <= T; i++){
		int n; scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%d", &A[j]);
			B[A[j]]++;
		}
		printf("Test %d: \n", i);
		for(int k = 0; k < n; k++){
			if (B[A[k]] > 0){
				if(B[A[k]] == 1)
					printf("%d appears %d times\n", A[k], B[A[k]]);
				else
					printf("%d appears %d times\n", A[k], B[A[k]]);
				B[A[k]] = 0;
			}
		}
	}
	return 0;
}

//BÀI 88: LEADING NUMBERS
int A[1001];
int B[1001];

int lead_num(int A[], int i, int n){
	for(int j = i+1; j < n; j++){
		if(A[j] >= A[i])
			return 0;
	}
	return 1;
}

void bubble_decend(int B[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n-1; j > i; j--){
			if(B[j] > B[j-1]){
				int tmp = B[j];
				B[j] = B[j-1];
				B[j-1] = tmp;
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int cnt = 0;
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		for(int i = 0; i < n; i++){
			if(lead_num(A, i, n) == 1){
				B[cnt] = A[i];
				cnt++;
			}
		}
		bubble_decend(B,cnt);
		for(int k = 0; k < cnt; k++)
			printf("%d ", B[k]);
		printf("\n");
	}
}

//BÀI 89: LONGEST INCREASING SEQUENCE
int main(){
	int t; scanf("%d", &t);
	int k = 1;
	while(t--){
		int n; scanf("%d", &n);
		int a[n+3];
		int cnt = 1, max = -1e9;
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Test %d:\n", k++);
		for(int i = 0; i < n-1; i++){
			if(a[i] < a[i+1])	++cnt;
			else{
				if(cnt > max)
					max = cnt;
				cnt = 1;
			}
		}
		printf("%d\n", max);
		cnt = 1;
		for(int i = 0; i < n-1; i++){
			if(a[i] < a[i+1]){
				cnt++;
				if(cnt == max){
					for(int j = i-max+2; j <= i+1; j++)
						printf("%d ", a[j]);
					cnt = 1;
					printf("\n");
				}
			}
			else cnt = 1;
		}
	}
}

//BÀI 90: MERGE AND SORT
int a[101];
int b[101];

void bubble_ascend(int A[], int n){
	for(int j = 0; j < n; j++){
		for(int i = n-1; i > j; i--){
			if(A[i] < A[i-1]){
				int tmp = A[i];
				A[i] = A[i-1];
				A[i-1] = tmp;
			}
		}
	}
}

void bubble_decend(int A[], int n){
	for(int j = 0; j < n; j++){
		for(int i = n-1; i > j; i--){
			if(A[i] > A[i-1]){
				int tmp = A[i];
				A[i] = A[i-1];
				A[i-1] = tmp;
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	for(int k = 1; k <= T; k++){
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", a+i);
		for(int i = 0; i < n; i++)
			scanf("%d", b+i);
		bubble_ascend(a,n);
		bubble_decend(b,n);
		int cnt = 1;
		printf("Test %d:\n", k);
		for(int i = 0; i < 2*n; i++){
			if(i%2 == 0)
				printf("%d ", a[i/2]);
			else{
				printf("%d ", b[i-cnt]);
				cnt++;
			}
		}
		printf("\n");
	}
}

