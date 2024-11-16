#pragma once

#include <iostream>
#include <string>

class Person final
{
private:
    std::string name_;
    int age_;
    int height_;

public:
    Person() {}

    Person(const std::string &name, int age, int height)
      : name_(name), age_(age), height_ (height) {}

    std::string get_name() const
    {
        return name_;
    }

    void set_name(const std::string &name)
    {
        name_ = name;
    }

    int get_age() const
    {
        return age_;
    }

    void set_age(int age)
    {
        age_ = age;
    }

    int get_height() const
    {
        return height_;
    }

    void set_height(int height)
    {
        height_ = height;
    }

    void dump() const
    {
        std::cout << "Person {name = " << name_
                  << ", age = " << age_
                  << ", height = " << height_
                  << "}" << std::endl;
    }
};

class PersonBuilder final
{
private:
    Person person_;
public:
    PersonBuilder &set_age(int age)
    {
        person_.set_age (age);
        return *this;
    }

    PersonBuilder &set_name(const std::string &name)
    {
        person_.set_name (name);
        return *this;
    }

    PersonBuilder &set_height(int height)
    {
        person_.set_height (height);
        return *this;
    }

    Person get() const
    {
        return person_;
    }
};

