#include <iostream>

struct product
{
    virtual double cost () const = 0;
    virtual ~product() = default;
};

struct milk final : public product {
    double cost () const override {
        return 100.;
    }
};

/* Let's include taxes.  */
class product_decorator : public product
{
protected:
    const product &product_wrap;
public:
    product_decorator (const product &p)
      : product_wrap (p) {}

    double cost () const override
    {
        return product_wrap.cost ();
    }

    virtual ~product_decorator () = default;
};

struct filtered_milk_decorator final : public product_decorator
{
    filtered_milk_decorator(const product &p)
      : product_decorator (p) {}

    double cost () const override
    {
        return product_wrap.cost() * 1.1;
    }
};

/* Let's imagine that tax for sour milk is more expensive.  */
struct sour_milk_decorator final : public product_decorator
{
    sour_milk_decorator(const product &p)
      : product_decorator (p) {}

    double cost () const override
    {
        return product_wrap.cost() * 1.3;
    }
};

auto main () -> int
{
    milk prod;
    std::cout << "Regular milk cost: " << prod.cost () << std::endl;

    filtered_milk_decorator filter (prod);
    std::cout << "Filtered milk cost: " << filter.cost () << std::endl;

    sour_milk_decorator sour (filter);
    std::cout << "Sour milk cost: " << sour.cost () << std::endl;
}

