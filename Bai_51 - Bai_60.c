#include <stdio.h>
#include <math.h>

//BÀI 51: SMALLEST SQUARE
int main(){
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("\n");
	scanf("%d%d%d%d", &x3, &y3, &x4, &y4);
	int x_min = fmin(x1, x3);
	int x_max = fmax(x2, x4);
	int y_min = fmin(y1, y3);
	int y_max = fmax(y2, y4);
	int sqr = fmax(x_max - x_min, y_max - y_min);
	printf("%d", sqr*sqr);
	return 0;
}

//BÀI 52: PRODUCT OF PRIME FACTORS
void checkP(int n);

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		checkP(n);
		printf("\n");
	}
}

void checkP(int n){
	int A[100], B[100];
	int dem = 0, cnt = 0;
	int i = 2, mul = 1;
	while(n > 1){
		if(n%i == 0){
			n /= i;
			cnt++;
			if(n%i != 0){
				A[dem] = i;
				B[dem] = cnt;
				dem++;
				cnt = 0;
				}
			}
		else
			i++;
	}
	for(int j = 0; j < dem; j++)
		mul *= A[j];
	printf("%d", mul);
}

//BÀI 53: LIST OF SQUARE NUMBERS
int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	if(m > n){
		int tmp = m;
		m = n;
		n = tmp;
	}
	else{
		int count = 0;
		for(int i = ceil(sqrt(m)); i*i <= n; i++){
				count++;
		}
		printf("%d\n", count);
		for(int i = ceil(sqrt(m)); i*i <= n; i++)
			printf("%d\n", i*i);
	}
	return 0;
}

//BÀI 54: NON-DECREASING NUMBER
long long no_decrease(long long n){
	int check = 9;
	while(n > 0){
		long long reminder = n%10;
		if(reminder <= check)
			check = reminder;
		else
			return 0;
		n /= 10;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		if(no_decrease(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 55: FIRST-LAST EXCHANGE (PASSED)
int main(){
	int n; scanf("%d", &n);
	int dem = 0, k = n;
	while(k >= 10){
		k /= 10; dem++;
	}
	int A[dem+1];
	int cnt = dem;
	while(n > 0){
		A[cnt] = n%10;
		n /= 10;
		cnt--;
	}
	if(A[0] != A[dem]){
		if(A[dem] != 0){
			A[0] = A[0] + A[dem];
			A[dem] = A[0] - A[dem];
			A[0] = A[0] - A[dem];
			for(int i = 0; i <= dem; i++)
				printf("%d", A[i]);
		}
		else{
			A[dem] = A[0];
			for(int i = 0; i < dem; i++){
				A[i] = A[i+1];
				printf("%d", A[i]);
			}
		}	
	}
}

//BÀI 56: DIVISIBLE-BY-2 DIVISORS
int main(){
	int T; scanf("%d", &T);
	while(T--){
		unsigned int n; scanf("%d", &n);
		if(n < 1) return 0;
		else{
			int cnt = 0;
			if(n%2 == 0) cnt = 1;
			for(int i = 2; i*i <= n; i++){
				if(n%i == 0){
					if(i%2 == 0)
						cnt++;
					if(i != n/i){
						if((n/i)%2 == 0)
							cnt++;
					}
				}
			}
			printf("%d\n", cnt);
		}
	}
}

//BÀI 57: LISTING PAIRS OF COPRIME NUMBERS
int gcd(int a, int b){
	int max = fmax(a,b);
	for(int i = 2; i < max; i++){
		if(a%i == 0 && b%i == 0)
			return 0;
	}
	return 1;
}

int main(){
	int l, r;
	scanf("%d%d", &l, &r);
	if(l > r){
		int tmp = l;
		l = r;
		r = tmp;
	}
	for(int i = l; i <= r; i++){
		for(int j = i+1; j <= r; j++){
			if(gcd(i,j))
				printf("(%d,%d)\n", i, j);
		}
	}
	return 0;
}

//BÀI 58: PALINDROME PRIMES
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

int palin(int n){
	int A[20];
	int cnt = 0;
	while(n > 0){
		A[cnt] = n%10;
		cnt++;
		n /= 10;
	}
	for(int i = 0; i < cnt; i++){
		if(A[i] != A[cnt-1-i])
			return 0;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int l,r;
		scanf("%d%d", &l, &r);
		if(l > r){
			l+=r;
			r = l - r;
			l-=r;
		}
		int cnt = 0;
		for(int i = l; i <= r; i++){
			if(checkP(i) && palin(i)){
				printf("%d ", i);
				cnt++;
			}
			if(cnt%10 == 0){
				printf("\n");
			}
		}
		printf("\n\n");
	}
	return 0;
}

//BÀI 59: PERFECT NUMBERS IN AN INTERVAL
int perfect_num(int n){
	int sum = 0;
	for(int i = 1; i <= n/2; i++){
		if(n%i == 0)
			sum += i;
	}
	if(sum == n)
		return 1;
	else
		return 0;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if(a > b){
		for(int i = b; i <= a; i++)
			if(perfect_num(i))
				printf("%d ", i);
	}
	else{
		for(int i = a; i <= b; i++)
			if(perfect_num(i))
				printf("%d ", i);
	}
	return 0;
}

//BÀI 60: STRONG NUMBERS IN AN INTERVAL
int strong_num(int n){
	int remainder, sum = 0, a = n;
	for(a; a > 0; a /= 10)
	{
		int i, b = 1;
		remainder = a%10;
		for(i = 1; i <= remainder; i++)
			b *= i;
		sum += b;
	}
	if(sum == n)
		return 1;
	else
		return 0;
}

int main(){
	int a, b;
	scanf("%d%d", &a, &b);
	if(a > b){
		for(int i = b; i <= a; i++)
			if(strong_num(i))
				printf("%d ", i);
	}
	else{
		for(int i = a; i <= b; i++)
			if(strong_num(i))
				printf("%d ", i);
	}
	return 0;
}

