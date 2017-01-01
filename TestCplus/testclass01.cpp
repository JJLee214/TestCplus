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
	//// 기저 사례: 맨 아래 줄까지 도달했을 경우
	//if (y == n - 1) return sum + triangle[y][x];

	//// 메모이제이션
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
	int radix = 10;  // 진수 
	int deg = 1;
	int cnt = 0;

	while (1) {    // 자리수의 수를 뽑는다 
		if ((num / deg) > 0)
			cnt++;
		else
			break;
		deg *= radix;
	}
	deg /= radix;    // deg가 기존 자리수보다 한자리 높게 카운트 되어서 한번 나누어줌  
					 // EX) 1241 ->    cnt = 4; deg = 1000; 
	for (i = 0; i<cnt; i++) {    // 자리수만큼 순회 
		*(str + i) = num / deg + '0';    // 가장 큰 자리수의 수부터 뽑음 
		num -= ((num / deg) * deg);        // 뽑은 자리수의 수를 없엠 
		deg /= radix;    // 자리수 줄임 
	}
	*(str + i) = '\0';  // 문자열끝널.. 
	return str;
}
//////////////////////////////예외처리의 장//////////////////////////////
void funcExecption(int fun1, int fun2)
{
	if (fun2 == 0)
	{
		throw fun2;
	}
	cout << fun1 << "를 " << fun2 << "로 나눈 몫은 " << fun1 / fun2 << "입니다" << endl;
}
//////////////////////////////예외처리의 장//////////////////////////////


//////////////////////////////템플릿의 장//////////////////////////////
//template<typename Tem>
//int TemplateClass<Tem>::bar;
//
//template class TemplateClass<Foo>;
//template class TemplateClass<Bar>;

//////////////////////////////템플릿의 장//////////////////////////////
//class TestClass01
//{
//	
//	int n, triangle[100][100];
//	int cache[100][100][MAX_NUMBER * 100 + 1];
//
//	int path1(int y, int x, int sum)
//	{
//		// 기저 사례: 맨 아래 줄까지 도달했을 경우
//		if (y == n - 1) return sum + triangle[y][x];
//
//		// 메모이제이션
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
