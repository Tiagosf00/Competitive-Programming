#warning colocar primos ate n nesse vetor
vector<int> primes;
template <class T>
void forward_multiple_transform(std::vector<T>& a) {
    const int n = (int)a.size() - 1;
    for (const auto p : primes) {
        if (p > n) break;
        for (int i = n / p; i > 0; --i) a[i] += a[i * p];
    }
}

template <class T>
void backward_multiple_transform(std::vector<T>& a) {
    const int n = (int)a.size() - 1;
    for (const auto p : primes) {
        if (p > n) break;
        for (int i = 1; i * p <= n; ++i) a[i] -= a[i * p];
    }
}

template <class T>
std::vector<T> gcd_convolution(const std::vector<T>& a,
                               const std::vector<T>& b) {
    assert(a.size() == b.size());
    int n = (int)a.size();
    auto A = a;
    auto B = b;
    forward_multiple_transform(A);  // A[i] = sum a[d * i]
    forward_multiple_transform(B);  // B[i] = sum b[d * i]
    for (int i = 0; i < n; ++i) A[i] *= B[i];
    // A[i] = sum_{gcd(d, e) = 1} a[d * i] b[e * i]
    backward_multiple_transform(A);
    return A;
}
