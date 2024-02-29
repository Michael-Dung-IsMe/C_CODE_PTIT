#include <stdio.h>
#include <math.h>

//BÀI 51 - C02028: TAM GIAC KI TU - 2
int main(){
	int n;
	scanf("%d", &n);
	int j = 0;
	for(int i = n; i > 0; i--){
		for(j; j < 2*n; j+=2){
			printf("%c", (char)(65+j));
		}
		j -= 2*(i-1);
		printf("\n");
	}
	return 0;
}

//BÀI 52 - C02031: TAM GIAC KI TU - 5
int main(){
	int n;
	scanf("%d", &n);
	for(int i = n; i > 0; i--){
		for(int j = i-2; j < 2*(i-1); j++)
			printf("%c", (char)(65+j));
		printf("\n");
	}
	return 0;
}

//BÀI 53 - C03001: TONG CHU SO CHIA HET CHO 10
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int sum = 0;
		while(n){
			sum += n%10;
			n /= 10;
		}
		if(sum%10)
			printf("NO\n");
		else
			printf("YES\n");
	}
}

//BÀI 54 - C03002: SO NGUYEN TO NHO HON N
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;	
	}
	return 1;
}

int main(){
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; ++i){
		if(checkP(i))
			printf("%d\n", i);
	}
}

//BÀI 55 - C03003: LIET KE N SO NGUYEN TO DAU TIEN
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

int main(){
	int n; scanf("%d", &n);
	int count = 0, i = 2;
	while(count < n){
		if(checkP(i)){
			printf("%d\n", i);
			count++;
		}
		i++;
	}
}

//BÀI 56 - C03004: GCD - LCM
long long gcd(long long a, long long b){
	if(b == 0)
		return a;
	return gcd(b, a%b);	
}

long long lcm(long long a, long long b){
	return (a*b)/gcd(a,b);
}

int main(){
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld\n%lld", gcd(a,b), lcm(a,b));
}

//BÀI 57 - C03005: LIET KE CAC CAP SNT CUNG NHAU
int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

void sntcn(int a, int b){
	for(int i = a; i <= b; ++i){
		int j = i+1;
		while(j <= b){
			int k = gcd(i,j);
			if(k == 1 || (i%k != 0 && j%k != 0))
				printf("(%d,%d)\n", i, j);
			j++;
		}
	}
}

int main(){
	int l, r;
	scanf("%d%d", &l, &r);
	sntcn(l,r);
}

//BÀI 58 - C03006: PHAN TICH THUA SO NGUYEN TO 3 (XEM LAI --> Hieu cach lam)
int main(){
	int t; scanf("%d", &t);
	int m = 1;
	while(t--){
		int n; scanf("%d", &n);
		printf("Test %d: ", m++);
		for(int i = 2; i <= n; ++i){
			int cnt = 0;
			while(n%i == 0){
				cnt++;
				n /= i;
				if(n%i != 0)
					printf("%d(%d) ", i, cnt);
			}
			if(n == 1) 
				break;
		}
		printf("\n");
	}
}

//BÀI 59 - C03007: VUA NGUYEN TO VUA THUAN NGHICH
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

int palin(int n){
	int a[11] = {0};
	int cnt = 0;
	while(n){
		a[cnt++] = n%10;
		n /= 10;
	}
	for(int i = 0; i < cnt; ++i){
		if(a[i] != a[cnt-i-1])
			return 0;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int l, r;
		scanf("%d%d", &l, &r);
		if(l > r){
			int tmp = l;
			l = r;
			r = tmp;
		}
		int k = 0;
		for(int i = l; i <= r; ++i){
			if(checkP(i) && palin(i)){
				printf("%d ", i);
				k++;
			}
			if(k == 10){
				printf("\n");
				k = 0;
			}	
		}
		printf("\n");
	}
}

//BÀI 60 - C03008: SO HOAN HAO NHO HON N
int main(){
	int n;
	scanf("%d", &n);
	if(n > 33550336) printf("6 28 496 8128 33550336");
	else if(n > 8128) printf("6 28 496 8128");
	else if(n > 496) printf("6 28 496");
	else if(n > 28) printf("6 28");
	else if(n > 6) printf("6");
}

//END
