#ifndef _ARTIFICIAL_INTELLIGENCE_CREATOR_H_
#define _ARTIFICIAL_INTELLIGENCE_CREATOR_H_

using namespace std;


class Artificial_Intelligence_Creator: public board_setup_and_view_setup
{
private:
    Artificial_Intelligence_Pot_part Pot; // West=0 // North=1 // East=2 // South=3
protected:
    int Max_card;
    int Max_card_player;
    int temptrk;
    int E_W_POINT;
    int N_S_POINT;
public:
    Artificial_Intelligence_Creator(): E_W_POINT(0)
    {   constructor();  }
    void constructor();
    int ask_about_Error(void);
    int Searching_Error(void);
    int searching_jack_error(void);
    void Max_card_calculation(int a, int pr);
    void Marriage_calculation(int a, int pr);
    void put_a_card_on_pot(int a, int pr);
    void Re_view_Pot_card(int pr);
    void clear_pot_and_pot_table(void);
    void clear_recent_history(void);
    int selecting_A_card_for_play(int pr);
    int show_trump_by_robot_player(int pr);
    int Find_a_card_by_fllowing_pot(int pr);
    int show_half_of_marriage(int pr);
    int show_round_winner_SMS(int win);
    int ask_about_starting_A_new_deal(void);
    int Receive_A_card_from_User(void);
    int Play_A_Lead(int Starting_player);
    int Play_eight_lead(void);
};

#endif
