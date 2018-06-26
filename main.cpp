#include <iostream>
#include <cstdio>
#include <ctime>
#define LENGTH 5
#define VALUE 10
#define ROW 5
#define COL 5
#define MAX_TERMS 10
using namespace std;

struct Matrix
{
	int row;
	int col;
	int value;
};

void MatSum(Matrix *MatA, Matrix *MatB)
{

	for (int i = 0; i < LENGTH; i++) {
		cout << "MatA[" << i << "] = " << MatA[i].row << " ";
		cout << MatA[i].col << " ";
		cout << MatA[i].value << " ";
		cout << endl;
	}

	cout << "=================================" << endl;

	for (int i = 0; i < LENGTH; i++) {
		cout << "MatB[" << i << "] = " << MatB[i].row << " ";
		cout << MatB[i].col << " ";
		cout << MatB[i].value << " ";
		cout << endl;
	}

	cout << "=================================" << endl;





	Matrix MatC[LENGTH * 3];

	// MatA와 MatB를 탐색해서 서로 다른 행열값 찾아내기.. 그런다음 MatC 할당

	MatC[0].row = 5;
	MatC[0].col = 5;
	MatC[0].value = 0;


	int k = 1;
	for (int i = 1; i < LENGTH * 2; i++) { // A.B 서로같을때
		for (int j = 1; j < LENGTH * 2; j++) {
			if ((MatA[i].row == MatB[j].row) && (MatA[i].col == MatB[j].col)) {
				MatC[k].row = MatA[i].row;
				MatC[k].col = MatA[i].col;
				MatC[k].value = MatA[i].value + MatB[j].value; k += 1;
			}
		}
	}
	int i = 1;
	int j = 1;
	while (1) {// A.B 서로다를때
		MatC[k].row = MatA[i].row;
		MatC[k].col = MatA[i].col;
		MatC[k].value = MatA[i].value;
		MatC[k + 1].row = MatB[j].row;
		MatC[k + 1].col = MatB[j].col;
		MatC[k + 1].value = MatB[j].value; i++; j++; k += 2;
		if (k > LENGTH * 2 - 1)
			break;
	}


	for (int i = 0; i < LENGTH * 2; i++) // MatC[0] 데이터 저장
		if (MatC[i].value > 0 && MatC[i].value < 30) {
			MatC[0].value += 1;
		}


	for (int i = 0; i < LENGTH * 3; i++) {
		if (MatC[i].row < 0 || MatC[i].col < 0 || MatC[i].value < 0 || MatC[i].row > 100 || MatC[i].col > 100 || MatC[i].value > 100)
			continue;
		cout << "MatC[" << i << "] = " << MatC[i].row << " ";
		cout << MatC[i].col << " ";
		cout << MatC[i].value << " ";
		cout << endl;
	}

}


// 두 구조체를 더하는 함수 + 출력하는 함수

int main()
{
	Matrix MatA[LENGTH];
	Matrix MatB[LENGTH];

	// 5행 3열 구조체 배열(멤버가 3개인 구조체 5개) 선언 => 총 14+1개의 희소행렬값 저장가능
	// 5*5 행렬을 더하는 함수 작성하기..
	cout << "희소행렬A와 B를 더하여 희소행렬C값을 출력합니다" << endl << "=================================" << endl;


	MatA[0].row = ROW;
	MatA[0].col = COL;
	MatA[0].value = LENGTH - 1;
	// 각 첫 행에 행렬데이터 입력
	MatB[0].row = ROW;
	MatB[0].col = COL;
	MatB[0].value = LENGTH - 1;

	srand((int)time(NULL));
	for (int i = 1; i < LENGTH; i++) {
		MatA[i].row = rand() % ROW;
		MatA[i].col = rand() % COL;
		MatA[i].value = rand() % VALUE + 1;
		// 나머지 행에 행렬데이터 입력(랜덤으로 희소행렬 값 대입)
		MatB[i].row = rand() % ROW;
		MatB[i].col = rand() % COL;
		MatB[i].value = rand() % VALUE + 1;
	}
	MatSum(MatA, MatB);
}