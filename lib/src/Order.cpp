#include <lib/Order.h>

void Order::add(const std::string &article, size_t quantity)
{
    _article = article;
    _quantity = quantity;
}

void Order::fill(Store &store)
{
    if (store.inventory(_article) >= _quantity) {
        store.remove(_article, _quantity);
    }
}
