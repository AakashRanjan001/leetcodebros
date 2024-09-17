
class DiningPhilosophers {
    int arr[5];
    condition_variable cv;
    mutex m;
public:
    DiningPhilosophers() {
        for(int i=0;i<5;i++) arr[i]=0;
    }

    void wantsToEat(int p,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

        unique_lock<mutex> lock(m);
		while(arr[p] != 0 && arr[(p+1)%4] != 0) {
            cv.wait(lock);
        }
        arr[p]=1;
        arr[(p+1)%4] = 1;
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        arr[p]=0;
        arr[(p+1)%4] = 0;
        cv.notify_all();
    }
};