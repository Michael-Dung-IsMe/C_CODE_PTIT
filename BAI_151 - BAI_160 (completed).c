#include <stdio.h>
#include <math.h>
#define ll long long

//BÀI 151 - C02030: TAM GIAC KI TU - 4
int main(){
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2*i; j+=2)
			printf("%c", 64+j);
		for(int j = 2*(i-2); j >= 0; j-=2)
			printf("%c", 64+j);
		printf("\n");
	}	
	return 0;
}

//BÀI 152 - C03015: UOC SO NGUYEN TO LON NHAT
int main(){
	int t; scanf("%d", &t);
	while(t--){
		long long n; scanf("%lld", &n);
		long long a[1005] = {0};
		long long k = n, cnt = 0;
		for(long long i = 2; i*i <= n; ++i){
			if(k%i == 0){
				while(k%i == 0){
					a[cnt] = i;
					k /= i;
				}
				cnt++;
			}
		}
		if(k > 1)
			a[cnt++] = k;
		printf("%lld\n", a[cnt-1]);
	}
}

//BÀI 153 - C03016: KIEM TRA SO FIBONACCI 2
long long fibo(long long n){
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
		if(fibo(n))
		    printf("YES\n");
		else
		    printf("NO\n");
	}
	return 0;
}

//BÀI 154 - C03019: SO DEP 2
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

//BÀI 155 - C03020: SO DEP 3
int pretty_num(int n){
	int a[20] = {0}, b[10] = {0};
	int count = 0, sum = 0;
	while(n){
		a[count] = n%10;
		sum += a[count++];
		b[n%10]++;
		n /= 10;
	}
	if(b[6] == 0 || sum%10 != 8)
		return 0;
	else{
		for(int i = 0; i < count; ++i){
			if(a[i] != a[count-1-i])
				return 0;
		}
	}
	return 1;
}

int main(){
	int a, b; scanf("%d%d", &a, &b);
	if(a > b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	for(int i = a; i <= b; ++i){
		if(pretty_num(i))
			printf("%d ", i);
	}
}

//BÀI 156 - C03022: TONG CHU SO CHIA HET CHO 5
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

int divided_by_5(int n){
	int sum = 0;
	while(n){
		sum += n%10;
		n /= 10;
	}
	if(sum%5)
		return 0;
	return 1;
}

int main(){
	int n; scanf("%d", &n);
	if(n < 6)
		printf("1");
	else{
		printf("5 ");
		int cnt = 1;
		for(int i = 6; i <= n; ++i){
			if(checkP(i) && divided_by_5(i)){
				printf("%d ", i);
				cnt++;
			}
		}
		printf("\n%d", cnt);
	}
}

//BÀI 157 - C03023: SO THUAN NGHICH KO CO CHU SO 9
int palin_no9(int n){
	int a[20] = {0}, b[10] = {0};
	int count = 0;
	while(n){
		a[count++] = n%10;
		b[n%10]++;
		n /= 10;
	}
	if(b[9])
		return 0;
	else{
		for(int i = 0; i < count; ++i){
			if(a[i] != a[count-1-i])
				return 0;
		}
	}
	return 1;
}

int main(){
	int n; scanf("%d", &n);
	int cnt = 0;
	for(int i = 2; i <= n; ++i){
		if(palin_no9(i)){
			printf("%d ", i);
			cnt++;
		}
	}
	printf("\n%d", cnt);
}

//BÀI 158 - C03038: UOC SO CUA GIAI THUA
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, p; scanf("%d%d", &n, &p);
		int i = 1, x = 0;
		while(p*i <= n){
			int k = p*i;
			while(k%p == 0){
				k /= p;
				++x;
			}
			++i;
		}
		printf("%d\n", x);
	}
}

//BÀI 159 - C03045 (BAI 159 BI LAP)
int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		ll a[1005] = {0};
		ll k = n, cnt = 0;
		for(ll i = 2; i*i <= n; ++i){
			if(k%i == 0){
				while(k%i == 0){
					a[cnt] = i;
					k /= i;
				}
				cnt++;
			}
		}
		if(k > 1)
			a[cnt++] = k;
		printf("%lld\n", a[cnt-1]);
	}
}

//BÀI 160 - C03057: TINH TONG LON NHAT VA NHO NHAT
ll change_to_6(ll n){
	ll a[20] = {0}, sum = 0, cnt = 0;
	while(n){
		a[cnt] = n%10;
		if(a[cnt] == 5)
			a[cnt] = 6;
		cnt++;
		n /= 10;
	}
	for(ll i = 0; i < cnt; ++i)
		sum = sum*10 + a[cnt-1-i];
	return sum;
}

ll change_to_5(ll n){
	ll a[20] = {0}, sum = 0, cnt = 0;
	while(n){
		a[cnt] = n%10;
		if(a[cnt] == 6)
			a[cnt] = 5;
		cnt++;
		n /= 10;
	}
	for(ll i = 0; i < cnt; ++i)
		sum = sum*10 + a[cnt-1-i];
	return sum;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll a, b; scanf("%lld%lld", &a, &b);
		ll x = change_to_5(a) + change_to_5(b);
		ll y = change_to_6(a) + change_to_6(b);
		printf("%lld %lld\n", x, y);
	}
}

//END
