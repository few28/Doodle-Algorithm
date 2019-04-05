#include <iostream>
#include <cstring> //memset을 사용하기위해
#include <string>

using namespace std;
// 배열
int d[51][51][51][3][3];

int go(int a, int b, int c, int p1, int p2){
    
    int &ans = d[a][b][c][p1][p2];

    if(a+b+c==0) return ans = 1;
    if(ans != -1) return ans;
    if(a>0 && go(a-1, b, c, 0, p1)==1){
        return ans =1;
    }
    if(b>0 && p1 != 1){
        if(go(a, b-1, c, 1, p1)==1)
            return ans = 1;
    }
    if(c>0 && p1 !=2 && p2!=2){
        if(go(a, b, c-1, 2, p1)==1)
            return ans =1;
    }
    
    return ans = 0; 
}

string printString(int a, int b, int c, int p1, int p2){
    if(a+b+c ==0)
        return "";

     if(a>0 && go(a-1, b, c, 0, p1)==1){
        return "A" + printString(a-1, b, c, 0, p1);
    }
    if(b>0 && p1 != 1){
        if(go(a, b-1, c, 1, p1)==1)
            return "B" + printString(a, b-1, c, 1, p1);
    }
    if(c>0 && p1 !=2 && p2!=2){
        if(go(a, b, c-1, 2, p1)==1)
            return  "C" + printString(a, b, c-1, 2, p1);
    }
    
    return "";
    
}


int main(){
    string s;
    cin >> s;

    int n = s.length();

    // a, b, c의 개수를 나타낼 배열
    int cnt[3] = {0,0,0};

    // d배열 초기화
    memset(d, -1, sizeof(d));

    // A, B, C의 갯수를 count
    for(int i = 0; i < n; i++){
        cnt[s[i]-'A'] += 1;
    }

    int ans = go(cnt[0], cnt[1], cnt[2], 0 , 0);
    if(ans==0)
        cout << -1 << '\n';
    else{
        cout << printString(cnt[0], cnt[1], cnt[2], 0 , 0) << '\n';
    }
    return 0;
}