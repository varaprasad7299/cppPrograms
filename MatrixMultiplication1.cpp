 #include <iostream>
#include<vector>
using namespace std;


void print(string display, vector<vector<int> > matrix,
		int start_row, int start_column, int end_row,
		int end_column)
{
	cout << endl << display << " =>" << endl;
	for (int i = start_row; i <= end_row; i++) {
		for (int j = start_column; j <= end_column; j++) {

			cout << matrix[i][j]<<"   ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void add_matrix(vector<vector<int> > A,
				vector<vector<int> > B,
				vector<vector<int> >& C,
				int k)
{
	for (auto i = 0; i < k; i++)
		for (auto j = 0; j < k; j++)
			C[i][j]
				= A[i][j] + B[i][j];
}

vector<vector<int> >
multiply_matrix(vector<vector<int> > A,
				vector<vector<int> > B)
{
	int col_1 = A[0].size();
	int row_1 = A.size();
	int col_2 = B[0].size();
	int row_2 = B.size();

	if (col_1 != row_2) {
		cout << "\nError: The number of columns in Matrix "
				"A must be equal to the number of rows in "
				"Matrix B\n";
		return {};
	}

	vector<int> rm_row(col_2, 0);
	vector<vector<int> > rm(row_1,
									rm_row);

	if (col_1 == 1)
		rm[0][0]
			= A[0][0] * B[0][0];
	else {
		int k = col_1 / 2;

		vector<int> row_vector(k, 0);
		vector<vector<int> > rm_00(k,row_vector);
		vector<vector<int> > rm_01(k,row_vector);
		vector<vector<int> > rm_10(k,row_vector);
		vector<vector<int> > rm_11(k,row_vector);

		vector<vector<int> > a00(k, row_vector);
		vector<vector<int> > a01(k, row_vector);
		vector<vector<int> > a10(k, row_vector);
		vector<vector<int> > a11(k, row_vector);
		vector<vector<int> > b00(k, row_vector);
		vector<vector<int> > b01(k, row_vector);
		vector<vector<int> > b10(k, row_vector);
		vector<vector<int> > b11(k, row_vector);

		for (auto i = 0; i < k; i++)
			for (auto j = 0; j < k; j++) {
				a00[i][j] = A[i][j];
				a01[i][j] = A[i][j + k];
				a10[i][j] = A[k + i][j];
				a11[i][j] = A[i + k]
									[j + k];
				b00[i][j] = B[i][j];
				b01[i][j] = B[i][j + k];
				b10[i][j] = B[k + i][j];
				b11[i][j] = B[i + k]
									[j + k];
			}

		add_matrix(multiply_matrix(a00, b00),
				multiply_matrix(a01, b10),
				rm_00, k);
		add_matrix(multiply_matrix(a00, b01),
				multiply_matrix(a01, b11),
				rm_01, k);
		add_matrix(multiply_matrix(a10, b00),
				multiply_matrix(a11, b10),
				rm_10, k);
		add_matrix(multiply_matrix(a10, b01),
				multiply_matrix(a11, b11),
				rm_11, k);

		for (auto i = 0; i < k; i++)
			for (auto j = 0; j < k; j++) {
				rm[i][j]
					= rm_00[i][j];
				rm[i][j + k]
					= rm_01[i][j];
				rm[k + i][j]
					= rm_10[i][j];
				rm[i + k]
							[j + k]
					= rm_11[i][j];
			}

		rm_00.clear();
		rm_01.clear();
		rm_10.clear();
		rm_11.clear();
		a00.clear();
		a01.clear();
		a10.clear();
		a11.clear();
		b00.clear();
		b01.clear();
		b10.clear();
		b11.clear();
	}
	return rm;
}

int main()
{

    cout<<"Enter no of rows :";
    int ROW_1;
    cin>>ROW_1;
    cout<<"Enter no of columns :";
    int COL_1;
    cin>>COL_1;
	vector<vector<int> > A(ROW_1,(vector<int>(COL_1,0)));
	for(int i=0;i<ROW_1;i++){
        for(int j=0;j<COL_1;j++){
            cin>>A[i][j];
        }
	}
	//print("Array A", A, 0, 0, ROW_1 - 1, COL_1 - 1);

    cout<<"Enter no of rows :";
    int ROW_2;
    cin>>ROW_2;
    cout<<"Enter no of columns :";
    int COL_2;
    cin>>COL_2;
	vector<vector<int> > B(ROW_2,(vector<int>(COL_2,0)));
	for(int i=0;i<ROW_2;i++){
        for(int j=0;j<COL_2;j++){
            cin>>B[i][j];
        }
	}
	//print("Array B", B, 0, 0, ROW_2 - 1, COL_2 - 1);

	vector<vector<int> > rm(
		multiply_matrix(A, B));

	print("Result Array", rm, 0, 0, ROW_1 - 1,
		COL_2 - 1);
}

// Time Complexity: O(n^3)
// Code Contributed By: lucasletum
