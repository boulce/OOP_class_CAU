#  C++ 기초 체크리스트 (for C언어 숙달자)

<br>

****

<br>

```
C를 할 줄 알지만, C++을 처음 공부하는 사람이 많을 것이다.
C++은 C와 다른 점이 많다. 하지만 처음부터 모든 것들을 공부하면 시간 낭비가 심할텐데
C만 할 줄 아는 상태에서 C++을 처음 공부했던 경험을 바탕으로 처음 보거나, 새롭게 배운 것들을 정리했다.
정말 기초적인 부분이니 쭉 보면서 본인이 이해가지 않는 부분만 찾아서 공부하면 좋을 것이다.
```

<br>

## 1. cout (Standard Output)

<br>

```
C에서 printf() 함수와 비슷하지만, 조금은 다른 기능을 한다.
```

#### cout : screen stream object

다음의 코드를 실행해보자.

```c++
#include <iostream>

int		main(void)
{
	std::cout << "Hello World! ";
	std::cout << "now, I'm C++ Programmer!" << std::endl;
    return (0);
}
```

결과

```
Hello World! now, I'm C++ Programmer!
$
```

<br>

<br>

## 2. cin (Standard Input)

<br>

```
C에서 scanf() 함수의 기능과 비슷하다.
```

#### cin : keyboard stream object

다음의 코드를 실행해보자

```c++
#include <iostream>
using namespace std;

int			main(void)
{
	int		i;
	
	cout << "Please enter an integer value: ";
	cin >> i;
	cout << "The Value you entered is " << i;
	cout << "and its double is " << i * 2 << endl;
	return (0);
}
```

```
Please enter an integer value: 77
The Value you entered is 77 and its double is 154
$
```

<br>

<br>

## 3. Function

****

문법 자체는 C와 동일하다.

<br>

```c++
#include <iostream>
using namespace std;

int		addition(int a, int b)
{
	int		r;
	r = a + b;
	return (r);
}

int		main(void)
{
	int		z;
	z = addition(5, 3);
	cout << "The result is " << z << endl;
}
```

<br>

<br>

## 4. Array, Pointer, Dynamic allocation

****

<br>

<b>배열과, 포인터는 C와 거의 비슷하다.</b>

<br>

##### 동적할당

```
메모리할당은 run time과 compile time에 작업될 수 있다.
우리가 malloc()을 통해 할당하는 동적할당은 run time에 할당되는 것.
우리가 보통 배열을 int a[10]; 이렇게 할당하는 정적할당은 compile time에 sizeof(int) * 10 만큼 할당되는 것.
```

- malloc <-> new
- Free <-> delete

```c
in C

{
	int		*x;
	
	x = (int *)malloc(sizeof(int) * 10);
	...
	free (x);
}
/*
dynamic allocation
- C 메모리할당은 런타임에 실행된다.
*/
```

```c++
in C++

{
	int		*x;
	
	x = new int[10];
	...
	delete[] x;
}
/*
static allocation
- C++ 메모리할당은 컴파일 타임에 실행된다.
*/
```

<br>

##### C스타일

처음에 프로그램이 컴파일할 때, x라는 포인터변수만 가진다. 즉 4바이트만 가짐.<br>

실행해서 한줄씩 내려가다, malloc(sizeof(int) * 10)을 만나면 40바이트가 포인터변수 x에 할당됨.

<br>

##### C++ 스타일

컴파일 할 때, new int[10]을 만나면 그 크기(40바이트) 만큼 할당한다.

<br>

그렇다면 이 둘의 장단점은 무엇일까?

<br>

![malloc vs new](https://github.com/feldblume5263/OOP_class_CAU/blob/master/other_materials/newVsMalloc.png?raw=true)



<br>

<br>

## 5. Class

****

##### C++ 는 C언어 + Class라고 할 수 있을 정도로 중요하다.

가장 기본적인 Class에 대해서 알아보자.

<br>

Class 는 member data와 member function을 탑재할 수 있는 자료구조 타입이다.

<br>

```c++
#include <iostream>
using namespace std;

class		Rectangle
{
	int			width, height;
	
public:
	void		set_values(int, int);
	int			area() { return (width * height); }
}

void		Rectangle::set_values(int x, int y)
{
  width = x;
  height = y;
}



int			main(void)
{
	Rectangle		rct, retb;
	
	rect.set_values(3, 4);
	rectb.set_values(5, 6);
	cout << "rect area: " << rect.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	return (0);
}
```

<br>

우리는 메모리에 오브젝트를 가지고 있다. <br>

rect 와 rectb <br>

그리고 각각의 메모리는 width와 height를 가지고 있다. <br>

<br>

<br>

## 6. Class constructor(생성자) / destructor(소멸자)

****

```c++
#include <iostream>
using namespace std;

class		Rectangle
{
	int			width, height;
	
public:
	Rectangle(int, int); // 이렇게 이름이 같은 부분이 생성자(constructor)이다.
	int			area() { return (width * height); }
}

Rectangle::Rectangle(int x, int y) // 생성자 구현
{
  cout << "constructor start" << endl; // main에서 생성 순서를 보기 위한 장치
  width = x;
  height = y;
  cout << "constructor end" << endl;
}



int			main(void)
{	
  cout << "0" << endl;
	Rectangle rect(3, 4); // 오브젝트 생성
  cout << "1" << endl;
	Rectangle rectb(5, 6); // 오브젝트 생성
  cout << "2" << endl;
	cout << "rect area: " << rect.area() << endl;
	cout << "rectb area: " << rectb.area() << endl;
	return (0);
}
```

<br>

<br>

## 7. Pointer to Class object

****

```c++
#include <iostream>
using namespace std;

class		Rectangle
{
	int			width, height;
	
public:
  Rectangle() { width = 1; height = 1; } // 아무값도 들어오지 않았을 때, 생성자.
	Rectangle(int, int);
	int			area() { return (width * height); }
}

Rectangle::Rectangle(int x, int y)
{
  width = x;
  height = y;
}



int			main(void)
{	
	Rectangle		obj(3, 4);
	Rectangle		*foo, *bar, *baz;
  foo = &obj; // obj 주소를 가져다 씀.
  bar = new Rectangle(5, 6); // 한개 크기만큼 생성 매개변수는 5, 6
  baz = new Rectangle[2]; // 2개 크기만큼 생성
	
  
  cout << "obj's area: " << obj.area() << endl;
  cout << "foo's area: " << foo.area() << endl;
  cout << "bar's area: " << bar.area() << endl;
  cout << "baz[0]'s area: " << baz[0].area() << endl;
  cout << "baz[1]'s area: " << baz[1].area() << endl;
  delete bar;
  delete[] baz;
  
	return (0);
}
```

