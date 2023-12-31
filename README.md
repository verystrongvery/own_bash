# 프로젝트 요약
1. 나만의 Bash Shell 구현
2. fork, execve, waitpid, signal, pipe, dup2 등의 System Call 활용

# 기술스택
- C
- Makefile
- Linux

# 프로젝트 구현 내용
### 1. Bash의 Built In 명령어 구현
1. 터미널에 ls 입력
2. main 함수의 인자값으로 들어오는 환경변수들의 복잡한 파싱과정을 거쳐, ls 실행파일의 경로 조회
3. fork() 함수를 호출하여 자식프로세스 생성
4. 자식프로세스는 execve() 함수를 호출하여 ls 실행파일을 실행한 뒤 종료됨
5. 부모프로세스는 waitpid() 함수를 호출하여 자식프로세스가 종료될때까지 기다림
6. 터미널에 ls 결과가 출력됨

### 2. ctrl+c 구현
1. signal() 함수를 호출하여 ctrl+c가 하는 기존의 행동 대신, 내가 정의한 행동을 하게 만듬
    - 기존의 행동 : 나만의 Bash Shell을 종료시킴
    - 내가 정의한 행동 : 터미널에 "bash$" 라는 문자열을 출력시킴
2. ctrl+c 입력
3. 나만의 Bash Shell을 종료시키는 행동 대신, 터미널에 "bash$" 라는 문자열을 출력시킴

### 3. 파이프 ( | ) 구현
1. ls | grep e 입력
2. fork() 함수를 호출하여 자식프로세스 생성
3. 자식프로세스
    - pipe() 함수를 호출하여, 두 파일 디스크립터 a와 b가 서로 이어지게 만듬 
    - fork() 함수를 호출하여 자식 프로세스 생성
4. 자식프로세스의 자식프로세스
    - dup2() 함수를 호출하여 파일디스크립터 a에 STDOUT의 파일디스크립터를 복사
    - execve() 함수를 호출하여 ls 실행파일을 실행한 뒤 종료됨
    - ls 실행파일의 결과가 STDOUT 대신 파일 디스크립터 a로 출력됨
5. 자식프로세스 
    - waitpid() 함수를 호출하여 자식프로세스의 자식프로세스가 종료될때까지 기다림
    - dup2() 함수를 호출하여 파일디스크립터 b에 STDIN의 파일디스크립터를 복사
    - 파일디스크립터 b는 a와 이어져 있기 때문에, 자식프로세스의 자식프로세스에서 실행한 ls의 결과가 grep e의 입력값으로 넘어옴
    - execve() 함수를 호출하여 grep 실행파일을 실행한 뒤 종료됨
6. 부모프로세스는 waitpid() 함수를 호출하여 자식프로세스가 종료될때까지 기다림
7. 터미널에 ls | grep e 결과가 출력됨

### 4. 리다이렉션  >, >> 구현
1. ls > test.txt 입력
2. text.txt 파일을 open() 함수를 이용하여 기존의 파일 내용을 삭제하는 옵션으로 파일 열기(>> 일 경우, 덮어쓰기 옵션으로 파일 열기)
3. fork() 함수를 호출하여 자식프로세스 생성
4. 자식프로세스는 execve() 함수를 호출하여 ls 실행파일을 실행한 뒤 종료됨
5. 부모프로세스는 waitpid() 함수를 호출하여 자식프로세스가 종료될때까지 기다림
6. test.txt에 ls 의 결과가 저장됨

### 5. 리다이렉션 < 구현
1. cat < test.txt 입력
2. text.txt 파일을 open() 함수를 이용하여 읽기 전용 옵션으로 파일 열기
3. fork() 함수를 호출하여 자식프로세스 생성
4. 자식프로세스는 execve() 함수를 호출하여 cat 실행파일을 실행한 뒤 종료됨
5. 부모프로세스는 waitpid() 함수를 호출하여 자식프로세스가 종료될때까지 기다림
6. test.txt의 내용이 터미널로 출력됨
