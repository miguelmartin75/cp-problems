#include <iostream>
#include <string>
using namespace std;

enum Direction
{
    Z_PLUS,
    Z_MINUS,
    Y_PLUS,
    Y_MINUS,
    X_PLUS,
    X_MINUS,
    COUNT
};

int main(int argc, char *argv[])
{
    const Direction lookup[6][4] = 
    {
        // Z+
        { X_MINUS, X_PLUS, Z_PLUS, Z_PLUS },
        // Z-
        { X_PLUS, X_MINUS, Z_MINUS, Z_MINUS },
        // Y+
        { Y_PLUS, Y_PLUS, X_MINUS, X_PLUS },
        // Y-
        { Y_MINUS, Y_MINUS, X_PLUS, X_MINUS },
        // X+
        { Z_PLUS, Z_MINUS, Y_PLUS, Y_MINUS },
        // X-
        { Z_MINUS, Z_PLUS, Y_MINUS, Y_PLUS },
    };

    int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            break;
        }

        Direction current = X_PLUS;
        for(int i = 0; i < n - 1; ++i)
        {
            string word;
            cin >> word;

            if(word == "No")
            {
                continue;
            }

            Direction dir;
            switch(word[1])
            {
                case 'x':
                    dir = X_PLUS;
                    break;
                case 'y':
                    dir = Y_PLUS;
                    break;
                case 'z':
                    dir = Z_PLUS;
                    break;
            }

            if(word[0] == '-') 
            {
                dir = (Direction)((int)dir + 1);
            }

            current = lookup[current][dir];
        }

        switch(current)
        {
            case Z_PLUS:
                cout << "+z";
                break;
            case Z_MINUS:
                cout << "-z";
                break;
            case Y_PLUS:
                cout << "+y";
                break;
            case Y_MINUS:
                cout << "-y";
                break;
            case X_PLUS:
                cout << "+x";
                break;
            case X_MINUS:
                cout << "-x";
                break;
            default:
                break;
        }
        cout << endl;
    }
}
