#include <iostream>//1
#include <conio.h>//2
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <iomanip>
#include <string>
#include <stdio.h>

using namespace std;
//enum eDirection {STOP = 0,LEFT,RIGHT,DOWN,UP};
//eDirection dir;
unsigned char field1 [10][10];
unsigned char field2 [10][10];

unsigned char monitor1[10][10];
unsigned char monitor2[10][10];

int cur_menu_pos;
int Proverka = 0;

class ship
{
public:
    int x;
    int y;
};
class shoot
{
public:
    int x;
    int y;
};
ship  ship[2];
shoot shoots[2];

void Draw(int playernum)//для мапы
{
    if (playernum==1)
    {
        system("color 03");
        system("cls");
        cout << "playfield1               monitor1" << endl;
        cout<<"=======================  ======================"<<endl;
        for (int i=0;i<10;i++)
        {
            cout<<"| ";
            for (int j=0;j<10;j++)
            {
                cout<<field1[i][j]<<" ";
            }
            cout<<"|  |";
            for (int h=0;h<10;h++)
            {
                cout<<monitor1[i][h]<<" ";
            }
            cout<<"|";
            cout<<endl;
        }
        cout<<"=======================  ======================"<<endl;
    }
    else if(playernum==2)
    {
        system("color 04");
        system("cls");
        cout << "playfield2               monitor2" << endl;
        cout<<"=======================  ======================"<<endl;
        for (int i=0;i<10;i++)
        {
            cout<<"| ";
            for (int j=0;j<10;j++)
            {
                cout<<field2[i][j]<<" ";
            }
            cout<<"|  |";
            for (int h=0;h<10;h++)
            {
                cout<<monitor2[i][h]<<" ";
            }
            cout<<"|";
            cout<<endl;
        }
        cout<<"=======================  ======================"<<endl;
    }
}

void form_ship (int plr_num)
{
    if(plr_num==1)
    {
        field1[ship[plr_num].y][ship[plr_num].x]=254;
    }
    else if(plr_num==2)
    {
        field2[ship[plr_num].y][ship[plr_num].x]=254;
    }
}

void ster (int playernum)
{
        if(playernum==1)
    {
        field1[ship[playernum].y][ship[playernum].x]=' ';
    }
    else if(playernum==2)
    {
        field2[ship[playernum].y][ship[playernum].x]=' ';
    }
}

void Input(int plr_num,int X,int Y)//нажатия пользователя
{
    ship[plr_num].x=X;
    ship[plr_num].y=Y;
    form_ship(plr_num);
    Draw(plr_num);
        while (true)
        {
        if(_kbhit())
            switch(_getch())
            {
                case 'w':
                    if(ship[plr_num].y>0)
                        {
                            ster(plr_num);
                            ship[plr_num].y--;
                            form_ship(plr_num);
                            Draw(plr_num);
                        }
                    break;

                case 's':
                    if(ship[plr_num].y<9)
                        {
                            ster(plr_num);
                            ship[plr_num].y++;
                            form_ship(plr_num);
                            Draw(plr_num);
                        }
                    break;
                case 'a':
                    if(ship[plr_num].x>0)
                        {
                            ster(plr_num);
                            ship[plr_num].x--;
                            form_ship(plr_num);
                            Draw(plr_num);
                        }
                    break;
                case 'd':
                    if(ship[plr_num].x<9)
                        {
                            ster(plr_num);
                            ship[plr_num].x++;
                            form_ship(plr_num);
                            Draw(plr_num);
                        }
                    break;
                case 13:   //enter
                    return ;
                    break;
            }
        }
}

void Shoots (int plr_num,int X,int Y)
{
    while (true)
    {
        cout<<"Enter target coordinates:"<<endl;
        cin>> X ;
        cin>> Y ;

        shoots[plr_num].y=Y;
        shoots[plr_num].x=X;

        if(plr_num==1)
        {
            field2[shoots[plr_num].y][shoots[plr_num].x]='X';
        }
        else if(plr_num==2)
        {
            field1  [shoots[plr_num].y][shoots[plr_num].x]='X';
        }

    }

}


void Menu (){
    while (true){
        system ("cls");
        cout << "\n";
        cout << "                             Welcome to SeaBattle " << endl;//8
        cout << "\n";
        if ( cur_menu_pos == 1 )
        {
            cout << "                       player vs player" << endl;//6
        }
        else
        {
            cout << "                        ->player vs player<-" << endl;//6
        }
        if ( cur_menu_pos == 2 )
        {
            cout << "                       player vs bot" << endl;
        }
        else
        {
            cout << "                        ->player vs bot<-" << endl;
        }


        while (true)
            if ( kbhit())
            {
                switch (getch())
                {
                    case 72: //up
                        if (cur_menu_pos>1)
                        {
                            cur_menu_pos--;
                            Menu();
                        }
                        break;
                    case 80: //down
                        if (cur_menu_pos<3)
                        {
                            cur_menu_pos++;
                            Menu();
                        }
                        break;
                    case 13:
                        switch (cur_menu_pos)
                        {
                            case 1:
                                Draw(1);
                                Input(1, 5, 5);
                                Input(2, 5, 5);
                                Shoots(1, 2, 3);
                                break;


                            case 2:
                                Draw(1);
                                Input(1, 5, 5);
                                Shoots(1, 2, 3);
                                break;


                            case 3:

                                system ("cls");
                                exit(0);
                                break;
                        }
                }
            }
    }
}
int POBEDA ()
{
    Proverka=0;
    for(int i=0; i<12; i++)
        {
        for(int j=0; j<12; j++)
        {
            if (field1[j][i]=='X')
            {
                Proverka++;
            }
        }
    }
    if (Proverka==20){
        system ("cls");
        system ("color 04");
        cout << "\n\n\n\n";
        cout << "===========================================================";
        cout << "                          Player 2 won" << endl;
        cout << "            Press any button to return to the menu" << endl;
        cout << "                          (Not Enter)" << endl;
        cout << "===========================================================";
        while (true){
            if ( kbhit()){
                switch (getch()){
                    case 13:
                        break;
                    default:
                        Menu();
                }
            }
        }
    }
    Proverka=0;
    for ( int i = 0 ; i < 12 ; i++ ){
        for(int j=0 ; j<12 ; j++ ){
            if ( field2[j][i] == 'X'){
                Proverka++;
            }
        }
    }
    if (Proverka==20){
        system ("cls");
        system ("color 03");
        cout << "\n\n\n\n";
        cout << "===========================================================";
        cout << "                          Player 1 won" << endl;
        cout << "            Press any button to return to the menu" << endl;
        cout << "                          (Not Enter)" << endl;
        cout << "===========================================================";
        while (true){
            if ( kbhit()){
                switch (getch()){
                    case 13:
                        break;
                    default:
                        Menu();
                }
            }
        }
    }
}
int main()
{
    //setlocale(LC_ALL, "Russian");
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            field1[i][j]=' ';
            monitor1[i][j]=' ';
            field2[i][j]=' ';
            monitor2[i][j]=' ';
        }
    }
        Menu();

        Draw(1);
        Input(1,2,2);//корабль 1
        Input(2,2,2);//корабль 2
        Shoots(1,2,3);
        POBEDA();

}
