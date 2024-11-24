#include "entity.hpp"

int main ()
{
    my_entity::Entity entity_1;

//   entity_1.m_data_3 = 1; // error

    entity_1.set_data_3(1); 
    assert(entity_1.data_3() == 1);
    assert(entity_1.data_as_string() == "0/0/1");

//  ---------------------------------------------

    const my_entity::Entity entity_2;

//  entity_2.set_data_3(1); // error

    assert(entity_2.data_3() == 0);
    assert(entity_2.data_as_string() == "0/0/0");

//  ---------------------------------------------
    my_entity::Entity entity_3;
    my_entity::Entity entity_4(1, 2, 3);
    my_entity::Entity entity_5(1, 2);

//  Entity entity_6(); // warning

//  --------------------------------

    entity_1.test(); my_entity::Entity::test();
}
