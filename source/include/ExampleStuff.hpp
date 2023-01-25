#pragma once
#include <ExampleInterface.hpp>

class Example : public ExampleInterface
{
public:
    virtual ~Example() = default;
    virtual void doStuff() override;
};