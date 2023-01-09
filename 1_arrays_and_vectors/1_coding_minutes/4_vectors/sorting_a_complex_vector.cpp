#include<bits/stdc++.h>
using namespace std;
int calculatemarks(vector<int> marks)
{
    return marks[0] + marks[1] + marks[2];
}
bool cmp(pair<string, vector<int> > s1, pair<string, vector<int> > s2)
{
vector<int> v1, v2;
v1=s1.second;
v2=s2.second;
return calculatemarks(v1)>calculatemarks(v2);
}

int main()
{
    vector<pair<string, vector<int> >>student_marks={
        {"Rohan",{10,20,11}},
        {"Prateek",{10,21,3}},
        {"Vivek",{4,5,6}},
        {"Rijual",{10,13,20}}
    };

    sort(student_marks.begin(), student_marks.end(),cmp);
    for(auto s : student_marks) {
        cout<<s.first<<" total_marks "<<calculatemarks(s.second)<<endl;
    }
    return 0;
}