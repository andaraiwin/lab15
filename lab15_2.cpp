#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	for(int i = 0; i < N; i++)
	{
		cout << "Row " << i+1 << ": ";
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}	
	}
}

void findLocalMax(const double A[][N], bool B[][N]){
	for(int i = 1; i<(N-1); i++ ){
		for(int j = 1; j<(N-1) ; j++){
			if( A[i][j] >= A[i-1][j] && A[i][j] >= A[i][j-1] && A[i][j] >= A[i][j+1] && A[i][j] >= A[i+1][j] ){
				B[i][j] = 1;
			}else{
				B[i][j] = 0;
			}
		}

	}
	for(int k = 0; k<N; k++){
		B[0][k] = 0;
	}
	for(int l = 0; l<N; l++){
		B[N][l] = 0;
	}
	for(int m = 0; m<N; m++){
		B[m][0] = 0;
	}
	for(int n = 0; n<N; n++){
		B[n][N] = 0;
	}
}

void showMatrix(const bool B[][N]){
	for(int i = 0; i < N; i++ ){
		for(int j = 0; j < N; j++){
			if(B[i][j] == 0){
				cout << 0 << " ";
			}else if(B[i][j] == 1){
				cout << 1 << " ";
			}
		}
		cout << '\n';
	}
}
