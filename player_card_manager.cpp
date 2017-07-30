#include<cstring>
#include<ctime>
#include<cstdlib>
#include "card_deck.cpp"
#include "Total_menu_view_controller.cpp"
//using namespace std;


class player_card_manager
{
private:
    int P_card[9];
    int TOP;
protected:
    int c_type[4];
public:
    player_card_manager(): TOP(0) //constructor
    {   constructor();     }
    void constructor()
    {
        for(int i=0; i<4; i++)
            c_type[i]=0;
        P_card[8]=0;
    }
    int which_type_card(int a);
    int get_card_type(int i)
    {
        return c_type[i];
    }
    void push_card(int i, int a)
    {
        TOP++;
        c_type[which_type_card(a)]++;
        P_card[i]=a;
    }
    int get_card(int i)
    {
        return (P_card[i]);
    }
    int pop_card( int i)
    {
        TOP--;
        c_type[which_type_card(P_card[i])]--;
        return (P_card[i]);
    }
    int get_top()
    {
        return (TOP);
    }
    int play_card(int c)
    {
        int return_value=P_card[c];
        c_type[which_type_card(P_card[c])]--;
        for(int i=c; i<get_top(); i++)
        {
            P_card[i]=P_card[i+1];
        }
        TOP--;
        return (return_value);
    }
};


///////////////////////////////////////////////////////////////////////////


int player_card_manager::which_type_card(int a)
{
    if(a>=0 && a<8)
    {
        return 0;
    }
    else if(a>=8 && a<16)
    {
        return 1;
    }
    else if(a>=16  && a<24)
    {
        return 2;
    }
    else if(a>=24 && a<32)
    {
        return 3;
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
