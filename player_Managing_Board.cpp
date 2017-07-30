#include"player_Managing_Board.h"


int player_Managing_Board::card_provider_2nd()
{
    card_distribute_2nd();
    Marriage_search();
    return 0;
}



///////////////////////////////////////////////////////////////////////////////////

int player_Managing_Board::card_provider_1st()
{
    Career cr;
    cr.put_user_rank(cr.get_user_rank()+1);
    cr.SaveCareer(cr.get_user_name(),cr.get_fix_user());
    shuffle_card();
    card_distribute_1st();
    assembling_card();
    for(int i=0; i<3; i++)
        player_bit_manager(i);
    Marriage_search();
    for(int i=0; i<3; i++)
    {
        if(Marriage[i])
        {
            maxbit[i]+=3;
            if(maxbit[i]>20)
                maxbit[i]--;
            if(maxbit[i]>19)
                maxbit[i]--;
        }
    }
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////////////


void player_Managing_Board::player_bit_manager(int i)
{
    trump[i]=(player[i].get_card_type(0)>player[i].get_card_type(1)?player[i].get_card_type(0):player[i].get_card_type(1));
    trump[i]=(trump[i]>player[i].get_card_type(2)?trump[i]:player[i].get_card_type(2));
    trump[i]=(trump[i]>player[i].get_card_type(3)?trump[i]:player[i].get_card_type(3));
    int choose[4]={0,0,0,0};
    int c=0;
    for(int j=0; j<4; j++)
    {
        if(trump[i]==player[i].get_card_type(j))
        {
            choose[c]=j;
            c++;
        }
    }
    int bitpoint[4]={0,0,0,0};
    for(int j=0; j<c; j++)
    {
        if(trump[i]>=3)
            bitpoint[j]++;
        for(int k=0; k<4; k++)
        {
            int n=choose[j]*8;
            if(player[i].get_card(k)==n)
                bitpoint[j]+=3;
            else if(player[i].get_card(k)==0 || player[i].get_card(k)==8 || player[i].get_card(k)==16 || player[i].get_card(k)==24 )
                bitpoint[j]++;
            else if( player[i].get_card(k)==(n+1) )
                bitpoint[j]++;
            else if( trump[i]==4 && player[i].get_card(k)==(n+2) )
            {
                bitpoint[j]++;
            }
        }
    }
    if(c==1)
        trump[i]=0;
    else if(c==2)
        trump[i]=(bitpoint[0]>bitpoint[1]?0:1);
    else if(c==3)
    {
        trump[i]=(bitpoint[0]>bitpoint[1]?0:1);
        trump[i]=(bitpoint[trump[i]]>bitpoint[2]?trump[i]:2);
    }
    else if(c==4)
    {
        trump[i]=(bitpoint[0]>bitpoint[1]?0:1);
        trump[i]=(bitpoint[trump[i]]>bitpoint[2]?trump[i]:2);
        trump[i]=(bitpoint[trump[i]]>bitpoint[3]?trump[i]:3);
    }
    maxbit[i]=bitpoint[trump[i]]+15;
    trump[i]=choose[trump[i]];
    for(int k=0; k<4; k++)
        if( player[i].get_card(k)==trump[i]*8 )
                maxbit[i]-=2;

}


////////////////////////////////////////////////////////////////////////////////////


int player_Managing_Board::shuffle_card()
{
    int c=0,B[32],f[32];
    time_t t;
    srand((unsigned)time(&t));
    memset(f,0,sizeof(f));
    while(c!=32)
    {
        for(int i=0;i<32;i++)
        {
            int w=rand()%32;
            if(f[w]!=1)
            {
                B[i]=w;
                f[w]=1;
                c++;
            }
            else
            i--;
        }
    }
    for(int i=0;i<32;i++)
        all_card[i]=B[i];
    /*for(int i=0; i<4; i++)
        player[i].constructor();*/
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////


int player_Managing_Board::card_distribute_1st()
{
    for(int i=0;i<16;i++)
    {
        if(i<4)
            player[0].push_card(i,all_card[i]);
        else if(i<8)
             player[1].push_card(i-4,all_card[i]);
        else if(i<12)
             player[2].push_card(i-8,all_card[i]);
        else if(i<16)
             player[3].push_card(i-12,all_card[i]);
    }
    return 0;
}



/////////////////////////////////////////////////////////////////////////////////



int player_Managing_Board::card_distribute_2nd()
{
    for(int i=16;i<32;i++)
    {
        if(i<20)
            player[0].push_card(i-12,all_card[i]);
        else if(i<24)
             player[1].push_card(i-16,all_card[i]);
        else if(i<28)
             player[2].push_card(i-20,all_card[i]);
        else if(i<32)
             player[3].push_card(i-24,all_card[i]);
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////

int player_Managing_Board::assembling_card()
{
    for(int i=0; i<4; i++)
    {
        for (int c=0; c < (player[i].get_top()-1); c++)
        {
            for (int d=0; d < (player[i].get_top()-c-1); d++)
            {
                if(player[i].get_card(d) > player[i].get_card(d+1)) /* For decreasing order use < */
                {
                    int Swap= player[i].pop_card(d);
                    player[i].push_card(d,player[i].pop_card(d+1));
                    player[i].push_card(d+1,Swap);
                }
            }
        }
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////


void player_Managing_Board::Marriage_search()
{
    for(int i=0; i<3; i++)
    {
        Marriage[i]=0;
        for(int j=0; j<player[i].get_top(); j++)
        {
            if(trump[i]*8+4==player[i].get_card(j))
                Marriage[i]++;
            else if(trump[i]*8+5==player[i].get_card(j))
                Marriage[i]++;
        }
        if(Marriage[i]==2)
            Marriage[i]=1;
        else
            Marriage[i]=0;
    }
}
