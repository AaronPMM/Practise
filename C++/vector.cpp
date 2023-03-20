//
// Created by 78157 on 2022/10/31.
//
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    vector<int> vi;  //create a zero-size array of int
    int n;

    for(n = 0; n < 10; n++){
        vi.push_back(n);
        cout << vi[n] << ",";
    }

    for(n = 0; n < 5; n++){
        vi.pop_back();
    }

    cout << "\n" << endl;

    for(n = 0; n < vi.size(); n++){
        cout << vi[n] << ",";
    }

    return 0;


}