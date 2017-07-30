#ifndef _START_GAME_H_
#define _START_GAME_H_


class start_game
{
protected:
    Artificial_Intelligence_Creator Let;
    Total_menu_view_controller menu;
    games_table_view_management frame;
public:
    void starting_messege(void);
    void View_Calculated_Rating(void);
    void View_Calculated_Result(void);
    void Update_Score_Board(void);
    void playerCareer_setup(void);
    void serve_card_among_AllPlayer(void);
    int start_A_board_circle(void);
};

#endif
