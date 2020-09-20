## 좋은 프로그래밍이란 무엇일까?

[학습 자료](https://github.com/feldblume5263/OOP_class_CAU/blob/master/class_materials/Intro_1_1.pdf)
<br>

### 1. 정확성 (correctness)

		유저의 요구 만족

### 2. 효율성 (efficiency)

		HW (GPU) / SW (algorithms, data structures, ... )

### 3. 유지보수 쉬운(maintainability)

	<객체지향 프로그래밍의 가장 중요한 목적이다. (우리의 가장 관심사)>
		읽기 쉽고 이해하기 쉽다. (readability, understandability)
		수정하기 쉽다. (modifiability)
		확장하기 쉽다. (extensibility)
		디버깅하기 쉽다. (repairablity)
		옮기기 쉽다. (portability)
		재사용하기 쉽다. (reusability)

### 4. 안정성, 신뢰성, 의지가능한 (stability, reliability, depenablitiy)
		언제나 일정하게 정확성을 가져야 한다.

### 5. 사용하기 쉬운 (usability)

### 6. 간결성 (conciseness)

### 7. 보안성 (security)

******

우리의 수업의 focus는 3번 maintainability이다!!<br>
유지보수가 용이하게 프로그래밍하는 것은 매우 중요하기 때문이다.<br>
이것은 결국 cost, time과 연관된다.<br>

******

## 소프트웨어의 위기 (Software Crisis)
<br>

하드웨어 성능 성장과 SW의 복잡화가 가속화된다.<br>
복잡화는 정확한, 이해가능, 확인가능한 프로그램을 만드는 것을 어렵게 한다.<br>
<br>
빌게이츠가 윈도우 demo를 시연했을 때, 블루스크린이 떴다.<br>
그만큼 정확하면서 효율적인 프로그램을 만드는 것은 정말 어렵다.<br>
<br>

#### 소프트웨어 증상
	관리가 불가능한
	유지하기 어려움
	예산 초과
	시간 초과
	나쁜 퀄리티
	올바르게 작동하지 않음
##### 대부분의 문제점 = 정확성

******

## 소프트웨어 개발 사이클
<br>

### 1. 필요성 분석
### 2. 디자인
### 3. 실제 코딩
### 4. 테스트와 디버깅
### 5. 유지
<br>
소프트웨어 개발 단계에서 뭐가 가장 중요할까?<br>
<b>가장 중요한 단계는 유지단계이다!! <- Cost와 Time의 문제이다.</b> <br>

Fred Brooks라는 소프트웨어 교수는 90%이상의 전형적인 시스템의 코스트가 유지관리에서 일어난다고 말했다. 그리고 어떠한 성공적인 소프트웨어들은 관리와 필수불가결한 관계이다. <br>



******

## 소프트웨어 공학

<br>

#### 정의

1. 소프트웨어의 개발, 운영 및 유지 관리에 대한 체계적이고 규율 적이며 정량화 가능한 접근 방식의 적용
2. 안정적이고 효율적으로 작동하는 소프트웨어를 <u><b>경제적</b></u>으로 얻기위한 건전한 엔지니어링 원칙의 수립 및 사용

#### 목표

1. 정확하고 효율적이며 신뢰할 수있는 소프트웨어 생성
2. 소프트웨어 개발 및 유지 관리 <u><b>비용</b></u> 최소화

******

## SE의 목적

<br>

#### Maintainability

### Depenability

### Efficiency

### Usability

******

## 프로그래밍 방법론

<br>

#### 1. 1960년대 - 구조가 없는 프로그래밍

```
	오직 하나의 main프로그램으로 구성
	일련의 명령문으로 이루어짐
	오직 전역 data만 존재
	goto구문 사용 (절대 사용 X)
	함수의 부재
```

  Spaghetti code

```
	복잡하고 얽힌 구조를 가진 코드
	goto 구문으로 계속 건너뛰어다님
	이해하기 불가능함
	흐름을 따라가기 어려움
	수정하기 어려움
```

<br>

#### 2. 절차 프로그래밍 (C)

```
	프로그램 (일련의 절차 수행)
	절차 (같은 순서의 문장)
	더욱 구조화 (반복을 줄임)
	오류에서 더욱 자유로움
	구조화된 프로그램
		Top - down approach
			- 하나의 복잡한 문제를 여러개의 간단한 문제로 쪼개서 해결.
		Divide and conquer
			- Top-down approach와 비슷한 개념.
		Functional decomposition
			- 함수를 사용
			
	** 시험문제를 풀 때에도 이 개념을 이해해서 활용하는 것은 중요하다.
```

<br>

#### 3. 모듈 프로그래밍 (절차 프로그래밍과 비슷)

```
		소프트웨어 프로그램은 서로 다른 모듈의 집합체이다.
		공통 기능의 절차는 별도의 모듈을 통해 함께 그룹화된다.
		모듈의 특징
			프로그램은 인터페이스를 통해 모듈을 사용한다.
			인터페이스 : 가시적, 실행 : 비가시적
			유지성을 증진시킨다.
```

<br>

<b>전역변수를 사용하지 말자</b>

```
		전역변수를 사용하는 것은 매우 위험하다.
		1. 전역변수(Can access everywhere) <-> 지역변수(Access locally)
		2. 데이터를 공유하는 작업(전역변수 사용)은 모듈화를 방해한다.
		3. 모든 모듈들이 제한없이 전역변수를 이용하게 된다.
		4. 모듈이 서로에게 의존하도록 한다. (dependency)
```

<br>

<b>절차/모듈 프로그래밍의 문제점</b>

```
		data와 operation이 분리되어 있다.
		큰 시스템에서 잘 작동하지 않는다. (객체지향에 비해)
			1. 디버그가 힘들다.
			2. 코드 재사용이 제한적이다.
		명시적 생성 및 제거
```

<br>

#### 4. 객체지향 프로그래밍 (JAVA, C++)

```
		객체지향 프로그램은 상호작용하는 오브젝트들의 집합으로 이루어져있다.
		각각의 오브젝트들은 각각의 상태를 유지한다.
		data와 operation은 오브젝트 안에 묶여있다.
```

<br>

<b>오브젝트란 무엇일까?</b>

```
		클래스의 instance이다. (클래스들의 사례)
		오브젝트는
			1. identity (이름)
			2. attribute (멤버)
			3. behavior (메소드)
			4. relationship with other objects
		(데이터 + 기능)오브젝트 + (데이터 + 기능)오브젝트   => 프로그램
		bottom - up approach
```

<br>

<br>

****

## 객체지향언어 프로그램 concepts

<br>

![object_overview](https://github.com/feldblume5263/OOP_class_CAU/blob/master/other_materials/object_overview.png?raw=true)

<br>

### 1. Data Abstraction (자료 추상화)

```
ADT(추상자료형)
	- 특정 구현과 독립적으로 정확하게 지정된 데이터 변수 및 관련 작업 집합
	- data + operation (no implementaion)
		= class without function implementation
		
	컴퓨터사이언스에서 추상화라는 단어는 단순화와 비슷하다고 보면 된다.
	
	ex)
	ADT: Integer
	{
		int x; <- data
		int_plus();
		int_multifly();
		int_minus(); <- operation
		...
	} 따로 어떤 것을 실행을 하는 것이 아니라. 오직 자료와 함수 선언만 되어있음.

	
	C++에서 "Class"는 ADT를 정의하기 위해 사용된다.
```

<br>

### 2. Object

```
외부에서는 오브젝트의 data와 internal operations에 접근할 수 없다.
캡슐화는 메시지를 보내는 객체로부터 클래스의 기능 세부 사항을 숨긴다.
개체의 내부 데이터는 인터페이스를 통해서만 수정할 수 있다.
```

<br>

### 3. Class

```
Class vs Object

비유 예시.
	int			x; 처럼 선언을 예로 들어보자 이 때, 자료형과 변수는 각각
	(class)		(object) 로 비유될 수 있다.
	변수 x는 4바이트 크기의 메모리를 가지고 있다. 이는 object에 비유된다.
	하지만 자료형은 그냥 type일 뿐이다. 이는 class에 비유된다.
	
	하나의 클래스에 여러가지 오브젝트가 가능하다.
```

<br>

### 4. Inheritance (상속)

```
목적 : 코드 재사용
Sub class는 Super class로부터 속성과 동작을 상속받는다.
```

<br>

### 5. Polymorphism (다형성)

```
하나의 이름에 여러가지 의미를 가질 수 있다.
```

<br>

### 6. Dynamic binding

 

