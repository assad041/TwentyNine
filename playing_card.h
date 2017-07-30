#ifndef _PLAYING_CARD_H_
#define _PLAYING_CARD_H_

#include<string.h>
#include<iostream>
#include"asdgraphics.h"
using namespace std;

class playing_card
{
    private:
        char c[4];
    public:
        void put_char(int i,char ch)
        {
            c[i]=ch;
        }
        string get_card()
        {
            return (c);
        }
};


#endif
