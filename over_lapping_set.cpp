#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class over_lapping_set
{
public:
    vector<int> overlappingvalues(vector<int>&s1, vector<int>&s2)
    {
        vector<int>vs;
        int count =0 ;
        if(s1.size() > s2.size())
        {
            sort(s1.begin(), s1.end());
        }
        else
        {
            sort(s2.begin(), s2.end());
        }
        if(is_sorted(s1.begin(),s1.end()))
        {
            for(auto itr : s2)
            {
                if(binary_search(s1.begin(),s1.end(), itr))
                {
                    count++;
                }

            }
                for(auto itr : s2)
            {
                if(binary_search(s1.begin(),s1.end(), itr))
                {
                    vs.push_back(itr);
                }

            }
                vs.resize(count);
        }
        else
        {
            for(auto itr : s1)
            {
                if(binary_search(s2.begin(),s2.end(), itr))
                {
                    count++;
                }
            }
            for(auto itr : s1)
            {
                if(binary_search(s2.begin(),s2.end(), itr))
                {
                    vs.push_back(itr);
                }
            }
            vs.resize(count);
        }

        return vs;
    }    
};


vector<int> init(int range);
void print(vector<int>);
int main()
{
    srand(time(0));
    int s1size, s2size;
    vector<int>s1;
    vector<int>s2;
    cout <<"enter set one size: ";
    cin >> s1size;
    cout << "enter set 2 size: ";
    cin >>s2size;
    s1= init(s1size);
    s2 = init(s2size);
    print(s1);
    print(s2);
    over_lapping_set sets;
    auto inter_section = sets.overlappingvalues(s1,s2);
    print(inter_section);
}

vector<int> init( int range)
{
    set<int>sets;
    int i=0;
    while( i<range)
    {
        sets.insert(rand()%range+1);
        i++;
    }
    vector<int>vals(sets.begin(),sets.end());
    return vals;
}

void print(vector<int> s)
{
    cout<<"{";
    for(vector<int>::iterator itr =s.begin(); itr!=s.end(); itr++)
    {
        cout << *itr<<",";
    }
    cout <<"} \n";
}



