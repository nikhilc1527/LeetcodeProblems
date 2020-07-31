#include <vector>
#include <stack>

class DinnerPlates {
private:
  int capacity;
  int i;
  std::vector<std::stack<int>> stacks;
  
public:
  
  DinnerPlates(int capacity)
    : capacity(capacity), i(0) {
    
  }
    
  void push(int val) {
    stacks.push_back(std::stack<int>());
    stacks[i].push(val);
  }
    
  int pop() {
    int res = stacks[i].top();
    if (stacks[i].size() == 1) {
      i--;
      stacks.pop_back();
    }
    else stacks[i].pop();
    return res;
  }
    
  int popAtStack(int index) {
    int res = stacks[index].top();
    if (stacks[index].size() == 0) {
      return -1;
    }
    else return res;
  }
};

int main() {
  DinnerPlates* obj = new DinnerPlates(2);
  obj->push(val);
  int param_2 = obj->pop();
  int param_3 = obj->popAtStack(index);
}
