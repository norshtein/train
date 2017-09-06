
void mincut(const string& str, const set<string>& dict)
{
    int dp[str.size() + 5][str.size() + 5];
    for(int )
}


int main(int argc, const char * argv[])
{
    string strS;
    string dictStr;
    int nDict;
    set<string> dict;

    cin>>strS;
    cin>>nDict;
    for (int i = 0; i < nDict; i++)
    {
        cin>>dictStr;
        dict.insert(dictStr);
    }
    mincut(strS, dict);

    return 0;
}
