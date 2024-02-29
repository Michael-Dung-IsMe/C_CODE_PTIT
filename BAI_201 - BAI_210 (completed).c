#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define ll long long

//BÀI 201 - C06025: HIEU HAI SO NGUYEN LON
int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char s1[1003], s2[1003];
		gets(s1); gets(s2);
		int n1 = strlen(s1), n2 = strlen(s2);
		int dai = fmax(n1,n2);
		int u[1003] = {0}, v[1003] = {0}, res[1005] = {0};
		for(int i = 0; i < n1; ++i)
			u[i] = s1[n1-1-i] - '0';
		for(int i = 0; i < n2; ++i)
			v[i] = s2[n2-1-i] - '0';
		int check = 0;
		if(n1 == n2){
			for(int i = n1-1; i >= 0; --i){
				if(u[i] - v[i] < 0){
					check = 1;
					break;
				}
			}
		}
		if(check){
			int cnt = 0;
			for(int i = 0; i < dai-1; ++i){
				res[i] = v[i] - u[i] - cnt;
				if(res[i] < 0){
					res[i] += 10;
					cnt = 1;
				}
			}
			res[dai-1] = v[dai-1] - u[dai-1] - cnt;
			if(res[dai-1] != 0)
				printf("%d", abs(res[dai-1]));
		}
		else{
			int cnt = 0;
			for(int i = 0; i < dai-1; ++i){
				res[i] = u[i] - v[i] - cnt;
				if(res[i] < 0){
					res[i] += 10;
					cnt = 1;
				}
			}
			res[dai-1] = u[dai-1] - v[dai-1] - cnt;
			if(res[dai-1] != 0)
				printf("%d", abs(res[dai-1]));
		}
		for(int i = dai-2; i >= 0; --i)
			printf("%d", res[i]);
		printf("\n");
	}
}

//BÀI 202 - C06026: TIM TU THUAN NGHICH DAI NHAT (DA THAM KHAO)
int palin(char c[]){
	int l = 0, r = strlen(c);
	while(l < r){
		if(c[l] != c[r-1])
			return 0;
		l++;
		r--;
	}
	return 1;
}

int main(){
    int n = 0, max = 0;
    char x[50], a[10000][50];
    while(scanf("%s", x) != -1){
        if(palin(x)){
            int m = strlen(x);
            strcpy(a[n++], x);
            if (max < m)
                max = m;
        }
    }
    for(int i = 0; i < n; i++){
        if(strlen(a[i]) == max){
            int s = 1;
            for(int j = i + 1; j < n; j++){
                if (!strcmp(a[i], a[j])){
                    a[j][0] = 0;
                    s++;
                }
            }
            printf("%s %d\n", a[i], s);
        }
    }
}

