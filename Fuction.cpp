#include "Define.h"
#include "Main.h"
#include "cursor.h"

#include<iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand �Լ�
#include <ctime> // time �Լ�
#include <time.h> // Ÿ�̸�
#include <algorithm> // copy �Լ�

#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

using namespace std;

int x = 8, y = 0;
clock_t startDropT, endT, startGroundT;
int blockForm;
int blockRotation = 0;
int key;
int score;



//��� ���
int blocks[7][4][4][4] = {
    { // T��� ��
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
    {    // ���� ��
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
    {   // ���� �� �ݴ�
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
    {   // 1���� ��
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
    {   // L���� ��
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
    {   // L���� �� �ݴ�
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
    {   // �� ��
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


//���� ȭ��
int map[19 + 1][12 + 2] = {   //����, ����
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

//���� �� ����, ���� ���� �׸�
void DrawMap() {
    gotoxy(0, 0);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 14; j++) {
            if (map[i][j] == 1) {
                gotoxy(j * 2, i);
                printf("��");
            }
            else if (map[i][j] == 2) {
                gotoxy(j * 2, i);
                printf("��");
            }
        }
    }
}

//��� �������� ����߸���
void CreateRandomForm() {
    blockForm = rand() % 7;
}


//�浹 ����
bool CheckCrash(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[blockForm][blockRotation][i][j] == 1) {
                int t = map[i + y][j + x / 2];
                if (t == 1 || t == 2) { // �� or ���� ��
                    return true;
                }
            }
        }
    }
    return false;
}

//���� �� ĭ�� ������ ����
void DropBlock() {
    endT = clock();
    if ((float)(endT - startDropT) >= 800) { //0.8��
        if (CheckCrash(x, y + 1) == true) return;
        y++;
        startDropT = clock();
        startGroundT = clock();
        system("cls");
    }
}

//���� ���� ���� �� �ƹ� ������ ������ ������ ����
void BlockToGround() {
    if (CheckCrash(x, y + 1) == true) {
        if ((float)(endT - startGroundT) > 1500) { //1.5��
            // ���� ��� ����
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (blocks[blockForm][blockRotation][i][j] == 1) {
                        map[i + y][j + x / 2] = 2;
                    }
                }
            }
            x = 8;
            y = 0;
            CreateRandomForm(); //������ �� ����� ���� �ø�
        }
    }
}


//����� �� ���� �Ǹ� ����
void RemoveLine() {
    for (int i = 19; i >= 0; i--) { // ������ ������ ��
        int cnt = 0;
        for (int j = 1; j < 13; j++) { // 
            if (map[i][j] == 2) {
                cnt++;
            }
        }
        if (cnt >= 12) { // ������ �� ���ִٸ�
            for (int j = 0; i - j >= 0; j++) {
                for (int x = 1; x < 13; x++) {
                    if (i - j - 1 >= 0)
                        map[i - j][x] = map[i - j - 1][x];
                    else      // õ���̸� 0����
                        map[i - j][x] = 0;
                }
            }
        }
    }
}

// ������ �׸���
void DrawBlock() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (blocks[blockForm][blockRotation][i][j] == 1) {
                gotoxy(x + j * 2, y + i);
                printf("��");
            }
        }
    }
}

// ���� �̵�, ����� �ٲ� ���� ������ �ٷ� ���� ���� �� ������ ����
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
    CursorView(false); // �ܼ� ȭ�� Ŀ�� ���� 
    system("mode con cols=100 lines=40 | title ��Ʈ���� ����"); // �ܼ�â ũ�� �� ���� ����
    MainMenu(); // ���� �޴� �׸��� ������ ȣ��
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







