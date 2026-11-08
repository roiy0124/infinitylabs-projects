//WS: Functions (C++)
//Name: Roie Itzhakov
//Reviewer: Ariel Vaknin
//Date: 09/08/2026

#include <stdlib.h> //for using system func
#include <stdio.h> // for using printf and getchar funcs
#include "functions.hpp"

namespace ilrd
{

static void printA()    { printf("A-pressed\n"); }
static void printT()    { printf("T-pressed\n"); }
static void doNothing() {}


void HandleSwitch()
{
    system("stty -icanon -echo");
    
    int key;
    
    while((key = getchar()) != 27)
    {
        switch(key)
        {
        case 'A':
        {
            printf("A-pressed\n");
            break;
        }
        case 'T':
        {
            printf("T-pressed\n");
            break;
        }
    }
    }
    system("stty icanon echo");
}

void HandleIfElse()
{
    system("stty -icanon -echo");
    
    int key;
    
    while((key = getchar()) != 27)
    {
        if(key == 'A')
        {
            printf("A-pressed\n");
        }
        else if(key == 'T')
        {
            printf("T-pressed\n");
        }
    }
    system("stty icanon echo");
}

void HandleLUT()
{    
    system("stty -icanon -echo");

    typedef void (*funcPtr)();

    int key, i;
    funcPtr arr[256];
        
    for(i=0;i<256;i++)
    {
        arr[i] = doNothing;
    }
    
    arr[65] = printA;
    arr[84] = printT;
    while((key = getchar()) != 27)
    { 
        arr[static_cast<unsigned char>(key)]();
    }

    system("stty icanon echo");
}
}
