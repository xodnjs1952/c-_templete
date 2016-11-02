#include <iostream>

class vectorNd {
public:
	int n;//벡터의 차원
	vectorNd() {
		n = 0;
	}

	vectorNd(int n_) {
		n = n_;
	}
	
	int *v; //변수의 크기만큼 동적 할당.  //크기
	
	void malloc_a() {
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
	
	vectorNd result;
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
	//4x3 * 3x1 = 4 x 1
	//(1  2  3)     1
	//(4  5  6)    *2
	//(7  8  9)     3
	//(10 11 12)
	
	vectorNd b(5);
	b.malloc_a();

	vectorNd a(4);
	a.malloc_a();
	a.v[0] = 1;
	a.v[1] = 2;
	a.v[2] = 3;
	a.v[3] = 4;

	matrix_mxn m_a;
	m_a.m = 5;
	m_a.malloc_ac();
	m_a.vector[0].n = a.n;
	m_a.vector[0].malloc_a();
	m_a.vector[1].n = a.n;
	m_a.vector[1].malloc_a();
	m_a.vector[2].n = a.n;
	m_a.vector[2].malloc_a();
	m_a.vector[3].n = a.n;
	m_a.vector[3].malloc_a();
	m_a.vector[4].n = a.n;
	m_a.vector[4].malloc_a();

	m_a.vector[0].v[0] = 1;
	m_a.vector[0].v[1] = 2;
	m_a.vector[0].v[2] = 3;
	m_a.vector[0].v[3] = 4;

	m_a.vector[1].v[0] = 5;
	m_a.vector[1].v[1] = 6;
	m_a.vector[1].v[2] = 7;
	m_a.vector[1].v[3] = 8;

	m_a.vector[2].v[0] = 9;
	m_a.vector[2].v[1] = 10;
	m_a.vector[2].v[2] = 11;
	m_a.vector[2].v[3] = 12;

	m_a.vector[3].v[0] = 13;
	m_a.vector[3].v[1] = 14;
	m_a.vector[3].v[2] = 15;
	m_a.vector[3].v[3] = 16;

	m_a.vector[4].v[0] = 17;
	m_a.vector[4].v[1] = 18;
	m_a.vector[4].v[2] = 19;
	m_a.vector[4].v[3] = 20;
	
	b = m_a*a;
	std::cout << b.v[0] <<" "<< b.v[1]<< " " << b.v[2] << " "<<b.v[3] << " " << b.v[4] << std::endl;




	getchar();
	return 0;
}