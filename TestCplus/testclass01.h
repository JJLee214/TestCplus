#pragma once
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include <stdio.h>
#include <math.h>

//#define MAX_NUMBER 100

class testclass01
{
private:
	int n, triangle[100][100];
	//int cache[100][100][10 * 10 + 1];

public:
	testclass01();
	~testclass01();


	int path1(int y, int x, int sum);
	char *itoa(int num, char *str);
};


//////////////////////////////가상 함수 테스트의 장////////////////////////////
class parentclass
{
private:
	virtual int darvish()
	{
		return 5;
	}
public:
	const char* bark01()
	{
		return "woofoo";
	}

	virtual const char* bark02(char* input)
	{
		return input;
	}
	virtual const char* bark02()
	{
		return "woofoo";
	}
	//virtual const char* bark03() = 0; //순수 가상 함수
};

class catclass : public parentclass
{

public:
	const char* bark01()
	{
		return "meow";
	}

	using parentclass::bark02;

	const char* bark02()
	{
		return "meow";
	}

	const char* bark03()
	{
		return "meow";
	}

private:

	static std::new_handler nh;
};

std::new_handler catclass::nh = 0;

class dogclass : public parentclass
{
public:
	const char* bark01()
	{
		return "bowwow";
	}

	const char* bark02()
	{
		return "bowwow";
	}
	const char* bark03()
	{
		return "bowwow";
	}
};

//////////////////////////////가상 함수 테스트의 장////////////////////////////

//////////////////////////////구조체와 공용체의 장//////////////////////////////

typedef struct st
{
private:
	int st_private_m = 0;

public:
	int st_public_m = 1;
}mystruct;

union intbox
{
	int a;
	short b;
	char c;
	float d;
};

union tag_ip {
	unsigned long addr;
	unsigned char sub[4];
};


//공용체와 구조체는 닮았지만 메모리 운영방식이 서로 다르다

//////////////////////////////구조체와 공용체의 장//////////////////////////////

//////////////////////////////프렌드의 장//////////////////////////////
class B; // B 클래스가 있다는걸 알림!

class foreign
{
private:
	int rootdata;
public:
	void roototherData(B* b);
	void roototherDataRef(B& b);

};

class A {
private:
	int adata;
public:
	A(int _data)
	{
		adata = _data;
	}
	void ShowData(B b);
	friend class B;
};

class B {
private:
	int bdata;
public:
	B(int _data)
	{
		bdata = _data;
	}
	inline void ShowData(A a)
	{
		cout << "a.data: " << a.adata << endl;
	}
	friend class A;

	friend void foreign::roototherData(B* b);
	friend void foreign::roototherDataRef(B& b);
};

class privater
{
public:
	privater() { money = 1000; }
private:
	int money;
	friend void privateFunction(privater* pri)
	{
		cout << "나는 지금 " << pri->money << "원 가지고 있다" << endl;
	}

};

//////////////////////////////프렌드의 장//////////////////////////////

//////////////////////////////연산자오버로딩의 장//////////////////////////////
class MahClass {
private:
	int data1, data2;
public:
	MahClass()
	{

	}
	MahClass(int _data1, int _data2)
	{
		data1 = _data1;
		data2 = _data2;
	}

	const MahClass operator+(MahClass &ref)
	{
		return MahClass(data1 + ref.data1, data2 + ref.data2);
	}

	MahClass operator++()
	{
		data1 += 10;
		data2 += 5;

		//return &this;
		return *this;
	}

	MahClass operator++(int)
	{
		data1 += -1000;
		data2 += 1000;

		//return &this;
		return *this;
	}

	MahClass& operator=(MahClass& ref)
	{

	}

	void ShowData()
	{
		cout << "Mah data1 : " << data1 << " Mah data2 : " << data2 << endl;
	}
};


