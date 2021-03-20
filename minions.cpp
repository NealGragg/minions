#include <iostream>
#include <thread>
#include <vector>

void minion(int m) {
  std::cout<<"Hello! I am minion "<<m<<".\n";
}

void overlord() {
  std::cout<<"Hello Minions! I am the Overlord!\n";
}

int main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }

  std::vector<std::thread> minionthreads;

  int numOfMinions = atoi(argv[1]);

  for(int i = 1; i <= numOfMinions; ++i) {
    std::thread minionthread(minion, i);

    minionthreads.push_back(std::move(minionthread));
  }

  for(auto & t : minionthreads) {
    if(t.joinable())
      t.join();
    else
      std::cout<<"t is not joinable\n";
  }
  std::thread overthread(overlord);

  overthread.join();
  
  return 0;
}
