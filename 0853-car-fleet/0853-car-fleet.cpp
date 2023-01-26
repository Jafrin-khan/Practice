
    /*************  YOUTUBE EXPLANATION***********/
/*
    https://www.youtube.com/watch?v=Pr6T-3yB9RM
    */
    
    
    /*
    Solution: O(NlogN +N) Time, Sort + Mono Stack
Let's look at some examples first.

Ex:
Target: 12
Pos:  [10,8,0,5,3]
Speed:[ 2,4,1,1,3]
First we sort the cars by there position.

Ex:
Target: 12
Pos:  [0,3,5,8,10]
Speed:[1,3,1,4, 2]
Then we calculate the time it need to reach target

Ex:
Target: 12
Pos:  [0, 3, 5, 8,10]
Speed:[1, 3, 1, 4, 2]
Time: [12,3, 7, 1, 1]
How to calculate the time?
Easy, (target-pos)/speed

Alright, I think the previous procedure is sort of intuitive if we want to observe the pattern of the problem.

Now let's observe the pattern of time.

For car 0, it is really slow, it takes 12s to reach target. Thus it is itself a fleet.
For car 3, it is fast, but it will be blocked by car 5.
For car 8, it is fast, but it will be blocked by car 10.
When does the fleet occur?

When one car is blocked by the next car.
Car 0, 5, 10 are the ones who block the previous.
And it is actually a monotonic decreasing stack! Why?

From the perspective of numbers:
Let's pick up 0, 5, 10 and there time needed: [12,7,1]
12,7,1 is monotonic decreasing
From the perspective of reasoning:
If a car is slower then previous, all the previous faster car will bump into this car and become a fleet.
Ex:
Time [1,2,3,5] ==> [5]
5 is too slow, that 1,2,3 bump into 5
Time [1,2,3,5,3,4] ==> [5,4]
5 is too slow, and 4 is slow too.
123 bump into 5, 3 bump into 4.
4 is still faster than 5. Thus they won't bump together.
Time [1,2,3,5,3,4,8] ==> [8]
8 is really too slow all the previous bump into it.
Finally, the answer will be the size of the stack.

Since the stack is recording the cars that is blocking others. Which causes a fleet.
class Car{
public:
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    int pos;
    int speed;
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int N = position.size();
        for(int i = 0; i<N; i++){
            cars.emplace_back(position.at(i), speed.at(i));
        }
        
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });
        
        stack<float> mono;
        for(int i = 0; i<N; i++){
            float time = 
                (target-cars.at(i).pos)/(float)cars.at(i).speed;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();
    }
};
    */
        
class Car{
public:
    int pos;
    int speed;
    Car(int pos, int speed){
        this->pos = pos;
        this->speed= speed;
    }
    
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        int N = position.size();
        for(int i = 0; i<N; i++){
            cars.emplace_back(position.at(i), speed.at(i));
        }
        
        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.pos<b.pos;
        });
        
        stack<float> mono;
        for(int i = 0; i<N; i++){
            float time = 
                (target-cars.at(i).pos)/(float)cars.at(i).speed;
            while(!mono.empty() && time >= mono.top()){
                mono.pop();
            }
            mono.push(time);
        }
        return mono.size();
    }
};