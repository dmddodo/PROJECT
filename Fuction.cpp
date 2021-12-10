#include "Define.h"
#include "Main.h"
#include "cursor.h"

#include<iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand 함수
#include <ctime> // time 함수
#include <time.h> // 타이머
#include <algorithm> // copy 함수

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

int x = 8, y = 0;
clock_t startDropT, endT, startGroundT;
int blockForm;
int blockRotation = 0;
int key;
int score;



//블록 모양
int blocks[7][4][4][4] = {
    { // T모양 블럭
        {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,1,0},
            {0,0,0,0}
        },
 {
            {0,0,0,0},
            {0,1,0,0},
            {0,1,1,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {0,1,0,0}
        }
    },
    {    // 번개 블럭
        {
            {0,0,0,0},
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0}
        }
    },
    {   // 번개 블럭 반대
        {
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0}
        },
        {
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0}
        }
    },
    {   // 1자형 블럭
        {
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,1,0,0}
        },
        {
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}
        }
    },
    {   // L자형 블럭
        {
            {0,0,0,0},
            {1,0,0,0},
            {1,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {1,0,0,0}
        },
        {
            {0,0,0,0},
            {1,1,1,0},
            {0,0,1,0},
            {0,0,0,0}
        },
        {
            {0,1,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {0,0,0,0}
        }
    },
    {   // L자형 블럭 반대
        {
            {0,0,0,0},
            {0,0,1,0},
            {1,1,1,0},
            {0,0,0,0}
        },
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,1,1,0},
            {1,0,0,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,1,0,0}
        }
    },
    {   // ㅁ 블럭
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        },
        {
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}
        }
    }
};


//게임 화면
int map[19 + 1][12 + 2] = {   //세로, 가로
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

//게임 맵 형태, 쌓인 블럭을 그림
void DrawMap() {
    gotoxy(0, 0);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (map[i][j] == 1) {
                gotoxy(j * 2, i);
                printf("□");
            }
            else if (map[i][j] == 2) {
                gotoxy(j * 2, i);
                printf("■");
            }
        }
    }
}

//블록 랜덤으로 떨어뜨리기
void CreateRandomForm() {
    blockForm = rand() % 7;
}


//충돌 감지
bool CheckCrash(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[blockForm][blockRotation][i][j] == 1) {
                int t = map[i + y][j + x / 2];
                if (t == 1 || t == 2) { // 벽 or 블럭일 때
                    return true;
                }
            }
        }
    }
    return false;
}

//블럭을 한 칸씩 밑으로 내림
void DropBlock() {
    endT = clock();
    if ((float)(endT - startDropT) >= 800) { //0.8초
        if (CheckCrash(x, y + 1) == true) return;
        y++;
        startDropT = clock();
        startGroundT = clock();
        system("cls");
    }
}

//블럭이 땅에 닿을 때 아무 동작이 없으면 땅으로 변함
void BlockToGround() {
    if (CheckCrash(x, y + 1) == true) {
        if ((float)(endT - startGroundT) > 1500) { //1.5초
            // 현재 블록 저장
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (blocks[blockForm][blockRotation][i][j] == 1) {
                        map[i + y][j + x / 2] = 2;
                    }
                }
            }
            x = 8;
            y = 0;
            CreateRandomForm(); //랜덤한 블럭 만들고 위로 올림
        }
    }
}


//블록이 한 줄이 되면 제거
void RemoveLine() {
    for (int i = 19; i >= 0; i--) { // 벽라인 제외한 값
        int cnt = 0;
        for (int j = 1; j < 13; j++) { // 
            if (map[i][j] == 2) {
                cnt++;
            }
        }
        if (cnt >= 12) { // 벽돌이 다 차있다면
            for (int j = 0; i - j >= 0; j++) {
                for (int x = 1; x < 13; x++) {
                    if (i - j - 1 >= 0)
                        map[i - j][x] = map[i - j - 1][x];
                    else      // 천장이면 0저장
                        map[i - j][x] = 0;
                }
            }
        }
    }
}

// 현재블록 그리기
void DrawBlock() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[blockForm][blockRotation][i][j] == 1) {
                gotoxy(x + j * 2, y + i);
                printf("■");
            }
        }
    }
}

// 블럭이 이동, 모양이 바꿔 땅에 닿으면 바로 다음 블럭이 안 나오게 해줌
void InputKey() {
    if (_kbhit()) {
        key = _getch();
        switch (key) {
        case KEY_SPACE:
            blockRotation++;
            if (blockRotation >= 4) blockRotation = 0;
            startGroundT = clock();
            break;
        case KEY_LEFT:
            if (CheckCrash(x - 2, y) == false) {
                x -= 2;
                startGroundT = clock();
            }
            break;
        case KEY_RIGHT:
            if (CheckCrash(x + 2, y) == false) {
                x += 2;
                startGroundT = clock();
            }
            break;
        case KEY_DOWN: // down
            if (CheckCrash(x, y + 1) == false)
                y++;
            break;
        }
        system("cls");
    }
}



int main(void) {
    CursorView(false); // 콘솔 화면 커서 제거 
    system("mode con cols=100 lines=40 | title 테트리스 게임"); // 콘솔창 크기 및 제목 설정
    MainMenu(); // 메인 메뉴 그리기 생성자 호출
    PlaySound(TEXT("music.wav"), 0, SND_ASYNC | SND_LOOP);
    _getch();


    while (getchar) {
        DrawMap();
        DrawBlock();
        DropBlock();
        BlockToGround();
        RemoveLine();
        InputKey();

    }

    return 0;
};







