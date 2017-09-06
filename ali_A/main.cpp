#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

struct Transport{
    void* buf;
    int length;
};

bool operator<(const Transport& t1,const Transport& t2)
{
    return t1.length < t2.length;
}

int main()
{
    int boatNum,carNum;
    long long totalBoatLength = 0,totalCarLength = 0;
    Transport *boat = nullptr;
    Transport *car = nullptr;

    cin >> boatNum;
    boat = new Transport[boatNum];

    int capacity;
    for(int i = 0;i < boatNum;i++)
    {
        cin >> capacity;
        if(capacity <= 0) //invaild value
        {
            i--;
            continue;
        }
        boat[i].length = capacity;
        totalBoatLength += capacity;
    }

    while(cin >> carNum && carNum == 0)
        continue;
    car = new Transport[carNum];

    for(int i = 0;i < carNum;i++)
    {
        cin >> capacity;
        if(capacity <= 0)
        {
            i--;
            continue;
        }
        car[i].length = capacity;
        totalCarLength += capacity;
    }

    if(totalBoatLength <= totalCarLength)
        puts("1");
    else
        puts("0");

/*
    有些不理解题意...
    //sort in length increasing order
    sort(boat,boat + boatNum);
    sort(car,car + carNum);

    //all goods should be put properly
    int carCursor = 0;
    bool vaild = true;
    for(int i = 0;i < boatNum;i++)
    {
        while(carCursor < carNum && car[carCursor].length < boat[i].length)
            carCursor++;
        if(carCursor >= carNum)
        {
            vaild = false;
            break;
        }
        carCursor++;
    }

    if(vaild)
        puts("1");
    else
        puts("0");
*/


    return 0;
}
