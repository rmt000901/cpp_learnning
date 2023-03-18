//
// Created by rmt on 23-3-18.
//
#include <iostream>

template <typename T>
class beta
{
private:
    template<typename V>
    class hold
    {
    private:
        V val;
    public:
        hold(V v = 0) : val(v) {}
        void show() const { std::cout << val << std::endl; }
        V Value() const { return val; }
    };
    hold<T> q;
    hold<int> n;
public:
    beta(T t, int i) : q(t), n(i) {}
    template<typename U>
    U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
    void Show() const { q.show(); n.show(); }
};

int main()
{
    beta<double> guy(3.5, 3);
    std::cout << "T was set to double\n";
    guy.Show();
    std::cout << "V was set to T, which is double, then V was set to int\n";
    std::cout << guy.blab(10, 2.3) << std::endl;
    std::cout << "U was set to int\n";
    std::cout << guy.blab(10.0, 2.3) << std::endl;
    std::cout << "U was set to double\n";
    std::cout << "Done\n";

    return 0;
}