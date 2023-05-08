
#include <iostream>

 
class DataStream {
private:
    int value;
    int k;
    int count = 0;

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if (num == this->value) {
            this->count++;
        } else {
            this->count = 0;
        }

        return this->count == this->k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main(void)
{
    DataStream* dataStream = new DataStream(4, 3);

    bool ret = dataStream->consec(4);
    std::cout << std::boolalpha << ret << std::endl;

    ret = dataStream->consec(4);
    std::cout << std::boolalpha << ret << std::endl;

    ret = dataStream->consec(4);
    std::cout << std::boolalpha << ret << std::endl;

    ret = dataStream->consec(3);
    std::cout << std::boolalpha << ret << std::endl;
}
