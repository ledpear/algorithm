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
//    	shape *ps;  //부모 클래스 타입 포인터
//     triangle *t = new triangle(); //자식 클래스 인스턴스
//     	
//   	cout << t << '\n';
//   	ps = static_cast<triangle *>(t);
//     //ps = t;
//   	cout << ps << '\n';
//     cout << "//1. upcast //\n";
//     ps->draw();
//   	delete(t);

	//2.downcast
    shape *s = new shape();        //부모 클래스 인스턴스
    triangle *pt;   //자식 클래스 타입 포인터
 	s->draw();		//virtual로 선언 안했을 시 부모 클래스의 함수 실행
 	
 	//pt = static_cast<triangle *>(s);
	pt = dynamic_cast<triangle *>(s);
	if (pt == nullptr)
	{
		cout << "is Null\n";
	}
	else
	{
		pt->draw();		//virtual 상관없이 자식 클래스의 함수 실행.
		pt->onlyTriangle();
	}
    
 	delete(s);

}