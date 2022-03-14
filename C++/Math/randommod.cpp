int randommod() {
    auto primo = [](int num) {
        for(int i = 2; i*i <= num; i++) {
            if(num%i == 0) return false;
        }
        return true;
    };
    uniform_int_distribution<int> distribution(1000000007, 1500000000);
    int num = distribution(rng);
    while(!primo(num)) num++;
    return num;
}
