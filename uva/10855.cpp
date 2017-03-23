#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rotate_90(vector<string>& mat)
{
    vector<string> res = mat;
    for(int i = 0; i < mat.size(); ++i)
    {
        for(int j = 0; j < mat.size(); ++j)
        {
            res[i][j] = mat[mat.size() - 1 - j][i];
        }
    }
    mat = res;
}

bool check_sub_mat(const vector<string>& mat, const vector<string>& sub, int sub_i, int sub_j)
{
    for(int i = 0; i < sub.size(); ++i)
    {
        for(int j = 0; j < sub[i].size(); ++j)
        {
            if(mat[sub_i + i][sub_j + j] != sub[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int N, n;
    while(cin >> N >> n)
    {
        if(N == 0 && n == 0)
            break;

        // [i][j]
        // i is the row
        // j is the col
        vector<string> mat;
        vector<string> sub_mat;

        for(int i = 0; i < N; ++i)
        {
            string s;
            for(int j = 0; j < N; ++j)
            {
                char ch;
                cin >> ch;
                s += ch;
            }
            mat.emplace_back(s);
        }

        for(int i = 0; i < n; ++i)
        {
            string s;
            for(int j = 0; j < n; ++j)
            {
                char ch;
                cin >> ch;
                s += ch;
            }
            sub_mat.emplace_back(s);
        }

        int c[4] = {};
        for(int i = 0; i <= N - sub_mat.size(); ++i)
        {
            for(int j = 0; j <= N - sub_mat.size(); ++j)
            {
                for(int k = 0; k < 4; ++k)
                {
                    if(check_sub_mat(mat, sub_mat, i, j))
                    {
                        c[k]++;
                    }

                    rotate_90(sub_mat);
                }
            }
        }

        for(int i = 0; i < 4; ++i)
        {
            cout << c[i];
            if(i != 3) cout << ' ';
        }
        cout << endl;
    }
}
