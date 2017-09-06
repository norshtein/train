#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
    int value;
    int num;
    double ratio;
};

void input(vector<Point>* points);
void init();
double calculateExpectation(vector<Point>& points, const int total, const int min);

double C[2000][2000];

int main()
{
    init();

    int total = 0;
    cin >> total;
    int mmin = 0;
    cin >> mmin;

    vector<Point> points;
    input(&points);

    double res = calculateExpectation(points, total, mmin);
    cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;
    return 0;
}

void input(vector<Point>* points)
{
    int n = 0;
    cin >> n;
    points->resize(n);

    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        Point& point = (*points)[i];
        cin >> point.value;
        cin >> point.num;
        sum += point.num;
    }

    for (int i = 0; i < n; ++i)
    {
        Point& point = (*points)[i];
        point.ratio = point.num / sum;
    }
}

double calculateExpectation(vector<Point>& points, const int total, const int mmin)
{
    sort(points.begin(),points.end(),[](const Point& p1,const Point& p2){
            return p1.value < p2.value;
        });
    vector<double> prefixSum(points.size());
    for(int i = 0;i < prefixSum.size();i++)
    {
        prefixSum[i] = points[i].ratio;
        prefixSum[i] += i ? prefixSum[i - 1] : 0;
    }

    double answer = 0;
    double pre = 0;
    for(int i = 0;i < points.size();i++)
    {
        /*
        cout << C[total][mmin - 1] * pow(prefixSum[i],mmin - 1) << endl;
        cout << points[i].ratio << endl;
        cout << pow(1.0 - (i ? prefixSum[i - 1] : 0),total -mmin) << endl;*/
        double rateLessThanOrEqualTo = ((i == points.size() - 1 )? 1.0 : C[total][mmin] * pow(prefixSum[i],mmin) * pow(1.0 - prefixSum[i] ,total -mmin));
        answer +=  (rateLessThanOrEqualTo - pre) * points[i].value;

        cout << pre << ' ' << rateLessThanOrEqualTo << endl;
        pre = rateLessThanOrEqualTo;
    }
    return answer;
}

void init()
{
    for(int i = 0;i < 2000;i++)
        C[i][0] = C[i][i] = 1;
    for(int i = 1;i < 2000;i++)
        for(int j = 1;j < i;j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
}
