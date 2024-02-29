#include <stdio.h>
#include <math.h>
#define ll long long

//BÀI 61 - C03009: SO HOAN HAO TRONG DOAN
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

//BÀI 62 - C03010: SO STRONG NHO HON N
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int k = i, sum = 0;
		while(k){
			int tich = 1;
			int m = k%10;
			for(int j = 2; j <= m; ++j)
				tich *= j;
			sum += tich;
			k /= 10;
		}
		if(sum == i)
			printf("%d ", i);
	}
}

//BÀI 63 - C03011: SO STRONG TRONG DOAN
int main(){
	int a, b; scanf("%d%d", &a, &b);
	if(a > b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	for(int i = a; i <= b; ++i){
		int k = i, sum = 0;
		while(k){
			int tich = 1;
			int m = k%10;
			for(int j = 2; j <= m; ++j)
				tich *= j;
			sum += tich;
			k /= 10;
		}
		if(sum == i)
			printf("%d ", i);
	}
}

//BÀI 64 - C03012: KIEM TRA SO FIBONACCI 1
int main(){
	long long A[93];
	for(long long j = 2; j < 93; j++){
		A[0] = 1;
		A[1] = 1;
		A[j] = A[j-1] + A[j-2];
	}
	int check = 0;
	long long n; scanf("%lld", &n);
	for(int i = 0; i < 93; ++i){
		if(A[i] == n){
			check = 1;
			break;
		}
	}
	if(check) printf("1");
	else printf("0");
	return 0;
}

//BÀI 65 - C03013: LIET KE N SO FIBONACCI DAU TIEN
long long fibo(int n){
	if(n == 0 || n == 1)
		return n;
	else
		return fibo(n-1) + fibo(n-2);
}

int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		printf("%d ", fibo(i-1));
}

//BÀI 66 - C03014: LCM - GCD
long long gcd(long long a, long long b){
	if(b == 0)
		return a;
	return gcd(b, a%b);	
}

long long lcm(long long a, long long b){
	return (a*b)/gcd(a,b);
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long a, b;
		scanf("%lld%lld", &a, &b);
		if(a > b){
			int tmp = a;
			a = b;
			b = tmp;
		}
		printf("%lld %lld\n", lcm(a,b), gcd(a,b));
	}
}

//BÀI 67 - C03018: SO DEP 1
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n %(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int fibo(long long n){
	long long a = 5*n*n - 4;
	long long b = 5*n*n + 4;
	if(((double)sqrt(a) == (int)sqrt(a)) || ((double)sqrt(b) == (int)sqrt(b))) return 1;
		return 0;
}

int main(){
	int a, b; scanf("%d%d", &a, &b);
	if(a > b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	for(int i = a; i <= b; ++i){
		int k = i, sum = 0;
		while(k){
			sum += k%10;
			k /= 10;
		}
		if(checkP(i) && fibo(sum))
			printf("%d ", i);
	}
}

//BÀI 68 - C03024: SO SANH TONG CHU SO
int divided(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int a, b; scanf("%d%d", &a, &b);
	int sum_a = divided(a);
	int sum_b = divided(b);
	if(sum_a > sum_b)
		printf("%d %d", b, a);
	else
		printf("%d %d", a, b);
}

//BÀI 69 - C03028: TAM GIAC PASCAL
ll pascal(ll k, ll n){
	if(k == 1 || k == n)
		return 1;
	else
		return pascal(k-1, n-1) + pascal(k, n-1);
}

int main(){
	ll n; scanf("%lld", &n);
	for(ll i = 1; i <= n; ++i){
		for(ll j = 1; j <= i; ++j)
			printf("%lld ", pascal(j,i));
		printf("\n");
	}
}

//BÀI 70 - C03029: SO CHAN DAC BIET
ll divided_by_2(ll n){
	if(n%2)
		return 0;
	else{
		while(n){
			int k = n%10;
			if(k%2)
				return 0;
			n /= 10;
		}
		return 1;
	}
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		if(divided_by_2(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//END
