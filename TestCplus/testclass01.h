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


//////////////////////////////���� �Լ� �׽�Ʈ�� ��////////////////////////////
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
	//virtual const char* bark03() = 0; //���� ���� �Լ�
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

//////////////////////////////���� �Լ� �׽�Ʈ�� ��////////////////////////////

//////////////////////////////����ü�� ����ü�� ��//////////////////////////////

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


//����ü�� ����ü�� ������� �޸� ������ ���� �ٸ���

//////////////////////////////����ü�� ����ü�� ��//////////////////////////////

//////////////////////////////�������� ��//////////////////////////////
class B; // B Ŭ������ �ִٴ°� �˸�!

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
		cout << "���� ���� " << pri->money << "�� ������ �ִ�" << endl;
	}

};

//////////////////////////////�������� ��//////////////////////////////

//////////////////////////////�����ڿ����ε��� ��//////////////////////////////
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
	friend ostream& operator<<(ostream& os, const Point& p); //����Ʈ ������ �����ε�
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


//////////////////////////////�����ڿ����ε��� ��//////////////////////////////

//////////////////////////////���ø��� ��//////////////////////////////
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

	////�Լ� const�� ��
	const T* GetData() const
	{
		mutant_data = 15; //��� �Լ������� ���� �����ϴ�!
		return &m_data;
	}

	void ShowData() const
	{
		ShowIntro();
		cout << "m_data : " << m_data << endl;
	}

	void ShowIntro() const//�� const�� ���� ShowData ���� ���� �߻�
		//- �����Ϸ��� ShowIntro�� ��� ������ ������ ���ɼ��� �ִ� �Լ��� �Ǵ��ϱ� ������
	{
		cout << "ShowIntro()" << endl;
	}

};

//////////////////////////////���ø��� ��//////////////////////////////

//////////////////////////////����ó���� ��//////////////////////////////
void funcExecption(int fun1, int fun2);

//////////////////////////////����ó���� ��//////////////////////////////
////////////////���� & ���� �켱 Ž���� ��////////////////
class commonclass
{
private:
	int n, min; // ���� ũ��� �ּҰ��� ��Ÿ���� ����
	int map[10][10]; // ���� ��Ÿ���� 2���� �迭
	int cnt = 0; //ī��Ʈ ���� C++���� 0�� �������� �ʾƵ� �ڵ����� 0���� �ʱ�ȭ
	int x[100], y[100], l[100]; //��ǥ�� ���̸� ���� �迭

public:
	void DFS(int x, int y, int l) //���� �켱 Ž���� ������ ������� �Ѵ�
	{
		// ���� ������ �������� ���
		if (x == n - 1 && y == n - 1)
		{
			// ���� �ּҰ��� l���� ũ��, l�� ���� ���̹Ƿ� l�� �ּҰ����� ����
			if (min > l)
				min = l;
			return;
		}
		map[y][x] = 0; // �湮������ ǥ���ϱ� ���� 0�� ����

		// ���� �̵��� �� �ִٸ� �̵�!
		if (y > 0 && map[y - 1][x] != 0) DFS(x, y - 1, l + 1);
		// �Ʒ��� �̵��� �� �ִٸ� �̵�!
		if (y < n - 1 && map[y + 1][x] != 0) DFS(x, y + 1, l + 1);
		// �������� �̵��� �� �ִٸ� �̵�!
		if (x > 0 && map[y][x - 1] != 0) DFS(x - 1, y, l + 1);
		// ���������� �̵��� �� �ִٸ� �̵�!
		if (x < n - 1 && map[y][x + 1] != 0) DFS(x + 1, y, l + 1);

		map[y][x] = 1; // ������ �ڸ��� �����·� �ǵ����� ���� 1�� ����
	}

	//ť�� ��ǥ ������ �����ϴ� �Լ�
	void enqueue(int _x, int _y, int _l)
	{
		x[cnt] = _x;
		y[cnt] = _y;
		l[cnt] = _l;
		cnt++;
	}

