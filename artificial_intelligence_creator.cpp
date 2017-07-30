#include"artificial_intelligence_creator.h"


///////////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::constructor()
{
    E_W_POINT=0;
    N_S_POINT=0;
    Constructor();
}

////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::ask_about_Error(void)
{
    asdgraphics::setColor(11);
    char ch[5];
    ch[0]=223;
    ch[1]=222;
    ch[2]=221;
    ch[3]=220;
    ch[4]=219;
    x=54;
    y=15;
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[1];
    }
    for(int i=1; i<33; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[0];
        asdgraphics::locate(x+i,y+11);
        cout<<ch[3];
    }
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x+33,y+i);
        cout<<ch[2];
    }
    asdgraphics::locate(57,18);
    cout<<" This  Lead  Will  Terminate";
    asdgraphics::locate(57,19);
    cout<<" With an Error. Error May Be";
    asdgraphics::locate(57,20);
    cout<<" Occur Because of One Player";
    asdgraphics::locate(57,21);
    cout<<" Have four Jack or Any Other";
    asdgraphics::locate(57,22);
    cout<<" Internal Problem. Hit Enter";
    asdgraphics::locate(57,23);
    cout<<" For Continue With New Deal.";
    asdgraphics::locate(58,25);
    cout<<"         [ENTER]";

    while(1)
    {
        char c;
        c=asdgraphics::getkey();
        if(c==1)
        {
            for(int i=0; i<13; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                     ";
            }
            return  0;
        }
        else
            cout<<'\a';
    }
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::Searching_Error(void)
{
    int D_error=0;
    if(Pot.get_top()<0 || Pot.get_top()>4)
        D_error=1;
    else if(Max_card_player<0 || Max_card_player>3)
        D_error=1;
    else if(Pot.get_pot_point()<0 || Pot.get_pot_point()>10)
        D_error=1;
    else if(N_S_POINT<0 || N_S_POINT>28 || E_W_POINT<0 || E_W_POINT>28)
        D_error=1;
    else if(Max_card<0 || Max_card>31)
        D_error=1;
    else if(Pot.lead_card<0 || Pot.lead_card>31)
        D_error=1;
    if(D_error==1)
    {
        clear_pot_and_pot_table();
        ask_about_Error();
    }
    return D_error;
}