//BÀI 203 - C06035: XAU DOI XUNG - 1
int main(){
	int t; scanf("%d", &t);
	while(t--){
		char s[50];
		scanf("%s", s);
		int check = 0;
		int leng = strlen(s);
		for(int i = 0; i <= (leng-1)/2; i++){
			if((int)s[i] != (int)s[leng-1-i])
				check++;
		}
		if(check == 1)
			printf("YES\n");
		else if(check == 0){
			if(leng%2)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}

//BÀI 204 - C07004: PHAN SO
struct phanso{
	int a, b, c, d;
};

typedef struct phanso ps;

int gcd(int xp, int yp){
	if(yp == 0) return xp;
	else
		return gcd(yp, xp%yp);
}

int lcm(int xp, int yp){
	return (xp * yp)/gcd(xp, yp);
}

int main(){
	int k = 1, t; scanf("%d", &t);
	while(t--){
		ps m;
		scanf("%d%d%d%d", &m.a, &m.b, &m.c, &m.d);
		int g1 = gcd(m.a, m.b), g2 = gcd(m.c, m.d), g3 = lcm(m.b/g1, m.d/g2);
		int l2 = lcm(m.b, m.d), l1 = m.a * (l2 / m.b) + m.c * (l2 / m.d);
		int t = gcd(m.a * m.d, m.b * m.c);
		printf("Case #%d:\n", k++);
		printf("%d/%d %d/%d\n", (m.a/g1)*g3/(m.b/g1), g3, (m.c/g2)*g3/(m.d/g2), g3);
		printf("%d/%d\n", l1/gcd(l1, l2), l2/gcd(l1, l2));
		printf("%d/%d\n", (m.a * m.d)/t, (m.b * m.c)/t);
	}
}

//BÀI 205 - C07012: SAP XEP DANH SACH MAT HANG
struct mathang{
	int stt;
	char ten[200], nhom[100];
	float mua, ban, loi;
};

typedef struct mathang mh;

void nhap(mh *a){
	getchar();
	gets(a->ten);
	gets(a->nhom);
	scanf("%f%f", &a->mua, &a->ban);
	a->loi = a->ban - a->mua;
}

void in(mh sp){
	printf("%d %s %s %.2f\n", sp.stt, sp.ten, sp.nhom, sp.loi);
}

int cmp(const void *xp, const void *yp){
	mh *x = (mh *)xp;
	mh *y = (mh *)yp;
	if(x->loi > y->loi)
		return 0;
	return 1;
}

int main(){
	int t; scanf("%d", &t);
	mh sp[t+3];
	for(int i = 0; i < t; ++i){
		sp[i].stt = i+1;
		nhap(&sp[i]);
	}
	qsort(sp, t, sizeof(mh), cmp);
	for(int i = 0; i < t; ++i)
		in(sp[i]);
	return 0;
}

//BÀI 206 - C07015: THU KHOA CUA KI THI
struct diemThi{
	int stt;
	char name[100], birth[20];
	float sub1, sub2, sub3;
	float sum;
};

typedef struct diemThi score;

void nhap(score *x){
	getchar();
	gets(x->name); gets(x->birth);
	scanf("%f%f%f", &x->sub1, &x->sub2, &x->sub3);
	x->sum = x->sub1 + x->sub2 + x->sub3;
}

void in(score x){
	printf("%d %s %s %.1f\n", x.stt, x.name, x.birth, x.sum);
}

int main(){
	int t; scanf("%d", &t);
	score A[t+3];
	for(int i = 0; i < t; ++i){
		A[i].stt = i+1;
		nhap(&A[i]);
	}
	float max = 0;
	for(int i = 0; i < t; ++i){
		if(A[i].sum > max)
			max = A[i].sum;
	}
	for(int i = 0; i < t; ++i)
		if(A[i].sum == max)
			in(A[i]);
}

//BÀI 207 - C07016: SAP XEP THI SINH
struct diemThi{
	int stt;
	char name[100], birth[20];
	float sub1, sub2, sub3;
	float sum;
};

typedef struct diemThi score;

int cmp(const void *xp, const void *yp){
	score *x = (score *)xp;
	score *y = (score *)yp;
	if(x->sum > y->sum)
		return 0;
	if(x->sum == y->sum){
		if(x->stt > y->stt)
			return 1;
		else
			return 0;
	}
	return 1;
}

void nhap(score *x){
	getchar();
	gets(x->name); gets(x->birth);
	scanf("%f%f%f", &x->sub1, &x->sub2, &x->sub3);
	x->sum = x->sub1 + x->sub2 + x->sub3;
}

void in(score x){
	printf("%d %s %s %.1f\n", x.stt, x.name, x.birth, x.sum);
}

int main(){
	int t; scanf("%d", &t);
	score A[t+3];
	for(int i = 0; i < t; ++i){
		A[i].stt = i+1;
		nhap(&A[i]);
	}
	qsort(A, t, sizeof(score), cmp);
	for(int i = 0; i < t; ++i)
		in(A[i]);
}

//BÀI 208 - C07020: TIEN HOA POKEMON
struct Pokemon{
	int stt, k, m, total;
	char name[100];
};

typedef struct Pokemon Pok;

void nhap(Pok *x){
	getchar();
	gets(x->name);
	scanf("%d%d", &x->k, &x->m);
	x->total = 0;
}

int main(){
	int n; scanf("%d", &n);
	Pok a[n+3];
	for(int i = 0; i < n; ++i){
		a[i].stt = i+1;
		nhap(&a[i]);
	}
	int sum = 0, max = 0;
	for(int i = 0; i < n; ++i){
		while(a[i].k <= a[i].m){
			a[i].total++;
			a[i].m = a[i].m - a[i].k + 2;
		}
		sum += a[i].total;
		if(a[i].total > max)
			max = a[i].total;
	}
	printf("%d\n", sum);
	for(int i = 0; i < n; ++i){
		if(a[i].total == max){
			printf("%s", a[i].name);
			break;
		}
	}
}

//BÀI 209 - PR-2022-001: TONG CAC SO TRONG MOT DOAN CUA DAY (NOT FOUND)

//BÀI 210 - PR-2022-002: SO NGUYEN TO VONG (NOT FOUND)

//END


