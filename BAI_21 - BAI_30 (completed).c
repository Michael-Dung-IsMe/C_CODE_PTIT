#include <stdio.h>
#include <math.h>

//BÀI 21 - C01036: TICH CHU SO
int main(){
	int n; scanf("%d", &n);
	int mul = 1;
	while(n){
		mul *= (n%10);
		n /= 10;
	}
	printf("%d", mul);
}

//BÀI 22 - C01037: TINH TONG TRONG DOAN
int main(){
	int l, r;
	scanf("%d%d", &l, &r);
	int cnt = abs(r-l)+1;
	long long res = (l+r)*cnt/2;
	printf("%lld", res);
}

//BÀI 23 - C01038: THAY DOI DAU CUOI
int main(){
	int n; scanf("%d",  &n);
	int a[20] = {0};
	int cnt = 0;
	while(n){
		a[cnt++] = n%10;
		n /= 10;
	}
	if(a[0] == 0)
		a[0] = a[cnt-1];
	else{
		int tmp = a[cnt-1];
		a[cnt-1] = a[0];
		a[0] = tmp;
		printf("%d", a[cnt-1]);
	}
	for(int i = cnt-2; i >= 0; --i)
		printf("%d", a[i]);
}

//BÀI 24 - C01039: DEM SO CHU SO
int main(){
	int n; scanf("%d",  &n);
	int cnt = 1;
	while(n /= 10)
		cnt++;
	printf("%d", cnt);
}

//BÀI 25 - C01040: SO HOAN HAO
int main(){
	int a, i, sum = 0;
	scanf("%d", &a);
	for(i = 1; i <= a/2; i++){
		if(a%i == 0)
			sum += i;
	}
	if(sum == a)
		printf("1");
	else
		printf("0");
	return 0;
}

//BÀI 26 - C01043: SO STRONG
int main(){
	int n; scanf("%d", &n);
	int sum = 0, a = n;
	while(a){
		int k = 1;
		int du = a%10;
		for(int i = 2; i <= du; ++i)
			k *= i;
		sum += k;
		a /= 10;
	}
	if(sum == n)
		printf("1");
	else
		printf("0");
}

//BÀI 27 - - C01045: CHU SO DAU CUOI
int main(){
	int n; scanf("%d", &n);
	int du = n%10;
	int thg = 0;
	while(n){
		thg = n%10;
		n /= 10;
	}
	printf("%d %d", thg, du);
}

//BÀI 28 - C01048: CHU SO CHAN LE - 1
int main(){
	int n; scanf("%d", &n);
	int even = 0, odd = 0;
	while(n){
		if((n%10)%2)
			odd++;
		else
			even++;
		n /= 10;
	}
	printf("%d %d", odd, even);
}

//BÀI 29 - C01049: CHU SO CHAN LE - 2
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int even = 0, odd = 0;
		while(n){
			if((n%10)%2)
				odd++;
			else
				even++;
			n /= 10;
		}
		printf("%d %d\n", odd, even);
	}
}

//BÀI 30 - C01050: HINH CHU NHAT DAU *
int main(){
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			if(i == 1 || i == m || j == 1 || j == n)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

//END