	void BFS(int _x, int _y) //���� �켱 Ž���� ť�� ������� �Ѵ�
	{
		int pos = 0;
		enqueue(_x, _y, 1);

		//�� �̻� �湮�� ������ ���ų� ���� ������ �����ϸ� ������ Ż��
		while (pos < cnt && (x[pos] != n - 1 || y[pos] != n - 1))
		{
			// �� �� �湮�ϰ� �ϸ� �ȵǹǷ�, �̹� �������ٴ� ǥ�ø� �صд�
			map[y[pos]][x[pos]] = 0;

			//���� �� �� �ִٸ� �� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
			if (y[pos] > 0 && map[y[pos] - 1][x[pos]] == 1)
				enqueue(x[pos], y[pos] - 1, l[pos] + 1);
			// �Ʒ��� �� �� �ִٸ�, �Ʒ� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
			if (y[pos] < n - 1 && map[y[pos] + 1][x[pos]] == 1)
				enqueue(x[pos], y[pos] + 1, l[pos] + 1);
			// �������� �� �� �ִٸ�, ���� ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
			if (x[pos] > 0 && map[y[pos]][x[pos] - 1] == 1)
				enqueue(x[pos] - 1, y[pos], l[pos] + 1);
			// �����ʷ� �� �� �ִٸ�, ������ ������ ��ǥ ������ ���̸� ť�� �����Ѵ�
			if (x[pos] < n - 1 && map[y[pos]][x[pos] + 1] == 1)
				enqueue(x[pos] + 1, y[pos], l[pos] + 1);

			// ť�� ���� ������ ������ �湮�Ѵ�
			pos++;
		}

		// cnt�� pos���� ũ�ٸ�, ���� ������ ������ ������ ���̶�� ���� �� �ִ�.
		// ���� �ݺ����� �������� �����ϰ� �Ǹ� ������ �ٷ� ���������� ������,
		// ���̸� �����ϴ� ť�� ������ ��Ұ� �ִ� ����� ���̶�� �� �� �ִ�.
		if (pos < cnt)
			cout << "�ִ� ��� ���� : " << l[pos] << endl;

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
		min = n * n; // ��� ��θ� ���ƴٳ൵ n * n�̴�, �̸� �ּҰ����� �����صд�
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf_s("%d", &map[i][j]);
		//DFS(0, 0, 1); // DFS ����!
		BFS(0, 0); // BFS ����!
		//printf("�ִ� �Ÿ�: %d\n", min);
	}
	////////////////���� & ���� �켱 Ž���� ��////////////////
};

////////////////Ŀ���� ���ڿ��Լ��� ��////////////////

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
		//�迭�� ����� strcat
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

	bool cmpstring(char* A, char* B) //������ ���� 1
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

	char* reverse_custom(char* src) // ���ڿ� ���� ' ' ����
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

	int fact(int fac) //���丮��
	{
		if (fac == 0 || fac == 1)
			return 1;

		return fac * fact(fac - 1);
	}
};


///////////////���� ������� ��////////////////
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

		// ȯ�� �迭�� ������ ���پ� �о���δ�
		while (file.good())
		{
			getline(file, L[size % K]);
			size++;
		}

		// ȯ�� �迭�� �������� ũ�� ���
		int start = size > K ? (size % K) : 0;
		int count = min(K, size);

		//���� ������� ���ҵ��� �� ���
		for (int i = 0; i < count; i++)
		{
			cout << L[(start + i) % K] << endl;
		}
	}
};


///////////////���� ������� ��////////////////

///////////////������ ���� //////////////////
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

///////////////������ ���� //////////////////

//////////���� ť ������ ��////////////////
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
////////�Լ� �������� �� /////////////

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

////////�Լ� ������ �� /////////////

////////����(��Ʈ)�� ��////////////
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

		//����� ������ �迭�� �ϳ��� ���Ͽ� �����Ѵ�. 
		while (i <= m && j <= e) {
			if (v[i] < v[j])ret.push_back(v[i++]);
			else if (v[i] > v[j])ret.push_back(v[j++]);
		}

		//���� ������ �ڿ� ä���־��ش�. 
		while (i <= m)  ret.push_back(v[i++]);
		while (j <= e)  ret.push_back(v[j++]);

		//���� �迭�� �������ش�.
		for (int k = s; k <= e; k++) {
			v[k] = ret[copy++];
		}
	}

	//�պ� ����
	static void mergeSort(vector<int>& v, int s, int e) {
		if (s<e) {
			int m = (s + e) / 2;
			/*divide, ����*/
			mergeSort(v, s, m); //s���� m����
			mergeSort(v, m + 1, e); //m+1���� e���� 
									/*conquer, �պ�*/
			merge(v, s, e, m);
		}
	}


};
////////����(��Ʈ)�� ��////////////

////////����Լ� ���ø��� ��//////////
template <typename T> class Complex
{
public:
	Complex(T a = T(), T b = T()) : re(a), im(b)
	{
	}

	// �Ϲ�ȭ�� ���������
	template <typename U>
	Complex(const Complex<U>& rhs);

	//��� Ÿ���� Complex�� private ����� ������ �� �־�� �Ѵ�
	template <typename U>
	friend class Complex;

private:
	T re;
	T im;
};

template <typename T>
template <typename U>
Complex<T>::Complex(const Complex<U>& rhs) : re(rhs.re), im(rhs.im) {}

////////����Լ� ���ø��� ��//////////


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

////////����(��Ʈ)�� ��////////////


////////////////////////////////////////////////