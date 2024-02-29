#include <stdio.h>
#include <math.h>
#include <string.h>
#define ll long long

//BÀI 71 - C03030: SO KHONG GIAM (AC - 0.38s)
int non_decrease(int n){
	int c = n%10;
	n /= 10;
	while(n){
		int b = n%10;
		if(b > c)
			return 0;
		c = b;
		n /= 10;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a = pow(10,n-1), b = pow(10,n);	//Neu ko gan --> moi lan chay vong for se phai tinh ham pow 1 lan --> TLE
		for(int i = a; i < b; ++i){
			if(non_decrease(i))
				printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}

//BÀI 72 - C03031: CAP SO
int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
	
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int x = gcd(a, b), y = gcd(c, d);
		if(x == y)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 73 - C03032: DEM SO NGUYEN TO
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

int divided_10(int n){
	while(n){
		int k = n%10;
		if(checkP(k) == 0)
			return 0;
		n /= 10;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int l, r; scanf("%d%d", &l, &r);
		int cnt = 0;
		if(l > r){
			int tmp  = l;
			l = r;
			r = tmp;
		}
		for(int i = l; i <= r; ++i){
			if(checkP(i) && divided_10(i))
				cnt++;
		}
		printf("%d\n", cnt);
	}
}

//BÀI 74 - C03033: PHAN TICH THUA SO NGUYEN TO
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		printf("%d = ", n);
		int dem = 0;
		for(int i = 2; i <= n; ++i){
			int cnt = 0;
			while(n%i == 0){
				cnt++;
				n /= i;
			}
			if(cnt > 0){
				if(n%i)
					printf("%d^%d", i, cnt);
				if(n > 1)
					printf(" * ");
			}
		}
		printf("\n");
	}
}

//BÀI 75 - C03034: CHIA HET CHO 2
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

//BÀI 76 - C03036: SO THUAN NGHICH LE
int palin_odd(ll n){
	ll cnt = 0, a[20] = {0};
	while(n){
		a[cnt] = n%10;
		if(a[cnt]%2 == 0) return 0;
		cnt++; n /= 10;
	}
	if(cnt%2 == 0) return 0;
	for(ll i = 0; i < cnt; ++i){
		if(a[i] != a[cnt-i-1])
			return 0;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		if(palin_odd(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 77 - C03037: DEM CHU SO NGUYEN TO
int main(){
	ll n; scanf("%lld", &n);
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

//BÀI 78 - C03040: SO SMITH
int tcs(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
	int n; scanf("%d", &n);
	int sum1 = tcs(n), sum2 = 0, k = n;
	for(int i = 2; i <= k; ++i){
		while(k%i == 0){
			if(i >= 10)
				sum2 += tcs(i);
			else
				sum2 += i;
			k /= i;
		}
	}
	if(sum1 - sum2)
		printf("NO");
	else
		printf("YES");
}

//BÀI 79 - C03041: HINH VUONG
	int t; scanf("%d", &t);
	while(t--){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x2-x1 == y2-y1 && x2-x1 != 0 && y2-y1 != 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 80 - C03042: SO GIAM
int dec_num(int n){
	int k = n%10;
	n /= 10;
	while(n){
		int l = n%10;
		if(l <= k)
			return 0;
		k = l;
		n /= 10;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int cnt = 0;
		int a, b; scanf("%d%d", &a, &b);
		for(int i = a; i <= b; ++i){
			if(dec_num(i))
				cnt++;
		}
		printf("%d\n", cnt);
	}
}

//END
