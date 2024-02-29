#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//BÀI 41: SWAPPING COLUMNS IN A MATRIX
int main(){
	int dong,cot, a, b;
    scanf("%d %d", &dong,&cot);
    int A[dong][cot];
    for(int i = 0; i < dong; i++){
        for (int j = 0; j < cot; j++)
            scanf("%d", &A[i][j]);
    }
    scanf("%d %d", &a, &b);
    a--;
	b--;
    for(int row = 0; row < dong; row++){
    	int temp = A[row][a];
    	A[row][a] = A[row][b];
    	A[row][b] = temp;
	}
	for (int i = 0; i < dong; i++){
        for (int j = 0; j < cot; j++){
            printf("%d ", A[i][j]);
    	}
        printf("\n");
    }
    return 0;
}

//BÀI 42: MATRIX PRODUCT
int main(){
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	int a[n][m], b[m][p];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < p; j++)
			scanf("%d", &b[i][j]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++){
			int sum = 0;
			for(int k = 0; k < m; k++){
				sum = sum + (a[i][k]*b[k][j]);
			}
			printf("%d ", sum);
			sum = 0;
		}
		printf("\n");
	}
	return 0;
}

//BÀI 43: PRODUCT OF A MATRIX AND ITS TRANSPOSE
int b[1000][1000];
int main(){
	int T; scanf("%d", &T);
	for(int r = 1; r <= T; r++){
		int n, m;
		scanf("%d%d", &n, &m);
		int a[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				b[j][i] = a[i][j];	
		}
		printf("Test %d:\n", r);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				int sum = 0;
				for(int k = 0; k < m; k++){
					sum = sum + (a[i][k]*b[k][j]);
					}
				printf("%d ", sum);
				sum = 0;
			}
			printf("\n");
		}
	}
	return 0;
}

//BÀI 44: SPIRAL MATRIX
void spiral(int rows, int cols){
	int A[rows][cols];
	int top = 0, bottom = rows, left = 0, right = cols;
	int cnt = 1;
	while(top < bottom && left < right){
		for(int i = left; i < right; i++){
			A[top][i] = cnt++;
		}
		top++;
		for(int i = top; i < bottom; i++){
			A[i][right-1] = cnt++;
		}
		right--;
		for(int i = right-1; i >= left; i--){
			A[bottom-1][i] = cnt++;
		}
		bottom--;
		for(int i = bottom-1; i >= top; i--){
			A[i][left] = cnt++;
		}
		left++;
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int main(){
	int n; scanf("%d", &n);
	int m = n;
	spiral(n,m);
}

//BÀI 45: BINARY MATRIX
int main(){
	int n; scanf("%d", &n);
	int A[n][3];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &A[i][j]);
			if(A[i][j] != 0 && A[i][j] != 1)
				return 0;
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int check0 = 0, check1 = 0;
		for(int j = 0; j < 3; j++){
			if(A[i][j] == 0)
				check0++;
			else
				check1++;
		}
		if(check1 > check0)
			cnt++;
		check0 = 0;
		check1 = 0;
	}
	printf("%d", cnt);
}

//BÀI 46: COUNTING WORDS IN A STRING
int main(){
	int T; scanf("%d", &T);
	getchar();
	while(T--){
		char c[201];
		char kq[50][20];
		gets(c);
		char *p = strtok(c, " ");
		int cnt = 0;
		while(p != NULL){
			cnt++;
			p = strtok(NULL, " ");
		}
		printf("%d\n", cnt);
	}
}

//BÀI 47: COUNTING CHARACTERS
int main(){
	char c[201];
	gets(c);
	int checkA = 0, check1 = 0, checkD = 0;
	for(int i = 0; i < strlen(c); i++){
		if(isalpha(c[i]))
			checkA++;
		else if(isdigit(c[i]))
			check1++;
		else
			checkD++;
	}
	printf("%d %d %d", checkA, check1, checkD);
}

//BÀI 48: REMOVING WORDS IN A STRING
int remve(char a[], char b[]){
	if(strlen(a) == strlen(b)){
		for(int i = 0; i < strlen(a); ++i){
			if(a[i] != b[i])
				return 0;
		}
		return 1;
	}
	return 0;
}

int main(){
	char c1[101];
	char c2[101];
	gets(c1); gets(c2);
	char res[20][50];
	int cnt = 0;
	char *spr = strtok(c1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt; i++){
		if(remve(res[i],c2) == 0)
			printf("%s ", res[i]);
	}
}

//BÀI 49: REMOVING DUPLICATE WORDS
int main(){
	char c1[1000];
	char c2[1000];
	gets(c1);
	char res[20][50];
	int cnt = 0;
	char *spr = strtok(c1, " ");
	while(spr != NULL){
		strcpy(res[cnt++], spr);
		spr = strtok(NULL, " ");
	}
	for(int i = 0; i < cnt; i++){
		int check = 1;
		for(int j = 0; j < i; j++){
			if(strcmp(res[i], res[j]) == 0)
				check = 0;
			}
			if(check)
				printf("%s ", res[i]);
	}
}

//BÀI 50: STANDARDZING NAME STRING (WA)
void inlower(char c[]){
	for(int i = 0; i < strlen(c); i++)
		c[i] = tolower(c[i]);
}

int main(){
	char c1[1000];
	char res[20][50];
	int T;
	scanf("%d", &T);
	while(T--){
		getchar();
		gets(c1);
		inlower(c1);
		int cnt = 0;
		char *spr = strtok(c1, " ");
		while(spr != NULL){
			strcpy(res[cnt++], spr);
			spr = strtok(NULL, " ");
		}
		for(int i = 0; i < cnt; i++){
			if(res[i] >= 'a' && res[i] <= 'z')
				res[i][0] = toupper(res[i][0]);
			printf("%s ", res[i]);
		}
		printf("\n");
	}	
}