class Point
{
private:
	int x, y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y) {}
	friend ostream& operator<<(ostream& os, const Point& p); //쉬프트 연산자 오버로딩
	Point operator+(const Point& p)
	{
		Point temp(x + p.x, y + p.y);
		return temp;
	}

};

//ostream& operator<<(ostream& os, const Point& p)
//{
//	os << "[" << p.x << ", " << p.y << "]" << endl;
//	return os;
//}


//////////////////////////////연산자오버로딩의 장//////////////////////////////

//////////////////////////////템플릿의 장//////////////////////////////
template <typename T>
void Swap(T& val1, T& val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}

template <class T>
class MyData
{
private:
	T m_data;

public:
	void SetData(T parm_data)
	{
		m_data = parm_data;
	}

	T GetData()
	{
		return m_data;
	}

};


template <typename T>
class TemplateClass
{
private:
	T m_data;
	mutable T mutant_data;

public:
	TemplateClass(T v)
	{
		m_data = v;
	}

	////함수 const의 장
	const T* GetData() const
	{
		mutant_data = 15; //상수 함수에서도 조작 가능하다!
		return &m_data;
	}

	void ShowData() const
	{
		ShowIntro();
		cout << "m_data : " << m_data << endl;
	}

	void ShowIntro() const//뒤 const를 빼면 ShowData 에서 오류 발생
		//- 컴파일러가 ShowIntro를 멤버 변수를 조작할 가능성이 있는 함수로 판단하기 때문에
	{
		cout << "ShowIntro()" << endl;
	}

};

//////////////////////////////템플릿의 장//////////////////////////////

//////////////////////////////예외처리의 장//////////////////////////////
void funcExecption(int fun1, int fun2);

//////////////////////////////예외처리의 장//////////////////////////////
////////////////깊이 & 넓이 우선 탐색의 장////////////////
class commonclass
{
private:
	int n, min; // 맵의 크기와 최소값을 나타내는 변수
	int map[10][10]; // 맵을 나타내는 2차원 배열
	int cnt = 0; //카운트 변수 C++에선 0을 대입하지 않아도 자동으로 0으로 초기화
	int x[100], y[100], l[100]; //좌표의 길이를 담을 배열

public:
	void DFS(int x, int y, int l) //깊이 우선 탐색은 스택을 기반으로 한다
	{
		// 도착 지점에 도착했을 경우
		if (x == n - 1 && y == n - 1)
		{
			// 현재 최소값이 l보다 크면, l이 작은 것이므로 l를 최소값으로 지정
			if (min > l)
				min = l;
			return;
		}
		map[y][x] = 0; // 방문했음을 표시하기 위해 0을 대입

		// 위로 이동할 수 있다면 이동!
		if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
		// 아래로 이동할 수 있다면 이동!
		if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
		// 왼쪽으로 이동할 수 있다면 이동!
		if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
		// 오른쪽으로 이동할 수 있다면 이동!
		if (x < n - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);

		map[y][x] = 1; // 지나간 자리를 원상태로 되돌리기 위해 1을 대입
	}

	//큐에 좌표 정보를 삽입하는 함수
	void enqueue(int _x, int _y, int _l)
	{
		x[cnt] = _x;
		y[cnt] = _y;
		l[cnt] = _l;
		cnt++;
	}

