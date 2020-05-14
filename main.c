//random 함수를 통해 랜덤으로 함수들 중 한 함수를 가져와서 실행시키고 그 값을 리턴시킴으로써 정답과 오답을 판별, 결과를 출력하는 코드입니다.

#include <stdio.h>

//랜덤 함수를 쓰기 위해 아래의 두 라이브러리를 가져옵니다.
#include <stdlib.h>
#include <time.h>

//매크로를 사용합니다.
#define Three 3

//함수정의
int quiz_select(int select);//문제번호를 매개변수로 받아 퀴즈 골라서 결과값 반환하는 함수
int quiz1();//퀴즈함수 
int quiz2();
int quiz3();


//main 함수
int main(void) {
    //변수 선언
    int result[Three];//결과값 저장 변수
    int correct =0;//정답개수 저장 변수
    int wrong =0;//오답개수 저장 변수
    int select[Three];//문제 고르기 변수
    printf("OX퀴즈입니다.\n");

    //시간을 기준으로 난수 초기화
    srand(time(0));
        
    //문제 반복 제거
    for(int k =0;k<Three;k++){
        
        select[k]=rand()%Three;

        for(int j =0;j<k;j++){
            if(select[j]==select[k]){
                k--;
                break;
            }
        }            
    }

    //반복문 세 번 적용    
    for(int i=0;i<Three;i++){
        //quiz_select함수 호출해 그 반환값을 i번째 result에 저장
        printf("%d번째 문제입니다.",i+1);
        result[i] = quiz_select(select[i]);
        
        //만약 반환값이 1일 경우
        if(result[i]==1){
            //정답 변수에 1을 더함
            correct++;
        }

        //만약 반환값이 2일 경우
        else if(result[i]==2){
            //오답 변수에 1을 더함
            wrong++;
        }

    }

    //결과 값 출력
    printf("총 %d개 맞췄고 %d개 틀렸습니다.\n",correct,wrong);

    for(int i = 0;i<Three;i++){
        if(result[i]==1){
            printf("%d번 문제는 맞았습니다.\n",i+1);
        }
        else{
            printf("%d번 문제는 틀렸습니다.\n",i+1);
        }
    }

    //조건문을 통해 등급 출력
    if(correct>2){
        printf("등급 A");
    }
    else if(correct>1){
        printf("등급 B");
    }
    else if(correct>0){
        printf("등급 C");
    }
    else{
        printf("등급 F");
    }
    
    return 0;
}

//퀴즈 고르기 함수
int quiz_select(int select){

    //변수 선언
    int result = 0;//결과 변수    

    //main함수에서 입력받은 값과 일치하는 문제함수로 이동, 그 결과값을 result 변수에 저장
    switch(select){
        case 0:
            result = quiz1();
            break;
        case 1:
            result = quiz2();
            break;
        case 2:
            result = quiz3();
            break;
    }

    //결과값 반환
    return result;
}

int quiz1(){
    //변수 선언
    char answer = 0;
    printf("아이유는 걸그룹 소속이다. 맞으면 o 틀리면 x :");
    scanf("%c",&answer);
    //버퍼 비우기: scanf 함수는 입력받을 때 버퍼를 이용합니다. 그러나 입력받을 때 키보드버퍼의 한 종류인 엔터도 포함이 되므로 다음 scanf 함수가 실행이 될 때 뒤에 입력할 값을 추가로 받는 게 아니라 기존에 입력되었던 엔터가 그 scanf 자리로 들어가게 됩니다. 그래서 getchar이라는 함수를 이용하여 그 자리에 엔터키 키보드 버퍼를 소모합니다.
    getchar();
    if(answer=='x'){
        return 1;
    }
    else{
        return 2;
    }
}

int quiz2(){
    //변수선언
    char answer = 0;
    printf("트와이스는 걸그룹이다. 맞으면 o 틀리면 x :");
    scanf("%c",&answer);
    getchar();

    if(answer=='o'){
        return 1;
    }
    else{
        return 2;
    }
}

int quiz3(){
    char answer = 0;
    printf("시진핑은 중국주석이다. 맞으면 o 틀리면 x :");
    scanf("%c",&answer);
    getchar();
    if(answer=='o'){
        return 1;
    }
    else{
        return 2;
    }
}