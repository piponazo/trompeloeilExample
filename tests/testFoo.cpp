#include <lib/Order.h>
#include <lib/Store.h>

#include <catch2/catch.hpp>
#include <trompeloeil.hpp>

extern template struct trompeloeil::reporter<trompeloeil::specialized>;

class StoreMock : public Store
{
public:
    MAKE_CONST_MOCK1(inventory, size_t(const std::string&), override);
    MAKE_MOCK2(remove, void(const std::string&, size_t), override);
};

TEST_CASE("filling does nothing if stock is insufficient")
{
    Order order;
    order.add("Talisker", 51);
    StoreMock store;
    {
        REQUIRE_CALL(store, inventory("Talisker")).RETURN(50);
        order.fill(store);
    }
}

TEST_CASE("filling removes from store if in stock")
{
    Order order;
    order.add("Talisker", 50);
    StoreMock store;
    {
        trompeloeil::sequence seq;
        REQUIRE_CALL(store, inventory("Talisker"))
                .RETURN(50)
                .IN_SEQUENCE(seq);
        REQUIRE_CALL(store, remove("Talisker", 50))
                .IN_SEQUENCE(seq);

        order.fill(store);
    }
}