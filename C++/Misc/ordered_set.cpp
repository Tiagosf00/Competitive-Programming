#include <bits/extc++.h>
// or
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds; // or pb_ds;
template<typename T, typename B = null_type>
using ordered_set = tree<T, B, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k)  : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from zero)

// to swap two sets, use a.swap(b);