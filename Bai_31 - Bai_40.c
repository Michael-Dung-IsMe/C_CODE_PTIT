#include <stdio.h>
#include <math.h>


//BÀI 31: SHIFTING RIGHT 
int main(){
	int n; scanf("%d", &n);
	int A[200];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int k; scanf("%d", &k);
	for(int j = n-k; j < n; j++)
		printf("%d ", A[j]);
	for(int j = 0; j < n-k; j++)
		printf("%d ", A[j]);
	return 0;
}

//BÀI 32: REMOVING DUPLICATES
int main(){
	int n; scanf("%d", &n);
	int A[200];
	int B[200];
	int k = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", A+i);
		B[i] = A[i];
	}
	for(int i = 0; i < n; i++){
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(A[i] == B[j])
				cnt++;
			if(cnt > 1){
				B[j] = 0;
				cnt = 0;
			}
		}
	}
	for(int i = 0; i < n; i++){
		if(B[i] != 0)
			printf("%d ", B[i]);
	}
}

//BÀI 33: INCREASING SORT
void swap(int *xp, int *yp){
	int swp = *xp;
	*xp = *yp;
	*yp = swp;
}

void bubble_ascend(int A[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = n - 1; j > i; j--){
			if(A[j] < A[j-1])
				swap(&A[j], &A[j-1]);
		}
	}
}

int main(){
	int n; scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	bubble_ascend(A,n);
	for(int j = 0; j < n; j++)
		printf("%d ", A[j]);
	return 0;
}
	
//BÀI 34: INTERCHANGE SORT
void swap(int *xp, int *yp);

int main(){
	int N; scanf("%d", &N);
	int a[200];
	for(int i = 0; i < N; i++)
		scanf("%d", a+i);
	for(int i = 0; i < N-1; i++){
		for(int j = i+1; j < N; j++){
			if(a[i] > a[j]){
				swap(&a[i], &a[j]);
			}
		}
		printf("\n");
		printf("Step %d: ", i+1);
		for(int k = 0; k < N; k++){
			printf("%d ", a[k]);
		}
	}
	return 0;
}

void swap(int *xp, int *yp){
	int swp = *xp;
	*xp = *yp;
	*yp = swp;
}
//BÀI 35: SELECTION SORT
void swap(int *xp, int *yp);

int main(){
	int N; scanf("%d", &N);
	int a[N];
	for(int i = 0; i < N; i++)
		scanf("%d", a+i);
	int min;
	for(int i = 0; i < N-1; i++){
		min = i;
		for(int j = i+1; j < N; j++){
			if(a[j] < a[min])
				min = j;
		}
		if(min != i)
			swap(&a[min], &a[i]);
		printf("\n");
		printf("Step %d: ", i+1);
		for(int k = 0; k < N; k++){
			printf("%d ", a[k]);
		}
	}
	return 0;
}

void swap(int *xp, int *yp){
	int swp = *xp;
	*xp = *yp;
	*yp = swp;
}
//BÀI 36: INSERTION SORT
int a[104];

int main(){
	int N; scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		scanf("%d", &a[i]);
	int min;
	int cnt = 1; 
	for(int i = 1; i <= N; i++){
		min = a[i];
		int j = i-1;
		while(j >= 0 && a[j] > min){
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = min;
		printf("Step %d: ", i-1);
		for(int k = 1; k <= cnt; k++){
			printf("%d ", a[k]);
		}
		cnt++;
		printf("\n");
	}
	return 0;
}

//BÀI 37: BUBBLE SORT
void bubble_sort(int A[], int n){
	int swp;
	for(int i = 0; i < n-1; i++){
		int cnt = 0;
		for(int j = 0; j < n-1-i; j++){
			if(A[j] > A[j+1]){
				swp = A[j];
				A[j] = A[j+1];
				A[j+1] = swp;
				cnt = 1;
			}
		}
		printf("\n");
		if(cnt == 0)
			break;
		printf("Step %d: ", i+1);
		for(int k = 0; k < n; k++)
			printf("%d ", A[k]);
	}
}

int main(){
	int n; scanf("%d", &n);
	int A[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	bubble_sort(A,n);
	return 0;
}

//BÀI 38: INTERSECTION OF TWO ARRAYS
void swap(int *xp, int *yp){
	int swp = *xp;
	*xp = *yp;
	*yp = swp;
}

void bubble_ascend(int A[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(A[i] > A[j])
				swap(&A[i], &A[j]);
		}
	}
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int a[1001], b[1001], c[1000];
	for(int i = 0; i < n; i++)	scanf("%d", a+i);
	for(int j = 0; j < m; j++)	scanf("%d", b+j);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i] == b[j]){
				c[cnt++] = a[i];
				break;
			}
		}
	}
	bubble_ascend(c,cnt);
	for(int i = 1; i <= cnt; i++){
		if(c[i] != c[i-1])
			printf("%d ", c[i-1]);
	}
	return 0;
}

//BÀI 39: UNION OF TWO ARRAYS
void swap(int *xp, int *yp){
	int swp = *xp;
	*xp = *yp;
	*yp = swp;
}

void bubble_ascend(int A[], int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = i+1; j < n; j++){
			if(A[i] > A[j])
				swap(&A[i], &A[j]);
		}
	}
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int a[1001], b[1001];
	for(int i = 0; i < n; i++)	scanf("%d", a+i);
	for(int j = 0; j < m; j++)	scanf("%d", b+j);
	int c[n+m];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		c[cnt] = a[i];
		cnt++;
	}
	for(int i = 0; i < m; i++){
		c[cnt] = b[i];
		cnt++;
	}
	bubble_ascend(c,cnt);
	for(int i = 1; i <= cnt; i++){
		if(c[i] != c[i-1])
			printf("%d ", c[i-1]);
	}
	return 0;
}

//BÀI 40: TRANSPOSE MATRIX
int main(){
	int row, col;
	scanf("%d %d", &row, &col);
	int a[11][11];
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++)	
			scanf("%d", &a[i][j]);
	}
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++)
			printf("%d ", a[j][i]);
		printf("\n");
	}
	return 0;
}

