#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class validornot 
{
  bool check(vector<vector<char> >& b) {
  	unordered_map<int, int> c[9];
    unordered_map<int, int> g[9];
    unordered_map<int, int> r[9];
    for (int i = 0; i < b.size(); i ++)
    {
      for (int j = 0; j < b[i].size(); j ++)
      {
			if(b[i][j] != '.')
			{
	 			r[i][b[i][j]] ++;
	 			if(r[i][b[i][j]] > 1)
	  			{
	    			return false;
	  			}
			    c[j][b[i][j]] ++;
	  			if (c[j][b[i][j]] > 1)
	  			{
	    			return false;
	  			}
	  			int p = i/3 * 3 + j/3;
	  			g[p][b[i][j]] ++;
	  			if (g[p][b[i][j]] > 1)
	  			{
	    			return false;
	  			}
			}
      	}
    }
    return true;
  }
};

int main(int argc, char **argv)
{
	//all blanks are taken as '.'
  char arr1[9],arr2[9],arr3[9],arr4[9],arr5[9],arr6[9],arr7[9],arr8[9],arr9[9];
  cout<<"Enter line 1"<<endl;
  cin>>arr1;
  cout<<"Enter line 2"<<endl;
  cin>>arr2;
  cout<<"Enter line 3"<<endl;
  cin>>arr3;
  cout<<"Enter line 4"<<endl;
  cin>>arr4;
  cout<<"Enter line 5"<<endl;
  cin>>arr5;
  cout<<"Enter line 6"<<endl;
  cin>>arr6;
  cout<<"Enter line 7"<<endl;
  cin>>arr7;
  cout<<"Enter line 8"<<endl;
  cin>>arr8;
  cout<<"Enter line 9"<<endl;
  cin>>arr9;
  vector<char> vec1(arr1 + 0, arr1 + 9);
  vector<char> vec2(arr2 + 0, arr2 + 9);
  vector<char> vec3(arr3 + 0, arr3 + 9);
  vector<char> vec4(arr4 + 0, arr4 + 9);
  vector<char> vec5(arr5 + 0, arr5 + 9);
  vector<char> vec6(arr6 + 0, arr6 + 9);
  vector<char> vec7(arr7 + 0, arr7 + 9);
  vector<char> vec8(arr8 + 0, arr8 + 9);
  vector<char> vec9(arr9 + 0, arr9 + 9);
  
  vector<vector<char> > vec;
  vec.push_back(vec1);
  vec.push_back(vec2);
  vec.push_back(vec3);
  vec.push_back(vec4);
  vec.push_back(vec5);
  vec.push_back(vec6);
  vec.push_back(vec7);
  vec.push_back(vec8);
  vec.push_back(vec9);

  validornot s;
  cout<<s.check(vec)<< endl;
}