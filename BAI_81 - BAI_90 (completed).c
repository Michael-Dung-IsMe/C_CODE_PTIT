#include <stdio.h>
#include <math.h>
#define ll long long

//BÀI 81 - C03046: CHU SO 4
int palin_no_4(int n){
	int sum = 0, cnt = 0, a[20] = {0};
	while(n){
		a[cnt] = n%10;
		if(a[cnt] == 4)
			return 0;
		sum += a[cnt++];
		n /= 10;
	}
	if(sum%10) return 0;
	for(int i = 0; i < cnt; ++i){
		if(a[i] != a[cnt-1-i])
			return 0;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a = pow(10, n-1), b = pow(10, n);
		for(int i = a; i < b; ++i){
			if(palin_no_4(i))
				printf("%d ", i);
		}
		printf("\n");
	}
}

//BÀI 82 - C03048: SO UU THE CHAN
int uu_the_chan(ll n){
	int chan = 0, le = 0;
	if(n%2)
		return 0;
	while(n){
		if((n%10)%2) le++;
		else chan++;
		n /= 10;
	}
	if(chan <= le)
		return 0;
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		if(uu_the_chan(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 83 - C03049: SO UU THE LE
int uu_the_le(ll n){
	ll chan = 0, le = 0;
	while(n){
		if((n%10)%2)
			le++;
		else
			chan++;
		n /= 10;
	}
	if(le <= chan)
		return 0;
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		if(uu_the_le(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 84 - C03050: DIEM TRUNG TAM
int p[100005];

int main(){
	int t; scanf("%d", &t);
	int k = t;
	k--;
	int check = 0;
	while(k--){
		int a, b;
		scanf("%d%d", &a, &b);
		p[a]++;	p[b]++;
	}
	for(int i = 1; i <= t; ++i){
		if(p[i] == t-1){
			check = 1;
			break;
		}
	}
	if(check)
		printf("Yes");
	else
		printf("No");
}

//BÀI 85 - C03051: SO CHI CO 3 UOC SO
ll checkP(ll n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(ll i = 5; i*i <= n; ){
		if((n%i == 0 || n%(i+2) == 0))
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll a, b, cnt = 0;
		scanf("%lld%lld", &a, &b);
		ll i = sqrt(a);
		for(i; i*i <= b; ++i){
			if(checkP(i))
				cnt++;
		}
		printf("%lld\n", cnt);
	}
}

//BÀI 86 - C03053: CAP SO NGUYEN TO
int checkP(int n){
	if(n == 2 || n == 3) return 1;
	if(n == 1 || n%2 == 0 || n%3 == 0) return 0;
	for(int i = 5; i*i <= n; ){
		if((n%i == 0 || n%(i+2) == 0))
			return 0;
		i += 6;
	}
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		for(int i = 2; i <= n/2; ++i){
			if(checkP(i) && checkP(n-i))
				printf("%d %d ", i, n-i);
		}
		printf("\n");
	}
}

//BÀI 87 - C03054: CAT DOI
int main(){
	int T; scanf("%d", &T);
	while(T--){
		ll n; scanf("%lld", &n);
		ll x = log10(n)+1;
		int cnt = 0;
		ll m = n;
		while(m > 0){
			if(m%10 != 0 && m%10 != 1 && m%10 != 8 && m%10 != 9)
				cnt++;
			m /= 10;
		}
		if(cnt != 0 || n == 0){
			printf("INVALID\n");
			continue;
		}
		cnt = 0;
		while(x >= 0){
			ll k = (ll)pow(10,x);
			if((n/k == 0 || n/k == 8 || n/k == 9) && cnt != 0)
				printf("0");
			if(n/k == 1){
				printf("1");
				cnt++;
			}
			n %= k;
			x--;
		}
		if(cnt == 0)
			printf("INVALID\n");
		else
			printf("\n");
	}
}

//BÀI 88 - C03060: CHIA HET
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	if(n == 1)
		printf("No");
	else{
		int mark = 0;
		for(int i = 2; i <= n; i+=2){
			int m = i;
			while(m%2 == 0){
				mark++;
				if(mark == k)
					break;
				m /= 2;
			}
			if(mark == k)
				break;
		}
		if(mark == k)
			printf("Yes");
		else
			printf("No");
	}
}

//BÀI 89 - C03061: SO DEP
int pretty_num(ll n){
	ll cnt = 0, a[20] = {0};
	while(n){
		a[cnt++] = n%10;
		n /= 10;
	}
	int check = 1;
	if(a[0] == 2*a[cnt-1] || 2*a[0] == a[cnt-1])
		check = 1;
	else
		check = 0;
	for(int i = 1; i < cnt-1; ++i){
		if(a[i] != a[cnt-1-i]){
			check = 0;
			break;
		}
	}
	if(check)
		return 1;
	return 0;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		ll n; scanf("%lld", &n);
		if(pretty_num(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 90 - C04001: SO CHAN TRONG DAY
int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n; scanf("%d", &n);
		int a[n+2];
		for(int i = 0; i < n; ++i){
			scanf("%d", &a[i]);
			if(!(a[i]%2))
				printf("%d ", a[i]);
		}
		printf("\n");
	}
}

//END
