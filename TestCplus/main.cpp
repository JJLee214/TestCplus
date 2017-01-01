#pragma once
#include "main.h"
#include "Singleton.h"
#include "BinaryTree.h"

int n; // ������ �� ����
int DFSmap[30][30], visit[30]; // ���� ��İ� �湮 ���θ� ��Ÿ���� �迭

/////////////������////////////////////
template <typename T>
void f(const T &x) {
	std::cout << "f: value = " << x << std::endl;
}

template <typename T>
void CallWithMax(const T &a, const T &b)
{
	f(a > b ? a : b);
}

int fib_buf[1000] = { 0, };
int fibo(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	if (fib_buf[n] != 0)
		return fib_buf[n];

	fib_buf[n] = fibo(n - 1) + fibo(n - 2);

	return fib_buf[n];
}

int practiceFunc(const int mah)
{
	cout << "mah : " << mah << endl;
	return mah;
}

void consttest(int* const hoo)
{
	*hoo = 100;
}

void consttest2(const char * str)
{
	str = "�̰� �o��?";
	// str�� �ּҰ� ����Ű�� ���ڿ��� �Ű������� �Ѿ�� ���ڿ��� �ƴ�
	// "�̰� �o��?"��� ���� ���ο� ���ڿ��� �ٲ�����ϴ�.
}

void MySwap(int* const a, int* const b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

//�������� ���� ���� ���� - effective c++ 35��
class GameCharacter;  
class HealthCalcFunc
{
public:
	virtual int calc(const GameCharacter& gc) const
	{
		//���� ü�� ���
		return 0;
	}

};

HealthCalcFunc defaultHealthCalc;

class GameCharacter
{
public :
	explicit GameCharacter(HealthCalcFunc *phcf = &defaultHealthCalc) : pHealthCalc(phcf)
	{

	}
	int healthValue() const
	{
		return pHealthCalc->calc(*this);
	}

private:

	HealthCalcFunc *pHealthCalc;

};

//�������� ���� ���� ����

class Shape
{
public:
	enum ShapeColor
	{
		Red, Green, Blue
	};

	void draw(ShapeColor color = Red) const
	{
		doDraw(color);
	}
private:
	virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle : public Shape
{
private:
	virtual void doDraw(ShapeColor color) const;
};

class Animal {};
class Dog : public Animal {};



class Kitty {
public:
	virtual void func() { cout << "Kitty on your lap\n"; }
};

class Chobits : public Kitty {
public:
	void func() { cout << "Chobits\n"; }
} obj;


/////////////������////////////////////

///////////���ø� ��Ÿ ���α׷���////////////
template<int N> struct Binary
{
private:
	// �� �ڸ����� ��ȿ���� Ȯ���ϱ� ���� template
	template<int N> struct Bit;
	template<> struct Bit<0>
	{
		enum { kValue = 0 };
	};
	template<> struct Bit<1>
	{
		enum { kValue = 1 };
	};
public:
	enum
	{
		kValue = 2 * Binary<N / 10>::kValue + Bit<n % 10>::kValue
	};
};

///////////���ø� ��Ÿ ���α׷���////////////

///////typetrait//////////
// primary template
template<typename T>
struct IsPointer
{
	enum { kValue = false };
};

// partial specialization
template<typename T>
struct IsPointer<T*>
{
	enum { kValue = true };
};

template<typename T>
void foo(const T& a)
{
	if (IsPointer<T>::kValue)
		cout << "T: pointer" << endl;
	else
		cout << "T: not pointer" << endl;
}
///////typetrait//////////

void DFS(int v)
{
	int i;

	visit[v] = 1; // ���� v�� �湮�ߴٰ� ǥ��
	for (i = 1; i <= n; i++)
	{
		// ���� v�� ���� i�� ����Ǿ���, ���� i�� �湮���� �ʾҴٸ�
		if (DFSmap[v][i] == 1 && !visit[i])
		{
			printf("%d���� %d�� �̵�\n", v, i);
			// ���� i���� �ٽ� DFS�� �����Ѵ�
			DFS(i);
		}
	}
}
 
////////�Լ� ������ �� �ݹ� �Լ�////////////
void CallBackTargetFunc()
{
	cout << "      @@@@>> receive callback" << endl;
}


void CallBackTestFunc(void(*callbackFunc)())
{
	int sum = 0;
	while (1)
	{

		cout << "callback func!" << endl;
		callbackFunc();
		break;
		//string input;
		//cout << "you can insert command string" << endl;
		//cin >> input;

		//if (input == "end") //end �Է½� ����
		//{
		//	break;
		//}
		//else
		//{
		//	cout << "command is : " << input << endl;

		//	if (input == "sum")
		//	{
		//		++sum;
		//		cout << "add sum : " << sum << endl;
		//	}

		//	else if (input == "shoot")
		//	{
		//		cout << "      @@@>> direct shoot callback" << endl;
		//		callbackFunc();
		//	}
		//	else if (input == "reset")
		//	{
		//		sum = 0;
		//		cout << "reset sum : " << sum << endl;
		//	}
		//	else
		//	{
		//		cout << "command error" << endl;
		//	}
		//}

		//if (sum == 3)
		//{
		//	cout << "      @@>> sum shoot callback" << endl;
		//	callbackFunc();
		//}
	}

}

////////�Լ� ������  �� �ݹ� �Լ�////////////


//////////////////////////���ڿ� Ŀ���� �Լ�//////////////////////////
int strrev_c(char* src)
{
	if (!src)
		return -1;
	if (!*src)
		return -1;

	int size = strlen(src);
	int limit = size / 2;
	for (int i = 0; i < limit; i++)
	{
		char *temp_c = &src[size];

		cout << src[size] << endl;
		src[size] = src[i];

		//src[i] = temp_c;

		size--;
	}

	return 0;
}

int strrev_c2(char *s)
{
	char tmp;
	int len = strlen(s);
	for (int i = 0; i<len / 2; ++i)
	{
		tmp = *(s + i);
		*(s + i) = *(s + len - 1 - i);
		*(s + len - 1 - i) = tmp;
	}
	return 0;
}
//////////////////////////���ڿ� Ŀ���� �Լ�//////////////////////////

int main()
{
	int start; // ���� ����
	int v1, v2;

	cout << "foo!" << endl;

	//scanf_s("%d%d", &n, &start);

	//while (1)
	//{
	//	scanf_s("%d%d", &v1, &v2);
	//	if (v1 == -1 && v2 == -1) break; // -1�� -1�� �ԷµǸ� ���� ���� Ż��
	//	map[v1][v2] = map[v2][v1] = 1; // ���� v1�� ���� v2�� ����Ǿ��ٰ� ǥ��
	//}
	//DFS(start); // DFS ����!

	int tempint = 65;
	testclass01 tc;


	char str[10];
	tc.itoa(64, str);
	cout << "itoa test : " << str << endl;


	//////////////////////////////���� �Լ� �׽�Ʈ�� ��////////////////////////////
	cout << "----�����Լ� �׽�Ʈ�� ��----" << endl;
    parentclass p1; //���� ���� �Լ� �߰��� ���� �߻� Ŭ������ �Ǿ���ȴ�
	parentclass *p11;
	p11 = new catclass;

	catclass p2;
	dogclass p3;
	catclass cat2;

	cout << "test1 : " << p1.bark01() << " " << p1.bark02() << endl;;
	cout << "test2 : " << p2.bark01() << " " <<  p2.bark02() << " " << p2.bark02("114514") << endl;;
	cout << "test3 : " << p3.bark01() << " " << p3.bark02() << endl;;
	cout << "test4 : " << p11->bark01() << " " << p11->bark02() << endl;;
	cout << "test5 : " << cat2.bark01() << " " << cat2.bark02() << endl;
	
	p11 = &p2;

	cout << "test4 : " << p11->bark01() << " " << p11->bark02() << endl;;

	
	cout << "test2 : " << p2.bark03() << " " << p2.bark03() << endl;;
	cout << "test3 : " << p3.bark03() << " " << p3.bark03() << endl;;

	//parentclass* p12 = new parentclass();
	parentclass* p12 = new catclass();
	catclass *cat3 = dynamic_cast<catclass*>(p12);

	cout << "p12 : " << p12->bark01() << endl;
	cout << "p12 : " << p12->bark02() << endl;
	//cout << "cat3 : " << p12->bark03() << endl;

	cout << "cat3 : " << cat3->bark01() << endl;
	cout << "cat3 : " << cat3->bark02() << endl;
	cout << "cat3 : " << cat3->bark03() << endl;

	//////////////////////////////���� �Լ� �׽�Ʈ�� ��////////////////////////////

	//////////////////////////////����ü�� ����ü�� ��//////////////////////////////

	cout << "----����ü�� ����ü�� ��----" << endl;
	st myst;
	myst.st_public_m = 3;
	
	intbox myunion;
	myunion.a = 12345678;
	//myunion.b = 2;

	cout << "union int a : " << myunion.a << endl;
	cout << "union short b : " << myunion.b << endl;
	cout << "union char c : " << myunion.c << endl;
	cout << "union float d : " << myunion.d << endl;

	tag_ip myip1;
	myip1.addr = 19216801;

	cout << "sub[0] : " << myip1.sub[0] << endl;
	cout << "sub[1] : " << myip1.sub[1] << endl;
	cout << "sub[2] : " << myip1.sub[2] << endl;
	cout << "sub[3] : " << myip1.sub[3] << endl;
	//////////////////////////////����ü�� ����ü�� ��//////////////////////////////

	//////////////////////�������� ��//////////////////
	cout << "----������----" << endl;
	enum days
	{
		Sunday,
		Monday,
		Tuesday,
		Wednesday = 10,
		Thursday = 11,
		Friday = 12,
		Saturday
	};


	cout << "sunday : " << Sunday << endl;
	cout << "Monday : " << Monday << endl;
	cout << "Tuesday : " << Tuesday << endl;
	cout << "Friday : " << Friday << endl;
	cout << "saturday : " << Saturday << endl;

	//////////////////////�������� ��//////////////////

	//////////////////////////////�������� ��//////////////////////////////
	int refn = 50;
	int &refn1 = refn;
	int *refn2 = &refn;

	cout << "num : " << &refn << endl;
	cout << "num1 : " << &refn1 << endl;
	cout << "num2 : " << &refn2 << endl;

	//////////////////////////////�������� ��//////////////////////////////

	//////////////////////////////�������� ��//////////////////////////////
	cout << "---- �������� �� ----" << endl;

	class A newA(114);
	class B newB(514);

	newB.ShowData(newA);

	class A newA2(893);
	//class A newA2 = new A(893); //error!
	class A *newA3 = new A(555);

	privater* myprivater = new privater();
	privateFunction(myprivater); //friend �����Լ�
	
	//////////////////////////////�������� ��//////////////////////////////

	//////////////////////////////�����ڿ����ε��� ��//////////////////////////////
	cout << "---- ������ �����ε��� �� ----" << endl;
	MahClass Mah1(114, 514);
	MahClass Mah2(893, 810);
	
	MahClass MahRes = Mah1 + Mah2;
	MahClass MahRes2 = MahRes;
	
	MahRes2++;
	++MahRes2;
	MahRes.ShowData();
	MahRes2.ShowData();

	//////////////////////////////�����ڿ����ε��� ��//////////////////////////////

	//////////////////////////////���ø��� ��//////////////////////////////
	cout << "---- ���ø��� �� ----" << endl;
	char* mychr1 = "Yajyu senpai";
	char* mychr2 = "Kimura";

	Swap(mychr1, mychr2);

	cout << "mychr1 : " << mychr1 << endl;
	cout << "mychr2 : " << mychr2 << endl;

	MyData<int> int_temp;
	MyData<double> double_temp;

	// int_temp ��ü�� 5�� �����Ѵ�. ( MyData<int>::m_data �� 5�� ����ȴ�. )
	int_temp.SetData(5);
	// int_temp ��ü�� ������ �ִ� 5�� ��µȴ�.
	cout << int_temp.GetData() << endl;

	// double_temp ��ü�� 5.1�� �����Ѵ�. ( MyData<double>::m_data �� 5.1�� ����ȴ�. )
	double_temp.SetData(5.1);
	// double_temp ��ü�� ������ �ִ� 5.1�� ��µȴ�.
	cout << double_temp.GetData() << endl;

//	TemplateClass<int> my_int_temp(50);

	TemplateClass<float> * foo1 = new TemplateClass<float>(10);
	TemplateClass<int> * bar1 = new TemplateClass<int>(20);

	cout << "foo1 : " << *foo1->GetData() << endl;
	cout << "bar1 : " << *bar1->GetData() << endl;

	cout << "getdata : " << *foo1->GetData() << endl;
	foo1->ShowData();

	//////////////////////////////���ø��� ��//////////////////////////////
	//////////////////////////////����ó���� ��//////////////////////////////
	cout << "---- ����ó���� �� ----" << endl;
	try {
		funcExecption(9, 0);
	}
	catch (int exce)
	{
		cout << "���� �߻�! ������ ���� " << exce << endl;
	}

	//////////////////////////////����ó���� ��//////////////////////////////
	/////////////////�����Ϳ� �����ڵ��� ��//////////////////

	cout << "----�����Ϳ� �����ڵ��� ��----" << endl;
	char oonaon[] = "Oon! Aon!";
	int n = 10;
	int n2 = 15;
	int n3 = 20;

	int *np = &n;
	int **npp = &np; //����������

	void *pv; //void������
	pv = &n;

	void (*pf)(); //�Լ� ������
	pf = CallBackTargetFunc;
	

	char *oonaon2 = oonaon;
	cout << "n : " << &n << endl;
	cout << "np : " << &np << endl;  
	cout << "npp : " << npp << endl;
	cout << "pv : " << (int*)pv << endl;

	cout << "oonaon : " << *oonaon << endl;
	pf();

	LPSTR mylpstr = "whynot";
	LPCSTR mylpcstr = "whynot2";
	LPCTSTR mylpctstr = "whynot3";
	DOUBLE mydouble = 3.141592;
	TCHAR* mytchar = "whynot4";
	
	cout << mylpstr << endl;
	cout << mylpcstr << endl;
	cout << mylpctstr << endl;
	cout << mytchar << endl;
	/////////////////�����Ϳ� �����ڵ��� ��//////////////////
	/////////////////������ �迭�� �迭 �������� ��//////////////////
	cout << "---������ �迭�� �迭 �������� ��---" << endl;

	char *arr1[5] = { "omaesa", "oon" , "aon", "iiyo", "ikiso" }; //������ �迭
	//char arr5[1][5] = { "MUR", "KMR", "TDKR", "TON", "KBTIT" };
	int arr2d[2][3] = { 1, 2, 3, 4, 5, 6}; 
	int (*arr2dp)[3] = arr2d; //�迭 ������
	cout << "�����͹迭" << endl;
	cout << arr1[0] << endl;
	cout << *arr1[1] << endl;
	cout << &arr1[1] << endl;
	cout << &arr1[2] << endl;
	cout << *arr1 + 1 << endl;
	//cout << *(arr1) + 1 << end;

	cout << "�迭������" << endl;
	cout << arr2dp[0][0] << endl;
	cout << arr2dp[0][1] << endl;
	//cout << arr2dp[0][0] + 1 << endl;
	cout << arr2dp[1] << endl;
	cout << *arr2dp[1] << endl;
	
	cout << &arr2dp[2] << endl;
	cout << &arr2dp[0][0] << endl;
	cout << &arr2dp[0][1] << endl;
	cout << &arr2dp[0][2] << endl;

	int *myalloc = (int*)malloc(sizeof(int));


	/////////////////������ �迭�� �迭 �������� ��//////////////////
	/////////////////�������� ��//////////////////
	cout << "---- ������� ���ؽ� ----" << endl;

	mutex mtx_lock;
	thread Threads1([&]()
	{
		for (int i = 0; i < 5; ++i)
		{
			mtx_lock.lock();
			cout << "Thread Num : " << i << endl;
			mtx_lock.unlock();
		}
	});


	thread Threads2;
	Threads2 = thread([&]()
	{
		for (int i = 10; i < 15; ++i)
		{
			mtx_lock.lock();
			cout << "Thread Num : " << i << endl;
			mtx_lock.unlock();
		}
	});

	thread Threads3 = thread([&](int nParam)
	{
		for (int i = 20; i < 25; ++i)
		{
			mtx_lock.lock();
			cout << "Thread Parameter : " << nParam << endl;
			mtx_lock.unlock();
		}
	}, 4);
	/*thread t(&pf,5);
	t.join();*/

	/////////////////�������� ��//////////////////
	/////////////////������ ��//////////////////

	cout << "---������ ��---" << endl;
	vector<int> va(3);
	va[0] = 8;
	va[1] = 9;
	va[2] = 3;

	va.at(2) = 5;

	for (size_t i = 0; i < va.size(); i++)
	{
		cout << "va : " << va[i] << endl;
	}
	cout << endl;
	vector<int> v(2);
	v.push_back(3);  // ������ ���� 3�Ҵ�
	v.push_back(6);
	v.push_back(4);
	
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << "v : " << v[i] << endl;
	}

	/////////////////������ ��//////////////////

	///////���ڿ� Ŀ���� �Լ�///////
	testclass01 mytest;
	
	cout << "���ڿ�Ŀ�����Լ�" << endl;
	char hkdogata[50] = "kusogadovaa";
	char zuruzuru[50] = "zuruzuru";
	char *iloveyoursoul = "I Love Your Soul";
	mychr_custom *mychr = new mychr_custom();

	cout << "my strlen : " << mychr->c_strlen(hkdogata) << endl;
	
	//mychr->c_strcat(hkdogata, zuruzuru);
	//cout << "my strcat : " << hkdogata << endl;
	
	mychr->c_strcpy(hkdogata, zuruzuru);
	cout << "my strcpy : " << hkdogata << endl;

	
	//char mahstr[200] = "���� ����  ����. �׸���, C���� ���α׷��� �ۼ��Ѵ�. ȭ����! ������ ����";
	//char *delimeters = " ,.!";
	//char * pos;
	//char *context;
	//pos = strtok_s(mahstr, delimeters, &context);  //ó�� ȣ�� �ÿ� ��� ���ڿ� ����
	//cout << pos << endl;


	char *tokend;
	char *context;
	tokend = mychr->c_strtok(iloveyoursoul, " ");
	//tokend = strtok_s(iloveyoursoul, " ", &context);
	cout << "my strtok : " << tokend << endl;
	//cout << "my strtok : " << tokend << endl;

	char str_apple[] = " apple";
	char str_apple2[] = "apple";
	
	cout << "strcmp : " << strcmp(str_apple, str_apple2) << endl;


	cout << "fact 4! : " << mychr->fact(4) << endl; //���丮��

	char mychar[] = "do or do not. there is no try";
	char cmpchar[] = "no";

	mychr->reverse_custom(mychar);
	cout << "reverse special : " << mychar << endl;

	//ychr->reverseWords(mychar);
	//cout << mychar << endl;

	///////���ڿ� Ŀ���� �Լ�///////


	/////////////������ ����/////////////////

	cout << "cmp string - ������ ���� : " << mychr->cmpstring(mychar, cmpchar) << endl;
	Vehicle Car("CAR", 4);
	Vehicle Carriage("CARRIAGE", 2);

	cout << "v1 name : " << Car.getName() << " / v1 wheels : " << Car.getNumberOfWheels() << endl;
	cout << "v2 name : " << Carriage.getName() << " / v2 wheels : " << Carriage.getNumberOfWheels() << endl;

	Comtus2 *mycomtus = new Comtus2();
	int coordmap[7][7] =
	{ { 0, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 1 },
	{ 0, 0, 1, 1, 1, 0, 1 },
	{ 1, 1, 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 1, 1, 0 },
	{ 1, 1, 0, 0, 0, 0, 0 }
	};

	cout << "areas : " << mycomtus->CalcArea(coordmap) << endl;

	/////////////������ ����/////////////////


	////////////////���� �켱 Ž���� ��////////////////

	cout << "���� �켱Ž��" << endl;
	commonclass cclass;
	//cclass.run();


	//////////���� ť ������ ��////////////////
	cout << "���� ť ������ ��" << endl;
	//CustomStack<int> *mystack = new CustomStack<int>();
	//auto_ptr<CustomStack<int>> mystack(new CustomStack<int>()); //����Ʈ ������
	shared_ptr<CustomStack<int>> mystack(new CustomStack<int>());
	shared_ptr<CustomStack<int>> mystack2(mystack);

	mystack = mystack2;


	mystack->initStack(3);
	mystack->push(8);
	mystack->push(9);
	mystack->push(3);
	mystack->push(1);

	mystack->pop();
	mystack->pop();
	mystack->pop();	
	mystack->pop();


	//////////���� ť ������ ��////////////////
	CustomQueue<int> *myqueue = new CustomQueue<int>();
	myqueue->initializeQueue(3);
	myqueue->push(8);
	myqueue->push(1);
	myqueue->push(0);
	myqueue->push(9);


	myqueue->pop();
	myqueue->pop();
	myqueue->pop();
	myqueue->pop();
	////////�̱����� �� /////////////
	 
	Singleton::getInstance()->showMessage();

	////////�̱����� �� /////////////
	////////�Լ� �����Ϳ� �ݹ� �Լ��� �� /////////////
	cout << "---�Լ� �����Ϳ� �ݹ� �Լ�----" << endl;

	CallBackTestFunc(CallBackTargetFunc);
	funcclass *fclass = new funcclass();

	fclass->pFunc = practiceFunc;
	fclass->pFunc(50);


	int(*FuncPointer)(const int) = practiceFunc;

	FuncPointer(114);

	////////�Լ� �����Ϳ� �ݹ� �Լ��� �� /////////////

	////////////////////////////////////////////////


	////////����(��Ʈ)�� ��////////////
	cout << "----������ ��----" << endl;

	char name[] = "Chara";
	int ar[] = { 5,2,6,1,7,9,4,3 };
	vector<int> ar2 = { 3,5,6,1,8,9,7,4, 5, 6, 2, 7, 8 };

	//sortClass::qsort(ar2, 0, ar2.size() - 1);
	//sortClass::mergeSort(ar2, 0, ar2.size() - 1);
	sortClass::qsort(ar2, 0, ar2.size() - 1);
	
	
	//��� ǥ��//
	cout << "ar2 size : " << sizeof(name) << endl;
	cout << "quick sort result : "; 
	for (int i = 0; i < ar2.size(); i++)
	{
		cout << ar2[i] << " ";
	}

	cout << endl;
	//��� ǥ��//


	////////����(��Ʈ)�� ��////////////

	/////////////������////////////////////
	cout << "----������----" << endl;
	int arr[2][3] =
	{
		{ 1, 2, 3 }
		,{ 4, 5, 6 }
	};
	int(*ptr)[3] = arr;

	printf("%d \n", ptr[0][0]);
	printf("%d \n", *(*(ptr + 1)) + 2);
	printf("%d \n", (*ptr + 1)[2]);

	printf("%d \n", *ptr[0]);
	printf("%d \n", ptr);
	printf("%d \n", *((*ptr) + 1));
	printf("%d \n", **ptr + 2);

	CallWithMax(5, 7);
		
	vector<int> vec = { 3, 5, 6, 1, 4, 2, 4 , 5 };
	const vector<int>::iterator iter = vec.begin(); // T* const �� ���� �ǹ�
	*iter = 10;
	//++iter; //���� ! iter�� ����Դϴ�

	vector<int>::const_iterator cIter = vec.begin(); //const T* �� ���� �ǹ�
	//*cIter = 10; //����! *cIter�� ����̱� ������ �� �˴ϴ�
	++cIter;

	//cout << iter << endl;

	cout << "vector elements " << endl;
	for (vector<int>::iterator iterm = vec.begin(); iterm != vec.end(); iterm++)
	{
		cout << *iterm << " ";
	}
	cout << endl;

	int a0 = 10;
	int* const a1 = &a0;
	int* const *a2 = &a1;

	a0 = 114514;
	*a1 = 364364;
	//a1 = null;
	*(*a2) = 810;
	//*a2 = nullptr;shared_ptr<widget>(new Widget)

	int b0 = 30;
	const int* b1 = &b0;
	const int** b2 = &b1;

	//*b1 = 514;
	b1 = &a0;
	*b2 = nullptr;
	vector<string> bv = { "iiyokoiyo", "oonaon", "huatu" };
	cout << "int size " << bv[1] << endl;

	map<string, int> mappractice;
	mappractice["apple"] = 100;

	cout << mappractice["apple"] << endl;
	
	multimap<string, int> multimappractice;
	multimappractice.insert(pair<string, int>("Foo", 50));
	multimappractice.insert(pair<string, int>("Foo", 90));
	multimappractice.insert(pair<string, int>("Foo", 114));

	multimap<string, int>::iterator mmapiter;
	for (mmapiter = multimappractice.begin(); mmapiter != multimappractice.end(); mmapiter++)
	{
	//	cout << 

	}
	set<int> falma;

	Dog* dog1 = new Dog;
	Animal* animal1 = dog1;

	shared_ptr<Dog> dog2(new Dog);
	shared_ptr<Animal> animal2 = dog2;

	animal2 = dog2;
	if (animal2 == dog2)
	{
		cout << "����Լ� ���ø�?" << endl;
	}

	int tt = 0; //typetraits
	foo(tt);  //< T: not pointer //typetraits
	foo(&tt); //< T: pointer //typetraits


	Kitty *po = dynamic_cast <Kitty *> (&obj);
	po->func();

	/////////////������////////////////////
	//////////////���� Ʈ���� ��//////////////////

	cout << "----���� Ʈ��----" << endl;
	// ��� ����
	BinaryTree* A = BT_CreateNode('A');
	BinaryTree* B = BT_CreateNode('B');
	BinaryTree* C = BT_CreateNode('C');
	BinaryTree* D = BT_CreateNode('D');
	BinaryTree* E = BT_CreateNode('E');
	BinaryTree* F = BT_CreateNode('F');
	BinaryTree* G = BT_CreateNode('G');

	//Ʈ���� ��� �߰�
	A->Left = B;
	A->Right = E;
	B->Left = C;
	B->Right = D;
	E->Left = F;
	E->Right = G;

	//Ʈ�� ���
	//���� ǥ���
	cout << "Preorder Print" << endl;
	BT_PreorderPrintTree(A);
	printf("\n");

	//���� ǥ���
	cout << "Inorder Print" << endl;
	BT_InoderPrintTree(A);
	printf("\n");

	//���� ǥ���
	cout << "Postorder Print" << endl;
	BT_PostoderPrintTree(A);
	printf("\n");

	//Ʈ�� �Ҹ�
	BT_DestroyTree(A);
	//////////////���� Ʈ���� ��//////////////////
	///////////////////����Ʈ �������� ��////////////////
	//shared_ptr<catclass> mycat(new catclass());
	//shared_ptr<parentclass> myparent(new catclass());

	//shared_ptr<catclass> myaprent2 = static_pointer_cast<catclass>(myparent);

	//int m4 = 40;
	//float m5 = 5.14;
	//m4 = static_cast<int>(m5);
	//cout << "m4 " << m4 << endl;

	///////////////////����Ʈ �������� ��////////////////

	system("pause");
	
	return 0;
}

