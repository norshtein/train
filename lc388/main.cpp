#include<bits/stdc++.h>

using namespace std;

class NumMatrix {
public:
    int** bit;
    int r,c;

    inline int lowbit(int x)
    {
        return x & (-x);
    }

    NumMatrix(vector<vector<int>> matrix) {
        r = matrix.size();
        c = r ? matrix[0].size() : 0;

        bit = new int*[r + 1];
        for(int i = 0;i <= r;i++)
        {
            bit[i] = new int[c + 1];
            for(int j =0;j <=c ;j++)
                bit[i][j] = 0;
        }

        for(int i = 0;i < r;i++)
            for(int j = 0;j < c;j++)
                update(i,j,matrix[i][j]);

    }


    void update(int row, int col, int val) {
        int delta = sumRegion(row,col,row,col) - val;
        for(int i = row + 1;i <= r;i+=lowbit(i))
        {
            for(int j = col + 1;j <= c;j += lowbit(j))
                bit[i][j] += delta;
        }
    }

    int getSum(int row,int col)
    {
        int sum = 0;
        for(int i = row;i > 0;i -= lowbit(i))
        {
            for(int j = col;j > 0;j -= lowbit(j))
                sum += bit[i][j];
        }
        return sum;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++,col1++,row2++,col2++;
        return getSum(row2,col2) - getSum(row2,col1 - 1) - getSum(row1 - 1,col2) + getSum(row1 - 1,col1 - 1);
    }
};

int main()
{
    vector<vector<int>> v = {{1}};
    auto obj = new NumMatrix(v);
    obj->update(0,0,-1);
    obj->sumRegion(0,0,0,0);
    return 0;
}
