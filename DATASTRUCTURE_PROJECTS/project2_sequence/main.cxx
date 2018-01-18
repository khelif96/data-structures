#include <iostream>
#include "sequence2.h"
using namespace std;
using namespace main_savitch_4;

int main(){
  sequence t(10);
  for(int i = 0; i<10; i++)
    t.attach(i);
  t.resize(30);
  for(int i = 11; i < 21; i++)
    t.attach(i);
  cout << "size : " << t.size() << endl;

  cout << t.current() << " : current | is_item : " << t.is_item() << endl;

}
