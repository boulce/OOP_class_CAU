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



