#include"artificial_intelligence_pot_part.h"

///////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Pot_part::constructor()
{
    TOP=0;
    Pot_point=0;
    for(int i=0; i<4; i++)
        card[i]=-1;
}

//////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Pot_part::which_type_card(int a)
{
    if(a<8)
    {
        return 0;
    }
    else if(a>7 && a<16)
    {
        return 1;
    }
    else if(a>15  && a<24)
    {
        return 2;
    }
    else if(a>23 && a<32)
    {
        return 3;
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Pot_part::push_card(int a)
{
    if(TOP==0)
    {
        lead_card=a;
    }
    Pot_point_calculation(a);
    card[TOP]=a;
    TOP++;
}

////////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Pot_part::Pot_point_calculation(int a)
{
    int type;
    type=which_type_card(a);
    if(a==type*8)
    {
        Pot_point+=3;
    }
    else if(a==type*8+1)
    {
        Pot_point+=2;
    }
    else if(a==type*8+2)
    {
        Pot_point+=1;
    }
    else if(a==type*8+3)
    {
        Pot_point+=1;
    }
}
