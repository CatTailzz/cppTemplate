// 最值线段树
template <class T>
class SegmentTree
{
    vector<T> d; // 区间节点
    vector<T> b; // lazy节点
    int n;
    function<T(T, T)> f;
    T bv;

public:
    SegmentTree(int n) : n(n), d(4 * n, INT32_MAX), b(4 * n, INT32_MAX), bv(INT32_MAX) /*修改*/
    {
        f = [](const T &a, const T &b)
        { return a < b ? a : b; };
    }

    T query(int l, int r, int s, int t, int p)
    {
        // [l, r] 为查询区间, [s, t] 为当前节点包含的区间, p 为当前节点的编号
        if (l <= s && t <= r)
            return d[p];
        // 当前区间为询问区间的子集时直接返回当前区间的和
        int m = s + ((t - s) >> 1);

        // 修改
        if (b[p] != bv)
        {
            // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
            d[p * 2] = f(d[p * 2], b[p]), d[p * 2 + 1] = f(d[p * 2 + 1], b[p]);
            b[p * 2] = f(b[p], b[p * 2]), b[p * 2 + 1] = f(b[p], b[p * 2 + 1]); // 将标记下传给子节点
            b[p] = bv;                                                          // 清空当前节点的标记
        }

        T res = bv;
        if (l <= m)
            res = f(res, query(l, r, s, m, p * 2));
        if (r > m)
            res = f(res, query(l, r, m + 1, t, p * 2 + 1));
        return res == bv ? -1 : res;
    }
    inline T query(int l, int r)
    {
        return query(l, r, 1, n, 1);
    }

    void update(int l, int r, T c, int s, int t, int p)
    {
        // [l, r] 为修改区间, c 为被修改的元素的变化量, [s, t] 为当前节点包含的区间, p
        // 为当前节点的编号
        if (l <= s && t <= r)
        {
            d[p] = f(d[p], c), b[p] = f(b[p], c);
            return;
        } // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
        int m = s + ((t - s) >> 1);
        if (b[p] != bv && s != t)
        {
            // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
            d[p * 2] = f(b[p], d[p * 2]), d[p * 2 + 1] = f(d[p * 2 + 1], b[p]);
            b[p * 2] = f(b[p * 2], b[p]), b[p * 2 + 1] = f(b[p * 2 + 1], b[p]); // 将标记下传给子节点
            b[p] = bv;                                                          // 清空当前节点的标记
        }
        if (l <= m)
            update(l, r, c, s, m, p * 2);
        if (r > m)
            update(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = f(d[p * 2], d[p * 2 + 1]);
    }
    inline void update(int l, int r, T c)
    {
        update(l, r, c, 1, n, 1);
    }
};