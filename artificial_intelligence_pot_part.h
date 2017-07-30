#ifndef _ARTIFICIAL_INTELLIGENCE_POT_PART_H_
#define _ARTIFICIAL_INTELLIGENCE_POT_PART_H_


class Artificial_Intelligence_Pot_part
{
private:
    int TOP;
    int Pot_point;
    int card[4];
public:
    /*Artificial_Intelligence_Pot_part(): TOP(0) //constructor
    {   constructor();     }*/
    int lead_card;
    void constructor(void);
    void Pot_point_calculation(int a);
    int get_pot_point(void)    {    return Pot_point;   }
    int which_type_card(int a);
    void push_card(int a);
    int get_card(int i)     {   return card[i];   }
    int get_top(void)   {   return TOP;     }
};

#endif
