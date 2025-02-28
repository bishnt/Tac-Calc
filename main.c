#include<stdio.h>
#include"hero.h"
#include"circuit.h"

#include"login.h"

void line(){
    printf("\n\t  ___________________________________________________________________________\t\n\n");
}

void color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
    //home_page
    hero();

    line();

    //login_page
    color(3);
    printf("\n\t\t\t\t ---------LOGIN---------- \n");
    color(6);
    login();
    color(7);
    line();


    printf("\n\t\tPress Any Key to Continue.. \n");

    return 0;
    

}

