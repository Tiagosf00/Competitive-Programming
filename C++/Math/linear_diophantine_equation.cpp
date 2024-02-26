// Linear Diophantine Equation
array<ll, 3> exgcd(int a, int b) {
    if (a == 0) return {0, 1, b};
    auto [x, y, g] = exgcd(b % a, a);
    return {y - b / a * x , x, g};
}

array<ll, 4> find_any_solution(ll a, ll b, ll c) {
    auto[x, y, g] = exgcd(a, b);
    if (c % g) return {false, 0, 0, 0};
    x *= c / g;
    y *= c / g;
    return {true, x, y, g};
}

//  All solutions
//  x' = x + k*b/g
//  y' = y - k*a/g