	void BFS(int _x, int _y) //넓이 우선 탐색은 큐를 기반으로 한다
	{
		int pos = 0;
		enqueue(_x, _y, 1);

		//더 이상 방문할 지점이 없거나 도착 지점에 도착하면 루프를 탈출
		while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1))
		{
			// 두 번 방문하게 하면 안되므로, 이미 지나갔다는 표시를 해둔다
			map[y[pos]][x[pos]] = 0;

			//위로 갈 수 있다면 위 지점의 좌표 정보와 길이를 큐에 삽입한다
			if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1)
				enqueue(x[pos], y[pos] - 1, l[pos] + 1);
			// 아래로 갈 수 있다면, 아래 지점의 좌표 정보와 길이를 큐에 삽입한다
			if (y[pos] < n - 1 && map[y[pos] + 1][x[pos]] == 1)
				enqueue(x[pos], y[pos] + 1, l[pos] + 1);
			// 왼쪽으로 갈 수 있다면, 왼쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
			if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1)
				enqueue(x[pos] - 1, y[pos], l[pos] + 1);
			// 오른쪽로 갈 수 있다면, 오른쪽 지점의 좌표 정보와 길이를 큐에 삽입한다
			if (x[pos] < n - 1 && map[y[pos]][x[pos] + 1] == 1)
				enqueue(x[pos] + 1, y[pos], l[pos] + 1);

			// 큐의 다음 순서의 지점을 방문한다
			pos++;
		}

		// cnt가 pos보다 크다면, 도착 지점에 무사히 도착한 것이라고 말할 수 있다.
		// 위의 반복문은 도착점에 도착하게 되면 루프를 바로 빠져나오기 때문에,
		// 길이를 삽입하는 큐의 마지막 요소가 최단 경로의 길이라고 할 수 있다.
		if (pos < cnt)
			cout << "최단 경로 길이 : " << l[pos] << endl;

	}

	commonclass()
	{

	}
	~commonclass()
	{

	}

	void run()
	{
		int i, j;

		scanf_s("%d", &n);
		min = n * n; // 모든 경로를 돌아다녀도 n * n이니, 이를 최소값으로 지정해둔다
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf_s("%d", &map[i][j]);
		//DFS(0, 0, 1); // DFS 시작!
		BFS(0, 0); // BFS 시작!
		//printf("최단 거리: %d\n", min);
	}
	////////////////깊이 & 넓이 우선 탐색의 장////////////////
};

////////////////커스텀 문자열함수의 장////////////////

class mychr_custom : commonclass
{
private:
	int testvariable;

public:
	int c_strlen(char *str)
	{
		int length = 1;
		for (int i = 0; *(str + i) != 0; i++)
		{
			length++;
		}
		return length;
	}

	char* c_strcat(char *src, char *plus)
	{
		//배열을 사용한 strcat
		/*int i, j = 0;
		for (i = 0; src[i] != 0; i++);

		for (j = 0; plus[j] != 0; j++)
			src[i + j] = plus[j];
		return src;*/
		while (*src != 0)
		{
			*(src++);
		}
		while (*plus != 0)
		{
			*(src++) = *(plus++);
		}
		//*src = 0;

		return src;
	}

	char* c_strcpy(char *src, char *dest)
	{
		while (*dest != 0)
		{
			*(src++) = *(dest++);
		}

		return src;
	}


	char* c_strtok(char *src, const char *token)
	{
		char tempchar[128] = { 0, };

		int i;
		for (i = 0; src[i] != 0; i++)
		{
			if (src[i] == *token)
			{
				//*src = 0;
				//src++;
				break;
			}
			else
			{
				tempchar[i] = *src;
				i++;
			}

		}

		return src;
	}

	bool cmpstring(char* A, char* B) //컴투스 문제 1
	{
		int lengthA = strlen(A);
		int lengthB = strlen(B);

		for (int i = 0; i < lengthA - lengthB + 1; i++)
		{
			int correctCounter = 0;
			for (int j = 0; j < lengthB; j++)
			{
				if (*(A + i + j) == *(B + j))
				{
					correctCounter++;
					if (correctCounter == lengthB)
						return true;
				}
			}
		}
		return false;
	}

	char* c_strrev(char src[])
	{
		int start = 0;
		int end = strlen(src) - 1;

		while (start < end)
		{
			char temp = src[start];
			src[start] = src[end];
			src[end] = temp;
			start++;
			end--;
		}
		return src;
	}

