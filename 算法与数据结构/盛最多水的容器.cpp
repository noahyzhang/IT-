#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0, right = height.size() - 1;
		int maxarea = 0;
		while (left < right)
		{
			maxarea = std::max(maxarea, std::min(height[left], height[right])*(right - left));
			if (height[left] < height[right])
				left++;
			else
				right--;
		}
		return maxarea;
	}
};

//int main()
//{
//	char p = '2';
//	std::cout << (int)&p << std::endl;
//	char&& pp = std::move(p);
//	
//	pp = '3';
//	p = '4';
//
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//class Moveable {
//public:
//	Moveable() :i(new int(3)) {}
//	~Moveable() { delete i; }
//	Moveable(const Moveable & m) : i(new int(*m.i)) { }
//	Moveable(Moveable && m) :i(m.i) {
//		m.i = nullptr;
//	}
//
//	int* i;
//};
//
//int main() {
//	Moveable a;
//
//	Moveable c(move(a));    // 会调用移动构造函数
//	cout << *c.i << endl;
//	cout << *a.i << endl;   // 运行时错误
//}

//int get_data(int&& num)
//{
//	num += 3;
//	return num;
//}
//
//int main()
//{
//	int a = 5;
//	cout << get_data(move(a)) << endl;
//	cout << a << endl;
//	return 0;
//}

//#include<string>
//
//int main()
//{
//	std::string st{ "1234" };
//	string s = std::move(st);
//
//	int size = st.size();
//	int i = st[2];
//	st[1] = '9';
//}


//int main()
//{
//	std::vector<int> vec1{ 1,2,3,4 };
//	std::vector<int> vec2 = std::move(vec1);
//
//	int size = vec1.size();
//	int i = vec1[2];
//	vec1[1] = 7;
//}