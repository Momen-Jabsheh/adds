#include <string>
#include<vector>
#include <cinttypes>
#include<algorithm>
#include <cctype>
#include<cmath>
#include<iostream>
#include <limits.h>
#include <array> 
using namespace std ;
string string_repeat(string str , int repeat_count)
{
  string result ;
  for (int i = 0 ; i < repeat_count ; i++)
    result += str +' ' ;
  result.pop_back() ;
  return result ;
}
///////////////////////////////////////////////////////////////////
string zfill (string str , int zcount , char ch)
{
  string result ;
  if (zcount - str.size() > 0)
  {
  for(int i = 0 ; i < zcount - str.size() ; i++)
  result += ch;
 }
 return result + str ;
}
string zfill (int x , int zcount)
{ string str =  to_string(x) ;
 string result ;
  if (zcount - str.size() > 0)
  {
  for(int i = 0 ; i < zcount - str.size() ; i++)
  result += '0';
}
result += str ;
return (result) ;
}
///////////////////// i want to save it
uint64_t descendingOrder(uint64_t a)
{
  string x = to_string(a) ;
  sort(x.begin() , x.end()) ;
  reverse(x.begin() , x.end()) ;
  return stoull(x) ;
}
//////////////////////////////////////////////////////////////////////
string string_reverse(string str)
{
  string result ;
  for(int i = str.length() -1 ; i >= 0; i--)
      result += str[i];
  return result ;
}
//////////////////////////////////////////////////////////////////////
string Generate_Range_Of_Letters(char start , char end)
{
  string result ;
  for(int i = start ; i <= int(end) ; i++)
      {result += char(i)  ;
      result += ' ' ;}  
  return result ;
}
//////////////////////////////////////////////////////////////////////
int get_min_num(  vector <int> nums)
{
  sort(nums.begin() , nums.end()) ;
  return nums[0];
}
//////////////////////////////////////////////////////////////////////
int get_max_num(vector<int> nums)
{
  sort(nums.begin() , nums.end()) ;
  return nums.back();
}
//////////////////////////////////////////////////////////////////////
int get_sum_of_num(vector<int> nums , char op = '+')
{
  int result = nums[0] ;
  for (int i = 1 ; i < nums.size() ; i++)
    result = op == '+' ? result + nums[i] : op == '-' ? result - nums[i] : op == '*' ? result * nums[i] : result / nums[i] ;
  return result ;
}
int get_sum_of_num_except_div(vector<int> nums , char op = '+')
{
  int result = op == '*' ? 1 : 0 ;
  if (op == '-') nums[0] *= -1 ; ;
  for(int num : nums)
  {
    switch (op)
    {
     case '+' : result += num ; break ;
     case '-' : result -= num ; break ;
     case '*' : result *= num ; break ;
    }
  }
  return result ;
}
//////////////////////////////////////////////////////////////////////
string lower_to_upper(string str)
{
  string result ;
  for(char ch : str)
     result += toupper(ch) ;
  return result ;
}
string upper_to_lower (string str)
{
  string result ;
  for(char ch : str)
     result += tolower(ch) ;
  return result ;
}
string swap_lower_upper(string str) 
{
  string result ;
  for(char ch : str)
    result += isupper(ch) ? tolower(ch) : toupper(ch) ;
    return result ;
}
//////////////////////////////////////////////////////////////////////
int Parse_Integer(string str)
{
  string result ;
  for(char ch : str)
   if (isdigit(ch)) result += ch ;
  return stoi(result) ;
}
//////////////////////////////////////////////////////////////////////
bool isNaN(string str)
{
  for(char ch : str)
    if(!isdigit(ch)) return false ;
  return true ;
}
//////////////////////////////////////////////////////////////////////
string Trim_String (string str , char op , string direction = "all")
{
  if(direction == "all")
  {
    string result ;
   for(char ch : str)
   if(ch != op)result += ch ;
   return result ;
  }
  else if (direction == "right")
  {
    while(true)
   {
    if (str.back() == op)
         str.pop_back();
    else
         break ;
   }
   return str ;
  }
  else
  {
    reverse(str.begin() , str.end()) ;
    while(true)
   {
    if (str.back() == op)
         str.pop_back();
    else
         break ;
   }
   reverse(str.begin() , str.end()) ;
   return str ;
  }
}
//////////////////////////////////////////////////////////////////////
string substring(string str , int start , int end , bool include_end = true , bool count_space = true)
{
  string result ;
  for(int i = start ; include_end ? i <= end : i < end ; i++)
     {result += str[i] ;
     if(count_space == false)
      if (isspace(str[i])) end ++ ;
     }
  return result ;
}
//////////////////////////////////////////////////////////////////////
string clean_string(string st, bool keepnums = true)
{
  string result ;
  for(char c : st)
  {
     if (c >= 'A' && c <= 'Z')
      result += c;
    else if (c >= 'a' && c <= 'z')
      result += c;
    else if (keepnums == true && isdigit(c))
     result += c ;
    else if (c == '_')
      result += c;
  }
  return result ;
}
//////////////////////////////////////////////////////////////////////
class person
{
   public :
     string first_name_oop ;
     string last_name_oop ;
   void print_full_name()
   {
    cout << first_name_oop << ' ' << last_name_oop <<endl ;
   }   
};
struct student
{
  int age ;
  string name ;
  int id ;
};
class rectangle{
  private :
     float heigth  ; // make a defoult value
     float width  ;
  public :
  rectangle (float w , float h) : heigth(0) , width(0)
  {}
   float get_heigth()
  {
    return heigth ;
  }
  void set_heigth(float x)
  {
     heigth = x;
  }
  void set_width(float x)
  {
   width = x ;
  }
  float get_width()
  {
    return width ;
  }
  float get_area() ;
} ;
float rectangle:: get_area()
{
   return heigth * width ;
}
class youtube_chanle {
  public :
  string name ;
  string owner_name ;
  int subs_count ;
  youtube_chanle(): subs_count(0) 
  {
    cout << "\n" ;
  }
  void get_info() {
       cout << "name : " << name << endl;
       cout << "owner name  : " << owner_name << endl;
       cout << "subs count  : " << subs_count << endl;
  }
};
//////////////////////////////////////////////////////////////////////
string parse_string(string st)
{
  string result ;
  for(int i = 0 ; i < st.length() ;  i++)
  {
    if (st[i] != '&' && st[i] != '=')
      result += st[i] ;
    else if (st[i] == '=')
    result += " : " ;
    else
    result += "\n" ;
  }
  return result ;
}
////////////////////////////////////////////////////////////////////////
int Words_Count(string st, char sep = ' ')
{
  int count = 0;
  bool inWord = false;
  for (int i = 0; i < st.length(); i++)
  {
    if (st[i] == sep)
    {if (inWord)
      {
        ++count;
        inWord = false; 
      }}
    else
      inWord = true; 
  }
  if (inWord)
    ++count;
  return count;
}
////////////////////////////////////////////////////////////////////////
bool firstCapital(string st)
{  if (islower(st[0]) ) return false ;
  for(int i =0 ; i < st.length() ; i++ )
     {
       if (islower(st[i]))if (st[i-1] == ' ')return false ;
     }
     return true ;
}
////////////////////////////////////////////////////////////////////////
bool in_array(vector<int> v , int x)
{
  for(auto ch : v)
    if(ch == x) return true ;
  return false ;
}
/////////////////////////////////////////////////////////////////////////
int floor_mmm(float x)
  { return x ;}