	char* reverse_custom(char* src) // 문자열 역순 ' ' 별로
	{
		int start = 0;
		int end = 0;
		int size = strlen(src);

		c_strrev(src);

		for (int i = 0; i <= size; i++)
		{
			if (src[i] == ' ' || i == size)
			{
				while (start < end)
				{
					char temp = src[start];
					src[start] = src[end];
					src[end] = temp;

					start++;
					end--;
				}
				start = i + 1;
				end = i;
			}

			else
			{
				end = i;
				continue;
			}
		}

		return src;
	}

	int fact(int fac) //팩토리얼
	{
		if (fac == 0 || fac == 1)
			return 1;

		return fac * fact(fac - 1);
	}
};


///////////////파일 입출력의 장////////////////
class fileclass
{
private:

public:
	void printLast10Lines(char * filename)
	{
		const int K = 10;
		ifstream file(filename);
		string L[K];
		int size = 0;

		// 환형 배열에 파일을 한줄씩 읽어들인다
		while (file.good())
		{
			getline(file, L[size % K]);
			size++;
		}

		// 환형 배열의 시작점과 크기 계산
		int start = size > K ? (size % K) : 0;
		int count = min(K, size);

		//읽은 순서대로 원소들의 값 출력
		for (int i = 0; i < count; i++)
		{
			cout << L[(start + i) % K] << endl;
		}
	}
};


///////////////파일 입출력의 장////////////////

///////////////컴투스 문제 //////////////////
class Vehicle
{
private:
	char* Name;
	int Wheels;

public:
	Vehicle(char* Name, int Wheels)
	{
		this->Name = Name;
		this->Wheels = Wheels;
	}
	void Move();
	char* getName()
	{
		return Name;
	}
	int getNumberOfWheels()
	{
		return Wheels;
	}

	void swap(char *a, char *b)
	{
		char s = *a;

	}

};

class Comtus2
{
private:


	int RectCounter = 0;

public:
	int CalcArea(int(*mymap)[7])
	{

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (mymap[i][j] == 0)
					continue;
				else if (mymap[i][j] == 1)
				{
					RectCounter++;
				}
			}
		}
		return RectCounter;
	}


};

///////////////컴투스 문제 //////////////////

//////////스택 큐 구현의 장////////////////
template <typename T>
class CustomStack
{
private:
	T *Stack;
	int Size = 0;
	int top = 0;

public:

	void initStack(const int inputSize)
	{
		Stack = new T[inputSize];
		Size = inputSize;
		cout << "size of stack : " << sizeof(Stack) << endl;
	}

	bool push(T inputData)
	{
		if (top < Size)
		{
			*(Stack + top) = inputData;
			cout << "top : " << Stack[top] << endl;
			top++;

		}
		else
		{
			cout << "stack overflow" << endl;
			return false;
		}
	}

	T pop()
	{
		if (top > 0)
		{
			cout << "top : " << Stack[top - 1] << endl;
			top--;
			return Stack[top];
		}
		else
		{
			cout << "stack underflow" << endl;
			return false;
		}
	}
};

template <typename T>
class CustomQueue
{
private:
	int size;
	int counter;
	T* Queue;

public:
	CustomQueue<T>()
	{
		counter = 0;
	}

	void initializeQueue(const int inputsize)
	{
		size = inputsize;
		Queue = new T[inputsize];
	}

	void push(const T inputData)
	{
		if (counter < size)
		{
			*(Queue + counter) = inputData;
			cout << "push queue : " << *(Queue + counter) << endl;
			counter++;
		}
		else
		{
			cout << "Queue overflow" << endl;
		}
	}

	T pop()
	{
		if (Queue[0] < 0 || Queue[0] > 1000)
		{
			cout << "Queue underflow" << endl;
			return 0;
		}
		else
		{
			T tempdata = Queue[0];

			int i = 0;
			while (i < counter)
			{
				Queue[i] = Queue[i + 1];
				i++;
			}
			counter--;
			cout << "pop queue : " << tempdata << endl;
			return tempdata;
		}
	}
};
////////함수 포인터의 장 /////////////

