#ifndef _PLAYER_MANAGING_BOARD_H_
#define _PLAYER_MANAGING_BOARD_H_

class player_Managing_Board
{
private:
    int maxbit[4];
    int trump[4];
    int Marriage[4];
    int all_card[32];
protected:
    int shuffle_card();
    int assembling_card();
    int card_distribute_1st();
    int card_distribute_2nd();
    void player_bit_manager(int i);
    player_card_manager player[4];    // West=0 // North=1 // East=2 // South=3
    void Marriage_search();
public:
    int card_provider_1st();
    int card_provider_2nd();
    void put_user_max_bid(int b)  {   maxbit[3]=b;  }
    int get_trump_card(int i)     {   return trump[i];    }
    int get_max_bit(int i)        {   return maxbit[i];    }
    int get_Marriage(int i)       {   return Marriage[i];   }
};

#endif







