#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ll long long

//BÀI 191 - C06009: BIEN SO DEP
int main(){
	int t; scanf("%d\n", &t);
	while(t--){
		char s[100];
		gets(s);
		int lp = 0, tang = 0, bang = 1, check = 0;
		if(s[8] == '6' || s[8] == '8') lp = 1;
		if(s[6] == s[7] && s[7] == s[8] && s[10] == s[11])
			check = 1;
		for(int i = 6; i < 9; ++i){
			if(s[i+1] - '0' == -2)
				break;
			else{
				if(s[i] < s[i+1]) tang++;
				if(s[i] == s[i+1]) bang++;
				if(s[i] == '6' || s[i] == '8') lp++;
			}
		}
		for(int i = 10; i < 12; ++i){
			if(s[8] < s[i]) tang++;
			if(s[8] == s[i]) bang++;
			if(s[i] == '6' || s[i] == '8') lp++;
			s[8] = s[i];
		}
		if(lp == 5 || tang == 4 || bang == 5 || check)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BÀI 192 - C06013: SO DAY DU
int main(){
	int t; scanf("%d\n", &t);
	while(t--){
		char s[1005];
		gets(s);
		int a[10] = {0}, check = 1;
		for(int i = 0; i < strlen(s); ++i){
			if(s[i] - '0' < 0 || s[i] - '0' > 9 || s[0] == '0'){
				check = -1;
				break;
			}
			int k = s[i] - '0';
			a[k]++;
		}
		for(int i = 0; i < 10; ++i){
			if(check == -1)
				break;
			else{
				if(a[i] == 0){
					check = 0;
					break;
				}
			}
		}
		if(check == -1) printf("INVALID\n");
		if(check == 1) printf("YES\n");
		if(check == 0) printf("NO\n");
	}
}

//BÀI 193 - C06014: CHUAN HOA XAU HO TEN 1
int main(){
	int t; scanf("%d\n", &t);
	while(t--){
		char s[1005], res[50][20];
		gets(s);
		for(int i = 0; i < strlen(s); ++i)
			s[i] = tolower(s[i]);
		int cnt = 0;
		char *spr = strtok(s, " ");
		while(spr != NULL){
			strcpy(res[cnt++], spr);
			spr = strtok(NULL, " ");
		}
		for(int i = 0; i < cnt; ++i){
			res[i][0] = toupper(res[i][0]);
			printf("%s", res[i]);
			if(i != cnt-1)
				printf(" ");
		}
		printf("\n");
	}
}

//BÀI 194 - C06015: CHUAN HOA XAU HO TEN 2
int main(){
	int t; scanf("%d\n", &t);
	while(t--){
		char s[1005], res[50][20];
		gets(s);
		for(int i = 0; i < strlen(s); ++i)
			s[i] = tolower(s[i]);
		int cnt = 0;
		char *spr = strtok(s, " ");
		while(spr != NULL){
			strcpy(res[cnt++], spr);
			spr = strtok(NULL, " ");
		}
		for(int i = 1; i < cnt; ++i){
			res[i][0] = toupper(res[i][0]);
			printf("%s", res[i]);
			if(i != cnt-1)
				printf(" ");
			else
				printf(", ");
		}
		for(int i = 0; i < strlen(res[0]); ++i){
			res[0][i] = toupper(res[0][i]);
			printf("%c", res[0][i]);
		}
		printf("\n");
	}
}

//BÀI 195 - C06017: TAP TU RIENG CUA HAI XAU 1 (Code dc copy)
int main()
{
    int n1 = 0, p1 = 0, n2 = 0, p2 = 0;
    char s1[200], s2[200], a[100][100], b[100][100];
    gets(s1);
    gets(s2);
    int m1 = strlen(s1), m2 = strlen(s2);
    for (int i = 0; i < m1; i++)
    {
        if (s1[i] == ' ')
        {
            a[n1][p1] = 0;
            n1++;
            p1 = 0;
        }
        else
            a[n1][p1++] = s1[i];
    }
    a[n1][p1] = 0;
    for (int i = 0; i < m2; i++)
    {
        if (s2[i] == ' ')
        {
            b[n2][p2] = 0;
            n2++;
            p2 = 0;
        }
        else
            b[n2][p2++] = s2[i];
    }
    b[n2][p2] = 0;
    for (int i = 0; i <= n1; i++)
        for (int j = i + 1; j <= n1; j++)
            if (strcmp(a[i], a[j]) == 0)
                a[j][0] = 0;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = i + 1; j <= n1; j++)
        {
            if (strcmp(a[i], a[j]) > 0)
            {
                char x[200];
                strcpy(x, a[i]);
                strcpy(a[i], a[j]);
                strcpy(a[j], x);
            }
        }
    }
    for (int i = 0; i <= n1; i++)
    {
        int ok = 1;
        for (int j = 0; j <= n2; j++)
        {
            if (strcmp(a[i], b[j]) == 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            printf("%s ", a[i]);
    }
    printf("\n");
}

//BÀI 196 - C06018: TAP TU RIENG CUA HAI XAU 2 (Code dc copy)
int main()
{
	int t; scanf("%d", &t);
	getchar();
	while(t--)
	{
	    int n1 = 0, p1 = 0, n2 = 0, p2 = 0;
	    char s1[200], s2[200], a[100][100], b[100][100];
	    gets(s1);
	    gets(s2);
	    int m1 = strlen(s1), m2 = strlen(s2);
	    for (int i = 0; i < m1; i++)
	    {
	        if (s1[i] == ' ')
	        {
	            a[n1][p1] = 0;
	            n1++;
	            p1 = 0;
	        }
	        else
	            a[n1][p1++] = s1[i];
	    }
	    a[n1][p1] = 0;
	    for (int i = 0; i < m2; i++)
	    {
	        if (s2[i] == ' ')
	        {
	            b[n2][p2] = 0;
	            n2++;
	            p2 = 0;
	        }
	        else
	            b[n2][p2++] = s2[i];
	    }
	    b[n2][p2] = 0;
	    for (int i = 0; i <= n1; i++)
	        for (int j = i + 1; j <= n1; j++)
	            if (strcmp(a[i], a[j]) == 0)
	                a[j][0] = 0;
	    for (int i = 0; i <= n1; i++)
	    {
	        for (int j = i + 1; j <= n1; j++)
	        {
	            if (strcmp(a[i], a[j]) > 0)
	            {
	                char x[200];
	                strcpy(x, a[i]);
	                strcpy(a[i], a[j]);
	                strcpy(a[j], x);
	            }
	        }
	    }
	    for (int i = 0; i <= n1; i++)
	    {
	        int ok = 1;
	        for (int j = 0; j <= n2; j++)
	        {
	            if (strcmp(a[i], b[j]) == 0)
	            {
	                ok = 0;
	                break;
	            }
	        }
	        if (ok)
	            printf("%s ", a[i]);
	    }
	    printf("\n");
	}
}

//BÀI 197 - C06019: DIA CHI EMAIL PTIT
int main(){
	char s1[205], res[205][205];
	gets(s1);
	for(int i = 0; i < strlen(s1); ++i)
		s1[i] = tolower(s1[i]);
	int cnt = 0;
	char *spr = strtok(s1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt-1; ++i)
		printf("%c", res[i][0]);
	printf("%s@ptit.edu.vn", res[cnt-1]);
}

//BÀI 198 - C06021: SO UU THE
int main(){
	int t; scanf("%d", &t);
	while(t--){
		char s1[1005];
		scanf("%s", s1);
		int c, l, d, check;
		c = l = d = check = 0;
		for(int i = 0; i < strlen(s1); ++i){
			if((int)s1[i] < 48 || (int)s1[i] > 57){
				check = 1;
				break;
			}
			if((s1[i] - '0')%2)
				l++;
			else
				c++;
			d++;
		}
		if(check)
			printf("INVALID\n");
		else{
			if((d%2 && l > c) || (d%2 == 0 && c > l))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}

//BÀI 199 - C06022: XOA TU TRONG XAU
int check(char a[], char b[]){
	char x[205], y[205];
	strcpy(x, a);
	strcpy(y, b);
	for(int i = 0; i < strlen(x) || i < strlen(y); ++i){
		x[i] = tolower(x[i]);
		y[i] = tolower(y[i]);
	}
	return(strcmp(x,y));
}

int main(){
	int t; scanf("%d", &t);
	int k = 1;
	getchar();
	while(t--){
		char s1[205], s2[25], res[205][205];
		gets(s1);
		gets(s2);
		printf("Test %d: ", k++);
		int cnt = 0;
		char *spr = strtok(s1, " ");
		while(spr != NULL){
			strcpy(res[cnt++], spr);
			spr = strtok(NULL, " ");
		}
		for(int i = 0; i < cnt; ++i){
			if(check(res[i], s2))
				printf("%s ", res[i]);
		}
		printf("\n");
	}
}

//BÀI 200 - C06024: TONG HAI SO NGUYEN LON
int main(){
	int t; scanf("%d", &t);
	getchar();
	while(t--){
		char s1[505], s2[505];
		gets(s1); gets(s2);
		int n1 = strlen(s1), n2 = strlen(s2), n = n1;
		if(n1 < n2)
			n = n2;
		int a[505] = {0}, b[505] = {0}, tong[510] = {0};
		for(int i = 0; i < n1; ++i)
			a[i] = s1[n1-1-i] - '0';
		for(int i = 0; i < n2; ++i)
			b[i] = s2[n2-1-i] - '0';
		int nho = 0;
		for(int i = 0; i < n-1; ++i){
			tong[i] = a[i] + b[i] + nho;
			if(tong[i] >= 10){
				tong[i] %= 10;
				nho = 1;
			}
			else nho = 0;
		}
		tong[n-1] = a[n-1] + b[n-1] + nho;
		for(int i = n-1; i >= 0; --i)
			printf("%d", tong[i]);
		printf("\n");
	}
}

//END
