#include <iostream>

class vectorNd {
public:
	int n;//������ ������ũ��
	//����Ʈ ������
	vectorNd() {
	}
	//������
	vectorNd(int n_) {
		n = n_;
	}
	
	int *v; //������ ũ�⸸ŭ ���� �Ҵ�.  //ũ��
	
	void malloc_a() {//n���� ������ ũ�⸦ �������ִ� �Լ�
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
	
	vectorNd result;//�̺κж����� ����Ŭ������ ����Ʈ �����ڰ� �ʿ��ϴ�.
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
	//����� ������ ����
	//������ ũ�⸸ŭ �����Ҵ����ش�.
	vectorNd result(m);
	result.malloc_a();

	//���� a ={1,2,3,4};
	//���� a�� �����ϰ�
	//���� a�� ũ�⸦ �����Ҵ��Ѵ�.
	vectorNd a(n);
	a.malloc_a();
	for (int i = 0; i <  n; i++) {
		a.v[i] = i + 1;
	}
	//��Ʈ���� ����
	//��Ʈ������ ����� m(=5)
	//��Ʈ���� ������ m��ŭ ���͸� ������ش�.
	matrix_mxn m_a;
	m_a.m = m;
	m_a.malloc_ac();

	//��Ʈ���� ������ ���Ϳ� ũ�⸦ �������� �Ҵ����ִ� �κ�
	for (int i = 0; i < m; i++) {
		m_a.vector[i].n = n;
		m_a.vector[i].malloc_a();
	}
	////��Ʈ���� ������ ���Ϳ� ������ �����ϴ� �κ� 1~20����
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			m_a.vector[i].v[j] = count++;
		}
	}
	//���Ѵ�!
	result = m_a*a;
	
	//������!
	for (int i = 0; i < m; i++) {
		std::cout << result.v[i] << " ";
	}



	getchar();
	return 0;
}