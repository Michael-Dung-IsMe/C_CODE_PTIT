#include <stdio.h>
#include <math.h>

//BÀI 61: FIBONACCI CHECK
long long fibonacci(long long n){
	if (n == 0 || n == 1)
        return 1;
	long long Fn, Fn_1, Fn_2;
	Fn_1 = 0, Fn_2 = 1;
    for(int i = 3; i <= 94; i++){
    	Fn = Fn_1 + Fn_2;
    	if (Fn == n)
	    	return 1;
    	Fn_2 = Fn_1;
    	Fn_1 = Fn;
        }
	return 0;
}

int main(){
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		long long n; scanf("%lld", &n);
		if(fibonacci(n))
		    printf("YES\n");
		else
		    printf("NO\n");
	}
	return 0;
}

//BÀI 62: NON-9 PALINDROMIC NUMBERS
int non_9(int n){
	int A[20];
	int cnt = 0;
	while(n > 0){
		A[cnt] = n%10;
		cnt++;
		n /= 10;
	}
	for(int i = 0; i < cnt; i++){
		if(A[i] != A[cnt-1-i] || A[i] == 9)
			return 0;
	}
	return 1;
}

int main(){
	unsigned int N;
	scanf("%d", &N);
	int count = 0;
	for(int i = 2; i <= N; i++){
		if(non_9(i)){
			printf("%d ", i);
			count++;
		}
	}
	printf("\n%d", count);
}

//BÀI 63: SPECIALLY EVEN NUMBERS
long long checkDigit(long long n){
	int sum, cnt = 0;
	while(n > 0){
		long long reminder = n%10;
		if(reminder%2 != 0)
			return 0;
		sum += reminder;
		n /= 10;
	}
	cnt = 1;
	if(sum%2 == 0)
		cnt++;
	else
		return 0;
	if(cnt == 2)
		return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		if(checkDigit(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 64: LISTING NON-DECREASING NUMBERS
int non_decrease(int n){
	int c = n%10;
	while(n > 0){
		int b = n%10;
		if(b > c)
			return 0;
		else
			c = b;
			n /= 10;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int N; scanf("%d", &N);
		for(int i = pow(10,N-1); i < pow(10,N); i++){
			if(non_decrease(i))
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}

//BÀI 65: PAIR OF NUMBERS
int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);	
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int a1, b1, a2, b2;
		scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
		int check1 = gcd(a1,b1);
		int check2 = gcd(a2,b2);
		if(check1 == check2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 66: COUNTING PRIME NUMBERS
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

int checkDigit(int n){
	while(n > 0){
		int reminder = n%10;
		if(checkP(reminder) == 0)
			return 0;
		else
			n /= 10;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int l,r;
		scanf("%d%d", &l, &r);
		r = fmax(l,r); l = fmin(l,r);
		int count = 0;
		for(int i = l; i <= r; i++){
			if(checkP(i) && checkDigit(i))
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}

//BÀI 67: ODD PALINDROMIC NUMBERS
void odd_palin_num(long long n){
	long long A[100];
	int cnt = 0, sum = 0;
	while(n > 0){
		A[cnt] = n%10;
		cnt++;
		n /= 10;
	}
	for(int i = 0; i < cnt; i++)
		sum += A[i];
	int check = 0;
	for(int i = 0; i <= (cnt-1)/2; i++){
		if(A[i] != A[cnt-1-i] || A[i]%2 == 0 || A[cnt-1-i]%2 == 0 || sum%2 == 0){
			printf("NO\n");
			break;
		}
		else
			printf("YES\n");
			break;
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		odd_palin_num(n);
	}
}

//BÀI 68: GREATEST PRIME DIVISOR (TLE)
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
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		long long max = 0;
		if(checkP(n))
			max = n;
		else{
			for(int i = 2; i*i <= n; i++){
				if(n%i == 0 && checkP(i)){ 
					if(i != n/i && checkP(n/i))
						max = n/i;
					else
						max = i;
				}
			}
		}
		printf("%lld\n", max);
	}
	return 0;
}

//BÀI 69: EVENLY ADVANTAGEOUS NUMBERS
long long evenly_advan_num(long long n){
	long long A[20];
	int cnt = 0, sum = 0;
	while(n > 0){
		A[cnt] = n%10;
		cnt++;
		n /= 10;
	}
	int checkE = 0, checkO = 0;
	for(int i = 0; i < cnt; i++){
		if(A[i] != 0){
			if(A[i]%2 == 0)
				checkE++;
			else
				checkO++;
		}
		else
			continue;
	}
	if(checkE > checkO)
		return 1;
	else
		return 0;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		if(n%2 == 0 && evenly_advan_num(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 70: DIGIT 4
long long anti_4(long long n){
	long long A[20];
	int cnt = 0, sum = 0;
	while(n > 0){
		A[cnt] = n%10;
		if(A[cnt] == 4)
			return 0;
		else{
			sum += A[cnt];
			cnt++;
			n /= 10;
		}
	}
	for(int i = 0; i < cnt; i++){
		if(A[i] != A[cnt-1-i] || sum%10 != 0)
			return 0;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		long long n; scanf("%lld", &n);
		for(long long i = pow(10,n-1); i < pow(10,n); i++){
			if(anti_4(i))
				printf("%lld ", i);
		}
		printf("\n");
	}
}

