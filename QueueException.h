#include <iostream>

using namespace std;

class QueueException{
public:
  QueueException(const string& err): errMsg(err){}
  string getError() {return errMsg;}
private:
  string errMsg;
};
