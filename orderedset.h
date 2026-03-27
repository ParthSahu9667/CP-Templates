#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// do less_equal<T> to use it as multiset
template<typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

//erase for multiset
void myerase(ordered_set<int> &t, int v){
    int rank = t.order_of_key(v);//Number of elements that are less than v in t
    ordered_set<int>::iterator it = t.find_by_order(rank); //Iterator that points to the (rank+1)th element in t
    t.erase(it);
}