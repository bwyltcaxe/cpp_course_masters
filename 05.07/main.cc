#include <iostream>
#include <vector>
#include <vector>

template<typename T>
struct my_stack : private std::vector<T>
{
    using std::vector<T>::empty;
    using std::vector<T>::size;

    my_stack () {}
    my_stack(const std::vector<T>& container)
      : std::vector<T>(container) {}

    void push (const typename std::vector<T>::value_type &val)
    {
        std::cout << "Push" << val << std::endl;
        std::vector<T>::push_back (val);
    }

    void push (typename std::vector<T>::value_type &&val)
    {
        std::cout << "Push" << val << std::endl;
        std::vector<T>::push_back (std::move (val));
    }

    void pop ()
    {
        std::cout << "Pop" << std::endl;
        std::vector<T>::pop_back ();
    }

    typename std::vector<T>::reference top ()
    {
        auto &val = std::vector<T>::back ();
        std::cout << "top = " << val << std::endl;
        return val;
    }

    typename std::vector<T>::const_reference top () const
    {
        const auto &val = std::vector<T>::back ();
        std::cout << "top = " << val << std::endl;
        return val;
    }
};

auto main () -> int
{
    std::vector<int> vec = {3, 34, 8, 12};
    my_stack<int> st (vec);

    int new_val = 13;
    st.push (new_val);

    new_val = -11;
    st.push (new_val);

    std::cout << "---------------------------------------" << std::endl;
    while (!st.empty())
    {
        auto top = st.top ();
        st.pop ();
    }

    return 0;
}

