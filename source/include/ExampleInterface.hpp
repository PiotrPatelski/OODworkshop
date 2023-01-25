#pragma once

class ExampleInterface
{
public:
    virtual ~ExampleInterface() = default;
    virtual void doStuff() = 0;
};