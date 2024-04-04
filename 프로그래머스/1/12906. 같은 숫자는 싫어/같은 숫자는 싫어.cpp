#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=arr[i+1])answer.push_back(arr[i+1]);
    }if(arr.back()!=0)answer.pop_back();
    return answer;
}