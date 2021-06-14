#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
class jisuanqi
{
    private:
    int a,b;
    int index;
    int used;
    int ans;
    protected:
    char fuhao[4] = {'+','-','*','/'};
    int len = 4;
    static int add(int a,int b)
    {
        return a+b;
    }
    static int sub(int a,int b)
    {
        return a-b;
    }
    static int mul(int a,int b)
    {
        return a*b;
    }
    static int div(int a,int b)
    {
        if (b==0) return -1;
        else return a/b;
    }
    int (*fun_array [4])(int,int) = {add,sub,mul,div};
    public:
    int operator()(string s)
    {
        for (int i=0;i<=len;i++)
        if ((index = s.find(fuhao[i])) != string::npos)
        {
            a=stoi(s.substr(0,index));b = stoi(s.substr(index+1,s.size()));
            for (int j=0;j<=len;j++)
            {
                if (s[index] == fuhao[j])
                {
                    used = j;
                    break;
                }
            }
        }
        cerr << "bad input" << endl;
        exit(1);
        ans = fun_array[used](a,b);
        if (ans == -1)
        {
            cerr << "can't div 0" << endl;
            exit(1);
        }
    }
};
jisuanqi mainuse;
int main()
{
    string input;
    getline(cin, input);
    mainuse(input);
}