#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;
        Difference(vector<int> v) 
        { 
            elements = v; 
        }
        void computeDifference() 
        {
            sort(elements.begin(), elements.end());
          maximumDifference = elements[elements.size() - 1] - elements[0];
          if (maximumDifference < 0)
            maximumDifference = -1 * (maximumDifference);
        }
        // Add your code here

}; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
