#include <iostream>
#include <stdexcept>
using namespace std;


void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


//c++ exercise: template-ify this and make its comparator generic!
class MinHeap {
    public:

        int getMin(){
            if (heapSize <= 0){
                throw new invalid_argument("there are no elements in the heap");
            }
            return heapStorage[0];
        }

        //insert key is basically just decreaseKey with some extra book keeping
        void insertKey(int value){
            if (heapSize >= maxSize){
                //todo: sizing strategies
                cout << "Overflow: heap is not dynamically sizable." << "\n";
            }

            heapSize++;
            decreaseKey(value);
        }

        // Removes a key by placing INT_MIN over a specific location
        // we then decrease this key which should bubble to the top of the
        // heap and then call extractMin to remove it and re-heapify
        void deleteKey(int i){
            if (i < 0 || i > heapSize){
                throw invalid_argument("bad position");
            }

            //todo test me, write a anki card about this operation
            //overwrite the root the bottom of the heap
            heapStorage[i] = heapStorage[heapSize-1];
            heapSize--;
            minHeapify(i); //re heap
        }

        //extraMin
        int extractMin() {
            if (heapSize <= 0){
                throw invalid_argument("heap is empty");
            }

            if (heapSize == 1){
                heapSize--;
                return heapStorage[0];
            }

            //return the root
            int root = heapStorage[0];

            //overwrite the root the bottom of the heap
            heapStorage[0] = heapStorage[heapSize-1];
            heapSize--;
            minHeapify(0); //re heap
            return root;
        }

        //getMin

        MinHeap(int size){
            maxSize = size;
            heapSize = 0;
            heapStorage = new int[size];
        }

    private:
        int *heapStorage;
        int heapSize;
        int maxSize;

        //logn
        void decreaseKey(int value){
            int pos = heapSize - 1;
            heapStorage[pos] = value;
            while(pos != 0 && heapStorage[parent(pos)] > heapStorage[pos]){
                swap(&heapStorage[pos], &heapStorage[parent(pos)]);
                pos = parent(pos);
            }
        }

        void minHeapify(int position){
            int leftPos = left(position);
            int rightPos = right(position);
            int smallest = position;

            //check to see if children are smaller than our current position (we're not proper)
            if (leftPos < heapSize && heapStorage[leftPos] < heapStorage[smallest]){
                smallest = leftPos;
            }

            if (rightPos < heapSize && heapStorage[rightPos] < heapStorage[smallest]){
                smallest = rightPos;
            }

            //there was a move continue to the tree we moved
            if (smallest != position){
                swap(&heapStorage[position], &heapStorage[smallest]);
                minHeapify(smallest);
            }
        }

        int parent(int i) {
            return (i-1) / 2;
        }

        int left(int i) {
            return 2*i + 1;
        }

        int right(int i) {
            return 2*i + 2;
        }
};


int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	cout << h.getMin();
	return 0;
}
