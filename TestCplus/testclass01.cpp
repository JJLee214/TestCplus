#include "testclass01.h"


testclass01::testclass01()
{
	cout << "olaf" << endl;
}

testclass01::~testclass01()
{
}

int testclass01::path1(int y, int x, int sum)
{
	//// ���� ���: �� �Ʒ� �ٱ��� �������� ���
	//if (y == n - 1) return sum + triangle[y][x];

	//// �޸������̼�
	//int& ret = cache[y][x][sum];
	//if (ret != -1)
	//	return ret;

	//sum += triangle[y][x];
	return 0;
	//return ret = max(path1(y + 1, x + 1, sum), path1(y + 1, x, sum));
}

char* testclass01::itoa(int num, char *str)
{
	int i = 0;
	int radix = 10;  // ���� 
	int deg = 1;
	int cnt = 0;

	while (1) {    // �ڸ����� ���� �̴´� 
		if ((num / deg) > 0)
			cnt++;
		else
			break;
		deg *= radix;
	}
	deg /= radix;    // deg�� ���� �ڸ������� ���ڸ� ���� ī��Ʈ �Ǿ �ѹ� ��������  
					 // EX) 1241 ->    cnt = 4; deg = 1000; 
	for (i = 0; i<cnt; i++) {    // �ڸ�����ŭ ��ȸ 
		*(str + i) = num / deg + '0';    // ���� ū �ڸ����� ������ ���� 
		num -= ((num / deg) * deg);        // ���� �ڸ����� ���� ���� 
		deg /= radix;    // �ڸ��� ���� 
	}
	*(str + i) = '\0';  // ���ڿ�����.. 
	return str;
}
//////////////////////////////����ó���� ��//////////////////////////////
void funcExecption(int fun1, int fun2)
{
	if (fun2 == 0)
	{
		throw fun2;
	}
	cout << fun1 << "�� " << fun2 << "�� ���� ���� " << fun1 / fun2 << "�Դϴ�" << endl;
}
//////////////////////////////����ó���� ��//////////////////////////////


//////////////////////////////���ø��� ��//////////////////////////////
//template<typename Tem>
//int TemplateClass<Tem>::bar;
//
//template class TemplateClass<Foo>;
//template class TemplateClass<Bar>;

//////////////////////////////���ø��� ��//////////////////////////////
//class TestClass01
//{
//	
//	int n, triangle[100][100];
//	int cache[100][100][MAX_NUMBER * 100 + 1];
//
//	int path1(int y, int x, int sum)
//	{
//		// ���� ���: �� �Ʒ� �ٱ��� �������� ���
//		if (y == n - 1) return sum + triangle[y][x];
//
//		// �޸������̼�
//		int& ret = cache[y][x][sum];
//		if (ret != -1)
//			return ret;
//
//		sum += triangle[y][x];
//		return 0;
//		//return ret = max(path1(y + 1, x + 1, sum), path1(y + 1, x, sum));
//	}
//
//public:
//	TestClass01();
//	~TestClass01();
//
//	char *itoa(int integer, char *buf, int buf_size, int radix)
//	{
//		int i = 0;
//		if (!buf)
//			return nullptr;
//		if (!buf_size)
//			return nullptr;
//		if (radix <= 0)
//			return nullptr;
//
//		for (; integer; i++, buf_size--)
//		{
//			if (!buf_size)
//				return nullptr;
//			buf[i] = integer % radix + '0';
//			integer /= radix;
//		}
//
//		//if (strrev(buf) < 0)
//		//{
//		//	return NULL;
//		//}
//
//		return buf;
//	}
//};

void foreign::roototherData(B * b)
{
	cout << " mm? " << endl;
}

void foreign::roototherDataRef(B & b)
{
}
