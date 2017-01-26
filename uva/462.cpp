#include <iostream>
#include <numeric>
#include <cassert>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

enum Card
{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE,
    CARD_COUNT
};

enum Suite
{
    SPADE,
    HEART,
    DIAMOND,
    CLUBS,
    SUITE_COUNT
};

using Deck = int[SUITE_COUNT][CARD_COUNT];

static_assert(CARD_COUNT == 13, "incorrect card count");
static_assert(SUITE_COUNT == 4, "incorrect suite count");

int main(int argc, char *argv[])
{
    while(true)
    {
        Deck deck = {};
        string cards[13];
        bool b = false;
        for(int i = 0; i < 13; ++i)
        {
            if(!(cin >> cards[i]))
            {
                b = true;
                break;
            }
        }

        if(b) break;

        for(auto& c : cards)
        {
            const auto suite = c[1];
            const auto card = c[0];

            int suite_index;
            switch(suite)
            {
                case 'S':
                    suite_index = SPADE;
                    break;
                case 'H':
                    suite_index = HEART;
                    break;
                case 'D':
                    suite_index = DIAMOND;
                    break;
                case 'C':
                    suite_index = CLUBS;
                    break;
                default:
                    assert(0 && "Incorrect suite");
            }

            int card_index;
            if(card >= '1' && card <= '9')
            {
                card_index = card - '1';
            }
            else
            {
                switch(card)
                {
                    case 'T':
                        card_index = TEN;
                        break;
                    case 'A':
                        card_index = ACE;
                        break;
                    case 'J':
                        card_index = JACK;
                        break;
                    case 'Q':
                        card_index = QUEEN;
                        break;
                    case 'K':
                        card_index = KING;
                        break;
                    default:
                        assert(0 && "Incorrect card");
                }
            }

            deck[suite_index][card_index]++;
        }

        int points = 0;
        bool all_stopped = true;
        for(auto& suite : deck)
        {
            const auto sum = accumulate(begin(suite), end(suite), 0);
            cout << "sum = " << sum << endl;

            if(suite[ACE] == 0 && !(suite[KING] >= 1 && sum >= 2) && !(suite[QUEEN] >= 1 && sum >= 3))
            {
                all_stopped = false;
            }

            points += suite[ACE] * 4;
            points += suite[KING] * 3;
            points += suite[QUEEN] * 2;
            points += suite[JACK];

            if(suite[KING] > 0 && sum == 1)
            {
                points -= 1;
            }
            else if(suite[QUEEN] && sum <= 2)
            {
                points -= 1;
            }
            else if(suite[JACK] && sum <= 3)
            {
                points -= 1;
            }
        }

        if(points >= 16 && all_stopped)
        {
            cout << "BID NO-TRUMP" << endl;
            continue;
        }

        int highest_suite = 0;
        int highest_sum = 0;
        int i = 0;
        for(auto& suite : deck)
        {
            const auto sum = accumulate(begin(suite), end(suite), 0);
            if(sum > highest_sum)
            {
                highest_suite = i;
                highest_sum = sum;
            }

            switch(sum)
            {
                case 0:
                case 1:
                    points += 2;
                    break;
                case 2:
                    points += 1;
                    break;
            }

            ++i;
        }

        if(points >= 14)
        {
            cout << "BID ";
            switch(highest_suite)
            {
                case SPADE:
                    cout << "S";
                    break;
                case DIAMOND:
                    cout << "D";
                    break;
                case CLUBS:
                    cout << "C";
                    break;
                case HEART:
                    cout << "H";
                    break;
                default:
                    break;
            }
            cout << endl;
        }
        else
        {
            cout << "PASS" << endl;
        }
    }
}
