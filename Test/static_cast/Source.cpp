#include<iostream>
#include<cstdio>
using namespace std;

class shape {
private:
	int a;
public:
	shape() {
		//cout << "shape class create\n";
	}
	virtual ~shape() {
		//cout << "shape class delete\n";
	}
	virtual void draw() {
		cout << "shape : called draw()" << endl;
	}
};


class triangle : public shape {
private:
	int b;
public:
	triangle() {
		b = 30;
		//cout << "triangle class create\n";
	}
	~triangle() {
		//cout << "triangle class delete\n";
	}
	void draw() {
		cout << "triangle : called draw()" << endl;
	}

	void onlyTriangle() {
		cout << "triangle : onlyTriangle()" << endl;
		cout << b << endl;
	}
};


int main(void) {

// 	//1.upcast
//    	shape *ps;  //�θ� Ŭ���� Ÿ�� ������
//     triangle *t = new triangle(); //�ڽ� Ŭ���� �ν��Ͻ�
//     	
//   	cout << t << '\n';
//   	ps = static_cast<triangle *>(t);
//     //ps = t;
//   	cout << ps << '\n';
//     cout << "//1. upcast //\n";
//     ps->draw();
//   	delete(t);

	//2.downcast
    shape *s = new shape();        //�θ� Ŭ���� �ν��Ͻ�
    triangle *pt;   //�ڽ� Ŭ���� Ÿ�� ������
 	s->draw();		//virtual�� ���� ������ �� �θ� Ŭ������ �Լ� ����
 	
 	//pt = static_cast<triangle *>(s);
	pt = dynamic_cast<triangle *>(s);
	if (pt == nullptr)
	{
		cout << "is Null\n";
	}
	else
	{
		pt->draw();		//virtual ������� �ڽ� Ŭ������ �Լ� ����.
		pt->onlyTriangle();
	}
    
 	delete(s);

}