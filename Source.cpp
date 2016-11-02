#include <iostream>

class vectorNd {
public:
	int n;//벡터의 차원의크기
	//디폴트 생성자
	vectorNd() {
	}
	//생성자
	vectorNd(int n_) {
		n = n_;
	}
	
	int *v; //변수의 크기만큼 동적 할당.  //크기
	
	void malloc_a() {//n차원 벡터의 크기를 설정해주는 함수
		v = (int*)malloc(sizeof(int)*n);
	}

	int operator *(const vectorNd& b) {
					int a=0;
					for (int i = 0; i < n; i++) {
						a = a + (this->v[i] * b.v[i]);
					}
					return a;
				}

};

class matrix_mxn {
public:
	int m;
	vectorNd *vector; 
	
	vectorNd result;//이부분때문에 벡터클래스의 디폴트 생성자가 필요하다.
	void malloc_ac() {
		vector=(vectorNd*)malloc(sizeof(vectorNd)*m);
		result.n = m;
		result.malloc_a();
	}


	vectorNd operator *(const vectorNd& a) {
		
		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < a.n;j++)
			result.v[i] = this->vector[i]*a;
		}
		return result;
	}
};



int main() {
	//5x4 * 4x1 = 4 x 1
	int m = 5;
	int n = 4;
	int count = 1;
	//결과를 저장할 벡터
	//벡터의 크기만큼 동적할당해준다.
	vectorNd result(m);
	result.malloc_a();

	//벡터 a ={1,2,3,4};
	//벡터 a를 선언하고
	//벡터 a의 크기를 동적할당한다.
	vectorNd a(n);
	a.malloc_a();
	for (int i = 0; i <  n; i++) {
		a.v[i] = i + 1;
	}
	//매트릭스 선언
	//매트릭스의 행수는 m(=5)
	//매트릭수 내부의 m만큼 벡터를 만들어준다.
	matrix_mxn m_a;
	m_a.m = m;
	m_a.malloc_ac();

	//매트릭스 내부의 벡터에 크기를 동적으로 할당해주는 부분
	for (int i = 0; i < m; i++) {
		m_a.vector[i].n = n;
		m_a.vector[i].malloc_a();
	}
	////매트릭스 내부의 벡터에 변수를 삽입하는 부분 1~20까지
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			m_a.vector[i].v[j] = count++;
		}
	}
	//곱한다!
	result = m_a*a;
	
	//결과출력!
	for (int i = 0; i < m; i++) {
		std::cout << result.v[i] << " ";
	}



	getchar();
	return 0;
}