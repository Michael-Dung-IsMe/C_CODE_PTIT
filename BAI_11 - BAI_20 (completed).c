#include <stdio.h>
#include <math.h>

//BÀI 11 - C01015: PHUONG TRINH BAC HAI
int main(){
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if((a<=1000 && b<=1000 && c<=1000) && (a!=0 || b!=0 || c!=0)){
		if(a == 0 && b == 0 && c != 0){
			printf("NO");
		}
		else{
			float delta = (b*b)-4*a*c;
			if(delta<0){
				printf("NO");
			}
			else if(delta>0){
				printf("%.2f", (-b+sqrt(delta))/(2*a));
				printf(" %.2f",(-b-sqrt(delta))/(2*a));
			}
			else{	
				printf("%.2f", -b/(2*a));
			}
		}
	}
	return 0;
}

//BÀI 12 - C01016: BANG CUU CHUONG
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= 10; i++)
		printf("%d ", n*i);
}

//BÀI 13 - C01018: SO CHINH PHUONG
int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for(int i = 1; i <= test_cases; i++){
		int a;
		scanf("%d", &a);
		float sqroot = 1.00*sqrt(a);
		if(sqroot - (int)sqroot == 0)
			printf("YES\n");
		else
			printf("NO\n");
		}
	return 0;
}

//BÀI 14 - C01021: TONG CHU SO - 1
int main(){
	int n; scanf("%d", &n);
	int sum = 0;
	while(n){
		sum += (n%10);
		n /= 10;
	}
	printf("%d", sum);
}

//BÀI 15 - C01022: TONG CHU SO - 2
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int sum = 0;
		while(n){
			sum += n%10;
			n /= 10;
		}
		printf("%d\n", sum);
	}
}

//BÀI 16 - C01024: BAT DAU VA KET THUC
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[12], cnt = 0;
		while(n){
			a[cnt++] = n%10;
			n /= 10;
		}
		if(a[0] == a[cnt-1])
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 17 - C01026: SO NGUYEN TO
int checkP(int n){
	if(n == 2 || n == 3)
		return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0)
		return 0;
	for(int i = 5; i*i <= n; ){
		if(n%i == 0 || n%(i+2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		if(checkP(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 18 - C01027: GCD
int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b%a, a);
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a,b));
	}
}

//BÀI 19 - C01030: PHAN TICH THUA SO NGUYEN TO 1
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 2; i <= n; ++i){
			while(n%i == 0){
				printf("%d ", i);
				n /= i;
			}
		}
		printf("\n");
	}
}

//BÀI 20 - C01034: LIET KE SO CHINH PHUONG
int main(){
	int l, r;
	int cnt = 0;
	scanf("%d%d", &l, &r);
	for(int i = ceil(sqrt(l)); i*i <= r; ++i)
		cnt++;
	printf("%d\n", cnt);
	for(int i = ceil(sqrt(l)); i*i <= r; ++i)
		printf("%d\n", i*i);
}

//END
