#include <iostream>
using namespace std;

// template <class myType>
// myType GetMax (myType a, myType b) {
//  return (a>b?a:b);
// }

// template <class myType>
// myType GetMin (myType a, myType b) {
//  return (a>b?b:a);
// }

// template <class T,class U>
// T GetMax (T a, U b) {
//   T result;
//   result = (a>b)? a : b;
//   return (result);
// }

// template <class T,class U>
// T GetMin (T a, U b) {
//   T result;
//   result = (a>b)? b : a;
//   return (result);
// }

template <class T,class U,class X>
T GetMax (T a, U b, X c) {
  T result;
  if(a>b && a>c){
    result = a;
  }
  else if(b>a && b>c){
    result = b;
  }
  else if(c>a && c>b){
    result = c;
  }
  return (result);
}

template <class T,class U,class X>
T GetMin (T a, U b, X c) {
  T result;
  if(a<b && a<c){
    result = a;
  }
  else if(b<a && b<c){
    result = b;
  }
  else if(c<a && c<b){
    result = c;
  }
  return (result);
}


// int main()
// {
//     int i = 5, j = 6, k;
//     long l = 10, m = 5, n;
//     k = GetMax(i, j);//the program still works if we <int> and <long>
//     n = GetMin(l, m);
//     cout << k << endl;
//     cout << n << endl;
//     return 0;
// }
int main () {
  char i='Z';
  int j=6, k;
  long l=10, m=5, n;
  k=GetMax(i,m,j);//the functions are running without any problem
  n=GetMin(j,l,m);
  cout << k << endl;
  cout << n << endl;
  system("pause");
  return 0;
}