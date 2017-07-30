#ifndef _GAMES_TABLE_VIEW_MANAGEMENT_H_
#define _GAMES_TABLE_VIEW_MANAGEMENT_H_

#include<iostream>
#include"asdgraphics.h"
using namespace std;

class games_table_view_management
{
private:
    char border[5];
    int count1;
public:
    void constuctor(void);
    games_table_view_management(): count1(0)
    {      constuctor();   }
    int games_first_view();
    int view_common_menu();
    int main_menu();
    void clear_free_space();
};


#endif
