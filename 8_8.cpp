#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Customer {
    int arrivalTime;
    Customer(int time) : arrivalTime(time) {}
};

void carwashSimulation(int simulationTime, int washTime, double arrivalProbability) {
    queue<int> customerQueue;
    int totalWaitTime = 0, customersServed = 0;

    srand(time(nullptr));

    for (int currentTime = 0; currentTime < simulationTime; ++currentTime) {
        double randomValue = static_cast<double>(rand()) / RAND_MAX; 
        if (randomValue < arrivalProbability) {
            customerQueue.push(currentTime);
        }

        if (!customerQueue.empty() && currentTime % washTime == 0) {
            totalWaitTime += currentTime - customerQueue.front();
            customerQueue.pop();
            customersServed++;
        }
    }

    // Change to the code 
    int currentTime = simulationTime;
    while (!customerQueue.empty()) {
        totalWaitTime += currentTime - customerQueue.front();
        customerQueue.pop();
        customersServed++;
        currentTime += washTime;
    }

    cout << "Total customers served: " << customersServed << endl;
    cout << "Average wait time: " << (customersServed > 0 ? (double)totalWaitTime / customersServed : 0) << " minutes" << endl;
}
