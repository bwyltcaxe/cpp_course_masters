#include "person.hpp"

auto main() -> int
{
    PersonBuilder builder;
    Person micro_chel = builder.set_name("Olga").set_age(29).set_height(162).get();
    micro_chel.dump();

    Person another_micro_chel = builder.set_name("Danya").get();
    another_micro_chel.dump();
}

