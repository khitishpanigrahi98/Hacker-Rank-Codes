#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the permutationEquation function below.
struct body
{
    int data;
    int index;
};
bool comp(body b1,body b2)
{
    return b1.data<b2.data;
}
vector<int> permutationEquation(vector<int> p) 
{
body b[p.size()+1];
int i,j,count=0,x=0,y=0;
vector<int> v;
for(i=1;i<=p.size();i++)
{
    b[i].data=p[i-1];
    b[i].index=i;
    //cout<<" data "<<b[i].data<<" index "<< b[i].index<<endl;
}
int a=p.size()+1;
sort(b+1,b+a,comp);
for(i=1;i<=p.size();i++)
{
   x=b[i].index;
   int y=1,h=1;
   while(y!=x)
   {
       y=b[h].data;
       if(y==x)break;
       h++;
   }
   y=b[h].index;
   v.push_back(y);
   //cout<<" pair "<<b[i].data<<"ind"<< x<<" ans "<<y<<endl;
  
}

return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        int p_item = stoi(p_temp[i]);

        p[i] = p_item;
    }

    vector<int> result = permutationEquation(p);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
