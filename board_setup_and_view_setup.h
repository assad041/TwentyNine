#ifndef _BOARD_SETUP_AND_VIEW_SETUP_H_
#define _BOARD_SETUP_AND_VIEW_SETUP_H_

#include"player_Managing_Board.cpp"
//using namespace std;

class board_setup_and_view_setup: public player_Managing_Board
{
private:
    int temp;
protected:
    int x;
    int y;
    card_deck cardBoy;
    int target_bid;
    int bid_player;
    int trump;
    int Double;
    int Marriage[4]; // West=0 // North=1 // East=2 // South=3
    int Show_Trump;
public:
    player_card_manager Hand_card[4][4];
    board_setup_and_view_setup():Double(0)  {   Constructor();   }
    void Constructor();
    void set_card(void);
    void remove_A_Hand_card(int player, int card);
    void Refresh_Hand_card(void);
    void clear_south_card(void);
    void clear_east_card(void);
    void clear_north_card(void);
    void clear_west_card(void);
    void clear_user_bid_box(void);
    void view_east_card(void);
    void view_west_card(void);
    void view_north_card(void);
    void view_south_card(void);
    void show_AllPlayingCard(void);
    int show_user_bid_box_Make_bid(void);
    int make_user_trump(void);
    int user_trump_options(void);
    int ask_about_double(void);
    int make_board_bid_and_trump(void);
    int search_marriage(void);
};

#endif