///////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::searching_jack_error(void)
{
    for(int pr=0; pr<4; pr++)
    {
        int D_error=0;
        for(int card=0; card<player[pr].get_top(); card++)
        {
            if(player[pr].get_card(card)==0 || player[pr].get_card(card)==8 || player[pr].get_card(card)==16 || player[pr].get_card(card)==24)
                D_error++;
        }
        if(D_error==4)
        {
            clear_pot_and_pot_table();
            ask_about_Error();
            return 1;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::Max_card_calculation(int a, int pr)
{
    if(Pot.which_type_card(Pot.lead_card)==Pot.which_type_card(a) && Pot.which_type_card(Pot.lead_card)==Pot.which_type_card(Max_card))
    {
        if(a<Max_card)
        {
            Max_card=a;
            Max_card_player=pr;
        }
    }
    else if(Pot.which_type_card(Pot.lead_card)!=Pot.which_type_card(a) && Show_Trump==1 && trump==Pot.which_type_card(a)  )
    {
        if(Pot.which_type_card(Max_card)!=trump)
        {
            Max_card=a;
            Max_card_player=pr;
        }
        else if(Pot.which_type_card(Max_card)==trump && a<Max_card)
        {
            Max_card=a;
            Max_card_player=pr;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::Marriage_calculation(int a, int pr)
{
    if( Pot.which_type_card(a)*8+4==a  && Show_Trump==1 && trump==Pot.which_type_card(a) )
    {
        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(Pot.which_type_card(a)*8+5==player[pr].get_card(i))
            {
                show_half_of_marriage(pr);
                Re_view_Pot_card(pr);
                int ppprrr;
                if(pr==0)
                    ppprrr=2;
                else if(pr==1)
                    ppprrr=3;
                else if(pr==2)
                    ppprrr=0;
                else if(pr==3)
                    ppprrr=1;
                if(bid_player==pr || bid_player==ppprrr)
                {
                    target_bid=target_bid-4;
                    if(target_bid<15)
                    {
                        target_bid=15;
                    }
                }
                else if( bid_player!=pr || bid_player!=ppprrr )
                {
                    target_bid=target_bid+4;
                }
                break;
            }
        }
    }
    else if( Pot.which_type_card(a)*8+5==a  && Show_Trump==1 && trump==Pot.which_type_card(a) )
    {
        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(Pot.which_type_card(a)*8+4==player[pr].get_card(i))
            {
                show_half_of_marriage(pr);
                Re_view_Pot_card(pr);
                int ppprrr;
                if(pr==0)
                    ppprrr=2;
                else if(pr==1)
                    ppprrr=3;
                else if(pr==2)
                    ppprrr=0;
                else if(pr==3)
                    ppprrr=1;
                if(bid_player==pr || bid_player==ppprrr)
                {
                    target_bid=target_bid-4;
                    if(target_bid<15)
                    {
                        target_bid=15;
                    }
                }
                else if( bid_player!=pr || bid_player!=ppprrr )
                {
                    target_bid=target_bid+4;
                }
                break;
            }
        }
    }

}

//////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::put_a_card_on_pot(int a,int pr)
{

    Marriage_calculation(a,pr);
    if(pr==0)
    {
        cardBoy.view_visual_card(a,65,17);
    }
    if(pr==1)
    {
        cardBoy.view_visual_card(a,68,15);
    }
    if(pr==2)
    {
        cardBoy.view_visual_card(a,71,17);
    }
    if(pr==3)
    {
        cardBoy.view_visual_card(a,68,19);
    }
    Beep(130, 100);
    if(Pot.get_top()==0)
    {
        Max_card=a;
        Max_card_player=pr;
    }
    else if(Pot.get_top()!=0)
    {
        Max_card_calculation(a,pr);
    }
    Pot.push_card(a);
    Searching_Error();
    remove_A_Hand_card(pr,a);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::clear_pot_and_pot_table(void)
{
    int x=50;
    int y=14;
    for(int i=y; i<30; i++)
    {
        asdgraphics::locate(x,i);
        cout<<"                                             ";
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::clear_recent_history(void)
{
    int x=3;
    int y=28;
    for(int i=y; i<40; i++)
    {
        asdgraphics::locate(x,i);
        cout<<"                           ";
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////

void Artificial_Intelligence_Creator::Re_view_Pot_card(int pr)
{
    for(int i=0; i<Pot.get_top(); i++)
    {
        if(pr<3)
            pr++;
        else if(pr==3)
            pr=0;
    }

    for(int i=0; i<Pot.get_top(); i++)
    {
        if(pr==0)
        {
            cardBoy.view_visual_card(Pot.get_card(i),65,17);
        }
        if(pr==1)
        {
            cardBoy.view_visual_card(Pot.get_card(i),68,15);
        }
        if(pr==2)
        {
            cardBoy.view_visual_card(Pot.get_card(i),71,17);
        }
        if(pr==3)
        {
            cardBoy.view_visual_card(Pot.get_card(i),68,19);
        }

        if(pr>0)
        {
            pr--;
        }
        else if(pr==0)
        {
            pr=3;
        }
    }

}

///////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::selecting_A_card_for_play(int pr)
{
    int Hand_Max_type_card[4]={Hand_card[pr][0].get_top(),Hand_card[pr][1].get_top(),Hand_card[pr][2].get_top(),Hand_card[pr][3].get_top()};
    int trak[4]={0,1,2,3};
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            if(Hand_Max_type_card[i]<Hand_Max_type_card[j])
            {
                int Swap=Hand_Max_type_card[i];
                int Sw=trak[i];
                Hand_Max_type_card[i]=Hand_Max_type_card[j];
                trak[i]=trak[j];
                Hand_Max_type_card[j]=Swap;
                trak[j]=Sw;
            }
    }

    for(int i=0; i<4; i++)
        Hand_Max_type_card[i]=trak[i];

    if(Show_Trump==0)
    {
        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==0 || player[pr].get_card(i)==8 || player[pr].get_card(i)==16 || player[pr].get_card(i)==24)
            {
                if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2 )
                    return i;
            }

        }

        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==1 || player[pr].get_card(i)==9 || player[pr].get_card(i)==17 || player[pr].get_card(i)==25)
            {
                if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8)
                        return i;
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+2 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+3 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+4 && (i+1)!=player[pr].get_top())
                    {
                        if(player[pr].get_card(i+2)!=player[pr].which_type_card(player[pr].get_card(i))*8+5 && (i+2)<player[pr].get_top())
                            return (i+1);
                    }
                    if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+5 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+6 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+7 && (i+1)!=player[pr].get_top())
                        return (i+1);
                }
            }
        }

        for(int i=player[pr].get_top()-1; i>=0; i--)
        {
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+7)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+6)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+5)
            {
                if(player[pr].get_card(i-1)!=Hand_Max_type_card[0]*8+4 && (i-1)!=-1 )
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+4)
            {
                if(player[pr].get_card(i+1)!=Hand_Max_type_card[0]*8+5 && i+1!=player[pr].get_top())
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+3)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+2)
                return i;
        }

        for(int i=player[pr].get_top()-1; i>=0; i--)
        {
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+7)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+6)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+5)
            {
                if(player[pr].get_card(i-1)!=Hand_Max_type_card[1]*8+4 && (i-1)!=-1 )
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+4)
            {
                if(player[pr].get_card(i+1)!=Hand_Max_type_card[1]*8+5 && i+1!=player[pr].get_top())
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+3)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+2)
                return i;
        }

        for(int i=player[pr].get_top()-1; i>=0; i--)
        {
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+7)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+6)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+5)
            {
                if(player[pr].get_card(i-1)!=Hand_Max_type_card[2]*8+4 && (i-1)!=-1 )
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+4)
            {
                if(player[pr].get_card(i+1)!=Hand_Max_type_card[2]*8+5 && i+1!=player[pr].get_top())
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+3)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+2)
                return i;
        }

        for(int i=player[pr].get_top()-1; i>=0; i--)
        {
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+7)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+6)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+5)
            {
                if(player[pr].get_card(i-1)!=Hand_Max_type_card[3]*8+4 && (i-1)!=-1 )
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+4)
            {
                if(player[pr].get_card(i+1)!=Hand_Max_type_card[3]*8+5 && i+1!=player[pr].get_top())
                    return i;
            }
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+3)
                return i;
            if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+2)
                return i;
        }

        for(int i=player[pr].get_top()-1; i>=0; i++)
        {
            return i;
        }
    }

    if(Show_Trump==1 || bid_player==pr)
    {
        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==0 || player[pr].get_card(i)==8 || player[pr].get_card(i)==16 || player[pr].get_card(i)==24)
            {
                if( player[pr].which_type_card(player[pr].get_card(i))==trump )
                    return i;
            }
        }

        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==1 || player[pr].get_card(i)==9 || player[pr].get_card(i)==17 || player[pr].get_card(i)==25)
            {
                if( player[pr].which_type_card(player[pr].get_card(i))==trump && Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>0)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8)
                        return i;
                }
            }
        }

        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==0 || player[pr].get_card(i)==8 || player[pr].get_card(i)==16 || player[pr].get_card(i)==24)
            {
                if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2 )
                    return i;
            }
        }

        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].get_card(i)==1 || player[pr].get_card(i)==9 || player[pr].get_card(i)==17 || player[pr].get_card(i)==25)
            {
                if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2 && player[pr].which_type_card(player[pr].get_card(i))!=trump)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8)
                        return i;
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+2 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+3 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+4 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+5 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+6 && (i+1)!=player[pr].get_top())
                        return (i+1);
                    else if(player[pr].get_card(i+1)==player[pr].which_type_card(player[pr].get_card(i))*8+7 && (i+1)!=player[pr].get_top())
                        return (i+1);
                }
            }
        }


        if(Hand_card[pr][trump].get_top()>0 )
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==trump*8+2)
                {
                    if(Hand_card[pr][trump].get_card(0)>trump*8+2 && player[pr].which_type_card(player[pr].get_card(i+1))==trump)
                        return i;
                }
                else if(player[pr].get_card(i)==trump*8+3)
                {
                    if(Hand_card[pr][trump].get_card(0)>trump*8+3 && player[pr].which_type_card(player[pr].get_card(i+1))==trump)
                        return i;
                }
            }
        }

        if(Hand_card[pr][trump].get_top()==0)
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                 if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)>player[pr].get_card(i))
                    return i;
            }
        }

        if(Hand_card[pr][trump].get_top()<3)
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==2 || player[pr].get_card(i)==10 || player[pr].get_card(i)==18 || player[pr].get_card(i)==26)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0) > player[pr].get_card(i) && trump!=player[pr].which_type_card(player[pr].get_card(i)))
                        return i;
                }
                if(player[pr].get_card(i)==3 || player[pr].get_card(i)==11 || player[pr].get_card(i)==19 || player[pr].get_card(i)==27)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0) > player[pr].get_card(i) && trump!=player[pr].which_type_card(player[pr].get_card(i)))
                        return i;
                }
                if(player[pr].get_card(i)==4 || player[pr].get_card(i)==12 || player[pr].get_card(i)==20 || player[pr].get_card(i)==28)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0) > player[pr].get_card(i) && trump!=player[pr].which_type_card(player[pr].get_card(i)))
                        return i;
                }
                if(player[pr].get_card(i)==5 || player[pr].get_card(i)==13 || player[pr].get_card(i)==21 || player[pr].get_card(i)==29)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0) > player[pr].get_card(i) && trump!=player[pr].which_type_card(player[pr].get_card(i)))
                        return i;
                }
                if(player[pr].get_card(i)==6 || player[pr].get_card(i)==14 || player[pr].get_card(i)==22 || player[pr].get_card(i)==30)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0) > player[pr].get_card(i) && trump!=player[pr].which_type_card(player[pr].get_card(i)))
                        return i;
                }
            }
        }

        if(trump!=Hand_Max_type_card[3])
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+2)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+3)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+4)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+5)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+6)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[3]*8+7)
                    return i;
            }
        }

        if(trump!=Hand_Max_type_card[2])
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+2)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+3)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+4)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+5)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+6)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[2]*8+7)
                    return i;
            }
        }

        if(trump!=Hand_Max_type_card[1])
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+2)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+3)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+4)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+5)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+6)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[1]*8+7)
                    return i;
            }
        }

        if(trump!=Hand_Max_type_card[0])
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+2)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+3)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+4)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+5)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+6)
                    return i;
                if(player[pr].get_card(i)==Hand_Max_type_card[0]*8+7)
                    return i;
            }
        }
        for(int i=player[pr].get_top()-1; i>=0; i++)
        {
            return i;
        }
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::show_trump_by_robot_player(int pr)
{
    clear_pot_and_pot_table();
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;

    x=54;
    y=18;
    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<32; i++)
    {
        asdgraphics::locate(x+i,y);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+6);
        cout<<ch[4];
    }

    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x+32,y+i);
        cout<<ch[4];
    }
    cout<<'\a';
    asdgraphics::setColor(12);
    asdgraphics::locate(x+2,y+2);
    if(pr==0)
        cout<<"WEST";
    else if(pr==1)
        cout<<"NORTH";
    else if(pr==2)
        cout<<"EAST";
    else if(pr==3)
    {
        cout<<"WOULD YOU LIKE SHOW TRUMP CARD";
        asdgraphics::locate(x+2,y+4);
        cout<<"     YES[Y]       NO[N]";
        asdgraphics::setColor(11);
        while(1)
        {
            char c;
            c=getch();
            if(c=='Y' || c=='y')
            {
                for(int i=0; i<7; i++)
                {
                    asdgraphics::locate(x,y+i);
                    cout<<"                                 ";
                }
                Re_view_Pot_card(pr);
                return  1;
            }
            else if(c=='N' || c=='n')
            {
                for(int i=0; i<7; i++)
                {
                    asdgraphics::locate(x,y+i);
                    cout<<"                                 ";
                }
                Re_view_Pot_card(pr);
                return  0;
            }
            else
                cout<<'\a';
        }
    }

    if(pr!=3)
    {
        cout<<" WANT TO SEE TRUMP CARD";
        asdgraphics::locate(x+2,y+4);
        cout<<"          [ENTER]";
        asdgraphics::setColor(11);
        while(1)
        {
            char c;
            c=asdgraphics::getkey();
            if(c==1)
            {
                for(int i=0; i<7; i++)
                {
                    asdgraphics::locate(x,y+i);
                    cout<<"                                 ";
                }
                Re_view_Pot_card(pr);
                return  0;
            }
            else
                cout<<'\a';
        }

    }
    Re_view_Pot_card(pr);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::Find_a_card_by_fllowing_pot(int pr)
{
    if(Show_Trump==0 || (Show_Trump==1 && temptrk!=1 && pr==bid_player))
    {
        int flag=0;
        for(int i=0; i<player[pr].get_top(); i++)
        {
            if(player[pr].which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
            {
                flag=1;
                break;
            }
        }
        int ppprrr;
        if(pr==0)
            ppprrr=2;
        else if(pr==1)
            ppprrr=3;
        else if(pr==2)
            ppprrr=0;
        if(Pot.get_top()==3)
        {
            if(flag==0 && Max_card_player!=ppprrr)
            {
                show_trump_by_robot_player(pr);
                Show_Trump=1;
                temptrk=1;
                cardBoy.view_visual_trump_card(trump,38,4);
            }
        }
        else
        {
            if(flag==0)
            {
                show_trump_by_robot_player(pr);
                Show_Trump=1;
                temptrk=1;
                cardBoy.view_visual_trump_card(trump,38,4);
            }
        }
    }

    int Crack=0;
    for(int i=0; i<player[pr].get_top(); i++)
    {
        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
        {
            Crack=1;
            break;
        }
    }

    if(Show_Trump==0)
    {
        if(Crack==1)
        {
            for(int i=0; i<player[pr].get_top(); i++)
            {
                if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2-Pot.get_top())
                        return i;
                }
                else if(player[pr].get_card(i)==player[pr].which_type_card(Pot.lead_card)*8+1)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2-Pot.get_top() && Max_card>player[pr].get_card(i))
                    {
                        if(Hand_card[pr][Pot.which_type_card(player[pr].get_card(i))].get_card(0)!=Pot.which_type_card(player[pr].get_card(i))*8 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8)
                            return i;
                    }
                }
                else if(player[pr].get_card(i)==player[pr].which_type_card(Pot.lead_card)*8+2 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8+1)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2-Pot.get_top())
                    {
                        if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8 && Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8+1 && Max_card>player[pr].get_card(i))
                            return i;
                    }
                }
                else if(player[pr].get_card(i)==player[pr].which_type_card(Pot.lead_card)*8+3 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8+1 && Max_card!=Pot.which_type_card(player[pr].get_card(i))*8+2)
                {
                    if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2-Pot.get_top())
                    {
                        if(Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8 && Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8+1 && Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_card(0)!=player[pr].which_type_card(player[pr].get_card(i))*8+2 )
                            return i;
                    }
                }
            }

            ////////////////////////////////////////////////////////////////////////////////////////////
            if(Pot.get_top()==3)
            {
                if(Pot.which_type_card(Max_card)!=trump)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card) && player[pr].get_card(i)< Max_card )
                            return i;
                    }

                }
            }
            ///////////////////////////////////////////////////////////////////////////
            if(Max_card==Pot.which_type_card(Pot.lead_card)*8 )
            {
                int ppprrr;
                if(pr==0)
                    ppprrr=2;
                else if(pr==1)
                    ppprrr=3;
                else if(pr==2)
                    ppprrr=0;
                if(Max_card_player==ppprrr)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card) && player[pr].get_card(i)< Pot.which_type_card(Pot.lead_card)*8+4)
                            return i;
                    }
                }
            }


            int arresting=1;
            if(Pot.get_top()>1)
            {
                if(pr==0)
                {
                    if(Max_card_player==2)
                    {
                        if(Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==1)
                {
                    if(Max_card_player==3)
                    {
                        if(Hand_card[pr][Pot.which_type_card(Pot.lead_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Pot.lead_card)].get_card(0)>Max_card )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==2)
                {
                    if(Max_card_player==0)
                    {
                        if(Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==3)
                {
                    if(Max_card_player==1)
                    {
                        if(Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else
                    arresting=0;
            }
            else if(Pot.get_top()<2)
                arresting=0;
            else
                arresting=0;

            ///////////////////////////////////////////////////////////////////////////

            if(arresting==1)
            {
                if( Pot.which_type_card(Max_card)==Pot.which_type_card(Pot.lead_card) )
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+1)
                            return i;
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+2)
                            return i;
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+3)
                            return i;
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+4)
                        {
                            if(player[pr].get_card(i+1)!=Pot.which_type_card(Pot.lead_card)*8+5)
                                return i;
                        }
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+5)
                            return i;
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+6)
                            return i;
                        else if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+7)
                            return i;
                    }

                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                            return i;
                    }

                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                        return i;
                }
            }

            if(arresting==0)
            {
                for(int i=player[pr].get_top()-1; i>=0; i--)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                    {
                        if(player[pr].get_card(i)==Pot.which_type_card(Pot.lead_card)*8+5)
                        {
                            if(player[pr].get_card(i-1)!=Pot.which_type_card(Pot.lead_card)*8+4)
                                return i;
                        }
                        else if(player[pr].get_card(i)!=Pot.which_type_card(Pot.lead_card)*8+1)
                            return i;
                    }
                }

                for(int i=player[pr].get_top()-1; i>=0; i--)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                        return i;
                }
            }
        } // end of the crack==1
        if(Crack==0)
        {
            int ppprrr;
            if(pr==0)
                ppprrr=2;
            else if(pr==1)
                ppprrr=3;
            else if(pr==2)
                ppprrr=0;
            if(Pot.get_top()==3 && Max_card_player==ppprrr)
            {
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==1 || player[pr].get_card(i)==17 || player[pr].get_card(i)==9 ||player[pr].get_card(i)==25 )
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==3 || player[pr].get_card(i)==19 || player[pr].get_card(i)==11 ||player[pr].get_card(i)==27)
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==2 || player[pr].get_card(i)==18 || player[pr].get_card(i)==10 ||player[pr].get_card(i)==26)
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==0 || player[pr].get_card(i)==16 || player[pr].get_card(i)==8 ||player[pr].get_card(i)==24)
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==7 || player[pr].get_card(i)==15 || player[pr].get_card(i)==23 ||player[pr].get_card(i)==31)
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==6 || player[pr].get_card(i)==14 || player[pr].get_card(i)==22 ||player[pr].get_card(i)==30)
                        return i;
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==5 || player[pr].get_card(i)==13 || player[pr].get_card(i)==21 ||player[pr].get_card(i)==29)
                        return i;
                    else if(player[pr].get_card(i)==4 || player[pr].get_card(i)==12 || player[pr].get_card(i)==20 ||player[pr].get_card(i)==28)
                        return i;
                }

            }
            for(int i=player[pr].get_top()-1; i>=0; i--)
            {
                return i;
            }

        }//End of Crack==0

    }

    if(Show_Trump==1 )
    {
        if(Crack==1)
        {
            if(Max_card==Pot.which_type_card(Pot.lead_card)*8 && Pot.which_type_card(Pot.lead_card)!=trump)
            {
                int ppprrr;
                if(pr==0)
                    ppprrr=2;
                else if(pr==1)
                    ppprrr=3;
                else if(pr==2)
                    ppprrr=0;
                if(Max_card_player==ppprrr)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card) && player[pr].get_card(i)< Pot.which_type_card(Pot.lead_card)*8+4)
                            return i;
                    }
                }
            }

            if(Pot.get_top()==3)
            {
                if(Pot.which_type_card(Max_card)!=trump)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card) && player[pr].get_card(i)< Max_card )
                            return i;
                    }

                }
            }
            int arresting=0;
            if(Pot.get_top()>1)
            {
                if(pr==0)
                {
                    if(Max_card_player==2)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==1)
                {
                    if(Max_card_player==3)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==2)
                {
                    if(Max_card_player==0)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==3)
                {
                    if(Max_card_player==1)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Pot.lead_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else
                    arresting=0;
            }
            else
                arresting=0;

            if( arresting==0)
            {
                if(Pot.which_type_card(Max_card)==Pot.which_type_card(Pot.lead_card))
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card) && Hand_card[pr][Pot.which_type_card(Pot.lead_card)].get_card(0)>player[pr].get_card(i))
                        {
                            if((Hand_card[pr][player[pr].which_type_card(player[pr].get_card(i))].get_top()>2-Pot.get_top() && Max_card>player[pr].get_card(i) ) || (player[pr].get_top()<4 && Max_card>player[pr].get_card(i) && Hand_card[pr][trump].get_top()<2 ))
                                return i;
                        }
                    }
                }

                for(int i=player[pr].get_top()-1; i>=0; i--)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                        return i;
                }
            }//End of the Arresting==0

            if( arresting==1 )
            {
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                        return i;

                }

            }//End of the Arresting==1

            for(int i=player[pr].get_top()-1; i>=0; i--)
            {
                if(Pot.which_type_card(player[pr].get_card(i))==Pot.which_type_card(Pot.lead_card))
                    return i;
            }

        }//end of the Crack==1

        if(Crack==0)
        {
            int ppprrr;
            if(pr==0)
                ppprrr=2;
            else if(pr==1)
                ppprrr=3;
            else if(pr==2)
                ppprrr=0;
            if(Pot.get_top()==3 && Max_card_player==ppprrr)
            {

                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==1 || player[pr].get_card(i)==17 || player[pr].get_card(i)==9 ||player[pr].get_card(i)==25 )
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==3 || player[pr].get_card(i)==19 || player[pr].get_card(i)==11 ||player[pr].get_card(i)==27)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==2 || player[pr].get_card(i)==18 || player[pr].get_card(i)==10 ||player[pr].get_card(i)==26)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==0 || player[pr].get_card(i)==16 || player[pr].get_card(i)==8 ||player[pr].get_card(i)==24)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==7 || player[pr].get_card(i)==15 || player[pr].get_card(i)==23 ||player[pr].get_card(i)==31)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==6 || player[pr].get_card(i)==14 || player[pr].get_card(i)==22 ||player[pr].get_card(i)==30)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(player[pr].get_card(i)==5 || player[pr].get_card(i)==13 || player[pr].get_card(i)==21 ||player[pr].get_card(i)==29)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                    else if(player[pr].get_card(i)==4 || player[pr].get_card(i)==12 || player[pr].get_card(i)==20 ||player[pr].get_card(i)==28)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                            return i;
                    }
                }

            }

            int arresting=0;
            if(Pot.get_top()>1)
            {
                if(pr==0)
                {
                    if(Max_card_player==2)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump )
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==1)
                {
                    if(Max_card_player==3)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==2)
                {
                    if(Max_card_player==0)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Max_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else if(pr==3)
                {
                    if(Max_card_player==1)
                    {
                        if((Hand_card[pr][Pot.which_type_card(Pot.lead_card)].get_top()>0 && Hand_card[pr][Pot.which_type_card(Max_card)].get_card(0)>Max_card) || Pot.which_type_card(Max_card)==trump)
                            arresting=1;
                        else
                            arresting=0;
                    }
                    else
                        arresting=0;
                }
                else
                    arresting=0;
            }
            else
                arresting=0;

            int Player_Max_type_card[4]={player[pr].get_card_type(0),player[pr].get_card_type(1),player[pr].get_card_type(2),player[pr].get_card_type(3)};
            int trak[4]={0,1,2,3};
            for(int i=0; i<4; i++)
            {
                for(int j=0; j<4; j++)
                    if(Player_Max_type_card[i]<Player_Max_type_card[j])
                    {
                        int Swap=Player_Max_type_card[i];
                        int Sw=trak[i];
                        Player_Max_type_card[i]=Player_Max_type_card[j];
                        trak[i]=trak[j];
                        Player_Max_type_card[j]=Swap;
                        trak[j]=Sw;
                    }
            }

            for(int i=0; i<4; i++)
                Player_Max_type_card[i]=trak[i];

            if( arresting==0 )
            {
                if(Pot.which_type_card(Max_card)!=trump)
                {
                    if( Hand_card[pr][player[pr].which_type_card(Pot.lead_card)].get_top()>2-Pot.get_top() )
                    {
                        for(int i=player[pr].get_top()-1; i>=0; i--)
                        {
                            if(Pot.which_type_card(player[pr].get_card(i))==trump)
                                return i;
                        }
                    }
                }


                if(Pot.which_type_card(Max_card)==trump)
                {
                    for(int i=player[pr].get_top()-1; i>=0; i--)
                    {
                        if(Pot.which_type_card(player[pr].get_card(i))==trump && player[pr].get_card(i)<Max_card)
                            return i;
                    }


                }


                for(int Mx=0; Mx<4; Mx++)
                {
                    int Do_or_do_not=1;
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+1 )
                        {
                            if(Hand_card[pr][Mx].get_card(0)==Player_Max_type_card[Mx]*8 && player[pr].get_card_type(Mx)<3 )
                                Do_or_do_not=0;
                        }
                        if(Player_Max_type_card[Mx]==trump)
                            Do_or_do_not=0;
                    }

                    if(Do_or_do_not==1)
                    {
                        for(int i=0; i<player[pr].get_top(); i++)
                        {
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+7)
                                return i;
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+6)
                                return i;
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+5)
                                return i;
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+4)
                                return i;
                        }

                    }// End of Do_or_do_not==1

                }// End of Mx loop

                for(int Mx=0; Mx<4; Mx++)
                {
                    int Do_or_do_not=1;
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+1 )
                        {
                            if(Hand_card[pr][Mx].get_card(0)==Player_Max_type_card[Mx]*8 && player[pr].get_card_type(Mx)<3 )
                                Do_or_do_not=0;
                        }
                        if(Player_Max_type_card[Mx]==trump)
                            Do_or_do_not=0;
                    }

                    if(Do_or_do_not==1)
                    {
                        for(int i=0; i<player[pr].get_top(); i++)
                        {
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+3)
                                return i;
                            if(player[pr].get_card(i)==Player_Max_type_card[Mx]*8+2)
                                return i;
                        }
                    }
                }// End of Mx loop

                for(int Mx=0; Mx<4; Mx++)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)!=Player_Max_type_card[Mx]*8 && player[pr].get_card(i)!=Player_Max_type_card[Mx]*8+1)
                            return i;
                    }
                }// End of Mx loop

                for(int Mx=0; Mx<4; Mx++)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)!=Player_Max_type_card[Mx]*8)
                            return i;
                    }
                }// End of Mx loop

                for(int i=0; i<player[pr].get_top(); i++)
                {
                    return i;
                }

            } // End of arresting==0

            if( arresting==1 )
            {
                int Hand_Max_type_card[4]={Hand_card[pr][0].get_top(),Hand_card[pr][1].get_top(),Hand_card[pr][2].get_top(),Hand_card[pr][3].get_top()};
                int trak[4]={0,1,2,3};
                for(int i=0; i<4; i++)
                {
                    for(int j=0; j<4; j++)
                        if(Hand_Max_type_card[i]<Hand_Max_type_card[j])
                        {
                            int Swap=Hand_Max_type_card[i];
                            int Sw=trak[i];
                            Hand_Max_type_card[i]=Hand_Max_type_card[j];
                            trak[i]=trak[j];
                            Hand_Max_type_card[j]=Swap;
                            trak[j]=Sw;
                        }
                }
                for(int i=0; i<4; i++)
                    Hand_Max_type_card[i]=trak[i];


                for(int Mx=3; Mx>=0; Mx--)
                {
                    for(int i=0; i<player[pr].get_top(); i++)
                    {
                        if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+1 && Hand_Max_type_card[Mx]!=trump )
                            return i;
                    }
                }

                for(int Mx=3; Mx>=0; Mx--)
                {
                    int Do_or_do_not=1;
                    if(Player_Max_type_card[Mx]==trump)
                        Do_or_do_not=0;
                    if(Do_or_do_not==1)
                    {
                        for(int i=0; i<player[pr].get_top(); i++)
                        {
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+3)
                                return i;
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+2)
                                return i;
                        }
                    }
                }

                for(int Mx=3; Mx>=0; Mx--)
                {
                    int Do_or_do_not=1;
                    if(Player_Max_type_card[Mx]==trump)
                        Do_or_do_not=0;
                    if(Do_or_do_not==1)
                    {
                        for(int i=0; i<player[pr].get_top(); i++)
                        {
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+4)
                                return i;
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+5)
                                return i;
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+6)
                                return i;
                            if(player[pr].get_card(i)==Hand_Max_type_card[Mx]*8+7)
                                return i;
                        }
                    }
                }
                for(int i=0; i<player[pr].get_top(); i++)
                {
                    if(Pot.which_type_card(player[pr].get_card(i))!=trump)
                        return i;
                }

                for(int i=0; i<player[pr].get_top(); i++)
                {
                    return i;
                }

            } // End of arresting==1

        } // End of the crack==0

    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::show_half_of_marriage(int pr)
{
    clear_pot_and_pot_table();
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    x=54;
    y=18;
    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<32; i++)
    {
        asdgraphics::locate(x+i,y);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+6);
        cout<<ch[4];
    }

    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x+32,y+i);
        cout<<ch[4];
    }
    cout<<'\a';
    asdgraphics::setColor(11);
    asdgraphics::locate(x+3,y+2);
    if(pr==0)
        cout<<"WEST";
    else if(pr==1)
        cout<<"NORTH";
    else if(pr==2)
        cout<<"EAST";
    else if(pr==3)
        cout<<"South";
    cout<<" Show Half Of Marriage.";
    asdgraphics::locate(x+2,y+4);
    cout<<"           [ENTER]";
    asdgraphics::setColor(11);
    while(1)
    {
        char c;
        c=asdgraphics::getkey();
        if(c==1)
        {
            for(int i=0; i<9; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                   ";
            }
            return  0;
        }
        else
            cout<<'\a';
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::show_round_winner_SMS(int win)
{
    asdgraphics::setColor(11);
    char ch[5];
    ch[0]=223;
    ch[1]=222;
    ch[2]=221;
    ch[3]=220;
    ch[4]=219;
    x=54;
    y=16;
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[1];
    }
    for(int i=1; i<33; i++)
    {
        asdgraphics::locate(x+i,y+1);
        cout<<ch[0];
        asdgraphics::locate(x+i,y+11);
        cout<<ch[3];
    }
    for(int i=1; i<12; i++)
    {
        asdgraphics::locate(x+33,y+i);
        cout<<ch[2];
    }
    char s[100],ss[100];
    if(bid_player==0)
    {
        strcpy(s,"West.");
        strcpy(ss,"E/W");
    }
    else if(bid_player==1)
    {
        strcpy(s,"North.");
        strcpy(ss,"N/S");
    }
    else if(bid_player==2)
    {
        strcpy(s,"East.");
        strcpy(ss,"E/W");
    }
    else if(bid_player==3)
    {
        strcpy(s,"South.");
        strcpy(ss,"N/S");
    }
    if(win==1)
    {
        asdgraphics::locate(56,18);
        cout<<"Congrats! Game Won By "<<s;
        asdgraphics::locate(56,20);
        cout<<"Highest Bid Was "<<target_bid<<" By "<<s;
        asdgraphics::locate(56,21);
        cout<<"East & West Won "<<E_W_POINT<<" Points.";
        asdgraphics::locate(56,22);
        cout<<"North & South Won "<<N_S_POINT<<" Points.";
        asdgraphics::locate(56,24);
        cout<<1+Double<<" Game Point(s) Awarded to "<<ss;
        asdgraphics::locate(58,26);
        cout<<"          [ENTER]";
    }
    else if(win==0)
    {
        asdgraphics::locate(56,18);
        cout<<"In Sorrow! Game lost By "<<s;
        asdgraphics::locate(56,20);
        cout<<"Highest Bid Was "<<target_bid<<" By "<<s;
        asdgraphics::locate(56,21);
        cout<<"East & West Won "<<E_W_POINT<<" Points.";
        asdgraphics::locate(56,22);
        cout<<"North & South Won "<<N_S_POINT<<" Points.";
        asdgraphics::locate(56,24);
        cout<<1+Double<<" Game Points Reprimand to "<<ss;
        asdgraphics::locate(58,26);
        cout<<"          [ENTER]";
    }
    tool_ber go;
    while(1)
    {
        char c;
        c=asdgraphics::getkey();
        c=go.toolber_menu_option(c);
        if(c=='r')
        {
            return 10;
        }
        if(c==1)
        {
            for(int i=0; i<13; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                     ";
            }
            return  0;
        }
        else
            cout<<'\a';
    }
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::ask_about_starting_A_new_deal()
{
    asdgraphics::setColor(11);
    char ch[6];
    ch[0]=3;
    ch[1]=5;
    ch[2]=4;
    ch[3]=6;
    ch[4]=219;
    ch[5]=31;
    x=54;
    y=18;
    for(int yx=5; yx<=38; yx++)
    {
        asdgraphics::locate(38,yx);
        cout<<"                                                                  ";
    }

    for(int i=0; i<4; i++)
    {
        asdgraphics::locate(38,5+i);
        cout<<"        ";
    }

    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x,y+i);
        cout<<ch[4];
    }

    for(int i=1; i<32; i++)
    {
        asdgraphics::locate(x+i,y);
        cout<<ch[4];
        asdgraphics::locate(x+i,y+6);
        cout<<ch[4];
    }

    for(int i=0; i<7; i++)
    {
        asdgraphics::locate(x+32,y+i);
        cout<<ch[4];
    }
    asdgraphics::setColor(11);
    asdgraphics::locate(x+2,y+2);
    cout<<"HIT ENTER FOR START NEW DEAL";
    asdgraphics::locate(x+2,y+4);
    cout<<"           [ENTER]";
    asdgraphics::setColor(11);
    tool_ber go;
    while(1)
    {
        char c;
        c=asdgraphics::getkey();
        c=go.toolber_menu_option(c);
        if(c=='r')
        {
            return 0;
        }

        if(c==1)
        {
            for(int i=0; i<9; i++)
            {
                asdgraphics::locate(x,y+i);
                cout<<"                                   ";
            }
            return  1;
        }
        else
            cout<<'\a';
    }
    return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::Receive_A_card_from_User()
{
    int lock=0;
    if(Show_Trump==0 || (Show_Trump==1 && temptrk!=1 && bid_player==3))
    {
        int flag=0;
        for(int i=0; i<player[3].get_top(); i++)
        {
            if(player[3].which_type_card(player[3].get_card(i))==Pot.which_type_card(Pot.lead_card))
            {
                flag=1;
                break;
            }
        }

        if(flag==0 && Pot.get_top()!=0)
        {
            asdgraphics::msleep(1500);
            if(show_trump_by_robot_player(3)==1)
            {
                Show_Trump=1;
                temptrk=1;
                for(int i=0; i<player[3].get_top(); i++)
                {
                    if(Pot.which_type_card(player[3].get_card(i))==trump)
                    {
                        lock=1;
                        break;
                    }
                }
                cardBoy.view_visual_trump_card(trump,38,4);
            }
        }
    }


    int Crack=0;
    for(int i=0; i<player[3].get_top(); i++)
    {
        if(Pot.which_type_card(player[3].get_card(i))==Pot.which_type_card(Pot.lead_card))
        {
            Crack=1;
            break;
        }
    }


    char ch=31;
    x=69-(((player[3].get_top()*3)/2)+2);
    y=30;
    int p=0;
    asdgraphics::setColor(10);
    while(1)
    {
        if(p==0)
        {
            asdgraphics::locate(x+3,y-1);
            cout<<ch;
        }
        else if(p==1)
        {
            asdgraphics::locate(x+6,y-1);
            cout<<ch;
        }
        else if(p==2)
        {
            asdgraphics::locate(x+9,y-1);
            cout<<ch;
        }
        else if(p==3)
        {
            asdgraphics::locate(x+12,y-1);
            cout<<ch;
        }
        else if(p==4)
        {
            asdgraphics::locate(x+15,y-1);
            cout<<ch;

        }
        else if(p==5)
        {
            asdgraphics::locate(x+18,y-1);
            cout<<ch;

        }
        else if(p==6)
        {
            asdgraphics::locate(x+21,y-1);
            cout<<ch;

        }
        else if(p==7)
        {
            asdgraphics::locate(x+26,y-1);
            cout<<ch;

        }
        int k=asdgraphics::getkey();
        tool_ber go;
        k=go.toolber_menu_option(k);
        if(k=='r')
        {
            return 10;
        }
        if(k==17 && p < player[3].get_top()-1 )
        {
            p++;
        }
        else if(k==16 && p>0)
        {
            p--;
        }
        else if(k==1)
        {
            asdgraphics::locate(x,y-1);
            cout<<"                              ";
            if(Pot.get_top()!=0)
            {
                if(Crack==1 && lock!=1)
                {
                    if(Pot.which_type_card(player[3].get_card(p))==Pot.which_type_card(Pot.lead_card))
                        return p;
                    else
                        cout<<'\a';
                }
                else if(lock==1)
                {
                    if(Pot.which_type_card(player[3].get_card(p))==trump)
                        return p;
                    else
                        cout<<'\a';
                }
                else if(Crack==0)
                    return p;
            }
            else
                return p;
        }
        else
        {
            if(k==17)
                p=0;
            else if(k==16)
                p=player[3].get_top()-1;
            else
                cout<<'\a';
        }
        asdgraphics::locate(x,y-1);
        cout<<"                              ";
    }


}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::Play_A_Lead(int Starting_player)
{
    instuctions info;
    char sm[4]={16,17,30,31};
    int n=0,error=0;
    int card_no;
    Pot.constructor();
    while(n!=4)
    {
        error=Searching_Error();
        if(error==1)
            return 10;
        if(Starting_player==0)
        {
            asdgraphics::locate(46,22);
            asdgraphics::setColor(10);
            cout<<sm[1];
            info.put_messages("West is thinking.");
            info.display_instuctions();
            asdgraphics::msleep(1500);
            asdgraphics::locate(46,22);
            cout<<" ";
        }
        else if(Starting_player==1)
        {
            asdgraphics::locate(70,14);
            asdgraphics::setColor(10);
            cout<<sm[2];
            info.put_messages("North is thinking.");
            info.display_instuctions();
            asdgraphics::msleep(1500);
            asdgraphics::locate(70,14);
            cout<<" ";
        }
        else if(Starting_player==2)
        {
            asdgraphics::locate(95,22);
            asdgraphics::setColor(10);
            cout<<sm[0];
            info.put_messages("East is thinking.");
            info.display_instuctions();
            asdgraphics::msleep(1500);
            asdgraphics::locate(95,22);
            cout<<" ";
        }
        info.put_messages("                       ");
        info.display_instuctions();
        if(n==0)
        {
            if(Starting_player==3)
            {
                card_no=Receive_A_card_from_User();
                if(card_no==10)
                    return 10;
            }
            else
                card_no=selecting_A_card_for_play(Starting_player);
        }                                       // West=0 // North=1 // East=2 // South=3
        if(n!=0)
        {
            if(Starting_player==3)
            {
                card_no=Receive_A_card_from_User();
                if(card_no==10)
                    return 10;
            }
            else
                card_no=Find_a_card_by_fllowing_pot(Starting_player);
        }
        int c_a=player[Starting_player].play_card(card_no);
        put_a_card_on_pot(c_a,Starting_player);
        if(Starting_player==0)
        {
            view_west_card();
        }
        else if(Starting_player==1)
        {
            view_north_card();
        }
        else if(Starting_player==2)
        {
            view_east_card();
        }
        else if(Starting_player==3)
        {
            view_south_card();
        }
        n++;
        if(Starting_player>0)
        {
            Starting_player--;
        }
        else if(Starting_player==0)
        {
            Starting_player=3;
        }
    }
    error=Searching_Error();
    if(error==1)
        return 10;
    if(Max_card_player==0)
    {
        asdgraphics::locate(62,22);
        asdgraphics::setColor(12);
        cout<<sm[1];
        info.put_messages("Press any key to continue...                * WEST WON THIS LEAD *");
        info.display_instuctions();
    }
    else if(Max_card_player==1)
    {
        asdgraphics::locate(71,14);
        asdgraphics::setColor(12);
        cout<<sm[2];
        info.put_messages("Press any key to continue...               * NORTH WON THIS LEAD * ");
        info.display_instuctions();
    }
    else if(Max_card_player==2)
    {
        asdgraphics::locate(80,22);
        asdgraphics::setColor(12);
        cout<<sm[0];
        info.put_messages("Press any key to continue...               * EAST WON THIS LEAD * ");
        info.display_instuctions();
    }
    else if(Max_card_player==3)
    {
        asdgraphics::locate(71,28);
        asdgraphics::setColor(12);
        cout<<sm[3];
        info.put_messages("Press any key to continue...              * SOUTH WON THIS LEAD * ");
        info.display_instuctions();
    }
    getch();
    clear_pot_and_pot_table();
    info.put_messages("                                                                      ");
    info.display_instuctions();
    return Max_card_player;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

int Artificial_Intelligence_Creator::Play_eight_lead()
{
    int n=0,error=0;
    int winner;
    Career cr;
    int w=cr.get_user_rank()%4;
    clear_recent_history();
    error=searching_jack_error();
    if(error==1)
        return 0;
    asdgraphics::setColor(11);
    asdgraphics::locate(3,29);
    cout<<"E/W POINT N/S POINT  WINNER";
    int x=3;
    int y=31;
    while(n!=8)
    {
        error=0;
        if(n==0)
            winner=Play_A_Lead(w);
        else
            winner=Play_A_Lead(winner);
        asdgraphics::setColor(11);
        if(winner==0)
        {
            E_W_POINT=E_W_POINT+Pot.get_pot_point();
            error=Searching_Error();
            if(error==1)
                return 0;
            asdgraphics::locate(x,y);
            cout<<"    "<<E_W_POINT<<"  \t"<<N_S_POINT<<"\tWEST";
        }
        else if(winner==1)
        {
            N_S_POINT=N_S_POINT+Pot.get_pot_point();
            error=Searching_Error();
            if(error==1)
                return 0;
            asdgraphics::locate(x,y);
            cout<<"    "<<E_W_POINT<<"  \t"<<N_S_POINT<<"\tNORTH";
        }
        else if(winner==2)
        {
            E_W_POINT= E_W_POINT + Pot.get_pot_point();
            error=Searching_Error();
            if(error==1)
                return 0;
            asdgraphics::locate(x,y);
            cout<<"    "<<E_W_POINT<<"  \t"<<N_S_POINT<<"\tEAST";
        }
        else if(winner==3)
        {
            N_S_POINT=N_S_POINT+Pot.get_pot_point();
            error=Searching_Error();
            if(error==1)
                return 0;
            asdgraphics::locate(x,y);
            cout<<"    "<<E_W_POINT<<"  \t"<<N_S_POINT<<"\tSOUTH";
        }
        else if(winner==10)
        {
            return 0;
        }
        y++;
        n++;
    }
    int err;
    if(bid_player==0)
    {
        if( target_bid<=E_W_POINT )
        {
            err=show_round_winner_SMS(1);
            if(err==10)
                return 0;
            cr.put_computer_result(cr.get_computer_result()+1+Double);
        }
        else
        {
            err=show_round_winner_SMS(0);
            if(err==10)
                return 0;
            cr.put_computer_result(cr.get_computer_result()-1-Double);
        }
    }
    else if(bid_player==1)
    {
        if( target_bid<=N_S_POINT )
        {
            err=show_round_winner_SMS(1);
            if(err==10)
                return 0;
            cr.put_user_result(cr.get_user_result()+1+Double);
        }
        else
        {
            err=show_round_winner_SMS(0);
            if(err==10)
                return 0;
            cr.put_user_result(cr.get_user_result()-1-Double);
        }

    }
    else if(bid_player==2)
    {
        if( target_bid<=E_W_POINT )
        {
            err=show_round_winner_SMS(1);
            if(err==10)
                return 0;
            cr.put_computer_result(cr.get_computer_result()+1+Double);
        }
        else
        {
            err=show_round_winner_SMS(0);
            if(err==10)
                return 0;
            cr.put_computer_result(cr.get_computer_result()-1-Double);
        }
    }
    else if(bid_player==3)
    {
        if( target_bid<=N_S_POINT )
        {
            err=show_round_winner_SMS(1);
            if(err==10)
                return 0;
            cr.put_user_result(cr.get_user_result()+1+Double);
        }
        else
        {
            err=show_round_winner_SMS(0);
            if(err==10)
                return 0;
            cr.put_user_result(cr.get_user_result()-1-Double);
        }
        Pot.constructor();
    }
    error=Searching_Error();
    if(error==1)
        return 0;
    cr.SaveAllCareer("NAME");
    clear_recent_history();
    constructor();
    return 1;
}