int ceil_mmm(float x)
{  return x + 1 ;}
int round_mmm(float x)
{
  if (x <= floor(x))
     return floor(x) ;
  else if (x >= ceil(x))
    return ceil(x) ;
  else
  return x ;
}
////////////////////////////////////////////////////////////////////////
string Join_Elements(vector<string> x , char bar = ',')
{
  string result ;
  for(auto ch : x)
  {
    result += ch ;
    result += ' ' ;
    result += bar ;
  }
  if (result.back() == bar)
  result.pop_back() ;
  return result ;
}
///////////////////////////////////////////////////////////////////////
vector <string> Fill_Container(int count , string x)
{
 vector <string> result ;
 for (int i = 0 ; i < count ; i++ )
  result.push_back(x) ;
  return result ; 
}
/////////////////////////////////////////////////////////////////////////
vector <int> Create_Range(int start , int end , bool end_is_include = true)
{
  vector <int> result ;
  for(int i = start ; (end_is_include == true ? i <= end : i < end) ; i++)
   result.push_back(i) ;
  return result ;
}
/////////////////////////////////////////////////////////////////////////
string String_Slice(string str , int start , int end , bool end_is_include = false)
{
  string result;
  for(int i = start ; (end_is_include == true ? i <= end : i < end) ; i++ )
    result += str[i] ;
  return result ;
}
/////////////////////////////////////////////////////////////////////////
bool  String_Starts_With(string word , string the_start)
{
  for(int i = 0 ; i < the_start.length() ; i++)
    if (word[i] != the_start[i])
           return false ;
  return true ;
}
///////////////////////////////////////////////////////////////////////////
string money_formate(int m)
{
  string temp = to_string(m) ;
  reverse(temp.begin() , temp.end()) ;
  string result ;
  for(int i = 0 ; i < temp.length() ; i++)
  {
    result += temp[i] ;
    if ((i+1 )% 3 == 0)
     result += "," ;
  }
  if (result.back() == ',')
  result.pop_back() ;
   reverse(result.begin() , result.end()) ;
   return result ;
}
/////////////////////////////////////////////////////////////////////////
vector <string> Replace_String_In_Vector (vector <string> vec , string st , string reb)
{
  vector <string> result ; 
  for(auto ch : vec)
  {
    result.push_back(ch ==  st ? reb : ch) ;
  }
  return result ;
}
//////////////////////////////////////////////////////////////////////////
string Generate_Characters(bool caps = true , bool sm_l = false , bool nums = false)
{
  string result ;
  if (caps == true)
    {
      for (int i = 'A' ; i <= 'Z' ; i++)
       result.push_back(char(i)) ;
    }
    if (sm_l == true)
    {
      for (int i = 'a' ; i <= 'z' ; i++)
       result.push_back(char(i)) ;
    }
    if (nums == true)
    {
      for (int i = '0' ; i <= '9' ; i++)
       result.push_back(char(i)) ;
    }
    return result ;
}
int digital_root(int Z) {
    return --Z % 9 + 1;
}
int first_xor (bool a , bool b){
  return a^b ;
}
////////////////////////////////
string autoMorphic(int n)
{
  string x = to_string(n) ;
  string y = to_string(n*n) ;
  reverse(x.begin() , x.end()) ;
  reverse(y.begin() , y.end()) ;
  for (int i = 0 ; i < x.length() ; i++)
    {
    if (x[i] != y[i])   return "Not!!" ;
  }
  return "Automorphic" ;
}
///////////////////////////////////////////
void test (int x , bool y)
{
  if ( y == true) {
   for(int i = 0 ; i < x ; i++)
      cout << i << endl ; 
  }
  else {
   for(int i = 0 ; i < x ; i++)
   {
    int z ;
    cout << z << endl ; 
   }
      
  }
}
