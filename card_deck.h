#ifndef _CARD_DECK_H_
#define _CARD_DECK_H_

class card_deck
{
private:
    int color;
    playing_card deck[32];           /*0-7= hearts  8-15 = diamonds   16-13 = clubs   24-31 = spades */
    int cardcreate();
public:

    card_deck(): color(0)//constructor
    {    cardcreate();    }

    void view_visual_card(int i ,int x, int y);
    int view_hide_card(int i, int x, int y);
    void view_visual_trump_card(int t, int x, int y);
    void view_hide_trump_card(int i, int x, int y);
    void display(int i);

};

#endif
