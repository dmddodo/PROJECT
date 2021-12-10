#pragma once
#ifndef Main_h
#define Main_h

#include<iostream>
#include<string>

#include <windows.h>
#include "Define.h"
#include "cursor.h"
#include <conio.h> //콘솔 입출력 함수

using namespace std;

//커서
void CursorView(char show);

//메인 메뉴 클래스
class MainMenu {
public:
    MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";

        cout << "\t\t"; cout << "                   TetrisGame1.5 By SeokJinLee\n";

        getchar(); // 아무키 입력 기다림
        system("cls"); // 콘솔 창 clear
    }
};

#endif

