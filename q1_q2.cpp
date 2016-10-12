	#include <iostream>
#include <string>

//void print(const int& i)
//{
//	std::cout << i << std::endl;
//}
//
//void print(const float& i)
//{
//	std::cout << i << std::endl;
//}
//
//void print(const std::string& i)
//{
//	std::cout << i << std::endl;
//}
template<class t1>
void print(const t1& i){
	std::cout << i << std::endl;
}

//class VectorInt2D
//{
//	int x_, y_;
//};
//
//class VectorFloat2D
//{
//	float x_, y_;
//};
//
//class VectorDouble2D
//{
//	double x_, y_;
//};
template<class t2>
class Vector2D
{public:
	t2 x_, y_;
};
int main()
{
	print(1);
	print(2.345f);
	print("Hello World");
	Vector2D<int> my_vector;
	my_vector.x_=3;
	my_vector.y_=4;
	print(my_vector.x_);
	print(my_vector.y_);

	getchar();
	return 0;
}