class funcclass
{
private:
	int a1;
	vector<int> b1;
	string c1;
	vector<int> *b2;


public:
	funcclass() : a1(0), b1({ 0 }), c1("empty") {}

	funcclass(const int &a, const vector<int>& b, const string& c) : a1(a), b1(b), c1(c) {}
	int (*pFunc)(int);


	int Function(const int a)
	{
		*b2 = b1;
		cout << "Function Pointer : " << a << endl;
	}


	//int(*pFunc)(int) = Function;
	//pFunc your_func;

	//void regi_func(pFunc p_func)
	//{
	//	your_func = p_func;
	//}

	//void exec_func()
	//{
	//	your_func(1);
	//}


};

////////함수 포인터 장 /////////////

////////정렬(소트)의 장////////////
#define SWAP(a, b) {int t; t=a; a=b; b=t;}

class sortClass
{
private:
public:
	template<typename T>
	static void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}


	static void qsort(vector<int>& array, int left, int right)
	{
		int left_t = left;
		int right_t = right;
		int pivot = array[left];

		while (left < right)
		{
			while (pivot <= array[right] && left < right)
				right--;
			if (left > right)
				break;
			while (pivot >= array[left] && left < right)
				left++;
			if (left > right)
				break;
			swap(array[left], array[right]);
		}
		swap(array[left], array[left_t]);

		if (left_t < left)
			qsort(array, left_t, left - 1);
		if (right_t > right)
			qsort(array, left + 1, right_t);
	}

	static void merge(vector<int>& v, int s, int e, int m) {
		vector<int> ret;
		int i = s, j = m + 1, copy = 0;

		//결과를 저장할 배열에 하나씩 비교하여 저장한다. 
		while (i <= m && j <= e) {
			if (v[i] < v[j])ret.push_back(v[i++]);
			else if (v[i] > v[j])ret.push_back(v[j++]);
		}

		//남은 값들을 뒤에 채워넣어준다. 
		while (i <= m)  ret.push_back(v[i++]);
		while (j <= e)  ret.push_back(v[j++]);

		//원래 배열에 복사해준다.
		for (int k = s; k <= e; k++) {
			v[k] = ret[copy++];
		}
	}

	//합병 정렬
	static void mergeSort(vector<int>& v, int s, int e) {
		if (s<e) {
			int m = (s + e) / 2;
			/*divide, 분할*/
			mergeSort(v, s, m); //s부터 m까지
			mergeSort(v, m + 1, e); //m+1부터 e까지 
									/*conquer, 합병*/
			merge(v, s, e, m);
		}
	}


};
////////정렬(소트)의 장////////////

////////멤버함수 템플릿의 장//////////
template <typename T> class Complex
{
public:
	Complex(T a = T(), T b = T()) : re(a), im(b)
	{
	}

	// 일반화된 복사생성자
	template <typename U>
	Complex(const Complex<U>& rhs);

	//모든 타입의 Complex는 private 멤버에 접근할 수 있어야 한다
	template <typename U>
	friend class Complex;

private:
	T re;
	T im;
};

template <typename T>
template <typename U>
Complex<T>::Complex(const Complex<U>& rhs) : re(rhs.re), im(rhs.im) {}

////////멤버함수 템플릿의 장//////////


//static void qsort(vector<int>& array, int left, int right)
//{
//	int pivot = array[left];
//	int left_t = left;
//	int right_t = right;
//
//	while (left < right)
//	{
//		while (pivot <= array[right] && left < right)
//			right--;
//		if (left > right)
//			break;
//		while (pivot >= array[left] && left < right)
//			left++;
//		if (left > right)
//			break;
//
//		SWAP(array[left], array[right]);
//	}
//
//	SWAP(array[left_t], array[left]);
//
//	if (left_t < left)
//		qsort(array, left_t, left - 1);
//
//	if (right_t > right)
//		qsort(array, left + 1, right_t);
//
//
//}

////////정렬(소트)의 장////////////


////////////////////////////////////////////////