# [C++] 파일 입출력에 대해서

<br>

****

<br>

### file stream class

- **ofstream**: 파일에 쓰기 위한 stream class
- **ifstream**: 파일을 읽기 위한 stream class
- **fstream**: 파일을 읽고 쓰기 위한 stream class

```c++
#include <iostream>
#include <fstream>

using namespace std;

int			main(void)
{
    // 무언가를 쓰기 위해, 우리는 파일 스트림 오브젝트를 만들어야 한다.
    // 1. 파일 스트림 오브젝트 변수를 만들어야 한다.
    // 2. 파일을 열어야한다.
    // 3. 파일을 쓴다.
    // 4. 파일 스트림을 닫는다.
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << "writing this to a file.\n";
    myfile close();
    return (0);
}
```

<br>

**file 열때 고려해야 할 것들**<br>

​	모드 결정 -- 텍스트? 혹은 바이너리(그림, 음악, 실행파일 등등...)?   

​	쓰거나, 추가하거나 혹은 잘라내거나?   

​	파일 위치 (자동? 혹은 유저 지정?)   

<br>

<참고> **text file** vs **binary file**
   
129라는 숫자를 저장하고 싶다고 생각해보자.   
   
2가지 방법이 있다.   
   
1. text로 저장하는 방법 <- 3byte가 필요하다. '1','2','9'라는 ascii로 각각 저장한다.   
2. binary로 저장하는 방법 <- 10000001 이 저장된다.   
<br>
<br>

### 파일 프로세싱 모드

다음은 파일을 프로세싱 할 때 사용하는 모드이다. 아래의 코드 예시들을 보며 이해하면 쉬울 것이다.

| 모드        | 설명                                                         |
| ----------- | ------------------------------------------------------------ |
| ios::in     | Open for Input operation                                     |
| ios::out    | Open for output operation                                    |
| ios::binary | Open in binary mode                                          |
| ios::ate    | Set the initial position at the end of the file.<br />If this flag is not set, the initial position is the beginning of the file |
| ios::app    | All output operations are perfomed at the end of the file, appending the content to the current content of the file. |
| ios::trunc  | If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one. |

<br>

##### Default mode

| class    | default mode parameter |
| -------- | ---------------------- |
| ofstream | ios::out               |
| ifstream | ios::in                |
| fstream  | ios::in , ios::out     |

<br>

##### Check if file open was OK

```c++
if (myfile.is_open())
{
	// ok, preceed with output
}
```

<br>

##### Closing a file

```c++
myfile.close();
```

<br>

```c++
#include <iostream>
#include <fstream>

using namespace std;

int			main(void)
{
    ofstream myfile("example.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else
        cout << "Unable to open file" << endl;
    return (0);
}
```

<br>

<br>

### Get and Put Stream Positioning (file pointer 컨트롤)

<br>

파일을 읽을 때, 어디부터 읽을건지, 어디를 읽고 있는지 커서를 이동하는 개념이라고 생각하면 된다.

<br>

- tellg() / tellp() <br>

  Return current get/put position.

- seekg() / seekp()<br>
  Change the location of the get / put position.

<br>

```c++
seekg(position);
seekp(position);
seekg(offset, direction);
seekg(offset, direction);
```

```c++
#include <iostream>
#include <fstream>

using namespace std;

int			main(void)
{
    streampos begin, end; // int
    ifstream myfile("example.bin", ios::binary);
    begin = myfile.tellg(); // 0
    myfile.seekg(0, ios::end); // move position to the end
    end = myfile.tellg(); // 40
    myfile.close();
    cout << "size is: " << (end-begine) /*40*/ << " bytes." << endl;
    return (0);
}
```

```
실행결과
size is: 40 bytes.
```

<br>

<br>

### Binary 파일 프로세싱

<br>

```c++
write (memory_block, size);

read (memory_block, size);
```

<br>

```c++
// reading an entire binary file
#include <iostream>
#include <fstream>
using namespace std;

int			main(void)
{
    streampos	size;
    char		*memblock;
    
	ifstream file("example.bin", ios::in|ios::binary|ios::ate);
    // 파일 열기, 마지막 옵션 (ios::ate) 때문에 Position이 맨 끝에 있게 된다.
    if (file.is_open())
    {
        size = file.tellg(); // size는 파일 전체 크기만큼 할당된다.
        memblock = new char[size]; // memblock에 size만큼 할당.
        file.seekg (0, ios::beg); // position을 begin으로 옮긴다.
        file.read (memblock, size); // 파일을 memblock으로 읽기
        file.close();
        
        cout << "the entire file content is in memory" << endl;
        delete[] memblock;
    }
    else
        cout << "Unable to open file" << endl;
    return (0);
}
```



