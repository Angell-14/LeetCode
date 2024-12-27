#include <queue>
#include <vector>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the k largest elements
    int k; // The value of k

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num); // Initialize the heap with the given numbers
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val); // Add directly if the heap has fewer than k elements
        } else if (val > minHeap.top()) {
            minHeap.pop();     // Remove the smallest element
            minHeap.push(val); // Add the new value
        }
        return minHeap.top();  // The root of the heap is the kth largest element
    }
};


/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */